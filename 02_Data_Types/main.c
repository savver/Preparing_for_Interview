#include <stdio.h>
#include <stddef.h> //size_t, ptrdiff_t

//-------------------------------------------------------------------
void print_complier_info()
{
    printf("GNU version: %d.%d.%d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#if __x86_64
    printf("__x86_64 = true\n");
#endif
}
//-------------------------------------------------------------------
void check_types_size()
{
    printf("sizeof(int) = %d, sizeof(long) = %d, sizeof(long long) = %d, sizeof(void*) = %d\n",
           sizeof(int),       sizeof(long),      sizeof(long long),  sizeof(void*));
    printf("sizeof(size_t) = %d, sizeof(ptrdiff_t) = %d, sizeof(intptr_t) = %d,\n",
            sizeof(size_t),      sizeof(ptrdiff_t),      sizeof(intptr_t));
}
//-------------------------------------------------------------------
void check_shift()
{
#if __x86_64
    printf("__x86_64 = true\n");
#endif

    long long    mask = 1 << 32;
    printf("long long    mask = 1 << 32 = %lld\n", mask);

    mask = (long long)1 << 32;
    printf("long long    mask = (long long)1 << 32 = %lld\n", mask);

    mask = 1LL << 32;
    printf("long long    mask = 1LL << 32 = %lld\n", mask);
}
//-------------------------------------------------------------------
void check_byte_order()
{
#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ || \
    defined(__BIG_ENDIAN__) || \
    defined(__ARMEB__) || \
    defined(__THUMBEB__) || \
    defined(__AARCH64EB__) || \
    defined(_MIBSEB) || defined(__MIBSEB) || defined(__MIBSEB__)

    printf("BigEndian\n");

#elif defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ || \
    defined(__LITTLE_ENDIAN__) || \
    defined(__ARMEL__) || \
    defined(__THUMBEL__) || \
    defined(__AARCH64EL__) || \
    defined(_MIPSEL) || defined(__MIPSEL) || defined(__MIPSEL__)

     printf("LittleEndian\n");
#else
    printf("I don't know what architecture this is!\n");
#endif
}
//-------------------------------------------------------------------
void check_byte_order_runtime()
{
    int number = 0x1;
    char *numPtr = (char*)&number;
    printf("byte order is %s\n", (numPtr[0] == 1) ? "LE" : "BE");
}
//-------------------------------------------------------------------
int main()
{
    print_complier_info();
    check_types_size();
    check_byte_order();
    check_byte_order_runtime();
    return 0;
}

/* example:

GNU version: 7.3.0
__x86_64 = true
sizeof(int) = 4, sizeof(long) = 4, sizeof(long long) = 8, sizeof(void*) = 8
sizeof(size_t) = 8, sizeof(ptrdiff_t) = 8, sizeof(intptr_t) = 8

GNU version: 7.3.0
sizeof(int) = 4, sizeof(long) = 4, sizeof(long long) = 8, sizeof(void*) = 4
sizeof(size_t) = 4, sizeof(ptrdiff_t) = 4, sizeof(intptr_t) = 4,

__x86_64 = true
long long    mask = 1 << 32 = 0
long long    mask = (long long)1 << 32 = 4294967296
long long    mask = 1LL << 32 = 4294967296


*/
