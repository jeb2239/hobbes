FROM ubuntu:xenial
RUN  apt update
RUN  apt install -y cmake libedit-dev g++ llvm-3.7-dev libncurses5-dev
CMD  mkdir -p /build && cd /build && cmake /src && make && make test
