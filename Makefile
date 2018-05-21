.PHONY: run


TARGET=matrix
SRC=main.cpp

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(SRC)
	g++ -g -o $@ $<
