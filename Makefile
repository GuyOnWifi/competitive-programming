.PHONY: all build run clean

BIN := alpaca_array
SRC := $(BIN).cpp

all: build

build: $(BIN)

$(BIN): $(SRC)
	g++ $(CFLAGS) $(SRC) -o $(BIN)

run: build
	./$(BIN)

clean:
	rm -f $(BIN)
