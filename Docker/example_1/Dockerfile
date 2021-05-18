FROM ubuntu:18.04

RUN apt update && apt install  -y \
                     build-essential \
                     autoconf \
                     automake \
                     cmake \
                     curl \
                     gcc \
                     g++ \
                     git \
                     libtool \
                     make \
                     unzip \
                     wget \
                     python3 \
                     golang

RUN mkdir -p /usr/src/app/
WORKDIR /usr/src/app/

COPY . /usr/src/app/

RUN mkdir build && cd build && cmake ..
WORKDIR /usr/src/app/build

RUN make -j4

ENTRYPOINT ["./example_1"]
