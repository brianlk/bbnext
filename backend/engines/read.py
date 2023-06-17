import json

def hosts():
    item = '[{"hostname":"host1"}, {"hostname":"host2"}]'
    host_list = json.loads(item)
    return host_list
    
