#!/bin/bash

set -e

# check if required environment variables are set
if [ -z "$DB_NAME" ] || [ -z "$DB_USER" ] || [ -z "$DB_PASSWORD" ] || [ -z "$DB_ROOT_PASSWORD" ]; then
    echo "Error: Required environment variables DB_NAME, DB_USER, DB_PASSWORD, or DB_ROOT_PASSWORD are not set."
    exit 1
fi

mysqld_safe --datadir=/var/lib/mysql --skip-networking=0 &

# Wait for MariaDB to start
echo "Waiting for MariaDB to start..."
while ! mysqladmin ping --silent; do
    sleep 1
done
echo "MariaDB temp started successfully."

echo "CREATE DATABASE IF NOT EXISTS \`$DB_NAME\`;" > create_db.sql
echo "CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD';" >> create_db.sql
echo "GRANT ALL PRIVILEGES ON \`$DB_NAME\`.* TO '$DB_USER'@'%';" >> create_db.sql
echo "FLUSH PRIVILEGES;" >> create_db.sql

mariadb < create_db.sql
rm create_db.sql

mysqladmin shutdown

echo "Starting MariaDB in the foreground..."

# Start MariaDB in the foreground with proper binding
exec mysqld_safe --port=3306 --bind-address=0.0.0.0 --datadir=/var/lib/mysql
