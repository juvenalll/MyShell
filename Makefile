CC = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = builtin.o main.o
TARGET = project
all: $(TARGET)
$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~

