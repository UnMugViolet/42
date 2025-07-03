FROM debian:bullseye

RUN apt update && \
	apt install -y mariadb-server mariadb-client && \
	apt upgrade -y && \
	apt clean && \
	rm -rf /var/lib/apt/lists/*

# Copy initialization script
COPY conf/init.sh /usr/local/bin/init.sh
RUN chmod +x /usr/local/bin/init.sh

# Configure MariaDB
RUN sed -i 's/bind-address\s*=\s*127.0.0.1/bind-address = 0.0.0.0/' /etc/mysql/mariadb.conf.d/50-server.cnf

EXPOSE 3306

CMD ["/usr/local/bin/init.sh"]
