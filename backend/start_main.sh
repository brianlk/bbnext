#!/bin/bash


if [ $# -eq 0 ]; then
    echo "Usage: ./start_main.sh DEV"
    exit 1
fi

export PYTHONPATH=$PWD
export FLASK_APP=web_ui/main.py
export FLASK_DEBUG=0
export FLASK_RUNTIME_ENV=$1

flask run --host 0.0.0.0
