from engines.read import hosts

from flask import Flask, request, render_template
from flask_bootstrap import Bootstrap

app = Flask(__name__)
bootstrap = Bootstrap(app)

@app.route('/')
def index():
    return render_template('index.html', hosts=hosts(), request=request)


@app.route('/host/<host_id>')
def host(host_id):
    return "<h1>under construction</h1>"