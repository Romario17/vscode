PROJ_NAME=main

OUT_EXTENSION=.out

H_EXTENSION=.hpp

SRC_EXTENSION=.cpp

CC=gcc

CPP=g++

COMPILER_FLAG=$(CPP)

DEBUG_FLAG=-g

RELEASE_FLAG=-o

ARCHITECTURE_FLAG=-m32

CC_FLAGS=-c			\
		 -W         \
         -Wall

RM=rm

######################################################################

PROJ_PATH=debug/$(PROJ_NAME)$(OUT_EXTENSION)

OBJ_PATH=obj/*o

C_PATH=$(wildcard src/*$(SRC_EXTENSION))

H_PATH=$(wildcard include/*$(H_EXTENSION))

OBJ=$(subst $(SRC_EXTENSION),.o,$(subst src,obj,$(C_PATH)))

######################################################################

all: $(PROJ_PATH)

$(PROJ_PATH): $(OBJ)
	$(COMPILER_FLAG) $^ $(DEBUG_FLAG) $(RELEASE_FLAG) $@

obj/%.o: src/%$(SRC_EXTENSION)
	$(COMPILER_FLAG) $< $(CC_FLAGS) $(DEBUG_FLAG) $(RELEASE_FLAG) $@

create-folders:
	mkdir include src obj debug

.PHONY: clean mrproper
clean:
	@ $(RM) $(OBJ_PATH)

mrproper: clean
	@ $(RM) $(PROJ_PATH)