mkdir build
gcc -c libetp/etp.c -o build/etp.o -Ilibetp -g -lSDL2
gcc -c libetp/test.c -o build/test.o -Ilibetp -g -lSDL2
gcc -o test build/test.o build/etp.o -Ilibetp -g -lSDL2