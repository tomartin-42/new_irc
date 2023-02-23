# **************************************************************************** #
                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 09:11:45 by tomartin          #+#    #+#              #
#    Updated: 2023/02/23 21:33:39 by tommy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME = ft_ircserv 

# Compiling and flags
#CXX = clang++ --std=c++98
CXX = g++ #-std=c++98
CXXFLAGS = -Wall -Wextra -Werror -Iinc -MD -O3 -g3 -fsanitize=address
LDFLAGS = -fsanitize=address

# Folders
OBJ_DIR = obj/
SRC_DIR = src/

# Source files and includes
SRC_FILES = main.cpp com.cpp com_exceptions.cpp orchestator.cpp user.cpp \
			msg.cpp replies.cpp replies_generator.cpp aux_server.cpp \
			time_control.cpp log.cpp

# Objs
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))	
OBJ = $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.cpp=.o))
DEP = $(OBJ:.o=.d)

# all rule
all: obj $(NAME) 

-include $(DEP)

print:
	echo $(SRC)
	echo $(OBJ)
	echo $(DEP)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp 
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -o $@ -c $<
	
# Compiling
$(NAME): $(OBJ)
	@echo "Compiling "$(NAME)
	@echo "By Javgonza, Vicmarti & Tomartin in 42Madrid"
	@$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo "Compilation OK!!"
	@echo "$(NAME) ready!".

bonus: all

# debug
debug: CXXFLAGS += -g
debug: all
	lldb $(NAME)

# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@echo "Objects removed!"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed!"

 # re rule
 re: fclean all

 # phony
 .PHONY: all clean fclean re
