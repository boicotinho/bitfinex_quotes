# market_py2cpp Python module
 @ Fabio Fernandes

## Tools

Prerequisites:
    cmake  >= 3.4
    python >= 3.6
    gcc    >= 4.8
    pip 10+
    boost 1.75
    OpenSSL

Centos8 :
    sudo yum install -y cmake platform-python-devel openssl-devel

Centos7:
    sudo yum install -y rh-python36 openssl-devel
    source /opt/rh/rh-python36/enable

    CMake 3.23:
    wget https://github.com/Kitware/CMake/releases/download/v3.23.0-rc1/cmake-3.23.0-rc1.tar.gz
    tar zxvf cmake-3.*
    cd cmake-3.*
    ./bootstrap --prefix=/usr/local
    make -j$(nproc)
    sudo make install

    Boost from source:
    git clone --recursive https://github.com/boostorg/boost.git   # 28 minutes
    cd boost
    ./bootstrap.sh # 22 seconds. Alternatively specify a local dir, --prefix=/home/fabio/dev/dist/
    ./b2 # 2 minutes
    sudo./b2 install
## Build & Test

git clone --recurse-submodules https://github.com/boicotinho/market_py2cpp.git

pip3 install ./market_py2cpp --user

python3 market_py2cpp/tests/test_code_snippet.py

pip3 uninstall -y market_py2cpp
