NAME				=		pl

rwildcard			=		$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2)\
							$(filter $(subst *,%,$2),$d))

SFML_PATH			=		$(HOME)/.brew/Cellar/sfml/2.2

SFML_LIBS			=		-lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

COMPILER			=		clang++
CFLAGS				=		-g3 -O3 -Wall -Wextra -c -Isrcs -I $(INCLUDE_DIR)\
							-I sfml/includes\
							-std=c++1y\
							-I $(SFML_PATH)/include
LFLAGS				=		-L $(SFML_PATH)/lib $(SFML_LIBS)\
							-Wl,-rpath $(SFML_PATH)/lib

SRC					=		$(call rwildcard,srcs,*.cpp)

INCLUDE_DIR			=		includes

OBJ_DIR				=		objs
OBJ					=		$(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
OBJ_SUB_DIRS		=		$(dir $(OBJ))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "linking"
	@$(COMPILER) $^ $(LFLAGS) -o $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@$(foreach dir, $(OBJ_SUB_DIRS), mkdir -p $(dir);)

$(OBJ_DIR)/%.o: %.cpp
	@echo "compiling $(notdir $^)"
	@$(COMPILER) $(CFLAGS) $^ -o $@

clean:
	@echo "cleaning object files"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "cleaning executable"
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
