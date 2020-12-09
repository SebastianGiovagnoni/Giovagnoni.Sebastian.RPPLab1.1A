#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prestamos.h"
#include "cliente.h"
#include "generics.h"
#include "lib.h"

#define SA "SALDADO"
#define AC "ACTIVO"

void Altaprestamos(prestamos* listprestamos, int tamA, int* id,cliente* listcliente, int tamC){
    int i = GetprestamosById(listprestamos,tamA,-1);
    if(i != -1){
        *id = *id + 1;

        listprestamos[i].id = *id;

        do{
            system("cls");
            Listacliente(listcliente,tamC);
            SetInt(&listprestamos[i].idcliente,"\nIngrese id cliente: ");
        }while(GetclienteById(listcliente,tamC,listprestamos[i].idcliente) == -1 || listprestamos[i].idcliente < 0);


	do{
            SetInt(&listprestamos[i].importe,"\nIngrese el importe: ");
        }while(listprestamos[i].importe < 0 );


	do{
            SetInt(&listprestamos[i].cuotas,"\nIngrese las cuotas: ");
        }while(listprestamos[i].cuotas < 0 );

    strcpy(listprestamos[i].estado,AC);

    system("cls");
    printf("el id del prestamo es:%d\n", listprestamos[i].id);
    system("pause");

    }else{
        Alert("\nSistema lleno...\n");
    }
}

void saldarPrestamo (prestamos* listprestamos, int tam, cliente* listcliente, int tamC){
    int id;
    int i;
    char opcion[3];
    int clienteIndex;

    ListaprestamosActivos(listprestamos,tam);

    SetInt(&id,"Ingrese id: ");

    i = GetprestamosById(listprestamos,tam,id);

    system("cls");

    if(i != -1 && id != -1 && stricmp(listprestamos[i].estado,SA)!= 0){
     clienteIndex=GetclienteById(listcliente,tamC,listprestamos[i].idcliente);
     Mostrarcliente(listcliente[clienteIndex]);
     SetString(opcion,"desea continuar: s/n");
     if(opcion[0] == 's')
     {
         strcpy(listprestamos[i].estado,SA);
     }
    }else{
        Alert("\nNo existe id...");
    }
}

void reanudarPrestamo (prestamos* listprestamos, int tam, cliente* listcliente, int tamC){
    int id;
    int i;
    char opcion[3];

    ListaprestamosSaldados(listprestamos,tam);

    SetInt(&id,"Ingrese id: ");

    i = GetprestamosById(listprestamos,tam,id);

    system("cls");

    if(i != -1 && id != -1 && stricmp(listprestamos[i].estado,AC)!= 0){
     Mostrarcliente(listcliente[GetclienteById(listcliente,tamC,listprestamos[i].idcliente)]);
     SetString(opcion,"desea continuar: s/n");
     if(opcion[0] == 's')
     {
         strcpy(listprestamos[i].estado,AC);
     }
    }else{
        Alert("\nNo existe id...");
    }
}

void imprimirPrestamos(prestamos* listprestamos, int tam, cliente* listclientes, int tamC)
{
    int index;

    printf("ID| ID CLIENTE | IMPORTE | CUOTAS | ESTADO | CUIL\n");

    for(int i = 0; i < tam; i++){
        if(listprestamos[i].id != -1 && stricmp(listprestamos[i].estado,AC)==0){
            index=GetclienteById(listclientes,tamC,listprestamos[i].idcliente);
            printf("%d    %d    %d    %d    %s    %d\n",listprestamos[i].id,listprestamos[i].idcliente,listprestamos[i].importe,listprestamos[i].cuotas,listprestamos[i].estado,listclientes[index].cuil);
        }
    }
}

void informaClientesMasPrestamosActivos(prestamos* listprestamos, int tam, cliente* listclientes, int tamC)
{
    int aux = 0;
    int index = -1;


    for(int i = 0; i < tam; i++){
        if(listclientes[i].id != -1){

            if(aux<cantidadDePrestamosActivos(listprestamos,tamC,listclientes[i].id))
            {
                aux=cantidadDePrestamosActivos(listprestamos,tamC,listclientes[i].id);
                index = i;
            }

        }
    }
    if(index != -1)
    {
        printf("el cliente con mas prestamos activos es: %s    %s    %d\n",listclientes[index].nombre, listclientes[index].apellido,listclientes[index].cuil);
    }
}

void informaClientesMasPrestamosSaldados(prestamos* listprestamos, int tam, cliente* listclientes, int tamC)
{
    int aux = 0;
    int index = -1;


    for(int i = 0; i < tam; i++){
        if(listclientes[i].id != -1){

            if(aux<cantidadDePrestamosSaldados(listprestamos,tamC,listclientes[i].id))
            {
                aux=cantidadDePrestamosSaldados(listprestamos,tamC,listclientes[i].id);
                index = i;
            }

        }
    }
    if(index != -1)
    {
        printf("\nel cliente con mas prestamos saldados es: %s    %s    %d\n",listclientes[index].nombre, listclientes[index].apellido,listclientes[index].cuil);
    }
}

void informaClientesMasPrestamos(prestamos* listprestamos, int tam, cliente* listclientes, int tamC)
{
    int aux = 0;
    int index = -1;


    for(int i = 0; i < tam; i++){
        if(listclientes[i].id != -1){

            if(aux<cantidadDePrestamos(listprestamos,tamC,listclientes[i].id))
            {
                aux=cantidadDePrestamos(listprestamos,tamC,listclientes[i].id);
                index = i;
            }

        }
    }
    if(index != -1)
    {
        printf("\nel cliente con mas prestamos es: %s    %s    %d\n",listclientes[index].nombre, listclientes[index].apellido,listclientes[index].cuil);
    }
}
