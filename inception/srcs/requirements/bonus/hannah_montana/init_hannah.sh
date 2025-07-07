#!/bin/bash

# Always copy the latest web files to the mounted volume
echo "Copying latest web files to /var/www/html..."
rm -rf /var/www/html/*
cp -r /tmp/web-files/* /var/www/html/
chown -R www-data:www-data /var/www/html
chmod -R 755 /var/www/html

rm -rf /tmp/web-files

# Start Apache2 in foreground to keep container running
exec apache2ctl -D FOREGROUND
