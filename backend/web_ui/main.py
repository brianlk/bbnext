from engines.hosts import hosts, add_host

from flask import Flask, request, render_template
from flask_bootstrap import Bootstrap

app = Flask(__name__)
bootstrap = Bootstrap(app)

@app.route('/')
def index():
    xxx = hosts()
    if len(xxx) > 0:
        return render_template('index.html', hosts=xxx, request=request)
    return "<h1>No hosts</h1>"

@app.route('/add')
def add():
    add_host()
    return '<h1>aaa</h1>'
    

@app.route('/host/<host_id>')
def host(host_id):
    return "<h1>under construction</h1>"


@app.errorhandler(404)
def page_not_found(e):
    return render_template('404.html'), 404


@app.errorhandler(500)
def page_not_found(e):
    return render_template('500.html'), 500
