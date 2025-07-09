#!/bin/bash

# Create directory if it doesn't exist
mkdir -p /var/www/html

# Download adminer with the correct URL
curl -L -o /var/www/html/index.php https://github.com/vrana/adminer/releases/download/v5.3.0/adminer-5.3.0.php

chown -R www-data:www-data /var/www/html/index.php
chmod 755 /var/www/html/index.php

rm -rf /var/www/html/index.html

php -S 0.0.0.0:1313 -t /var/www/html
