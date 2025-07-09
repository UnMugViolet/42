# REDIS
FROM debian:bullseye

RUN apt-get update && apt-get install -y \
	redis-server \
	&& rm -rf /var/lib/apt/lists/*

# Create redis.conf file with custom configuration
RUN mkdir -p /etc/redis \
    && echo "maxmemory 256mb" >> /etc/redis/redis.conf \
    && echo "protected-mode no" >> /etc/redis/redis.conf \
    && echo "maxmemory-policy allkeys-lru" >> /etc/redis/redis.conf \
    && echo "bind 0.0.0.0" >> /etc/redis/redis.conf \
    && echo "daemonize no" >> /etc/redis/redis.conf

EXPOSE 6379

ENTRYPOINT ["redis-server", "/etc/redis/redis.conf"]
