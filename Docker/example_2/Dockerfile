FROM ubuntu:18.04

ENV TZ=Europe/Kiev

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
                     golang \
                     libboost-dev \
                     libboost-program-options-dev \
                     libgtest-dev

RUN apt install -y libconfig++-dev

WORKDIR /usr/src/boost

RUN cd /home && wget https://sourceforge.net/projects/boost/files/boost/1.74.0/boost_1_74_0.tar.gz \
  && tar xfz boost_1_74_0.tar.gz \
  && rm boost_1_74_0.tar.gz \
  && cd boost_1_74_0 \
  && ./bootstrap.sh --prefix=/usr/local --with-libraries=program_options \
  && ./b2 install \
  && cd /home


RUN mkdir -p /usr/src/app/
WORKDIR /usr/src/app/

COPY . /usr/src/app

RUN mkdir build && cd build && cmake ..
WORKDIR /usr/src/app/build

RUN make -j4

WORKDIR /usr/src/app/build/

ENTRYPOINT ["./httpserver"]
