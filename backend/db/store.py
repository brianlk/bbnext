import random
import threading
import time
import json
import os

# Store the host's metrics
class GObject:
    store = []
    
g = GObject()

# Background task
bt = None

class BackgroundTasks(threading.Thread):
    def run(self,*args,**kwargs):
        while True:
            global g
            # Clear the global list
            g.store.clear()
            g.store = open_json()
            time.sleep(2)



def open_json():
    with open(os.path.dirname(__file__) + "/db.json") as f:
        data = json.load(f)
        
    return data