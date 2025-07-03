FROM debian:bullseye

# Portainer
RUN apt-get update && apt-get install -y \
	curl \
	&& rm -rf /var/lib/apt/lists/* \
	&& curl -L https://github.com/portainer/portainer/releases/download/2.27.9/portainer-2.27.9-linux-amd64.tar.gz -o portainer.tar.gz \
	&& tar -xzf portainer.tar.gz -C /opt/ \
	&& rm portainer.tar.gz

EXPOSE 1312

CMD ["/opt/portainer/portainer"]
