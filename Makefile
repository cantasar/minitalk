CNAME	= client
SNAME	= server
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

CSRC	= client.c
SSRC	= server.c
COBJ	= $(CSRC:.c=.o)
SOBJ	= $(SSRC:.c=.o)

CBNAME	= client_bonus
SBNAME	= server_bonus

BONUS_CSRC	= client_bonus.c
BONUS_SSRC	= server_bonus.c
BONUS_COBJ	= $(BONUS_CSRC:.c=.o)
BONUS_SOBJ	= $(BONUS_SSRC:.c=.o)

all: $(CNAME) $(SNAME)

$(CNAME): $(COBJ)
	$(CC) $(CFLAGS) $(CSRC) ft_printf.c -o $(CNAME)

$(SNAME): $(SOBJ)
	$(CC) $(CFLAGS) $(SSRC) ft_printf.c -o $(SNAME)

bonus: $(CBNAME) $(SBNAME)

$(CBNAME): $(BONUS_COBJ)
	$(CC) $(CFLAGS) $(BONUS_CSRC) ft_printf.c -o $(CBNAME)

$(SBNAME): $(BONUS_SOBJ)
	$(CC) $(CFLAGS) $(BONUS_SSRC) ft_printf.c -o $(SBNAME)

clean:
	rm -rf $(COBJ) $(SOBJ) $(BONUS_COBJ) $(BONUS_SOBJ)

fclean: clean
	rm -rf $(CNAME) $(SNAME) $(CBNAME) $(SBNAME)

re: fclean all
