clang -c ./include/des.c -o ./include/des.o -I ./include/ -I ../../util/include/ &&
clang test.c ./include/des.o ../../util/StringUtil.o -I ./include/ -I ../../util/include/
