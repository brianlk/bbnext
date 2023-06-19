import json
from db.store import store, BackgroundTasks, xxx

def hosts():
    # global store
    global bt
    if not bt:
        bt = BackgroundTasks()
        bt.start()
    global store
    return store
    
def add_host():
    x = {"hostname":"host1", "cpu":1, "memory":1}
    global store
    store.append(x)
