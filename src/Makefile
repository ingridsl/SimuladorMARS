IDIR = ../include
CC = gcc -Wall
CFLAGS = -I$(IDIR) -lm

ODIR = obj
LDIR = ../lib

LIBS =

_DEPS = simulador.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = simulacao.o simulador.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

simulacao: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
