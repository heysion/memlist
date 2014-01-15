#**************************************************
#Description: md5 libfile makefile
#Version:     v0.01
#Copyleft:    
#**************************************************
#SHELL=/bin/sh
CC = gcc
SRC1    = memlist.c 
SRC2    = test.c
OBJ = memlist.o 
AR = ar rc
LIB_A = libmemlist.a
LD_FLAGS_A = -c 
LIB_SO = memlist.so
LD_FLAGS_SO = -shared -fpic -o

defuat:$(LIB_A)

$(LIB_OBJ):
	$(CC) $(SRC) $(LD_FLAGS_SO) $(LIB_SO)

$(LIB_A):$(OBJ)
	$(AR) $(LIB_A) $(OBJ)
$(OBJ):$(SRC1)
	$(CC) $(LD_FLAGS_A) $(SRC1) 


.PHONY:clean

clean:
	@echo "**********Clean*******************"
	@echo
	@-rm -f *.out *.a *.so *.o
	@echo "**********Complete****************"

#clean:
#	-rm -f $(BIN_OBJ) $(OBJ) $(LIB_OBJ_A) $(LIB_OBJ_SO) 
