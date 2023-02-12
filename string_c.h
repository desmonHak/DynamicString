#ifndef _STRING_C_H
#define _STRING_C_H	1

#include <stdlib.h>

typedef unsigned char ui8;
typedef struct _uint32_t {
    unsigned int     _uint32_t:32;
} _uint32_t;

#pragma GCC poison string
#pragma GCC diagnostic ignored "-Wattributes"

typedef __attribute__((__transparent_struct__)) struct string__c { 
    _uint32_t size_ocupated; 
    struct  { 
        ui8* pointer; 
        _uint32_t size; 
    } string_data; 
} string__c; 

typedef __attribute__ ((__transparent_union__)) union string_c {
    string__c *stringStruct;
    ui8 *stringPointerUi8;
} string_c;
#define NEW_STRING_C_VOID {.stringStruct = NULL, .stringPointerUi8 = NULL};
#define NEW_STRING_C(text) {.stringStruct = NULL, .stringPointerUi8 = (ui8*)text};

/*
* El atributo pure en C indica que una función no 
* tiene efectos secundarios, es decir, no modifica 
* ningún valor fuera de su alcance y siempre produce 
* el mismo resultado con los mismos argumentos. 
* Esto permite a los compiladores optimizar el código,
* por ejemplo, evitando llamar a la función si su resultado
* ya se conoce. 
*/

__attribute__ ((pure)) _uint32_t strlen_c(string_c data);
string_c create_string(string_c data);
__attribute__ ((pure)) string_c set_string(string_c data, ui8 * new_string);
ui8 * get_string(string_c str);
void copy_str_to_str(ui8 *str1, ui8 *str2, _uint32_t len);


#include "string_c.c"
#endif