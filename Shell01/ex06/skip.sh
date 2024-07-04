#!/bin/bash

# 1~2 is a command sequence - select every second line, start from 1
# p print them

ls -l | sed -n 1~2p 

# COMMAND TO USE : ./skip.sh | cat -e