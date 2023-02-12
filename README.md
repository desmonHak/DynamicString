# DynamicString
Esta cabecera  permite trabajar con string's dinamicos sin tener que preocuparse de reservar memoria, pasandolos al head y reservando previamente memoria mediante la funcion malloc.
La memoria se reserva al crearse el string inicialmente. Si el string struct tiene la capacidad de almacenar el nuevo string, no reserva memoria nueva, usa la ya reservada. En caso contrario, se reserva mas memoria mediante mmaloc y se copia los datos nuevos a la memoria nueva, acontinuacion de libera la memoria antigua.
Falta implementar un metodo que libere la memoria de los string's reservados, al finalizar el programa.
----

# Ejemplo de uso:
```C

#include <stdio.h>

#include "string_c.h"

int main(){

    // creacion de un string nuevo y vacio:
    string_c myString1 = NEW_STRING_C_VOID;

    // creamos el string:
    myString1 = create_string(myString1);

    // obtenemos el string para imprimir su contenido
    printf ("El contenido de myString1 es: %s\n", get_string(myString1));

    // cambiamos el contenido del string antiguo a uno nuevo:
    myString1 = set_string(myString1, "Hola mundo desde myString1");

    // obtenemos el string que hemos modificado:
    printf ("El contenido de myString1 modificado es: %s\n", get_string(myString1));


    // creamos un nuevo string no vacio:
    string_c myString2 = NEW_STRING_C("Adios Mundo desde myString2");

    // creamos el string:
    myString2 = create_string(myString2);

    // obtenemos el contenido de myString2:
    printf ("El contenido de myString2 es: %s\n", get_string(myString2));


    free(myString1.stringStruct->string_data.pointer);
    free(myString2.stringStruct->string_data.pointer);

    return 0;
}

```


----