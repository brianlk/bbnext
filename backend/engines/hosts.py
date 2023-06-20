import json
from db.store import g, BackgroundTasks, bt, open_json

def hosts():
    # global store
    global bt
    if not bt:
        bt = BackgroundTasks()
        bt.start()
    global g
    return g.store

