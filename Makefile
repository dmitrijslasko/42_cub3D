# PROJECT NAME
NAME = cub3D

AUTHORS = "fvargas & dmlasko"
INFO1 = $(B_CYAN)42 Berlin Core Curriculum – $(AUTHOR)$(RST)
INFO_M = "$(B_CYAN)42 Berlin Core Curriculum – Mandatory part$(RST)"
INFO2_M = "$(YELLOW)Run ./$(NAME) with a map file to launch$(RST)"
INFO_B = "$(B_MAGENTA)42 Berlin Core Curriculum – Bonus part$(RST)"
INFO2_B = "$(YELLOW)Run ./$(NAME) with a map file to launch$(RST)"
INFO_D = "$(B_MAGENTA)42 Berlin Core Curriculum – DEVMODE$(RST)"
VER = 1.0

HEADER_FILE_M = ./obj/_header_m
HEADER_FILE_B = ./obj/_header_b
HEADER_FILE_B = ./obj/_header_d

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

$(HEADER_FILE_D): $(OBJ)
	@mkdir -p obj
	@touch $(HEADER_FILE_D).tmp
	@mv $(HEADER_FILE_D).tmp $(HEADER_FILE_D)
	@echo "                     █████      ████████      █████"
	@echo "                    ░░███      ███░░░░███    ░░███"
	@echo "  ██████  █████ ████ ░███████ ░░░    ░███  ███████"
	@echo " ███░░███░░███ ░███  ░███░░███   ██████░  ███░░███"
	@echo "░███ ░░░  ░███ ░███  ░███ ░███  ░░░░░░███░███ ░███"
	@echo "░███  ███ ░███ ░███  ░███ ░███ ███   ░███░███ ░███"
	@echo "░░██████  ░░████████ ████████ ░░████████ ░░████████"
	@echo " ░░░░░░    ░░░░░░░░ ░░░░░░░░   ░░░░░░░░   ░░░░░░░░"
	@echo $(INFO_D)

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

# ------------------------------------------------------------------------------

# PROJECT NAME
NAME = cub3D

# COMPILER
CC = cc

# DIRECTORIES
INC_DIR = ./inc
SRC_DIR = ./src
OBJ_DIR = ./obj
OBJ_DIR_BONUS = ./obj_bonus
OBJ_DIR_DEV = ./obj_devmode

# LIBRARIES
LIBDIRS = ./lib
LIBFT_DIR = $(LIBDIRS)/libft
LIBFT = $(LIBFT_DIR)/libft.a

# COMPILATION FLAGS
CFLAGS = -Wall -Wextra
# CFLAGS += -Werror
CFLAGS += -g
CFLAGS += -MMD -MP
CFLAGS += -I$(INC_DIR)
CFLAGS += -std=c99
CFLAGS += -Wno-error=type-limits

#CFLAGS += -Wno-unused-but-set-variable

# LINKER FLAGS
LDFLAGS = -L$(LIBFT_DIR) -lft
LDFLAGS += -lmlx -lm -lXext -lX11

# EXTRA FLAGS
BONUSFLAGS = -DBONUS=1

# ------------------------------------------------------------------------------

# SOURCE FILES
SRC := $(shell find $(SRC_DIR) -name "*.c")
OBJ := $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC:.c=.o))
DEPS := $(OBJ:.o=.d)

# OBJECT FILES
OBJ_BONUS = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR_BONUS)/%, $(SRC:.c=.o))

# DEPENDENCIES
DEPS_BONUS = $(OBJ_BONUS:.o=.d)


# MAKE RULES
# ------------------------------------------------------------------------------

# DEFAULT GOAL
.DEFAULT_GOAL := all

# ------------------------------------------------------------------------------

test: all
	./${NAME} ./maps/good/square_map.cub

all: libft $(NAME) $(HEADER_FILE_M)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@
	@echo "$(B_CYAN)✅ $@ successfully compiled.$(RST)"
	@echo "🚩 $(CYAN)Flags: \n$(CFLAGS)\n$(LDFLAGS)$(RST)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)Compiling $<$(RST)"

-include $(DEPS)

# ------------------------------------------------------------------------------

libft:
	@$(MAKE) -s -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS) $(OBJ_DIR_DEV)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@echo "$(B_YELLOW)🔥 Clean complete.$(RST)"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@rm -f $(LIBFT)

re: fclean all

# ------------------------------------------------------------------------------

.PHONY: all bonus clean fclean re libft
