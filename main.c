#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "domicilio.h"
#include "cuenta.h"
#include "movimiento.h"

#define ARCHIVO_CLIENTES "archivo_clientes.dat"
#define ESC 27

void agregarClientesArchivo (char nombreDeArchivo[]);
void muestraClientesArchivo (char nombreDeArchivo[]);




int main()
{

    agregarClientesArchivo(ARCHIVO_CLIENTES);
    muestraClientesArchivo(ARCHIVO_CLIENTES);

    return 0;
}

void agregarClientesArchivo (char nombreDeArchivo[])
{
    char opcion = 0;
    stCliente c;

    FILE* archi = fopen(nombreDeArchivo, "a+b");

    if(archi)
    {
        while(opcion != ESC)
        {
            c = cargaUnCliente(&archi);
            fwrite(&c, sizeof(stCliente), 1, archi);


            printf("Desea continuar la carga?\n Presione ENTER para continuar o ESC para salir.");
            opcion = getch();

            system("cls");

        }
        fclose(archi);
    }
}

void muestraClientesArchivo (char nombreDeArchivo[])
{
    FILE* archi = fopen(nombreDeArchivo, "rb");
    stCliente c;

    if(archi)
    {
        while(fread(&c, sizeof(stCliente), 1, archi) > 0)
        {
            muestraUnCliente(c);
        }

        fclose(archi);
    }
}


