#!/bin/bash

# -G for Group id and -n for name
# tr = tranlate char

id -Gn $FT_USER | tr ' ' ', ' | tr -d '\n'

# COMMAND TO USE : ./print_groups.sh