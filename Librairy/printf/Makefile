##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile lib and source or execute unit test
##

# LIBRAIRIE
# ----------------------->
SILENT = @

LIB_NAME =	libprintf.a
LIB =	printf
LIB_FOLDER=	../

INCLUDE =	../include/
HEADER =	printf.h

LIB_SRC =	my_printf.c \
			take_format.c \
			check_specifier.c \
			take_flags.c \
			take_width_and_precision.c \
			take_length.c \
			check_character.c \
			print_char_and_string.c \
			print_number.c \
			print_pointer.c \
			put_str.c \
			put_nbr.c \
			put_nbr_base.c \
			str_len.c

OBJ_FOLDER =	../objects/

LIB_OBJ_FOLDER =	$(OBJ_FOLDER)printf/
LIB_OBJ =	$(patsubst %.c, $(LIB_OBJ_FOLDER)%.o, $(LIB_SRC))
# ----------------------->

# COMPILE
# ----------------------->
all:	directorie	$(LIB)

directorie:
	$(SILENT)mkdir -p $(INCLUDE)
	$(SILENT)mkdir -p $(OBJ_FOLDER)
	$(SILENT)mkdir -p $(LIB_OBJ_FOLDER)

$(LIB):
	$(SILENT)cp $(HEADER) $(INCLUDE)
	$(SILENT)gcc -c $(LIB_SRC) -I $(INCLUDE)
	$(SILENT)mv *.o $(LIB_OBJ_FOLDER)
	$(SILENT)ar rc $(LIB_NAME) $(LIB_OBJ)
	$(SILENT)mv $(LIB_NAME) $(LIB_FOLDER)
# ----------------------->

# CLEAN
# ----------------------->
clean:
	$(SILENT)rm -f *.o
	$(SILENT)rm -rf $(LIB_OBJ_FOLDER)

fclean:	clean
	$(SILENT)rm -f $(LIB_FOLDER)$(LIB_NAME)
	$(SILENT)rm -f $(INCLUDE)$(HEADER)
# ----------------------->

re: clean fclean all

.PHONY: clean re