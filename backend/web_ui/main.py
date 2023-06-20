from engines.hosts import get_hosts
from engines.forms import NameForm
from web_ui.app_config import app

from flask import request, render_template

import datetime


@app.route('/', methods=['GET', 'POST'])
def index():
    # get the current date and time
    now = datetime.datetime.now()
    hosts_states = get_hosts()
    name = None
    form = NameForm()
    if form.validate_on_submit():
        name = form.name.data
    print("=============")
    print(name)
    if len(hosts_states) > 0:
        return render_template('index.html', hosts=hosts_states, now=now, 
                               request=request, form=form)
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
