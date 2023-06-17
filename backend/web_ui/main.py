from engines.read import items

from flask import Flask, request, render_template
from flask_bootstrap import Bootstrap

app = Flask(__name__)
bootstrap = Bootstrap(app)

@app.route('/')
def index():
    a = [1,2,3]
    print(request.path)
    return render_template('index.html', arr=a, request=request)


@app.route('/host/<host_id>')
def host(host_id):
    return "<h1>under construction</h1>"