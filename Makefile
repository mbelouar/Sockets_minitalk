# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 22:59:35 by mbelouar          #+#    #+#              #
#    Updated: 2023/03/31 02:22:45 by mbelouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf
CLIENT = client.c
SERVER = server.c  

all : server client
	@printf "\n\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗%s\n"
	@printf "\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗%s \n"
	@printf "\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝%s \n"
	@printf "\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗%s\n"
	@printf "\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝%s\n"
	@printf "\t\t%s｡☆✼★━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━★✼☆｡%s\n"
	@printf "\n\t\t\t       By: bickle\n"
	@printf "\n\t     LETS HAVE A  A SMALL COMMUNICATION SERVER CLIENT\n\n"


server: $(SERVER)
		$(CC) $(CFLAGS) $(SERVER) -o $@

client: $(CLIENT)
		$(CC) $(CFLAGS) $(CLIENT) -o $@

clean:
	@rm -f server client

re : clean all
