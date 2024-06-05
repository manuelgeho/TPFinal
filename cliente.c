#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#define ARCHIVO_CLIENTES "archivo_clientes.dat"

int cuentaRegistrosArchivo(FILE* archi, int tamanioEstructura) ///recibe puntero a FILE y tam de stCliente
{
    int i = 0;

    fseek(archi, 0, SEEK_END);
    i = ftell(archi)/tamanioEstructura; ///desde el ppio del archivo hasta el cursos cuenta los bytes

    fclose(archi);

    return i+1;
}

stCliente cargaUnCliente ()
{
    stCliente c;
    char dni[10], mail[30];
    int buscaDni, validacionMail;

    FILE* archi = fopen(ARCHIVO_CLIENTES, "a+b"); ///abro archivo en a+b para poder mover el cursor en el archivo



    if (archi)
    {
        do
    {
        printf("Ingrese el DNI del cliente:\t"); ///ingreso DNI cliente
        fflush(stdin);
        gets(dni); ///tomo dni en variable, no en estructura

        buscaDni = buscarDNIenArchivo(archi, dni); ///funcion que busca el DNI del cliente para verificar que no exista

        if(buscaDni == -1) ///si no existe lo incluyo en la estructura
        {
            strcpy(c.dni, dni);

        }
        else
        {

            printf("El cliente ya existe. Intente nuevamente\n"); ///si existe printeo advertencia

        }
    } while(buscaDni == 0);

    c.id = cuentaRegistrosArchivo(archi, sizeof(stCliente));

    printf("Ingrese un n%cmero de cliente:\t", 163); ///ingreso nro cliente
    scanf("%d", &c.nroCliente);

    printf("Ingrese el nombre del cliente:\t"); ///ingreso nombre cliente
    fflush(stdin);
    gets(&c.nombre);

    printf("Ingrese el apellido del cliente:\t"); ///ingreso apellido de cliente
    fflush(stdin);
    gets(&c.apellido);

    printf("Ingrese tel%cfono de cliente:\t", 130); ///ingreso telefono del cliente
    fflush(stdin);
    gets(&c.telefono);

    c.domicilio = cargaUnDomicilio(); ///cargo todos los datos del domicilio

    do
    {
        printf("Ingrese email del cliente:\t"); ///ingreso mail de cliente
        fflush(stdin);
        gets(mail); ///lo tomo en una variable

        validacionMail = validarMail(mail);

        if(validacionMail == 1)
        {
            strcpy(c.email, mail); ///si es correcto lo tomo
        }
        else
        {
            printf("El email es incorrecto. Intente nuevamente\n"); ///si es incorrecto printeo advertencia
        }

       }while (validacionMail == 0);


    fclose(archi);
      }

    return c;

}
void muestraUnCliente(stCliente c)
{
    printf("\n ID CLIENTE: %d", c.id);
    printf("\nN%cmero de Cliente.....................:%d\n", 163, c.nroCliente);
    printf("\nNombre.................................:%s\n", c.nombre);
    printf("\nApellido...............................:%s\n", c.apellido);
    printf("\nDNI....................................:%s\n", c.dni);
    printf("\nEmail..................................:%s\n", c.email);
    muestraUnDomicilio(c.domicilio);
    printf("\nTel%cfono...............................:%s\n", 130, c.telefono);
    if(c.eliminado == 0)
    {
        printf("\n\tCLIENTE ACTIVO\n");

    }
    else
    {
        printf("\n\tCLIENTE INACTIVO\n");
    }
    printf("____________________________________________________");

}

int buscarDNIenArchivo(FILE* archi, char dni[])
{
    int flag = -1; ///-1 = no encontrado
    stCliente c;

    rewind(archi); /// voy al inicio del archivo

    while(flag == -1 && fread(&c, sizeof(stCliente), 1, archi) > 0) ///mientras no lo haya encontrado y tenga qué leer
    {
        if(strcmp(c.dni, dni) == 0) /// si encuentro el dato cambio el flag
        {
            flag = 0;
        }
    }
    return flag;
}

int validarMail (FILE* archi, char* mail[])
{
    int esValido = 0; ///de entrada mail incorrecto

    int arroba = 0, punto = 0;

    for (int i= 0; i < strlen(mail); i++) ///busco en cada pos el @ y un punto
    {
        if (mail[i] == '@')
        {
            arroba++; ///si lo encuentro incremento
        }
        if(mail[i] == '.')
        {
            punto++; ///si lo encuentro incremento
        }


    }

    if (arroba == 1 && punto >= 1) ///si hay un @ y al menos un punto
        {
            esValido = 1; ///cambio el estado del flag
        }

        return esValido;
}

int validarEmail(char *email)
{
    int arroba = -1;
    int punto = -1;
    int esValido = 1;


    for (int i = 0; i < strlen(email); i++) ///busca que existan el @ y un "."
        {
        if (email[i] == '@') {
            arroba++;
        } else if (email[i] == '.') {
            punto++;
        }
    }

    if (arroba >= 0 && punto >= 0) ///chequeo que existan
        {
        esValido = 1; /// Correo electrónico válido
    } else {
        esValido = 0; /// Correo electrónico no válido
    }
}
