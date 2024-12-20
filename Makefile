#==============================================================================#
#                                 SO_LONG PROJECT                              #
#==============================================================================#

# Main target names
NAME = so_long
NAME_BONUS = so_long_bonus

#------------------------------------------------------------------------------#
#                                COLORS & STYLES                               #
#------------------------------------------------------------------------------#

# ANSI color codes for prettier output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# Text style codes
BOLD = \033[1m
DIM = \033[2m
ITALIC = \033[3m
UNDERLINE = \033[4m

# Emojis for visual feedback
CHECK = ✓
CLEAN = 🧹
BUILD = 🔨
ROCKET = 🚀
BOOK = 📚
SPARKLES = ✨

#------------------------------------------------------------------------------#
#                            	  NAMES AND PATHS                              #
#------------------------------------------------------------------------------#

# Directory structure
BUILD_PATH = .build
SRC_PATH = src
BONUS_PATH = src_bonus
INC_PATH = inc
HEADERS = ${INC_PATH}/so_long.h
HEADERS += ${INC_PATH}/so_long_bonus.h

LIBFT_PATH = libs/libft
LIBFT_ARC = ${LIBFT_PATH}/libft.a

MINILIBX_PATH = libs/minilibx-linux
MINILIBX = ${MINILIBX_PATH}/libmlx_Linux.a

# Source files
SRCS = ${addprefix ${SRC_PATH}/, main.c init.c start_game.c key_handler.c \
		moves.c moves_utils.c display_textures.c set_player_texture.c \
		update_textures.c map_utils.c map_validation.c \
		map_validation_conditions.c map_validation_path.c quit_and_frees.c}

# Source Bonus files
SRCS_BONUS = ${addprefix ${BONUS_PATH}/, main_bonus.c init_bonus.c \
		start_game_bonus.c key_handler_bonus.c moves_bonus.c \
		moves_utils_bonus.c display_textures_bonus.c \
		set_player_texture_bonus.c update_textures_bonus.c map_utils_bonus.c \
		map_validation_bonus.c \
		map_validation_conditions_bonus.c \
		map_validation_path_bonus.c quit_and_frees_bonus.c}

# Object files derived from source files
OBJS = ${addprefix ${BUILD_PATH}/, ${notdir ${SRCS:.c=.o}}}
OBJS_BONUS = ${addprefix ${BUILD_PATH}/, ${notdir ${SRCS_BONUS:.c=.o}}}

#------------------------------------------------------------------------------#
#                            	   FLAGS & COMMANDS                            #
#------------------------------------------------------------------------------#

CC = cc                           # Compiler to use
CCFLAGS = -Wall -Wextra -Werror -g # Compiler flags for warnings/errors/debugging
LDFLAGS = -L${LIBFT_PATH} -lft
MLXFLAGS = -L${MINILIBX_PATH} -lmlx_Linux -lXext -lX11 -lm

AR = ar rcs                       # Archive command to create static libraries
RM = rm -fr                       # Command to remove files/directories forcefully
MKDIR_P = mkdir -p                # Command to create directories (with parent)
INC = -I ${INC_PATH}              # Include path for header file
MAKE = make --no-print-directory -C
MAKE_EXTRA = make extra --no-print-directory -C

VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

#------------------------------------------------------------------------------#
#                                    RULES                                     #
#------------------------------------------------------------------------------#

##  Compilation Rules for push_swap  ##

all: deps ${NAME}                 

${NAME}: ${BUILD_PATH} ${OBJS} ${LIBFT_ARC} ${MINILIBX}
	@printf "${CYAN}${DIM}Compiling main.c for running the program...${RESET}\n"
	@${CC} ${CCFLAGS} ${OBJS} -o ${NAME} ${MLXFLAGS} ${LDFLAGS} 
	@printf "${GREEN}${BOLD}${CHECK} so_long executable compiled successfully!${RESET}\n"
	@printf "${YELLOW}${BOLD}To run program type: ./so_long followed by the name of the map.${RESET}\n"

${BUILD_PATH}:
	@printf "\n${BLUE}${BOLD}Creating build directory...${RESET}\n"
	@${MKDIR_P} ${BUILD_PATH}
	@printf "${GREEN}${BOLD}${CHECK} Build directory created successfully!${RESET}\n"

${LIBFT_ARC}: deps
	@printf "${CYAN}${BOLD}${DIM} Compiling Libft..${RESET}\n"
	@${MAKE_EXTRA} ${LIBFT_PATH}
	@printf "${BLUE}${BOLD}${BUILD} ${WHITE}${LIBFT_ARC}${GREEN} compiled! ${RESET}\n"

${MINILIBX}: deps_mlx
	@printf "${CYAN}${BOLD}${DIM} Compiling MiniLibX..${RESET}\n"
	@${MAKE} ${MINILIBX_PATH}
	@printf "${BLUE}${BOLD}${BUILD} ${WHITE}${MINILIBX}${GREEN} compiled! ${RESET}\n"

${BUILD_PATH}/%.o: ${SRC_PATH}/%.c ${HEADERS} | ${BUILD_PATH}
	@printf "${CYAN}${DIM}Compiling: ${WHITE}%-30s${RESET}\r" ${notdir $<}
	@${CC} ${CCFLAGS} ${INC} -c $< -o $@

${BUILD_PATH}/%.o: ${UTIL_PATH}/%.c ${HEADERS} | ${BUILD_PATH}
	@printf "${CYAN}${DIM}Compiling: ${WHITE}%-30s${RESET}\r" ${notdir $<}
	@${CC} ${CCFLAGS} ${INC} -c $< -o $@

${BUILD_PATH}/%.o: ${BONUS_PATH}/%.c ${HEADERS} | ${BUILD_PATH}
	@printf "${CYAN}${DIM}Compiling: ${WHITE}%-30s${RESET}\r" ${notdir $<}
	@${CC} ${CCFLAGS} ${INC} -c $< -o $@

deps: deps_mlx
	@if test ! -d "${LIBFT_PATH}"; then make get_libft; \
		else printf "${GREEN}${BOLD}${ROCKET} ${WHITE}${LIBFT_ARC}${GREEN} folder found!${RESET}\n"; fi

get_libft:
	@printf "${CYAN}${BOLD}${BOOK} Getting Libft..${RESET}\n"
	@git clone https://github.com/melaniereis/libft.git ${LIBFT_PATH}
	@git pull
	@printf "${GREEN}${BOLD}${ROCKET} ${WHITE}${LIBFT_ARC}${GREEN} successfully downloaded!${RESET}\n"

deps_mlx:
	@if test ! -d "${MINILIBX_PATH}"; then make get_minilibx; \
    else printf "${GREEN}${BOLD}${ROCKET} ${WHITE}${MINILIBX}${GREEN} folder found!${RESET}\n"; fi

get_minilibx:
	@printf "${CYAN}${BOLD}${BOOK} Getting MiniLibX..${RESET}\n"
	@git clone git@github.com:melaniereis/minilibx-linux.git ${MINILIBX_PATH}
	@printf "${GREEN}${BOLD}${ROCKET} ${WHITE}${MINILIBX}${GREEN} successfully downloaded!${RESET}\n"



bonus: deps ${BUILD_PATH} ${OBJS_BONUS} ${LIBFT_ARC} ${MINILIBX}
	@printf "${CYAN}${DIM}Compiling main_bonus.c for running the program...${RESET}\n"
	@${CC} ${CCFLAGS} ${OBJS_BONUS} -o ${NAME} ${MLXFLAGS} ${LDFLAGS} 
	@printf "${GREEN}${BOLD}${CHECK} so_long bonus executable compiled successfully!${RESET}\n"
	@printf "${YELLOW}${BOLD}To run program type: ./so_long followed by the name of the map.${RESET}\n"

##  Norms Rules  ##

norm:                # Check norms for mandatory sources 
	@printf "\n${BLUE}${BOLD}${TEST} Checking Norminette...${RESET}\n"
	@norminette_output=$$(norminette *.c *.h | grep -v "OK!" || true); \
	if [ -z "$$norminette_output" ]; then \
		printf "${GREEN}${BOLD}${CHECK} No norminette errors found!${RESET}\n"; \
	else \
		printf "$$norminette_output\n"; \
		printf "${RED}${BOLD}❌ Norminette errors found.${RESET}\n"; \
	fi
	@printf "${GREEN}${BOLD}${CHECK} Norminette check completed!${RESET}\n"

##   Check for external functions  ##
check_external_functions: all               # Check norms for mandatory sources 
	@printf "\n${BLUE}${BOLD}${TEST} Checking External Functions...${RESET}\n"
	nm ./${NAME} | grep "U" | grep -v "__"
	@printf "${GREEN}${BOLD}${CHECK} External functions check completed!${RESET}\n"

##  Cleaning Rules  ##

clean:                       # Clean up object files and temporary build files 
	@printf "\n${YELLOW}${BOLD}${CLEAN} Cleaning object files...${RESET}\n"
	@${RM} ${OBJS} ${OBJS_BONUS}
	@printf "${GREEN}${BOLD}${CHECK} Object files cleaned!${RESET}\n"

fclean: clean               # Fully clean up by removing executables and build directories 
	@printf "${YELLOW}${BOLD}${CLEAN} Removing executable, libft.a and build files...${RESET}\n"
	@${RM} ${NAME}
	@${RM} ${BUILD_PATH}
# @make fclean -C ${LIBFT_PATH}
#@${RM} ${LIBFT_PATH}
	@${RM} ${MINILIBX_PATH}
	@printf "${GREEN}${BOLD}${CHECK} All files cleaned!${RESET}\n"

re: fclean all          # Rebuild everything from scratch 

.PHONY: all clean fclean re norm get_libft deps check_external_functions deps_mlx get_minilibx
# Declare phony targets
