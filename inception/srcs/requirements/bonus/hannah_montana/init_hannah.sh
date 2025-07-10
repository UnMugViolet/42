#!/bin/bash

echo "Starting Apache server..."

exec apache2ctl -D FOREGROUND
