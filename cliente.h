#ifndef CLIENTE_H_INCLUDED
#include <string.h>
#include"domicilio.h"
#define CLIENTE_H_INCLUDED

/**Estructura de Clientes: stCliente*/

typedef struct
{
    int id; /// campo único y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    stDomicilio domicilio;
    char telefono[12];
    int eliminado; /// 0 si está activo - 1 si está eliminado
}stCliente;

stCliente cargaUnCliente ();
void muestraUnCliente (stCliente c);
int buscarDNIenArchivo(FILE* archi, char dni[10]);
int validarEmail(char *email);
int cuentaRegistrosArchivo(FILE* archi, int tamanioEstructura);

#endif // CLIENTE_H_INCLUDED
