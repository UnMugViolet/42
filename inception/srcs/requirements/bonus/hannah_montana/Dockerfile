FROM debian:bullseye

RUN apt-get update && apt-get install -y \
	apache2 \
	&& rm -rf /var/lib/apt/lists/*

COPY ./init_hannah.sh /init_hannah.sh
COPY ./srcs/ /tmp/web-files/

RUN chmod +x /init_hannah.sh

# Configure Apache to listen on port 8080
RUN echo "Listen 8080" >> /etc/apache2/ports.conf
RUN sed -i 's/<VirtualHost \*:80>/<VirtualHost *:8080>/' /etc/apache2/sites-available/000-default.conf

# Set ServerName to suppress warning
RUN echo "ServerName localhost" >> /etc/apache2/apache2.conf

EXPOSE 8080

ENTRYPOINT ["/init_hannah.sh"]
