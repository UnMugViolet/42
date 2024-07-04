#! /bin/bash

# wc -l count each new line given by the find
find . -type f -o -type d | wc -l

# COMMAND TO USE : ./count_files.sh | cat -e
