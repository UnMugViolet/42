#!/usr/bin/zsh
ifconfig | grep ether | awk '{print $2}'
