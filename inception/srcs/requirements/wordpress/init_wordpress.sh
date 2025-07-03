#!/bin/bash

set -e

if [ -z "$WP_DATABASE" ] || [ -z "$WP_DATABASE_USER" ] || [ -z "$WP_DATABASE_PASSWORD" ] || [ -z "$WP_ADMIN_USER" ] || [ -z "$WP_ADMIN_PASSWORD" ] || [ -z "$WP_ADMIN_EMAIL" ]; then
    echo "Error: Required environment variables WP_DATABASE, WP_DATABASE_USER, WP_DATABASE_PASSWORD, BASE_HOST, WP_ADMIN_USER, WP_ADMIN_PASSWORD, or WP_ADMIN_EMAIL are not set."
    exit 1
fi

# Create PHP-FPM socket directory
mkdir -p /run/php
chown www-data:www-data /run/php

# Wait for the database to be ready
until mysql -h mariadb -u$WP_DATABASE_USER -p$WP_DATABASE_PASSWORD -e "show databases;" > /dev/null 2>&1; do
    echo "Waiting for MySQL to be ready..."
    sleep 2
done

# Download WordPress if not present
if [ ! -f /var/www/html/wp-config.php ]; then
    wp core download    --path=/var/www/html \
                        --allow-root

    wp config create    --path=/var/www/html \
                        --dbname=$WP_DATABASE \
                        --dbuser=$WP_DATABASE_USER \
                        --dbpass=$WP_DATABASE_PASSWORD \
                        --dbhost=mariadb \
                        --dbprefix=$WP_TABLE_PREFIX \
                        --allow-root

    wp core install     --path=/var/www/html \
                        --url="$WP_URL" \
                        --title="$WP_TITLE" \
                        --admin_user="$WP_ADMIN_USER" \
                        --admin_password="$WP_ADMIN_PASSWORD" \
                        --admin_email="$WP_ADMIN_EMAIL" \
                        --skip-email --allow-root
fi

# Configure PHP-FPM to listen on port 9000 instead of socket
sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 9000/' /etc/php/7.4/fpm/pool.d/www.conf
sed -i 's/;listen.owner = www-data/listen.owner = www-data/' /etc/php/7.4/fpm/pool.d/www.conf
sed -i 's/;listen.group = www-data/listen.group = www-data/' /etc/php/7.4/fpm/pool.d/www.conf

# Start PHP-FPM in the foreground
exec php-fpm7.4 -F
