import os

from flask import Flask
from flask_bootstrap import Bootstrap

app = Flask(__name__)
app.config['SECRET_KEY'] = 'abcd1234'
bootstrap = Bootstrap(app)

runtime_env = os.getenv('FLASK_RUNTIME_ENV')

import sqlalchemy as db
if runtime_env == "DEV":
    DBNAME = f'db/{runtime_env}.sqlite'
elif runtime_env == "PROD":
    pass

engine = db.create_engine(f'sqlite:///{DBNAME}')
connection = engine.connect()