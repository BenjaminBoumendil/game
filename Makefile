NAME				=	pl

rwildcard			=	$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2)\
						$(filter $(subst *,%,$2),$d))

SFML_PATH			=		$(HOME)/.brew/Cellar/sfml/2.2
SFML_LIBS			=		-lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

COMPILER			=	clang++
CFLAGS				=	-g3 -O3 -Wall -Wextra -c -Isrcs -I $(INCLUDE_DIR)\
						-I $(SIGNALS_DIR)\
						-I sfml/includes\
						-std=c++1y\
						-I $(SFML_PATH)/include
LFLAGS				=	-L $(SFML_PATH)/lib $(SFML_LIBS)\
						-Wl,-rpath $(SFML_PATH)/lib

INCLUDE_DIR			=	includes
SIGNALS_DIR			=	signals/signals

OBJ_DIR				=	objs
SRCS				=	$(call rwildcard, ./srcs/, *.cpp)
OBJS				=	$(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

OBJ_SUB_DIRS		=	$(dir $(OBJS))

all: show_fancy_name
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@echo "$(bold)$(blue)linking		$(green)$@$(reset)"
	@$(COMPILER) $^ $(LFLAGS) -o $@

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	@$(foreach dir, $(OBJ_SUB_DIRS), mkdir -p $(dir);)

$(OBJ_DIR)/%.o: %.cpp
	@echo "$(bold)$(cyan)compiling	$(white)$<$(reset)"
	@$(COMPILER) $(CFLAGS) $< -o $@

depend: .depend

.depend: $(SRCS)
	@rm -f ./.depend
	@$(foreach src, $^, $(COMPILER) $(CFLAGS) -MM -MT $(OBJ_DIR)/./$(src:.cpp=.o) $(src) >> ./.depend;)

-include .depend

clean: show_fancy_name
	@echo "$(bold)$(red)cleaning	$(white)$(OBJ_DIR)$(reset)"
	@rm -rf $(OBJ_DIR)
	@rm -f ./.depend

fclean: clean
	@echo "$(bold)$(red)removing	$(green)$(NAME)$(reset)"
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

show_fancy_name:
	@echo "\n$(bold)$(yellow)==> $(NAME)$(reset)"

# ANSI helpers
ansi			=	\033[$1m

bold			=	$(call ansi,1)
fg_color		=	$(call ansi,38;5;$1)
reset			=	$(call ansi,0)

red				=	$(call fg_color,1)
green			=	$(call fg_color,10)
blue			=	$(call fg_color,27)
cyan			=	$(call fg_color,6)
yellow			=	$(call fg_color,11)
white			=	$(call fg_color,255)
