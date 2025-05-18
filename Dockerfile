FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    g++ dpkg-dev libstdc++6 && rm -rf /var/lib/apt/lists/*

COPY avrg-arrays_1.0_all.deb /tmp/

RUN dpkg -i /tmp/avrg-arrays_1.0_all.deb || apt-get install -f -y

# Добавим проверку расположения файла
RUN ls -l /usr/bin/
RUN ls -l /usr/local/bin/
RUN find / -name avrg_arrays || echo "Файл avrg_arrays не найден"

ENTRYPOINT ["/usr/bin/avrg_arrays"]






