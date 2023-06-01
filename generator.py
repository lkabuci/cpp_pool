#!/usr/bin/env python3

import sys
import os

if len(sys.argv) < 2:
    print("Input argument is missing. Please provide the input.")
    sys.exit(1)

input_arg = sys.argv[1]

# Remove unnecessary parts of the input
files = input_arg.split(': ')[1]

# Replace .{h, hpp} with .hpp
files = files.replace('.{h, hpp}', '.hpp')

# Remove spaces and split the files by comma
file_list = [file.strip() for file in files.replace(' ', '').split(',')]

# Iterate over the files and create them
for file in file_list:
    if file.endswith('.hpp'):
        open(file, 'a').close()
    elif file.endswith('.cpp'):
        open(file, 'a').close()

print("Files created successfully!")
