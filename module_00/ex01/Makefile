CC			=	c++ -Wall -Wextra -Werror -std=c++98

SRCS		=	$(wildcard *.cpp)
BINS		=	$(SRCS:.cpp=)
NAME		=	phonebook

all:
	$(CC) $(SRCS) -o $(NAME)

clean:
	$(RM) $(BINS)

re:	clean all
