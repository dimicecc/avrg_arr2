FROM ubuntu:20.04

# Отключаем интерактивный режим (для установки пакетов)
ARG DEBIAN_FRONTEND=noninteractive

# Копируем .deb файл в контейнер
COPY avrg-arrays_1.0_all.deb /tmp/

# Устанавливаем .deb пакет и удаляем его
RUN apt-get update && \
    apt-get install -y /tmp/avrg-arrays_1.0_all.deb && \
    rm /tmp/avrg-arrays_1.0_all.deb

# Указываем команду, которая будет запускаться при запуске контейнера
ENTRYPOINT ["avrg_arrays"]
