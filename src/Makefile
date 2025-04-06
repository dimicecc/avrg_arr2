CC=g++
CFLAGS=-Wall -Wextra -std=c++17
TARGET=avrg_arrays
BIN_DIR=../usr/bin  # Указываем на существующую папку usr/bin в корне проекта
REQUIRED_PKGS="g++ make debhelper"

# Правила сборки и установки
all: check_deps $(TARGET)

$(TARGET): avrg_arrays.o
	$(CC) $(CFLAGS) -o $(TARGET) avrg_arrays.o

avrg_arrays.o: avrg_arrays.cpp
	$(CC) $(CFLAGS) -c avrg_arrays.cpp

# Очищаем промежуточные файлы
clean:
	rm -f $(TARGET) *.o

# Установка бинарного файла в существующую папку usr/bin
install: $(TARGET)
	mkdir -p $(BIN_DIR)  # Убедимся, что папка для бинарников существует в корне проекта
	cp $(TARGET) $(BIN_DIR)  # Копируем бинарник в правильную папку

# Проверка зависимостей
check_deps:
	@missing_pkgs=""; \
	for pkg in $(REQUIRED_PKGS); do \
		dpkg -s $$pkg >/dev/null 2>&1 || missing_pkgs="$$missing_pkgs $$pkg"; \
	done; \
	if [ -n "$$missing_pkgs" ]; then \
		echo "Устанавливаются отсутствующие пакеты:$$missing_pkgs"; \
		sudo apt update && sudo apt install -y $$missing_pkgs; \
	fi
