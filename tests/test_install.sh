#!/bin/bash

SCRIPT_DIR=$(dirname $(readlink -f $0))
ROOT_DIR=$(dirname ${SCRIPT_DIR})

source /opt/rh/rh-python36/enable
pip3 install ${ROOT_DIR} --user

echo "===== Running Test ====="
python3 ${ROOT_DIR}/tests/test_code_snippet.py
echo "===== Test exit code: $?"

pip3 uninstall -y bitfinex_quotes
