CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS		=	$(wildcard *.cpp)
BINS		=	$(SRCS:.cpp=)

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(BINS)

clean:
	$(RM) $(BINS)

re:	clean all
