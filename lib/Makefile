
# add files you create here
OBJ = Block.o Board.o Movement.o Game.o

all: libGame2048.a

test: all

# add files you want to remove here
clean:
	rm -f *~ libGame2048.a $(OBJ)

libGame2048.a: $(OBJ)
	$(AR) -r $@ $(OBJ) 

%.o:%.cpp
	$(CXX) -g -c -o $@ -I . -I ../include $< -Wall -Werror
