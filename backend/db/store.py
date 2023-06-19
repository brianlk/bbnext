import random
import threading
import time

# Store the host's metrics
store = []

# Background task
bt = None

class BackgroundTasks(threading.Thread):
    def run(self,*args,**kwargs):
        while True:
            if len(store) > 0:
                store[0]["cpu"] = random.randint(0,1)
                store[0]["memory"] = random.randint(0,1)
            else:
                store.append({"hostname":"host1", "cpu":1, "memory":1})
                
            print(store)
            time.sleep(5)


