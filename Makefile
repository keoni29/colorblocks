flags = -std=c++11 -lSDL2 -lSDL2_image -lSDL2_mixer
all:
	g++ *.cpp -o animated $(flags)
