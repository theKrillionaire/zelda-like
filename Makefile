build/prog: *.cpp
	mkdir -p build
	g++ *.cpp -o build/prog -lraylib -lm
	
with assets: build/prog
	mkdir -p build/sprites
	cp -r sounds build
	cp -r sprites/*.png build/sprites
	
static: *.cpp
	g++ *.cpp -o build/prog -L$$HOME/raylib -lraylib -lopengl32 -lgdi32 -lwinmm -lshell32 -luser32 -static-libg++
	
run: build/prog
	./build/prog