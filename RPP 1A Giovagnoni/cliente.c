#include "prestamos.h"
#include <stdio.h>
#include <stdlib.h>
#include "generics.h"
#include "cliente.h"

void Inicializarcliente(cliente* listcliente, int tam){
    for(int i = 0; i < tam; i++){
        listcliente[i].id = -1;
    }
}

int GetclienteById(cliente* listcliente, int tam,int id){
    int ret = -1;
    for(int i = 0; i < tam; i++){
        if(listcliente[i].id == id){
            ret = i;
            break;
        }
    }

    return ret;
}

void Mostrarcliente(cliente cliente){
    printf("%d    %d    %s    %s\n",cliente.id,cliente.cuil,cliente.nombre,cliente.apellido);
}


void Listacliente(cliente* listcliente, int tam){
    printf("ID | CUIL | NOMBRE | APELLIDO\n");

    for(int i = 0; i < tam; i++){
        if(listcliente[i].id != -1){
            Mostrarcliente(listcliente[i]);
        }
    }
}

void Altacliente(cliente* listcliente, int tam, int* id){
    int i = GetclienteById(listcliente,tam,-1);

    if(i != -1){
        *id = *id + 1;
        listcliente[i].id = *id;

		do{
            SetInt(&listcliente[i].cuil,"\nIngrese el cuil: ");
        }while(listcliente[i].cuil < 0);

        SetString(listcliente[i].nombre,"\nIngrese nombre: ");

        SetString(listcliente[i].apellido,"\nIngrese apellido: ");

        Alert("\nSe a ingresado con exito un cliente\n");
    }else{
        Alert("\nSistema lleno\n");
    }

}

void Eliminarcliente(cliente* listcliente, int tam, prestamos* listprestamos, int tamP){
    int id;
    int i;
    char opcion [3];

    Listacliente(listcliente,tam);

    SetInt(&id,"Ingrese id: ");

    i = GetclienteById(listcliente,tam,id);

    system("cls");



    if(i != -1 && id != -1){
            listarPorId(listprestamos,tamP,listcliente[i].id);
            SetString(opcion,"desea eliminar s/n:");
        if(opcion[0] == 's')
        {
            eliminarTodos(listprestamos,tamP,listcliente[i].id);
            listcliente[i].id = -1;
            Alert("\nexito\n");
        }

    }else{
        Alert("\nNo existe id...");
    }
}

void Modificarcliente(cliente* listcliente, int tam){
    int id;
    int i;

    Listacliente(listcliente,tam);

    SetInt(&id,"Ingrese id: ");

    i = GetclienteById(listcliente,tam,id);

    system("cls");

    if(i != -1 && id != -1){
        printf("1-Cuil\n2-Nombre\n3-Apellido\n");
        SetInt(&id,"Ingrese opcion: ");

        switch(id){
        case 1:
            do{
            SetInt(&listcliente[i].cuil,"\nIngrese el cuil: ");
        }while(listcliente[i].cuil < 0);
            break;
        case 2:
            SetString(listcliente[i].nombre,"\nIngrese nombre: ");
            break;
        case 3:
            SetString(listcliente[i].apellido,"\nIngrese apellido: ");
            break;
        default:
            Alert("\nOpcion incorrecta");
            break;
        }
    }else{
        Alert("\nNo existe id...");
    }
}

void imprimirClientes(cliente* listcliente, int tam, prestamos* listprestamos, int tamP)
{
    int aux;

    printf("ID | CUIL | NOMBRE | APELLIDO | CANT. PRESTAMOS \n");

    for(int i = 0; i < tam; i++){
        if(listcliente[i].id != -1){
            aux=cantidadDePrestamosActivos(listprestamos,tamP,listcliente[i].id);
            printf("%d    %d    %s    %s    %d\n",listcliente[i].id,listcliente[i].cuil,listcliente[i].nombre,listcliente[i].apellido,aux);
        }
    }
}
