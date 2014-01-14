CC = gcc
SRC = test.c
CFLAG = -g 

test.out :test.o
test.o:$(SRC)
	$(CC) -o test.out $(SRC)

tt.out:tt.o
tt.o:$(SRC)
	$(CC) -o tt.out $(SRC)
#cc -DDMALLOC -DDMALLOC_FUNC_CHECK file.c
#ttest.out:$(SRC)
#	$(CC) -DDMALLOC -DDMALLOC_FUNC_CHECK $(SRC)  -g -o ttest.out

tt2.out:tt2.o
tt2.o:$(SRC)
	$(CC) -o tt2.out $(SRC2)
clear:
	@echo "clear ...."
	@-rm *.out
