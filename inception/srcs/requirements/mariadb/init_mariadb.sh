#!/bin/bash

set -e

# check if required environment variables are set
if [ -z "$DB_NAME" ] || [ -z "$DB_USER" ] || [ -z "$DB_PASSWORD" ] || [ -z "$DB_ROOT_PASSWORD" ]; then
    echo "Error: Required environment variables DB_NAME, DB_USER, DB_PASSWORD, or DB_ROOT_PASSWORD are not set."
    exit 1
fi

# Initialize the database if it hasn't been initialized
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing database..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

# Check if database is already configured (to avoid reconfiguring on restart)
if [ ! -f "/var/lib/mysql/.configured" ]; then
    echo "Configuring database for first time..."
    
    # Start MySQL server in the background (temporary) to configure it
    mysqld_safe --datadir=/var/lib/mysql --skip-networking --socket=/tmp/mysql_temp.sock &
    TEMP_PID=$!
    
    # Wait for the MySQL server to be ready
    echo "Waiting for temporary MySQL server to start..."
    while ! mysqladmin --socket=/tmp/mysql_temp.sock ping --silent; do
        sleep 1
    done
    
    # Set root password and create database and user
    mysql --socket=/tmp/mysql_temp.sock -u root <<-EOSQL
		UPDATE mysql.user SET authentication_string = PASSWORD('${DB_ROOT_PASSWORD}') WHERE User = 'root' AND Host = 'localhost';
		DELETE FROM mysql.user WHERE User='';
		DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
		DROP DATABASE IF EXISTS test;
		DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';
		CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;
		CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
		GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '${DB_USER}'@'%';
		FLUSH PRIVILEGES;
	EOSQL
    
    # Shutdown the temporary server
    kill $TEMP_PID
    wait $TEMP_PID
    
    # Mark as configured
    touch /var/lib/mysql/.configured
    echo "Database configuration completed."
fi

echo "Starting MariaDB in the foreground..."

# Start MariaDB in the foreground with proper binding
exec mysqld_safe --port=3306 --bind-address=0.0.0.0 --datadir=/var/lib/mysql
