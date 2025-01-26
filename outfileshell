CC = cc

CFLAGS = -Wall -Wextra -Werror 

RCC = ar rcs

NAME = pipex
NAMEBONUS = bonus_pipex

SRCF = 	ft_printf/ft_printf.c \
		ft_printf/ft_printhexa.c \
		ft_printf/ft_putchar.c \
		ft_printf/ft_putnbr.c \
		ft_printf/ft_putnbrbase.c \
		ft_printf/ft_putnbrunsig.c \
		ft_printf/ft_putstr.c \
		src/ft_split.c \
		src/ft_strjoin.c \
		src/ft_substr.c \
		src/helpe_fc.c \
		mandatory/envpath.c \
		mandatory/pipex.c 

BSRCF = bonus/ft_printf/ft_printf.c \
		bonus/ft_printf/ft_printhexa.c \
		bonus/ft_printf/ft_putchar.c \
		bonus/ft_printf/ft_putnbr.c \
		bonus/ft_printf/ft_putnbrbase.c \
		bonus/ft_printf/ft_putnbrunsig.c \
		bonus/ft_printf/ft_putstr.c \
		bonus/src/ft_split.c \
		bonus/src/ft_strjoin.c \
		bonus/src/ft_substr.c \
		bonus/src/helpe_fc.c \
		bonus/bonus/envpath.c \
		bonus/bonus/here_doc.c \
		bonus/get_next_line/get_next_line.c\
		bonus/bonus/pipex.c\
		bonus/get_next_line/get_next_line_utils.c

HF = includes/ft_printf.h includes/pipex.h
BHF = bonus/includes/ft_printf.h bonus/includes/pipex.h bonus/includes/get_next_line.h

OBJ = ${SRCF:.c=.o}
BOBJ = ${BSRCF:.c=.o}

all : $(NAME) 

bonus : $(NAMEBONUS)

$(NAME) : $(OBJ) $(HF) mandatory/main.c
	$(CC) $(CFLAGS) mandatory/main.c $(OBJ) -o $(NAME)

$(NAMEBONUS) : $(BOBJ) $(HF) bonus/bonus/main.c
	$(CC) $(CFLAGS) bonus/bonus/main.c $(BOBJ) -o $(NAMEBONUS)

bonus/%.o : bonus/%.c $(BHF)
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.c $(HF)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	rm -f $(BOBJ)

fclean : clean
	rm -f $(NAME)
	rm -f $(NAMEBONUS)

re : fclean all