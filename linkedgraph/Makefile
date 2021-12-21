# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 22:30:00 by mki               #+#    #+#              #
#    Updated: 2021/12/21 12:39:58 by sujilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = linkedgraph
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

FILE = createLinkedGraph\
				createLinkedDirectedGraph\
				deleteLinkedGraph\
				isEmptyLG\
				addVertexLG\
				addEdgeLG\
				addEdgewithWeightLG\
				checkVertexValid\
				removeVertexLG\
				removeEdgeLG\
				getEdgeCountLG\
				getVertexCountLG\
				getMaxVertexCountLG\
				getGraphTypeLG\
				displayLinkedGraph\
				main\
				removeLLElement\
				clearLinkedList\
				getLLElement\
				traversalDFS\
				traversalBFS\
				linkedqueue

				
				

INCS = ./includes

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILE))) 
OBJS_DIR = ./srcs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILE))) 

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all bonus clean fclean re
