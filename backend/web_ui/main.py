from engines.read import items

from flask import Flask, request, render_template

app = Flask(__name__)

@app.route('/')
def index():
    a = [1,2,3]
    return render_template('index.html', arr=a)


@app.route('/host/<host_id>')
def host(host_id):
    return "<h1>under construction</h1>"