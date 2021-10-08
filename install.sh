#!/bin/bash
echo "Make sure venv is installed!"
if [ -d "./venv" ]; then
    source ./venv/bin/activate
    pip uninstall -y -r <(pip freeze)
else
    python3 -m venv venv
    source ./venv/bin/activate
fi
pip install -r requirements.txt