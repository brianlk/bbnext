import json
from db.store import store

def hosts():
    hosts = [
        {"hostname":"host1", "cpu":1, "memory":1},
        {"hostname":"host2", "cpu":0, "memory":0},
    ]
    global store
    return hosts
    
def add_host():
    x = {"hostname":"host1", "cpu":1, "memory":1}
    global store
    store.append(x)
