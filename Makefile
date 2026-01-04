.PHONY: all build run clean

CXXFLAGS := -g -O0 -Wall

FOLDER :=dmoj
BIN := bouncing_ball
SRC := $(FOLDER)/$(BIN).cpp

all: build

build: $(BIN)

$(BIN): $(SRC)
	g++ $(CXXFLAGS) $(SRC) -o out/$(BIN)

run: build
	./out/$(BIN)

clean:
	rm -f $(BIN)
