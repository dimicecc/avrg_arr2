FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

COPY avrg-arrays_1.0_all.deb /tmp/

RUN apt-get update && \
    apt-get install -y dpkg && \
    dpkg -i /tmp/avrg-arrays_1.0_all.deb || apt-get install -f -y && \
    rm /tmp/avrg-arrays_1.0_all.deb && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

ENTRYPOINT ["/usr/bin/avrg_arrays"]
