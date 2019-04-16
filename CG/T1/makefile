PROJ_NAME=main

PROJ_PATH=debug/$(PROJ_NAME)

C_SOURCE=$(wildcard src/*.c)

H_SOURCE=$(wildcard include/*.h)

OBJ=$(subst .c,.o,$(subst src,obj,$(C_SOURCE)))

CC=gcc

C++=g++

DEBUG_FLAG=-g

RELEASE_FLAG=-o

ARCHITECTURE_FLAG=-m32

CC_FLAGS=-c			\
		 -W         \
         -Wall

RM=rm

all: $(PROJ_PATH)

$(PROJ_PATH): $(OBJ)
	$(CC) $^ $(DEBUG_FLAG) $(RELEASE_FLAG) $@

obj/%.o: src/%.c
	$(CC) $< $(CC_FLAGS) $(DEBUG_FLAG) $(RELEASE_FLAG) $@

projectfolders:
	mkdir include src obj debug

.PHONY: clean mrproper
clean:
	@ $(RM) obj/*.o

mrproper: clean
	@ $(RM) debug/$(PROJ_NAME)