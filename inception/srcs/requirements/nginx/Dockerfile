# NGINX
FROM debian:bullseye

RUN apt update && \
    apt install -y nginx openssl && \
    apt upgrade -y && \
    apt clean && \
    rm -rf /var/lib/apt/lists/*

# Create SSL certificate
RUN mkdir -p /etc/nginx/ssl && \
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key \
    -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=FR/ST=Paris/L=Paris/O=42/OU=42/CN=pjaguin.42.fr"

# Copy nginx configuration
COPY ./nginx.conf /etc/nginx/sites-available/default

# Create necessary directories
RUN mkdir -p /var/run/nginx

EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]