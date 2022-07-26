CC := gcc
OBJ := obj
BIN := bin
SRC := src
SRCS := $(wildcard $(SRC)/*.c)
OBJS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
EXE := $(BIN)/main

.PHONY: all
all: $(BIN) $(OBJ) $(OBJS) $(EXE)

$(EXE): main.c $(SRCS)
	$(CC) $< $(OBJS) -o $@

$(OBJ):
	mkdir $@

$(BIN):
	mkdir $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(EXE)

.PHONY: run
run: all
	./$(EXE)
