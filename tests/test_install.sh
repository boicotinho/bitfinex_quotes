#!/bin/bash

SCRIPT_DIR=$(dirname $(readlink -f $0))
ROOT_DIR=$(dirname ${SCRIPT_DIR})

source /opt/rh/rh-python36/enable
pip install ${ROOT_DIR}
echo "===== Running Test ====="
python -c "import bitfinex_quotes as m; print('RESULT m.add(1, 2) = ' + str(m.add(1, 2)))"
echo "===== Test result: $?"
pip uninstall -y bitfinex_quotes
