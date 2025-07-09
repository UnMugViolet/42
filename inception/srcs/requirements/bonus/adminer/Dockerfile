# ADMINER
FROM debian:bullseye

RUN apt update && apt install -y \
	apache2 \
	php \
	php-mysql \
	curl \
	&& rm -rf /var/lib/apt/lists/*

COPY ./init_adminer.sh /init_adminer.sh
RUN chmod +x /init_adminer.sh

EXPOSE 1313

ENTRYPOINT ["/init_adminer.sh"]
