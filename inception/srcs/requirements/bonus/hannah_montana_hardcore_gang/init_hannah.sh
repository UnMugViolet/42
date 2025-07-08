#!/bin/bash

echo "Deleting existing web files..."
rm -rf /var/www/html/*

echo "Copying web files to /var/www/html..."
mkdir -p /tmp/web-files
cp -r /tmp/web-files/* /var/www/html/
chown -R www-data:www-data /var/www/html
chmod -R 755 /var/www/html

rm -rf /tmp/web-files

# Start Apache2 in foreground
exec apache2ctl -D FOREGROUND
