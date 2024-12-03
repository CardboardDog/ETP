mkdir -p build/src
mkdir -p build/include/libetp
mkdir -p build/include/SDL2_ETP
cp libetp/*.c build/src
cp SDL2_ETP/*.c build/src
cp libetp/*.h build/include/libetp
cp SDL2_ETP/*.h build/include/SDL2_ETP
gcc -c build/src/ETP_Image.c -o build/ETP_Image.o -Ibuild/include/libetp -Ibuild/include/ -g -lSDL2
gcc -c build/src/etp.c -o build/etp.o -Ibuild/include/libetp -Ibuild/include/ -g -lSDL2
gcc -c build/src/test.c -o build/test.o -Ibuild/include/libetp -Ibuild/include/ -g -lSDL2
gcc -o test build/test.o build/etp.o build/ETP_Image.o -Ibuild/include/libetp -Ibuild/include/ -g -lSDL2