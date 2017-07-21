# 将自己实现的数据结构编译为动态链接库

## 生成动态库

```bash
gcc -c -fPIC -I ../data_structure/stack/ ../data_structure/stack/stack.c -o stack.o
gcc -shared stack.o -o libstack.so
```

## 使用

```bash
cd data_structure/build
gcc ../test/test_stack.c -o test_stack -L../../dynamic_link_library -lstack -I../stack/ -Wl,-rpath=../../dynamic_link_library
```
