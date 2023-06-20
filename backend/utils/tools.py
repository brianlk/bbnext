import re

def match_regex(pattern, source):
    result = re.match(pattern, source)
    return result