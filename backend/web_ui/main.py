from engines.read import items


from flask import Flask
app = Flask(__name__)

@app.route('/')
def index():
    print(items())
    return "<h1>i am ok</h1>"