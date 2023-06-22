# Import app config
from web_ui.app_config import app, session

from engines.hosts import get_hosts
from engines.forms import SearchForm
from utils.tools import match_regex
from db.models import Host, CPUThreshold, MEMThreshold

from flask import request, render_template, abort

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


@app.route('/host/<hostname>', methods=['POST'])
def host(hostname):
    try:
        res_dict = request.get_json()
        cpu_t = CPUThreshold(cpu_threshold=res_dict["cpu_threshold"])
        mem_t = MEMThreshold(mem_threshold=res_dict["mem_threshold"])
        host = Host(hostname=hostname, cpu_threshold=[c], mem_threshold=[m])
        session.add(host)
        session.commit()
    except Exception as e:
        session.rollback()
        print("Exception occurred for value: "+ repr(e))
        abort(500)
    return "<h1>ok</h1>"


@app.errorhandler(404)
def page_not_found(e):
    return render_template('404.html'), 404


@app.errorhandler(500)
def page_not_found(e):
    return render_template('500.html'), 500
