# sudo docker build -t bitfinex_dock

FROM ubuntu:20.04

MAINTAINER Fabio Fernandes version: 0.3 (Ubuntu)

RUN apt-get update

# cmake 3.16.3
# g++ 9.3
# python 3.8.10
# pip 20.0.2
# boost 1.71
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y \
	tzdata \
	cmake \
	apt-utils \
	vim \
	strace \
	build-essential \
	python3 \
	python3-dev \
	python3-pip \
	libssl-dev \
	git \
	libboost-all-dev 

WORKDIR /app
COPY . /app

# finally, bitfinex_quotes (python)
RUN git clone --recursive https://github.com/boicotinho/bitfinex_quotes.git && \
	pip3 install ./bitfinex_quotes --user

# Running test, doesn't have to be done from dockerfile
# CMD ["python3", "bitfinex_quotes/tests/test_code_snippet.py"]
