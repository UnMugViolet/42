FROM debian:bullseye

RUN apt-get update && apt-get install -y \
	vsftpd \
	&& rm -rf /var/lib/apt/lists/*

COPY ./init_ftp.sh /init_ftp.sh

RUN chmod +x /init_ftp.sh

ENTRYPOINT ["/init_ftp.sh"]
