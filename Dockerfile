FROM ubuntu:16.04

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        vim g++ make && \
    rm -rf /var/lib/apt/lists/*

COPY src /src
WORKDIR /src
