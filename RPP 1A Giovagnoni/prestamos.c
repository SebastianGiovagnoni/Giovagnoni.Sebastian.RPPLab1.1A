#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prestamos.h"
#include "cliente.h"


#define SA "SALDADO"
#define AC "ACTIVO"

void Inicializarprestamos(prestamos* listprestamos, int tam){
    for(int i = 0; i < tam; i++){
        listprestamos[i].id = -1;
    }
}

int GetprestamosById(prestamos* listprestamos, int tam,int id){
    int ret = -1;
    for(int i = 0; i < tam; i++){
        if(listprestamos[i].id == id){
            ret = i;
            break;
        }
    }

    return ret;
}

void Mostrarprestamos(prestamos prestamos){
    printf("%d    %d    %d    %d    %s\n",prestamos.id,prestamos.idcliente,prestamos.importe,prestamos.cuotas,prestamos.estado);
}


void Listaprestamos(prestamos* listprestamos, int tam){
    printf("ID| ID CLIENTE | IMPORTE | CUOTAS | ESTADO\n");

    for(int i = 0; i < tam; i++){
        if(listprestamos[i].id != -1){
            Mostrarprestamos(listprestamos[i]);
        }
    }
}

void eliminarTodos(prestamos* listprestamos,int tam, int idCliente)
{
    for(int i = 0; i < tam; i++){
        if(listprestamos[i].idcliente == idCliente && listprestamos[i].id != -1){
            listprestamos[i].id = -1;
        }
    }

}

void listarPorId(prestamos* listprestamos,int tam, int idCliente)
{
    printf("ID| ID CLIENTE | IMPORTE | CUOTAS | ESTADO\n");

     for(int i = 0; i < tam; i++){
        if(listprestamos[i].id != -1 && listprestamos[i].idcliente == idCliente){
            Mostrarprestamos(listprestamos[i]);
        }
    }
}

void ListaprestamosSaldados(prestamos* listprestamos, int tam){
    printf("ID| ID CLIENTE | IMPORTE | CUOTAS | ESTADO\n");

    for(int i = 0; i < tam; i++){
        if(listprestamos[i].id != -1 && stricmp(listprestamos[i].estado,SA)==0){
            Mostrarprestamos(listprestamos[i]);
        }
    }
}

void ListaprestamosActivos(prestamos* listprestamos, int tam){
    printf("ID| ID CLIENTE | IMPORTE | CUOTAS | ESTADO\n");

    for(int i = 0; i < tam; i++){
        if(listprestamos[i].id != -1 && stricmp(listprestamos[i].estado,AC)==0){
            Mostrarprestamos(listprestamos[i]);
        }
    }
}

int cantidadDePrestamosActivos(prestamos* listprestamos, int tam, int idCliente)
{
    int contador=0;
    for(int i=0; i<tam; i++)
    {
        if(listprestamos[i].id != -1 && listprestamos[i].idcliente == idCliente && stricmp(listprestamos[i].estado,AC)==0)
        {
            contador++;
        }
    }
    return contador;
}

int cantidadDePrestamosSaldados(prestamos* listprestamos, int tam, int idCliente)
{
    int contador=0;
    for(int i=0; i<tam; i++)
    {
        if(listprestamos[i].id != -1 && listprestamos[i].idcliente == idCliente && stricmp(listprestamos[i].estado,SA)==0)
        {
            contador++;
        }
    }
    return contador;
}

int cantidadDePrestamos(prestamos* listprestamos, int tam, int idCliente)
{
    int contador=0;
    for(int i=0; i<tam; i++)
    {
        if(listprestamos[i].id != -1 && listprestamos[i].idcliente == idCliente )
        {
            contador++;
        }
    }
    return contador;
}



