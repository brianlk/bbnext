import json

def hosts():
    item = '[{"hostname":"host1"}, {"hostname":"host2"}, {"hostname":"host3"}]'
    hosts = json.loads(item)
    return hosts
    
