# PROJECT NAME
NAME = cub3D

AUTHORS = "fvargas & dmlasko"
INFO1 = $(B_CYAN)42 Berlin Core Curriculum – $(AUTHOR)$(RST)
INFO_M = "$(B_CYAN)42 Berlin Core Curriculum – Mandatory part$(RST)"
INFO2_M = "$(YELLOW)Run ./$(NAME) with a map file to launch$(RST)"
INFO_B = "$(B_MAGENTA)42 Berlin Core Curriculum – Bonus part$(RST)"
INFO2_B = "$(YELLOW)Run ./$(NAME) with a map file to launch$(RST)"
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