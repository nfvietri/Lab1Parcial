/*
 ============================================================================
 Name        : lab1parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "clientes.h"
#include "pedidos.h"
#include "utn.h"
#define QTY_CLIENTES 100
#define QTY_PEDIDOS 1000

void test(struct sClientes p[], int cantidad);

int main(void) {


	struct sClientes aClientes[QTY_CLIENTES];
	struct sClientes bCliente;
	struct sPedidos aPedidos[QTY_PEDIDOS];
	struct sPedidos bPedido;
	int opcion;
	int respuesta;

	initLugarLibreClientes(aClientes,QTY_CLIENTES);
	test(aClientes,QTY_CLIENTES);


	do{

		printf("-------Menu------\n"
				"1-Alta de cliente\n"
			   "2-Modificar datos de cliente\n"
			   "3-Baja de cliente\n"
			   "4-Crear pedido de recoleccion\n"
			   "5-Procesar residuos\n"
			   "6-Imprimir Clientes\n"
			   "7-Imprimir pedidos pendientes\n"
			   "8-Imprimir pedidos procesados\n"
			   "20-Salir\n");

		getInt(&opcion,"Ingrese una opción:\n","Error",0,20,3);

		switch(opcion)
		{

		case 1: getString(bCliente.nombreEmpresa,"Ingrese nombre de empresa:\n","Error",3,50,3);
				getString(bCliente.cuit,"Cuit?:\n","Error",3,50,3);
				getString(bCliente.direccion, "Direccion?\n","Error",3,50,3);
				getString(bCliente.localidad, "Localidad?\n","Error",3,50,3);
				altaClientePorId(aClientes,QTY_CLIENTES,bCliente);
				printf("Alta exitosa!\n");
				break;

		case 2: imprimirArrayClientes(aClientes,QTY_CLIENTES);
				getInt(&bCliente.idCliente, "Ingrese el ID a modificar:\n","Error",0,101,3);
				if(buscarClientePorId(aClientes,QTY_CLIENTES,bCliente.idCliente)){
					printf("Cliente seleccionado: %d - %s\n", bCliente.idCliente, aClientes[bCliente.idCliente].nombreEmpresa);
				}
				getString(bCliente.direccion,"Ingrese nueva direccion: \n", "Error", 3, 40, 3);
				getString(bCliente.localidad,"Ingrese nueva localidad: \n", "Error", 3, 40, 3);
				modificarClientePorId(aClientes,QTY_CLIENTES,bCliente);
				printf("Cliente modificado!\n");
				break;

		case 3: imprimirArrayClientes(aClientes,QTY_CLIENTES);
				getInt(&bCliente.idCliente, "Ingrese el ID a eliminar:\n","Error",0,101,3);
				if(buscarClientePorId(aClientes,QTY_CLIENTES,bCliente.idCliente)){
				printf("Cliente seleccionado: %d - %s\n", bCliente.idCliente, aClientes[bCliente.idCliente].nombreEmpresa);
				} else {
					printf("Cliente no encontrado\n");
				}
				getInt(&respuesta,"Desea eliminar? 1-si 2-no\n","Error",0,3,3);
				if(respuesta == 1)
				{
					bajaClientePorId(aClientes,QTY_CLIENTES,bCliente.idCliente);
					printf("Baja exitosa!\n");
				}
				break;

		case 4: imprimirArrayClientes(aClientes,QTY_CLIENTES);
				getInt(&bPedido.idCliente, "Ingrese el ID del cliente:\n","Error",0,101,3);
				if(buscarClientePorId(aClientes,QTY_CLIENTES,bPedido.idCliente)){
					printf("Cliente seleccionado: %d - %s\n", bPedido.idCliente, aClientes[bPedido.idCliente].nombreEmpresa);
				} else {
					printf("Cliente no encontrado\n");
				}
				getInt(&bPedido.cantidadKilos,"Ingrese cantidad de kilos a recolectar: \n","Error",0,100000,3);
				altaPedidoPorId(aPedidos,QTY_PEDIDOS,bPedido);
				printf("Pedido de recoleccion creado! \n");
				break;

		case 5: imprimirArrayPedidos(aPedidos,QTY_PEDIDOS);
				getInt(&bPedido.idPedido,"Ingrese el id del pedido:\n","Error",-1,1001,3);
				if(buscarPedidoPorId(aPedidos,QTY_PEDIDOS,bPedido.idPedido))
				{
					printf("Pedido seleccionado: Id - %d\n", bPedido.idPedido);
				} else {
					printf("Pedido no encontrado\n");
				}
				getInt(&bPedido.cantidadHDPE, "Cantidad de HDPE? (Polietileno de alta densidad)\n","Error",0,100000,3);
				getInt(&bPedido.cantidadLDPE, "Cantidad de LDPE? (POlietileno de baja densidad)\n","Error",0,100000,3);
				getInt(&bPedido.cantidadPP, "Cantidad de PP?(Polipropileno)\n","Error",0,100000,3);
				procesarResiduos(aPedidos,QTY_PEDIDOS,bPedido);
				printf("Residuo procesado!\n");
				break;

		case 7: imprimirPedidosPendientes(aPedidos,QTY_PEDIDOS,aClientes,QTY_CLIENTES);
				break;

		case 8: imprimirPedidosProcesados(aPedidos,QTY_PEDIDOS,aClientes,QTY_CLIENTES);
				break;
		}





	} while (opcion != 20);



	printf("CLIENTES\n");
	imprimirArrayClientes(aClientes,QTY_CLIENTES);
	printf("PEDIDOS\n");
	imprimirArrayPedidos(aPedidos,QTY_PEDIDOS);




	return EXIT_SUCCESS;
}


void test(struct sClientes p[], int cantidad)
{
	char aEmpresa[][50]={"Andes","Imperial","Planta Nuclear","American Dad","Family Guy"};
	char aCuit[][50]={"30-13122314-8","30-23674657-8","30-24354653-2","30-15975364-8","30-12345678-9"};
	char aDireccion[][50]={"Florida 123","Peron 600","Av. Boedo 234", "Calle falsa 123", "Siempre viva 90"};
	char aLocalidad[][50]={"CABA","Moron","CABA","Springfield","Avellaneda"};
	struct sClientes bCliente;
	int i;
	for(i=0;i<5;i++){
		strncpy(bCliente.nombreEmpresa,aEmpresa[i],50);
		strncpy(bCliente.cuit,aCuit[i],50);
		strncpy(bCliente.direccion,aDireccion[i],50);
		strncpy(bCliente.localidad,aLocalidad[i],50);

		altaClientePorId(p, QTY_CLIENTES, bCliente);
	}

}
