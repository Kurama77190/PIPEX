# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 16:01:20 by sben-tay          #+#    #+#              #
#    Updated: 2024/04/09 16:41:24 by sben-tay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Définitions de base

NAME = pipex
PRINTF = ./external/PRINTF
CC = cc
CFLAGS = -g -Wall -Wextra -Werror 
CPPFLAGS = -I./include
#=================================================__SRC__OF__PROJECT__=============================================================================
# SRC = $(wildcard ./src/*.c)
SRC = $(wildcard ./src/*.c) $(shell find ./src -type f -name '*.c')
#==================================================================================================================================================

# Définitions des fichiers sources et objets

OBJ = $(SRC)

# Règles des couleurs

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
CYAN = \033[0;36m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m
BLANC = \033[0;37m

all:	$(NAME)

$(NAME):
#===========================================ASCII_MOD===========================================

	@echo 🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟩🟩🟩🟩🟩🟦
	@echo 🟦🟦🟦🟦🟦🟦🟦🟦🟦🟨🟨🟨🟦🟨🟦🟨🟨🟨🟦🟨🟨🟨🟦🟨🟨🟦🟨🟨🟦🟦🟦🟦🟩🟩🟩🟩🟩🟦
	@echo 🟦🟦🟦🟦🟦🟦🟦🟦🟦🟨🟦🟨🟦🟨🟦🟨🟦🟨🟦🟨🟦🟦🟦🟦🟨🟨🟨🟦🟦🟦🟦🟦🟩🟩🟩🟩🟩🟦
	@echo 🟦🟦🟦👲🏼🟦🟦🟦🟦🟨🟨🟨🟦🟨🟦🟨🟨🟨🟦🟨🟨🟦🟦🟦🟦🟨🟦🟦🟦🟦🟦🟦🟩🟩🟩🟩🟩🟦
	@echo 🟩🟩🟩🟩🟩🟩🟩🟩🟦🟨🟦🟦🟦🟨🟦🟨🟦🟦🟦🟨🟦🟦🟦🟦🟨🟨🟨🟦🟦🟦🟩🟩🟩🟩🟩🟩🟩🟩
	@echo 🟩🟩🟩🟩🟩🟩🟩🟩🟦🟨🟦🟦🟦🟨🟦🟨🟦🟦🟦🟨🟨🟨🟦🟨🟨🟦🟨🟨🟦🟦🟩🟩🟩🟩🟩🟩🟩🟩
	@echo 🟦🟩🟩🟩🟩🟩🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦
	@echo 🟦🟩🟩🟩🟩🟩🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦
	@echo 🟦🟩🟩🟩🟩🟩🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦
	@echo 🟦🟩🟩🟩🟩🟩🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦
	@echo 🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫
	@echo 🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫
# 
# @echo "$(GREEN)"

# @echo -n "Compilation progress: ["
# @for i in $$(seq 1 50); do \
#     sleep 0.1; \
#     echo -n "#"; \
# done
# @echo "] 100 %"

# @echo "$(CYAN)Starting compilation..."
# @sleep 5 # Simule la compilation
# @echo "Done !"
#=============================================================================================

# Règle pour compiler printf

	@$(MAKE) -C $(PRINTF)

# Règle pour créer l'exécutable push_swap

	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -L$(PRINTF) -lftprintf -o $(NAME)

# Règles pour nettoyer les fichiers objets et l'exécutable

clean:
	@echo "$(RED)Cleaning up..."
	@rm -f $(NAME)
	@echo "Done !"

fclean: clean

# Règle pour recompiler
re: fclean all

# Pour éviter les conflits avec des fichiers du même nom
.PHONY: all clean fclean re