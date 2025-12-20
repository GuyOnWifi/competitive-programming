.PHONY: all build run clean

BIN := alpaca_array
SRC := $(BIN).cpp

all: build

build: $(BIN)

$(BIN): $(SRC)
	g++ $(CFLAGS) $(SRC) -o out/$(BIN)

run: build
	./out/$(BIN)

clean:
	rm -f $(BIN)
