FROM debian:bullseye

RUN apt-get update && apt-get install -y \
	apache2 \
	&& rm -rf /var/lib/apt/lists/*

COPY ./init_hannah.sh /init_hannah.sh
COPY ./srcs/ /var/www/html/

RUN chmod +x /init_hannah.sh \
	&& chown -R www-data:www-data /var/www/html \
	&& chmod -R 755 /var/www/html

RUN echo "Listen 1311" >> /etc/apache2/ports.conf
RUN sed -i 's/<VirtualHost \*:80>/<VirtualHost *:1311>/' /etc/apache2/sites-available/000-default.conf

# Warning occurs if the ServerName directive is not set
RUN echo "ServerName localhost" >> /etc/apache2/apache2.conf

EXPOSE 1311

ENTRYPOINT ["/init_hannah.sh"]
