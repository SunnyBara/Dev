#include <stddef.h>
void *my_realloc(void *ptr, size_t new_size, size_t old_size);
char *my_memset(char *s, int c, size_t n);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_memov(void *dest, const void *src, size_t n);
void memdump(const void  *addr, size_t len);
char* hexa(unsigned char a);
char conversion(char c);
int *array_init(size_t size);
void array_release(int *array);
void array_print(int *array,  size_t size);
void print_int(int n);
void array_sort(int *array, size_t size);
void array_fibo(int *array, size_t size, size_t n);
int fibo(int n);