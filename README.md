# bitfinex_quotes Python module

## Installation

Prerequisites:
    cmake  >= 3.4
    python >= 3.6
    gcc    >= 4.8
    pip 10+
    boost 1.75
    OpenSSL (openssl-devel)

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

    Boost:
    git clone --recursive https://github.com/boostorg/boost.git   # 28 minutes
    cd boost
    ./bootstrap.sh # 22 seconds. Alternatively specify a local dir, --prefix=/home/fabio/dev/dist/
    ./b2 # 2 minutes
    sudo./b2 install

git clone --recurse-submodules https://github.com/boicotinho/bitfinex_quotes.git
pip3 install ./bitfinex_quotes --user

python3 -c "import bitfinex_quotes as m; print('RESULT m.add(1, 2) = ' + str(m.add(1, 2)))"

pip3 uninstall -y bitfinex_quotes


TODO: Adapt doc to bitfinex_quotes

## Test call

```python
import bitfinex_quotes

```

[`cibuildwheel`]:          https://cibuildwheel.readthedocs.io
[FAQ]: http://pybind11.rtfd.io/en/latest/faq.html#working-with-ancient-visual-studio-2009-builds-on-windows
[vs2015_runtime]: https://www.microsoft.com/en-us/download/details.aspx?id=48145
[scikit-build]: https://scikit-build.readthedocs.io/en/latest/
