#!/bin/bash

# basename remove the directory and all suffix from files
find . -type f -name "*.sh" -exec basename {} .sh \;

# COMMAND TO USE : ./find_sh.sh | cat -e