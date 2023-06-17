#!/bin/bash

export PYTHONPATH=$PWD
export FLASK_APP=web_ui/main.py
export FLASK_DEBUG=0
flask run --host 0.0.0.0
