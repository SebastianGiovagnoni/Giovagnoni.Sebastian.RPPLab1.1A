#include <stdio.h>
#include <stdlib.h>
#include "prestamos.h"
#include "cliente.h"
#include "generics.h"
#include "lib.h"

#define TAM 50

int main()
{
    cliente listcliente[TAM];
    Inicializarcliente(listcliente,TAM);
    prestamos listprestamos[TAM];
    Inicializarprestamos(listprestamos,TAM);
    int opcion=0;
    int id = 0;
    int idP = 10000;

while(opcion != 10){
        printf("1-Alta cliente\n2-Modificar Cliente\n3-BajaCliente\n4-Alta Prestamo\n5-Saldar prestamo\n6-Reanudar prestamo\n7-Imprimir Clientes\n8-Imprimir Prestamos\n9-Informar Clientes\n10-SALIR\n");
        SetInt(&opcion,"Ingrese Opcion: ");
        system("cls");
        switch(opcion){
        case 1:
            Altacliente(listcliente,TAM,&id);
            break;
        case 2:
            Modificarcliente(listcliente,TAM);
            break;
        case 3:
            Eliminarcliente(listcliente,TAM,listprestamos,TAM);
            break;
        case 4:
            Altaprestamos(listprestamos,TAM,&idP,listcliente,TAM);
            break;
        case 5:
            saldarPrestamo(listprestamos,TAM,listcliente,TAM);
            break;
        case 6:
            reanudarPrestamo(listprestamos,TAM,listcliente,TAM);
            break;
        case 7:
            imprimirClientes(listcliente,TAM,listprestamos,TAM);
            system("pause");
            break;
        case 8:
            imprimirPrestamos(listprestamos,TAM,listcliente,TAM);
            system("pause");
            break;
        case 9:
            informaClientesMasPrestamosActivos(listprestamos,TAM,listcliente,TAM);
            informaClientesMasPrestamosSaldados(listprestamos,TAM,listcliente,TAM);
            informaClientesMasPrestamos(listprestamos,TAM,listcliente,TAM);
            system("pause");
            break;
        case 10:
            break;
        default:
            Alert("\nNo existe opcion\n");
            break;
        }
        system("cls");
    }

    return 0;
}
