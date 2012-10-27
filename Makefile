CC=clang
CFLAGS=-c -g -Wall -Iinclude
EXECUTABLE=mintchip
SOURCES=src/mintchip.c src/mintchip_info.c src/main.c
OBJECTS=$(SOURCES:.c=.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
