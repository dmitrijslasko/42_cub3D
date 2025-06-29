include config.mk
include colors.mk

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

SDL2_INC := lib/SDL2/build/include/SDL2
SDL2_MIXER_INC := lib/SDL2_mixer/build/include

# COMPILATION FLAGS
CFLAGS = -Wall -Wextra
CFLAGS += -Werror
CFLAGS += -g
#CFLAGS += -MMD -MP
CFLAGS += -I$(INC_DIR)
CFLAGS += -std=c99
CFLAGS += -Wno-error=type-limits
CFLAGS += -I$(SDL2_INC) -I$(SDL2_MIXER_INC) -D_REENTRANT



# LINKER FLAGS
LDFLAGS = -L$(LIBFT_DIR) -lft
LDFLAGS += -lmlx -lm -lXext -lX11
LDFLAGS += -Llib/SDL2/build/lib -Llib/SDL2_mixer/build/lib -lSDL2 -lSDL2_mixer

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
	./${NAME} ./maps/good/works.cub

all: libft $(NAME) $(HEADER_FILE_M)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@
	@echo "$(B_CYAN)✅ $@ successfully compiled.$(RST)"
	@echo "🚩 $(CYAN)Flags: \n$(CFLAGS)\n$(LDFLAGS)$(RST)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)Compiling $<$(RST)"

#-include $(DEPS)

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

%:
	@echo "$(RED)Failure:$(RESET) target '$@' is not a valid target."
	@echo "Please use one of the following valid targets:"
	@echo "- $(GREEN)make$(RESET): compiles the project"
	@echo "- $(GREEN)make re$(RESET): recompiles the project"
	@echo "- $(GREEN)make clean$(RESET): removes object files"
	@echo "- $(GREEN)make fclean$(RESET): removes object files and the final binary"

# ------------------------------------------------------------------------------

.PHONY: all bonus clean fclean re libft %
