#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Функция для поиска индекса минимального элемента
int findMinIndex(const std::vector<int>& arr) {
    return std::min_element(arr.begin(), arr.end()) - arr.begin();
}

// Функция для поиска индекса максимального элемента
int findMaxIndex(const std::vector<int>& arr) {
    return std::max_element(arr.begin(), arr.end()) - arr.begin();
}

// Функция для вычисления среднего значения четных чисел в части массива
double averageOfEvens(const std::vector<int>& part) {
    int sum = 0, count = 0;
    for (int val : part) {
        if (val % 2 == 0) {
            sum += val;
            count++;
        }
    }
    return count == 0 ? 0.0 : static_cast<double>(sum) / count;
}

// Функция для проверки корректности массива
bool isValidArray(const std::vector<int>& arr) {
    if (arr.empty()) return false;

    int minVal = *std::min_element(arr.begin(), arr.end());
    int maxVal = *std::max_element(arr.begin(), arr.end());

    if (minVal == maxVal) return false;

    int minCount = std::count(arr.begin(), arr.end(), minVal);
    int maxCount = std::count(arr.begin(), arr.end(), maxVal);

    return minCount == 1 && maxCount == 1;
}

int main(int argc, char* argv[]) {
    std::vector<int> arr;
    int n;

    // Обработка аргументов командной строки
    if (argc > 1) {
        n = std::atoi(argv[1]);
        if (n < 3) {
            std::cerr << "Массив должен содержать минимум 3 элемента.\n";
            return 1;
        }
        for (int i = 2; i < argc; ++i) {
            arr.push_back(std::atoi(argv[i]));
        }
    } else {
        std::cout << "Введите количество элементов: ";
        std::cin >> n;

        if (n < 3) {
            std::cerr << "Массив должен содержать минимум 3 элемента.\n";
            return 1;
        }

        std::cout << "Введите элементы массива:\n";
        for (int i = 0; i < n; ++i) {
            int val;
            std::cin >> val;
            arr.push_back(val);
        }
    }

    // Проверка на корректность массива
    if (!isValidArray(arr)) {
        std::cerr << "Массив некорректен (одинаковые элементы или дубликаты минимума/максимума).\n";
        return 1;
    }

    // Находим индексы минимального и максимального элементов
    int minIndex = findMinIndex(arr);
    int maxIndex = findMaxIndex(arr);

    // Делаем так, чтобы минимальный индекс всегда был меньше максимального
    if (minIndex > maxIndex) {
        std::swap(minIndex, maxIndex);
    }

    // Делаем разделение массива на три части
    std::vector<int> part1(arr.begin(), arr.begin() + minIndex); // от начала до minIndex
    std::vector<int> part2(arr.begin() + minIndex + 1, arr.begin() + maxIndex); // между minIndex и maxIndex
    std::vector<int> part3(arr.begin() + maxIndex + 1, arr.end()); // от maxIndex до конца

    // Если одна из частей пуста, то игнорируем её
    std::cout << "Среднее чётных в части 1: " << averageOfEvens(part1)
              << " Среднее чётных в части 2: " << averageOfEvens(part2)
              << " Среднее чётных в части 3: " << averageOfEvens(part3) << std::endl;

    return 0;
}
