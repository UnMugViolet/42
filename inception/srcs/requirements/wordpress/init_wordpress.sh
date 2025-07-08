#!/bin/bash

set -e

if [ -z "$WP_DATABASE" ] || [ -z "$WP_DATABASE_USER" ] || [ -z "$WP_DATABASE_PASSWORD" ] || [ -z "$WP_ADMIN_USER" ] || [ -z "$WP_ADMIN_PASSWORD" ] || [ -z "$WP_ADMIN_EMAIL" ]; then
    echo "Error: Required environment variables WP_DATABASE, WP_DATABASE_USER, WP_DATABASE_PASSWORD, BASE_HOST, WP_ADMIN_USER, WP_ADMIN_PASSWORD, or WP_ADMIN_EMAIL are not set."
    exit 1
fi

# Create PHP-FPM socket directory
mkdir -p /run/php
chown www-data:www-data /run/php

# Additional wait to ensure MariaDB is fully ready to accept connections
sleep 5

# Test database connection
echo "Testing database connection..."
while ! mysqladmin ping -h"mariadb" -u"$WP_DATABASE_USER" -p"$WP_DATABASE_PASSWORD" --silent; do
    echo "Database connection test failed. Retrying..."
    sleep 2
done
echo "Database connection successful!"

# Download WordPress if not present
if [ ! -f /var/www/html/wp-config.php ]; then
    echo "Setting up WordPress..."
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
                        --allow-root

    wp plugin install --path=/var/www/html \
                redis-cache \
                --activate \
                --allow-root

    # Configure Redis settings in wp-config.php
    wp config set --path=/var/www/html WP_REDIS_HOST redis --allow-root
    wp config set --path=/var/www/html WP_REDIS_PORT 6379 --allow-root
    wp config set --path=/var/www/html WP_REDIS_TIMEOUT 1 --allow-root
    wp config set --path=/var/www/html WP_REDIS_READ_TIMEOUT 1 --allow-root
    wp config set --path=/var/www/html WP_REDIS_DATABASE 0 --allow-root

    wp user create      --path=/var/www/html \
                        "$WP_USER_NAME" \
                        "$WP_USER_EMAIL" \
                        --role=editor \
                        --user_pass="$WP_USER_PASSWORD" \
                        --allow-root

    wp redis enable --path=/var/www/html --allow-root
    
    echo "WordPress setup completed!"
else
    echo "WordPress already configured."
fi

sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 0.0.0.0:9000/' /etc/php/7.4/fpm/pool.d/www.conf

# Start PHP-FPM in the foreground
exec php-fpm7.4 -F
