#include <stdio.h> /* printf */

/* For 32 bit numbers */
int reverse_endian(int num) {
    return ((num >> 24) & 0xff)        /* move byte 3 to byte 0 */
         | ((num << 8)  & 0xff0000)    /* move byte 1 to byte 2 */
         | ((num >> 8)  & 0xff00)      /* move byte 2 to byte 1 */
         | ((num << 24) & 0xff000000); /* byte 0 to byte 3 */
}

int main(void) {
    int test = 0xdeadbeef;
    int first = 0xde;

    char *hex = (char*)&test;
    int rev = reverse_endian(test);

    if(*hex == first) {
        printf("In little endian: 0x%x\n", test);
        printf("In big endian: 0x%x\n", rev);
    }
    else {
        printf("In big endian: 0x%x\n", test);
        printf("In little endian: 0x%x\n", rev);
    }

    return 0;
}

/*
uint16_t swap_uint16( uint16_t val )  {
    return (val << 8) | (val >> 8 );
}

int16_t swap_int16( int16_t val )  {
    return (val << 8) | ((val >> 8) & 0xFF);
}

uint32_t swap_uint32( uint32_t val ) {
    val = ((val << 8) & 0xFF00FF00 ) | ((val >> 8) & 0xFF00FF ); 
    return (val << 16) | (val >> 16);
}

int32_t swap_int32( int32_t val ) {
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF ); 
    return (val << 16) | ((val >> 16) & 0xFFFF);
}

int64_t swap_int64( int64_t val ) {
    val = ((val << 8) & 0xFF00FF00FF00FF00ULL ) | ((val >> 8) & 0x00FF00FF00FF00FFULL );
    val = ((val << 16) & 0xFFFF0000FFFF0000ULL ) | ((val >> 16) & 0x0000FFFF0000FFFFULL );
    return (val << 32) | ((val >> 32) & 0xFFFFFFFFULL);
}

uint64_t swap_uint64( uint64_t val ) {
    val = ((val << 8) & 0xFF00FF00FF00FF00ULL ) | ((val >> 8) & 0x00FF00FF00FF00FFULL );
    val = ((val << 16) & 0xFFFF0000FFFF0000ULL ) | ((val >> 16) & 0x0000FFFF0000FFFFULL );
    return (val << 32) | (val >> 32);
}
*/