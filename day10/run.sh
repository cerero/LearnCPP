clang++ -c ./include/Array.cpp -o ./include/Array.o -I ./include/ &&
clang++ -o test test.cpp ./include/Array.o -I ./include/
