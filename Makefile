# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 16:01:20 by sben-tay          #+#    #+#              #
#    Updated: 2024/04/13 11:01:32 by sben-tay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

# Définitions de base

NAME = pipex
NAME_BNS = pipex_bonus
PRINTF = ./external/PRINTF
CC = cc
CFLAGS = -g -Wall -Wextra -Werror 
CPPFLAGS = -I./include


# Définitions de chemin

LIB = src/Mandatory/lib/
PIPEX = src/Mandatory/pipex/
SECURITY = src/Mandatory/security/
BUILD = builder/

# Définitions des fichiers sources et objets

#=================================================__SRC__OF__PROJECT__=============================================================================
SRC = src/Mandatory/main.c \
	$(LIB)free_split.c $(LIB)ft_putstr_fd.c $(LIB)ft_split_envp.c $(LIB)ft_split.c $(LIB)ft_strjoin.c $(LIB)ft_strlen.c $(LIB)ft_strncmp.c \
	$(PIPEX)exec_cmd/exec_cmd.c $(PIPEX)path_functions/get_cmd.c $(PIPEX)prossessus/children.c \
	$(SECURITY)msg_error.c

SRC_BNS = $(wildcard ./src/Bonus/*.c) $(shell find ./src/Bonus -type f -name '*.c')


# Crée le dossier BUILD si nécessaire
$(shell mkdir -p $(BUILD))

OBJ = $(SRC:%.c=$(BUILD)%.o)
OBJ_BNS = $(SRC_BNS:%.c=$(BUILD)%.o)
#==================================================================================================================================================



# Règles des couleurs

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
CYAN = \033[0;36m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m
BLANC = \033[0;37m

all:	$(NAME)

$(NAME): $(OBJ)


#==================================ASCII_MOD_COMPILATION==================================

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
	@echo "$(GREEN)"

	@echo -n "Compilation progress: ["
	@for i in $$(seq 0.1 50); do \
		sleep 0.02; \
		echo -n "#"; \
	done
	@echo "] 100 %"

	@echo "$(CYAN)Starting compilation..."
	@echo "Starting external projects $(MAGENTA)PRINTF$(CYAN) and $(MAGENTA)GNL$(CYAN) compilations..."
	@sleep 2
	@$(MAKE) $(MAKEFLAGS) -C $(PRINTF)
	@echo "Starting project $(MAGENTA)PIPEX$(CYAN)..."
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -L$(PRINTF) -lftprintf -o $(NAME)

	@sleep 2
	@echo "Done !$(BLANC)"
#=============================================================================================


%.o:%.c   
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@


bonus: $(OBJ_BNS) # Règle pour créer l'exécutable pipex_BNS

	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ_BNS) -L$(PRINTF) -lftprintf -o $(NAME_BNS)


clean: # Règles pour nettoyer les fichiers objets

	@$(MAKE) -C $(PRINTF) clean
	@echo "$(RED)Cleaning up..."
	@rm -rf $(BUILD)
	@echo "Done !"


fclean: clean # Règles pour nettoyer les fichiers objets et l'exécutable

	@$(MAKE) -C $(PRINTF) fclean
	@rm -f $(NAME)
	@rm -f $(NAME_BNS)


re: fclean all # Règle pour recompiler


.PHONY: all clean fclean re bonus # Pour éviter les conflits avec des fichiers du même nom