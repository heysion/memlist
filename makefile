#**************************************************
#Description: memlist libfile makefile
#Version:     v0.01
#Copyleft:    
#**************************************************
#SHELL=/bin/sh
CC = gcc
DEBUG = -g
SRC1    = memlist.c 
SRC2    = test.c
OBJ = memlist.o 
TEST = test
AR = ar rc
LIB_A = libmemlist.a
LD_FLAGS_A = -c 
LIB_SO = libmemlist.so
LD_FLAGS_SO = -shared -fpic -o
LD_FLAGS = -L. -lmemlist -I.


defuat:$(LIB_A)


so:$(LIB_SO)
sa:$(LIB_A)

$(LIB_SO):
	$(CC) $(SRC1) $(LD_FLAGS_SO) $(LIB_SO) $(DEBUG)

$(LIB_A):$(OBJ)
	$(AR) $(LIB_A) $(OBJ) 

$(OBJ):$(SRC1)
	$(CC) $(LD_FLAGS_A) $(SRC1) $(DEBUG)

test:
	$(CC) -o $(TEST).out $(SRC2) $(LD_FLAGS) $(DEBUG)
test2:
	$(CC) -o $(TEST)2.out $(SRC2) $(LD_FLAGS) -Wl,-rpath,. $(DEBUG)

.PHONY:clean

clean:
	@echo "**********Clean*******************"
	@echo 
	@echo "**********Cleaning****************"
	@-rm -f *.out *.a *.so *.o
	@echo 
	@echo "**********Complete****************"

