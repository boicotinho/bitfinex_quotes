#!/bin/bash
source /opt/rh/rh-python36/enable
pip install ../
echo "===== Running Test ====="
python -c "import bitfinex_quotes as m; print('RESULT m.add(1, 2) = ' + str(m.add(1, 2)))"
echo "===== Test result: $?"
pip uninstall -y bitfinex_quotes

