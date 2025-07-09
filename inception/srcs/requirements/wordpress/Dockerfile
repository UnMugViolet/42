# WORDPRESS
FROM debian:bullseye

RUN apt update && \
    apt install -y php-fpm php-mysql php-curl php-gd php-xml php-mbstring php-zip wget curl mariadb-client && \
    apt upgrade -y && \
    apt clean && \
    rm -rf /var/lib/apt/lists/*

# Install wp-cli
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

# Copy initialization script
COPY ./init_wordpress.sh /init_wordpress.sh
RUN chmod +x /init_wordpress.sh

EXPOSE 9000

ENTRYPOINT ["/init_wordpress.sh"]
