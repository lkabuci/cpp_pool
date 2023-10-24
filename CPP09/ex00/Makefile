NAME = btc

SRCS = BitcoinExchange.cpp  main.cpp 
OBJS = ${SRCS:.cpp=.o}

INC  = BitcoinExchange.hpp

all: ${NAME} ${INC}

${NAME}: ${OBJS}
	c++ ${OBJS} -o ${NAME}

%.o: %.cpp ${INC}
	c++ -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: clean all
