
MAKE = make

DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m
UNDERLINE = \033[4m
BOLD = \033[1m

help: ## Outputs this help screen
	@grep -E '(^[a-zA-Z0-9_-]+:.*?##.*$$)|(^##)' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}{printf "\033[32m%-30s\033[0m %s\n", $$1, $$2}' | sed -e 's/\[32m##/[33m/'

## —— Deployement ——————————————————————————————————————————————————————————————

up: ## Start the Docker containers
	@mkdir -p /home/pjaguin/data/nginx
	@mkdir -p /home/pjaguin/data/wordpress
	@mkdir -p /home/pjaguin/data/mariadb
	@mkdir -p /home/pjaguin/data/portainer
	@mkdir -p /home/pjaguin/data/ftp
	@cd ./srcs && docker compose up -d
	@echo "$(YELLOW)$(BOLD) ✓ Containers started successfully.$(DEFAULT)"

## —— Cleaning —————————————————————————————————————————————————————————————————

down: ## Stop the Docker containers
	@cd ./srcs && docker compose down

nuke: ## Stop and remove all Docker containers, networks, and volumes
	@cd ./srcs && docker compose down --volumes --remove-orphans
	@docker rmi $(shell docker images -q) --force || true
	@echo "$(YELLOW)$(BOLD) ✓ All containers, networks, and volumes removed successfully.$(DEFAULT)"

delete: ## Delete the directories
	@sudo -v
	@sudo rm -rf /home/pjaguin/data/wordpress
	@sudo rm -rf /home/pjaguin/data/mariadb
	@sudo rm -rf /home/pjaguin/data/portainer
	@echo "$(YELLOW)$(BOLD) ✓ Data directories deleted successfully.$(DEFAULT)"

re: ## Restart the Docker containers
	@$(MAKE) nuke && $(MAKE) up
	@echo "$(YELLOW)$(BOLD) ✓ Containers restarted successfully.$(DEFAULT)"

.PHONY: help up bonus down restart
