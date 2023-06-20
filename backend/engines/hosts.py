import json
import random
from db.store import global_object, BackgroundTasks, bt, open_json

def get_hosts():
    # global store
    global bt
    if not bt:
        # Background thread maintains the global store
        bt = BackgroundTasks()
        bt.start()
    global global_object
    return global_object.store

