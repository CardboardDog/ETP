/*

    LIB ETP (c) 2024 EN
    VERSION 1.0
    THIS FILE IS UNDER THE MIT LICENSE
    https://github.com/CardboardDog/ETP/blob/main/LICENSE

*/

#ifndef ETP_VERSION
#define ETP_VERSION 0x10

#include<stdio.h>
#include<string.h>
#include<malloc.h>

/// An image loaded from LibETP
struct {
    /// image width
    unsigned char w;
    /// image height
    unsigned char h;
    /// image data stored as R,G,B,A
    unsigned char* p;
} typedef etp_base;

#define ETP_LOADED 0
#define ETP_WRONG_FORMAT 1
#define ETP_EMPTY 2
#define ETP_UNSUPPORTED 3
#define ETP_BAD 4
#define ETP_NULL 5

/// an error code
typedef int etp_result;

etp_base* etp_create_base();
/// load a etp from an already open file
etp_result etp_load(etp_base* dst, FILE* file);
/// load a etp from a file path 
etp_result etp_loads(etp_base* dst, const char* file);
/// use an error code to print an error message
void etp_print_error(etp_result error);
/// safe method to free an etp_base*
void etp_free(etp_base* ptr);

#endif