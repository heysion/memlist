CC = gcc
SRC = test.c

test.out :
	$(CC) -o test.out $(SRC)

#cc -DDMALLOC -DDMALLOC_FUNC_CHECK file.c
ttest.out:$(SRC)
	$(CC) -DDMALLOC -DDMALLOC_FUNC_CHECK $(SRC)  -g -o ttest.out
