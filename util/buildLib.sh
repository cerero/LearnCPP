clang -I./include LinkList.c StringUtil.c -dynamiclib -o libMyUtil.dylib &&
cp libMyUtil.dylib ./test/
