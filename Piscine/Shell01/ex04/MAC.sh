#!/bin/bash

# grep ether cath all the mac info 
# awk print second parameter 

ifconfig | grep ether | awk '{print $2}'

# COMMAND TO USE : ./MAC.sh | cat -e
