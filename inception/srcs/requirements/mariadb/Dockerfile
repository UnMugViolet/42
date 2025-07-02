FROM debian:bullseye

RUN apt update && \
	apt install -y mariadb-server mariadb-client && \
	apt upgrade -y && \
	apt clean && \
	rm -rf /var/lib/apt/lists/*

EXPOSE 3306

CMD ["mariadb"]
