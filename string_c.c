#ifndef _STRING_C_C
#define _STRING_C_C	1

#include "string_c.h"

_uint32_t strlen_c(string_c data){
    for (_uint32_t contador = (_uint32_t){0}; ; contador._uint32_t++) if (data.stringPointerUi8[contador._uint32_t] == 0x00) return contador;
}

void copy_str_to_str(ui8 *str1, ui8 *str2, _uint32_t len){

    /*
     * Esta func no es segura, pues no valida la longitud del buffer
     * de entrada ni el de salida, lo que que puede hacer que se sobrescriba datos
     * str1 = destino, str2 = origen
    */
    for (_uint32_t i = {0}; i._uint32_t < len._uint32_t; i._uint32_t++) {
        str1[i._uint32_t] = str2[i._uint32_t];
        //printf(">%c %x\n",str1[i._uint32_t], str2[i._uint32_t]);
    }

}

string_c create_string(string_c data){

    string__c *my_string = (string__c*)malloc(sizeof(string__c));;

    if (data.stringPointerUi8 != NULL || data.stringStruct != NULL){
        _uint32_t size_data = {strlen_c(data)._uint32_t + 1};

        *my_string = (string__c){
            // espacio ocupado del string:
            .size_ocupated = size_data,
            .string_data = {
                // puntero con donde almacenar los datos
                .pointer =  (ui8*) malloc(sizeof(ui8) * size_data._uint32_t),
                // espacio maximo a poder guardar en el string:
                .size = size_data
            }
        };

        // copiar el buffer1 al buffer2
        copy_str_to_str(my_string->string_data.pointer, data.stringPointerUi8, my_string->size_ocupated);


    } else {
        *my_string = (string__c){
            // espacio ocupado del string:
            .size_ocupated = {0},
            .string_data = {
                // puntero con donde almacenar los datos
                .pointer =  NULL,
                // espacio maximo a poder guardar en el string:
                .size = {0}
            }
        };
    }

    string_c my_string_ = {.stringPointerUi8 = NULL};
    my_string_.stringStruct = my_string;

    return my_string_;
}

string_c set_string(string_c data, ui8 * new_string){

    string_c data_new = {.stringPointerUi8 = new_string};

    _uint32_t size_data = {strlen_c(data_new)._uint32_t + 1};

    if ((data.stringStruct->string_data.size._uint32_t > size_data._uint32_t ) || data.stringStruct->string_data.size._uint32_t == 0 || data.stringStruct->string_data.pointer == 0){
        // si se ingreso un string de mayor tamano, cambiar los tamanos y reservar mas memoria:

        // cambiar el tamano maximo a poder almacenar en el string:
        data.stringStruct->string_data.size = size_data;

        // liberar memoria:
        free(data.stringStruct->string_data.pointer);

        // reservar mas espacio:
        data.stringStruct->string_data.pointer = (ui8*) malloc(sizeof(ui8) * size_data._uint32_t);
        // cambiar el tamano ocupado al max de la fun:
        data.stringStruct->size_ocupated = size_data;

        //copy_str_to_str(data.stringStruct->string_data.pointer, new_string, size_data._uint32_t)

    } else {
        // cambiar el tamano ocupado antiguo al nuevo:
        data.stringStruct->size_ocupated = size_data;
    }

    copy_str_to_str(data.stringStruct->string_data.pointer, new_string, data.stringStruct->size_ocupated);
    return data;
}

ui8 * get_string(string_c str){
    if (str.stringStruct->string_data.pointer != 0) {
        return str.stringStruct->string_data.pointer;
    }else if (str.stringPointerUi8 != NULL) {
        return str.stringPointerUi8;
    }  else {
        return NULL;
    }
}

#endif