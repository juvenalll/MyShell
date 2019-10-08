CC = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = builtin.o main.o help.o pipe_fork.o
TARGET = myshell
all: $(TARGET)
$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~

