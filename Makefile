build/prog: main.cpp
	mkdir -p build
	g++ main.cpp -o build/prog -lraylib -lm
	
with assets: build/prog
	mkdir -p build/sprites
	cp -r sounds build
	cp -r sprites/*.png build/sprites
	
run: build/prog
	./build/prog