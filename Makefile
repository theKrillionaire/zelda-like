build/prog: cpp_files/*.cpp
	mkdir -p build
	g++ -I h_files cpp_files/*.cpp -o build/prog -lraylib -lX11 -lXrandr -lXinerama -lXcursor -lXi -lXext -lGL -lm -lpthread -ldl -lrt
	
with assets: build/prog
	mkdir -p build/sprites
	cp -r sounds build
	cp -r sprites/*.png build/sprites
	
static: build/prog
	g++ *.cpp -o build/prog -L$$HOME/raylib -lraylib -lopengl32 -lgdi32 -lwinmm -lshell32 -luser32 -static-libg++
	
run: build/prog
	./build/prog
	rm -rf build/prog
