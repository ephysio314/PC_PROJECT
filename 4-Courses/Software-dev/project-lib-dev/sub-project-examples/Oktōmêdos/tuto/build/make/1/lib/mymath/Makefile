
PATH_BACK= ../..
BUILD_PATH= $(PATH_BACK)/build/lib

CC_VERSION= -std=c89
CC= gcc $(CC_VERSION)

NAME= mymath

INC= -I.
OBJ= $(BUILD_PATH)/$(NAME).o
LIB= $(BUILD_PATH)/lib$(NAME).a

$(LIB): $(OBJ) $(PATH_BACK)/build/README.md
	ar rcs $(LIB) $(OBJ)

$(BUILD_PATH)/$(NAME).o: $(NAME).c
	$(CC) -c $< -o $@ $(INC)
	
$(PATH_BACK)/build/README.md: $(PATH_BACK)/README.md
	cd $(PATH_BACK) ; make build/README.md ; cd lib/$(NAME) ;

all: $(NAME).c $(PATH_BACK)/build/README.md $(LIB)

remove:
	rm -rf $(PATH_BACK)/build
