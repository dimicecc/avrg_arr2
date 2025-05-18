FROM ubuntu:latest
RUN apt-get update && apt-get install -y \
    g++ \
    dpkg-dev \
    libstdc++6 \
    && rm -rf /var/lib/apt/lists/*
COPY avrg_arrays.deb /tmp/
RUN dpkg -i /tmp/avrg-arrays_1.0_all.deb || apt-get install -f
CMD ["/usr/bin/avrg_arrays"", "--success"]
