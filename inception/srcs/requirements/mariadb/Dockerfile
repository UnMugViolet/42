# MARIA DB
FROM debian:bullseye

RUN apt update && \
	apt install -y mariadb-server netcat && \
	apt upgrade -y && \
	apt clean && \
	rm -rf /var/lib/apt/lists/* && \
	mkdir -p /run/mysqld && \
	chown mysql:mysql /run/mysqld

COPY ./init_mariadb.sh /init_mariadb.sh
RUN chmod +x /init_mariadb.sh

EXPOSE 3306

ENTRYPOINT ["/init_mariadb.sh"]
