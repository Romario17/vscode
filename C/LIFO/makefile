PROJ_NAME=main

C_SOURCE=$(wildcard src/*.c)

H_SOURCE=$(wildcard include/*.h)

OBJ=$(subst .c,.o,$(subst src,obj,$(C_SOURCE)))

CC=gcc

CC_FLAGS=-c			\
		 -W         \
         -Wall

RM=rm

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^

obj/%.o: src/%.c
	$(CC) $(CC_FLAGS) $< -o $@

objFolder:
	mkdir obj

projectfolders: objFolder
	mkdir include src

.PHONY: clean mrproper
clean:
	@ $(RM) obj/*.o

mrproper: clean
	@ $(RM) $(PROJ_NAME).exe