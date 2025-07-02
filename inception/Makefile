
DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m
UNDERLINE = \033[4m

help: ## Outputs this help screen
	@grep -E '(^[a-zA-Z0-9_-]+:.*?##.*$$)|(^##)' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}{printf "\033[32m%-30s\033[0m %s\n", $$1, $$2}' | sed -e 's/\[32m##/[33m/'

## —— Deployement ——————————————————————————————————————————————————————————————

up: ## Start the Docker containers
	@cd srcs && \
	@docker-compose up -d
	echo $(GREEN)"Containers started successfully."$(DEFAULT)

bonus: ## Start the Docker containers with bonus features
	@cd srcs && \
	# @docker-compose -f docker-compose-bonus.yml up -d
	@docker-compose-bonus.yml up -d
	echo $(GREEN)"Bonus containers started successfully."$(DEFAULT)

## —— Cleaning —————————————————————————————————————————————————————————————————

down: ## Stop the Docker containers
	docker-compose down

restart: ## Restart the Docker containers
	@cd srcs && \
	@docker-compose down && \
	@docker-compose up -d
	echo $(GREEN)"Containers restarted successfully."$(DEFAULT)

.PHONY: help up down restart
