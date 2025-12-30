.PHONY: all build run clean

CXXFLAGS := -g -O0 -Wall

FOLDER :=cf-186
BIN := q4
SRC := $(FOLDER)/$(BIN).cpp

all: build

build: $(BIN)

$(BIN): $(SRC)
	g++ $(CXXFLAGS) $(SRC) -o out/$(BIN)

run: build
	./out/$(BIN)

clean:
	rm -f $(BIN)
