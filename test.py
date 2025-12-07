import re

text = 'hello hi hello\n'
split_text = re.split(r'(\W+|\w+)', text)

# Filter out empty strings if necessary
split_text = [part for part in split_text if part]

print(split_text)
