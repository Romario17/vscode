PROJ_NAME=main

PROJ_PATH=debug/$(PROJ_NAME)

C_SOURCE=$(wildcard src/*.cpp)

H_SOURCE=$(wildcard include/*.hpp)

OBJ=$(subst .cpp,.o,$(subst src,obj,$(C_SOURCE)))

CC=gcc

CPP=g++

DEBUG_FLAG=-g

RELEASE_FLAG=-o

ARCHITECTURE_FLAG=-m32

CC_FLAGS=-c			\
		 -W         \
         -Wall

RM=del

all: $(PROJ_PATH)

$(PROJ_PATH): $(OBJ)
	$(CPP) $^ $(DEBUG_FLAG) $(RELEASE_FLAG) $@

obj/%.o: src/%.c
	$(CPP) $< $(CC_FLAGS) $(DEBUG_FLAG) $(RELEASE_FLAG) $@

projectfolders:
	mkdir include src obj debug

.PHONY: clean mrproper
clean:
	@ $(RM) obj\*.o

mrproper: clean
	@ $(RM) debug\$(PROJ_NAME).exe