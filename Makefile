CC = gcc
TARGET = main.c
SRCS = manager.c product.c
OBJS = $(SRCS:.c=.o)
EXE1 = main
EXE2 = main_debug

$(EXE1) : $(OBJS)
	$(CC) $(TARGET) $^ -o $@
%.o: %.c
	$(CC) -c $(SRCS)       
$(EXE2) : $(OBJS)
	$(CC) -DDEBUG $(TARGET) $^ -o $@
	
clean :
	rm -f $(OBJS) $(EXE1) $(EXE2)
