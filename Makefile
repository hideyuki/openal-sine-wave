CC = gcc
CFLAGS = -O2 -Wall
LFLAGS = -lm
FRAMEWORKS = -framework OpenAL

SRC = sine_wave

$(SRC): $(SRC).c
		$(CC) $(CFLAGS) $@.c $(FRAMEWORKS) $(LFLAGS) -o $@
