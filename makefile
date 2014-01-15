#**************************************************
#Description: memlist libfile makefile
#Version:     v0.01
#Copyleft:    
#**************************************************
#SHELL=/bin/sh
CC = gcc
SRC1    = memlist.c 
SRC2    = test.c
OBJ = memlist.o 
TEST = test
AR = ar rc
LIB_A = libmemlist.a
LD_FLAGS_A = -c 
LIB_SO = memlist.so
LD_FLAGS_SO = -shared -fpic -o
LD_FLAGS = -L. -lmemlist -I.

defuat:$(LIB_A)

$(LIB_OBJ):
	$(CC) $(SRC) $(LD_FLAGS_SO) $(LIB_SO)

$(LIB_A):$(OBJ)
	$(AR) $(LIB_A) $(OBJ)
$(OBJ):$(SRC1)
	$(CC) $(LD_FLAGS_A) $(SRC1) 

$(TEST):
	$(CC) -o $(TEST).out $(SRC2) $(LD_FLAGS) 

.PHONY:clean

clean:
	@echo "**********Clean*******************"
	@echo
	@-rm -f *.out *.a *.so *.o
	@echo "**********Complete****************"

