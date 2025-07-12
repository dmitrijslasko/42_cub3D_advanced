# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/02 14:55:36 by fvargas           #+#    #+#              #
#    Updated: 2025/07/02 14:55:37 by fvargas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT NAME
NAME = cub3D

AUTHORS = "fvargas & dmlasko"
INFO1 = $(B_CYAN)42 Berlin Core Curriculum – $(AUTHOR)$(RST)
INFO_M = "$(B_CYAN)42 Berlin Core Curriculum – Mandatory part$(RST)"
INFO2_M = "$(YELLOW)Run ./$(NAME) with a map file to launch$(RST)"
INFO3_M = "$(YELLOW)Or, type in $(GREEN)"make test"$(YELLOW) to start a quick test.$(RST)"
INFO_B = "$(B_MAGENTA)42 Berlin Core Curriculum – Bonus part$(RST)"
INFO2_B = "$(YELLOW)Run ./$(NAME) with a map file to launch$(RST)"
INFO3_B = "$(YELLOW)Or, type in $(GREEN)"make test"$(YELLOW) to start a quick test.$(RST)"
VER = 1.0

HEADER_FILE_M = ./obj/_header_m
HEADER_FILE_B = ./obj/_header_b

# https://www.asciiart.eu/text-to-ascii-art
# Header will be generated ONLY when $(NAME) needs to be rebuilt

$(HEADER_FILE_M): $(OBJ)
	@mkdir -p obj
	@touch $(HEADER_FILE_M).tmp
	@mv $(HEADER_FILE_M).tmp $(HEADER_FILE_M)
	@echo "                     █████      ████████      █████"
	@echo "                    ░░███      ███░░░░███    ░░███"
	@echo "  ██████  █████ ████ ░███████ ░░░    ░███  ███████"
	@echo " ███░░███░░███ ░███  ░███░░███   ██████░  ███░░███"
	@echo "░███ ░░░  ░███ ░███  ░███ ░███  ░░░░░░███░███ ░███"
	@echo "░███  ███ ░███ ░███  ░███ ░███ ███   ░███░███ ░███"
	@echo "░░██████  ░░████████ ████████ ░░████████ ░░████████"
	@echo " ░░░░░░    ░░░░░░░░ ░░░░░░░░   ░░░░░░░░   ░░░░░░░░"
	@echo $(INFO_M)
	@echo $(INFO2_M)
	@echo $(INFO3_M)

$(HEADER_FILE_B): $(OBJ)
	@mkdir -p obj
	@touch $(HEADER_FILE_B).tmp
	@mv $(HEADER_FILE_B).tmp $(HEADER_FILE_B)
	@echo "                     █████      ████████      █████"
	@echo "                    ░░███      ███░░░░███    ░░███"
	@echo "  ██████  █████ ████ ░███████ ░░░    ░███  ███████"
	@echo " ███░░███░░███ ░███  ░███░░███   ██████░  ███░░███"
	@echo "░███ ░░░  ░███ ░███  ░███ ░███  ░░░░░░███░███ ░███"
	@echo "░███  ███ ░███ ░███  ░███ ░███ ███   ░███░███ ░███"
	@echo "░░██████  ░░████████ ████████ ░░████████ ░░████████"
	@echo " ░░░░░░    ░░░░░░░░ ░░░░░░░░   ░░░░░░░░   ░░░░░░░░"
	@echo $(INFO_B)
	@echo $(INFO2_B)
	@echo $(INFO3_B)
