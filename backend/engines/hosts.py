import json
from db.store import g, BackgroundTasks, bt, open_json

def hosts():
    # global store
    global bt
    if not bt:
        bt = BackgroundTasks()
        bt.start()
    global g
    print(g.store)
    return g.store
    
def add_host():
    x = {"hostname":"host1", "cpu":1, "memory":1}
    global store
    store.append(x)
