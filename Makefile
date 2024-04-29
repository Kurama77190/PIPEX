# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 16:01:20 by sben-tay          #+#    #+#              #
#    Updated: 2024/04/29 21:19:30 by sben-tay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

# Définitions de base

NAME = pipex
NAME_BNS = pipex_bonus
PRINTF = ./external/DPRINTF
CC = cc
CFLAGS = -g -Wall -Wextra -Werror 
CPPFLAGS = -I./include


# Définitions de chemin

LIB = src/Mandatory/lib/
PIPEX = src/Mandatory/pipex/
SECURITY = src/Mandatory/security/

LIB_B = src/Bonus/lib/
PIPEX_B = src/Bonus/pipex/
SECURITY_B = src/Bonus/security/

BUILD = builder/

# Définitions des fichiers sources et objets

#=================================================__SRC__OF__PROJECT__=============================================================================
SRC = src/Mandatory/main.c \
	$(LIB)free_split.c $(LIB)ft_putstr_fd.c $(LIB)ft_split_envp.c $(LIB)ft_split.c $(LIB)ft_strjoin.c $(LIB)ft_strlen.c $(LIB)ft_strncmp.c \
	$(LIB)ft_only_space.c $(LIB)ft_strchr.c $(LIB)ft_add_pid.c $(LIB)ft_lstclear.c \
	\
	$(PIPEX)exec_cmd/exec_cmd.c $(PIPEX)exec_cmd/exec_without_env.c $(PIPEX)exec_cmd/exec_utils.c $(PIPEX)path_functions/get_cmd.c $(PIPEX)process/children.c $(PIPEX)process/ft_utils_process.c \
	\
	$(SECURITY)msg_error.c $(SECURITY)initializing_data.c $(SECURITY)pid_controller.c $(SECURITY)msg_error_without_env.c

SRC_BNS = src/Bonus/main.c \
	$(LIB_B)free_split.c $(LIB_B)ft_putstr_fd.c $(LIB_B)ft_split_envp.c $(LIB_B)ft_split.c $(LIB_B)ft_strjoin.c $(LIB_B)ft_strlen.c $(LIB_B)ft_strncmp.c \
	$(LIB_B)ft_only_space.c $(LIB_B)ft_strchr.c $(LIB_B)ft_add_pid.c $(LIB_B)ft_lstclear.c \
	\
	$(PIPEX_B)exec_cmd/exec_cmd.c $(PIPEX_B)exec_cmd/exec_without_env.c $(PIPEX_B)exec_cmd/exec_utils.c $(PIPEX_B)path_functions/get_cmd.c $(PIPEX_B)process/children.c $(PIPEX_B)process/ft_utils_process.c \
	\
	$(SECURITY_B)msg_error.c $(SECURITY_B)initializing_data.c $(SECURITY_B)pid_controller.c $(SECURITY_B)msg_error_without_env.c



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


 # Règle pour créer l'exécutable pipex_BNS

bonus: $(NAME_BNS)

$(NAME_BNS): $(OBJ_BNS)
	@echo "$(CYAN)Starting compilation of bonus part..."
	@$(MAKE) $(MAKEFLAGS) -C $(PRINTF)
	@echo "$(MAGENTA)Compiling $(NAME_BNS)..."
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ_BNS) -L$(PRINTF) -lftprintf -o $(NAME_BNS)
	@echo "$(GREEN)Compilation complete: $(NAME_BNS)$(NC)"



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