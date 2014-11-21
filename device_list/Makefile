CC = gcc
CFLAGS = -O2 -Wall
LFLAGS = -lm
FRAMEWORKS = -framework OpenAL

SRC = device_list

$(SRC): $(SRC).c
		$(CC) $(CFLAGS) $@.c $(FRAMEWORKS) $(LFLAGS) -o $@
