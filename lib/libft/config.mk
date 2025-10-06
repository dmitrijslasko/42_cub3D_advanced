AUTHOR = lukgabri & dmlasko
INFO1 = $(B_CYAN)42 Berlin Core Curriculum – $(AUTHOR)$(RST)
INFO2 = $(B_MAGENTA)Mandatory part – Evaluation $(EVALUATION_NR)$(RST)
VER = 4.2

HEADER_FILE = ./obj/_header

# https://www.asciiart.eu/text-to-ascii-art
# Header will be generated ONLY when $(NAME) needs to be rebuilt

$(HEADER_FILE): $(OBJ)
	@mkdir -p obj
	@touch $(HEADER_FILE).tmp
	@mv $(HEADER_FILE).tmp $(HEADER_FILE)
	@echo "         _      _     __       ____ "
	@echo "  __ _  (_)__  (_)__ / /  ___ / / /"
	@echo " /  ' \/ / _ \/ (_-</ _ \/ -_) / / "
	@echo "/_/_/_/_/_//_/_/___/_//_/\__/_/_/ $(B_CYAN)v$(VER)$(RST)"

# Regular Colors
BLACK  = \033[0;30m
RED    = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
BLUE   = \033[0;34m
MAGENTA = \033[0;35m
CYAN   = \033[0;36m
WHITE  = \033[0;37m

# Bold Colors
B_BLACK  = \033[1;30m
B_RED    = \033[1;31m
B_GREEN  = \033[1;32m
B_YELLOW = \033[1;33m
B_BLUE   = \033[1;34m
B_MAGENTA = \033[1;35m
B_CYAN   = \033[1;36m
B_WHITE  = \033[1;37m

# Underline Colors
U_BLACK  = \033[4;30m
U_RED    = \033[4;31m
U_GREEN  = \033[4;32m
U_YELLOW = \033[4;33m
U_BLUE   = \033[4;34m
U_MAGENTA = \033[4;35m
U_CYAN   = \033[4;36m
U_WHITE  = \033[4;37m

# Background Colors
BG_BLACK  = \033[40m
BG_RED    = \033[41m
BG_GREEN  = \033[42m
BG_YELLOW = \033[43m
BG_BLUE   = \033[44m
BG_MAGENTA = \033[45m
BG_CYAN   = \033[46m
BG_WHITE  = \033[47m

# Reset
RST = \033[0m
