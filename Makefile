CC = g++
CFLAGS = -g -Wall

#OBJ - specifies which file to compile as part of the project
OBJ = src/main.cpp src/CWUtilities.cpp

#OUT - specifies the name of our executable
OUT = firstWindow

ifeq ($(shell uname), Darwin)
  INC = -I inc/ -I /usr/local/include -I /opt/X11/include
  LIB = -L /usr/local/lib -L /opt/X11/lib
  LINK = -framework OpenGL -lGLUT
else
  INC = _Iinc/ -I/usr/local/include
  LIB = -L/usr/local/lib
  LINK = -lGL -lGLU -lglut
endif

all : $(OBJS)
	$(CC) $(OBJ) $(INC) $(LIB) $(CFLAGS) $(LINK) -o $(OUT)

#firstWindow: firstWindow.o
#	$(CC) $(CFLAGS) -o $@ $< $(LIBS)
#
#.o:.c
#	$(CC) $(CFLAGS) -c $<
#
#clean: FORCE
#	-rm -f *.o
#
#FORCE:
