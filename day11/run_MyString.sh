clang++ -c ./include/MyString.cpp -o ./include/MyString.o -I ./include/ &&
clang++ -o test_MyString test_MyString.cpp ./include/MyString.o -I ./include/
