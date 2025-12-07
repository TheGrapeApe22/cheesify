# 12/6/2025
import re

# read and parse input
with open('victim.c', 'r') as file:
    content = file.read()

# content = input(" > ")

pattern = re.compile(r"""
(
    \n                  |
    [ ]+                |   # spaces
    //                  |
    /\*|\*/             |
    "                   |
    '                   |
    \\                  |   # backslash
    \( | \) | \{ | \} | \[ | \] | ; | # random chars i decided
    \#                  |   # for #define
    \w+                 |   # alphanumeric + underscore
    [^\s\w"'/\\#]+          # any other symbols (group consecutive ones)
)
""", re.VERBOSE)

tokens = pattern.split(content)
tokens = [t for t in tokens if t]
# print(tokens)

cheeses = {}
cheese_counter = 0

def generate(n):
    base = "chee"
    n2 = n
    multiplier = 64
    while (1 << (len(base)+2) <= n2):
        base += "e"
        n2 -= multiplier
        multiplier *= 2
    
    base += "se"
    
    out = ""
    for i in range(len(base)):
        if ((n2 >> i) & 1):
            out += base[i].upper()
        else:
            out += base[i]
    
    return out

def get_cheese(token):
    global cheese_counter
    if token not in cheeses:
        cheeses[token] = generate(cheese_counter)
        cheese_counter += 1
        print("#define {} {}".format(cheeses[token], token))
    return cheeses[token]

out = ""

i = 0
while i < len(tokens):
    token = tokens[i]
    
    def goto_next(s):
        global i, token
        while ((i + 1 < len(tokens))):
            i += 1
            token += tokens[i]
            # stop when found next except when backslash
            if tokens[i] == s and tokens[i-1] != '\\':
                break
    
    if token[0] == '\n' or token[0] == ' ':
        pass
    elif token == '"':
        goto_next('"')
    elif token == "'":
        goto_next("'")
    elif token == '//' or token == '#':
        goto_next('\n')
    elif token == '/*':
        goto_next('*/')
    # print(token, end='')
    
    if (token[0] == '#' or token == '\n' or token[0] == ' '):
        out += token
    elif token == '//':
        out += '// cheese'
    elif token == '/*':
        out += '/* cheese */'
    else:
        out += get_cheese(token)
        if (i+1 < len(tokens) and tokens[i+1] not in ['\n', ' ']):
            out += ' '
    i += 1

print(out)
