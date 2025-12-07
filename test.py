import re

pattern = r'(//|/\*|\*/|"| +|\n+|\w+|[^ \w\n]+)'

s = "aaa.-a//-=   b"
tokens = re.findall(pattern, s)
print(tokens)
