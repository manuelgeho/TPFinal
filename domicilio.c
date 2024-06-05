#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "domicilio.h"

stDomicilio cargaUnDomicilio()
{
    stDomicilio d;

    printf("Ingrese una calle:\t");
    fflush(stdin);
    gets(&d.calle);
    printf("Ingrese un numero:\t");
    fflush(stdin);
    gets(&d.nro);
    printf("Ingrese una localidad:\t");
    fflush(stdin);
    gets(&d.localidad);
    printf("Ingrese una provincia:\t");
    fflush(stdin);
    gets(&d.provincia);
    printf("Ingrese codigo postal:\t");
    fflush(stdin);
    gets(&d.cpos);

    return d;
}

void muestraUnDomicilio(stDomicilio d)
{
    printf("\nCalle..................................:%s\n", d.calle);
    printf("\nAltura.................................:%s\n", d.nro);
    printf("\nLocalidad..............................:%s\n", d.localidad);
    printf("\nProvincia..............................:%s\n", d.provincia);
    printf("\nCodigo Postal..........................:%s\n", d.cpos);
}


