#!/bin/bash

SCRIPT_DIR=$(dirname $(readlink -f $0))
ROOT_DIR=$(dirname ${SCRIPT_DIR})

source /opt/rh/rh-python36/enable
pip3 install ${ROOT_DIR} --user

echo "===== Running Test ====="
python3 -c "import bitfinex_quotes as m; print('RESULT m.add(1, 2) = ' + str(m.add(1, 2)))"
echo "===== Test exit code: $?"

pip3 uninstall -y bitfinex_quotes
