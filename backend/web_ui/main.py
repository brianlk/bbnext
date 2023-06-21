from engines.hosts import get_hosts
from engines.forms import SearchForm
from web_ui.app_config import app, session
from db.models import Student
from utils.tools import match_regex

from flask import request, render_template

import datetime


@app.route('/', methods=['GET', 'POST'])
def index():
    res_hosts = []
    # get the current date and time
    now = datetime.datetime.now()
    hosts_states = get_hosts()
    form = SearchForm()
    if request.method == "POST":
        name = form.name.data
        res_hosts = [ v for v in hosts_states if match_regex(name, v["hostname"]) ]
    else:
        res_hosts = hosts_states
    if len(res_hosts) > 0:
        return render_template('index.html', hosts=res_hosts, now=now, request=request, 
                               form=form)
    return render_template('no_host.html')


@app.route('/host/<host_id>')
def host(host_id):
    # new_student = Student(id=10, name="ccccc")
    # session.add(new_student)
    # session.commit()
    return "<h1>under construction</h1>"


@app.errorhandler(404)
def page_not_found(e):
    return render_template('404.html'), 404


@app.errorhandler(500)
def page_not_found(e):
    return render_template('500.html'), 500
