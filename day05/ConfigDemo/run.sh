clang -c ConfigUtil.c -I ./include/ -I ../../util/include/ &&
clang test.c ConfigUtil.o ../../util/StringUtil.o -I ./include/ -I ../../util/include/
