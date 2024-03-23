SHELL=bash
CONFIRM=0
MAKEFLAGS+= --no-print-directory
TOOLS=git make gcc aws
VERSION=`git describe --tags --always`
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = main.c helloworld.c
OFILES = main.o helloworld.o
NAME = mainapp
SOURCEDIR = src/
DISTDIR = dist/
BUILDDIR = build/

.PHONY: clean setup all

help:
	@grep -h -E '^[a-zA-Z0-9_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
__check-tools:
	@for TOOL in $(TOOLS); do \
  		type $$TOOL &> /dev/null && ([ $(CONFIRM) -eq 1 ] && echo "$$TOOL: OK" || true) || (echo "$$TOOL: MISSING"; exit 1); \
    done
	@aws --version | cut -f 1 -d " " | cut -f 2 -d "/" | grep -q "^2" || (echo "aws: OLD (upgrade to AWS CLI version 2)"; exit 1)
check-tools: ## Check if required tools are installed
	@$(MAKE) __check-tools CONFIRM=1

run: all  ## Build everything and run the app
	@dist/mainapp

all: setup $(NAME) ## Setup and Build everything

$(NAME): $(OFILES) ## Build application
	$(CC) -o $(DISTDIR)$(NAME) $(BUILDDIR)main.o $(BUILDDIR)helloworld.o -I$(SOURCEDIR)helloworld.h

main.o: ## Build main.o
	$(CC) -o $(BUILDDIR)main.o -c $(SOURCEDIR)main.c -I$(SOURCEDIR)helloworld.h

helloworld.o: ## Build helloworld.o
	$(CC) -o $(BUILDDIR)helloworld.o -c $(SOURCEDIR)helloworld.c -I$(SOURCEDIR)helloworld.h

clean: ## Clean the project (i.e., delete build and dist directories.)
	rm -rf $(BUILDDIR)
	rm -rf $(DISTDIR)

setup: clean ## Initializes build environment
	mkdir $(BUILDDIR)
	mkdir $(DISTDIR)




	













