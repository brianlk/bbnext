from engines.hosts import hosts

from flask import Flask, request, render_template
from flask_bootstrap import Bootstrap

import datetime

app = Flask(__name__)
bootstrap = Bootstrap(app)

@app.route('/')
def index():
    # get the current date and time
    now = datetime.datetime.now()
    hosts_states = hosts()
    if len(hosts_states) > 0:
        return render_template('index.html', hosts=hosts_states, now=now, 
                               request=request)
    return render_template('no_host.html')

@app.route('/host/<host_id>')
def host(host_id):
    return "<h1>under construction</h1>"


@app.errorhandler(404)
def page_not_found(e):
    return render_template('404.html'), 404


@app.errorhandler(500)
def page_not_found(e):
    return render_template('500.html'), 500
