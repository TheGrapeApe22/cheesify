# do laundry
# 12/6/2025

import re

with open('victim.c', 'r') as file:
    content = file.read()

split_text = re.split(r'(\n+|\s+|\w+)', content)

split_text = [part for part in split_text if part]

with open('out.txt', 'w') as file:
    for segment in split_text:
        file.write(repr(segment) + '\n')
