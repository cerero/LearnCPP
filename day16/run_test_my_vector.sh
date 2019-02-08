clang++ -c ./include/MyVector.cpp -o ./include/MyVector.o -I ./include/ &&
clang++ -o test_my_vector test_my_vector.cpp ./include/MyVector.o -I ./include/
