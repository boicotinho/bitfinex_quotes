# sudo docker build -t bitfinex_dock

FROM ubuntu

MAINTAINER Fabio Fernandes version: 0.2 (Ubuntu)

RUN apt-get update

# cmake 3.16.3
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y tzdata
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends tzdata
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y cmake

# g++ 9.3
RUN apt-get install -y apt-utils
RUN apt-get install -y vim
RUN apt-get install -y build-essential

# python 3.8.10
RUN apt-get install -y python3
RUN apt-get install -y python3-dev

# pip 20.0.2
RUN apt-get install -y python3-pip

RUN apt-get install -y libssl-dev
RUN apt-get install -y git

# boost 1.71
RUN apt-get install -y libboost-all-dev

# finally, bitfinex_quotes (python)
RUN git clone --recursive https://github.com/boicotinho/bitfinex_quotes.git
RUN pip3 install ./bitfinex_quotes --user
RUN python3 bitfinex_quotes/tests/test_code_snippet.py
