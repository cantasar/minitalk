CNAME	= client
SNAME	= server
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

CSRC	= client.c
SSRC	= server.c
COBJ	= $(CSRC.c=.o)
SOBJ	= $(SSRC.c=.o)

all: $(CNAME) $(SNAME)

$(CNAME): $(CSRC)
	$(CC) $(CFLAGS) $(CSRC) -o $(CNAME)

$(SNAME): $(SSRC)
	$(CC) $(CFLAGS) $(SSRC) -o $(SNAME)

clean:
	rm -rf $(COBJ) $(SOBJ)

fclean: clean
	rm -rf $(CNAME) $(SNAME)

re: fclean all
