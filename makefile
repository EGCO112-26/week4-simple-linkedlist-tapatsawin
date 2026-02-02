compile: main.c 
	 gcc main.c -o Act

run: Act
	 ./Act

clean: Act
	 rm Act
