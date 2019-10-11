#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedidos.h"



static int generarId(void)
{
	static int id = -1;
	id++;
	return id;
}


int initLugarLibrePedidos(struct sPedidos *aArray, int cantidad){
	int retorno = -1;
	int i;

	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0; i<cantidad; i++)
		{
			aArray[i].status = STATUS_EMPTY;
		}
	}

	return retorno;
}

int imprimirArrayPedidos(struct sPedidos *aArray, int cantidad){
	int i;
	int retorno = -1;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status != 0)
			{
				printf("Id: %d // Status: %d // Cantidad de kilos: %d // Estado: %s // IdCliente: %d\n",
									aArray[i].idPedido,
									aArray[i].status,
									aArray[i].cantidadKilos,
									aArray[i].estado,
									aArray[i].idCliente);
			}




		}
	}
	return retorno;
}

int buscarLugarLibrePedidos(struct sPedidos *aArray, int cantidad)
{
	int index = -1;
	int i;

	if(aArray != NULL && cantidad > 0)
	{
		for(i=0; i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_EMPTY)
			{
				index = i;
				break;
			}

		}

	}

	return index;
}

int altaPedidoPorId(struct sPedidos *aArray, int cantidad,struct sPedidos pedido)
{
	int retorno = -1;
	int index;

	if(buscarLugarLibrePedidos(aArray,QTY_PEDIDOS) != -1)
	{
		index = buscarLugarLibrePedidos(aArray,cantidad);
		aArray[index] = pedido;
		aArray[index].status = STATUS_NOT_EMPTY;
		strncpy(aArray[index].estado, "Pendiente",50);
		aArray[index].idPedido = generarId();
		retorno = 0;
	}

	return retorno;
}

int buscarPedidoPorId(struct sPedidos *aArray, int cantidad,int id)
{
	int retorno = -1;
	int i;

	if(aArray != NULL && cantidad > 0)
	{
		for(i=0; i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_NOT_EMPTY)
			{
				if(aArray[i].idPedido == id)
				{
					retorno = i;
					break;
				}

			}

		}
	}

	return retorno;
}

int procesarResiduos(struct sPedidos *aArray, int cantidad, struct sPedidos pedido)
{
	int retorno = -1;
	int index;

	if(aArray != NULL && cantidad > 0)
	{
		retorno = 0;
		index = buscarPedidoPorId(aArray,QTY_PEDIDOS,pedido.idPedido);
		aArray[index].cantidadHDPE = pedido.cantidadHDPE;
		aArray[index].cantidadLDPE = pedido.cantidadLDPE;
		aArray[index].cantidadPP = pedido.cantidadPP;
		pedido.cantidadBasura = aArray[index].cantidadKilos - aArray[index].cantidadHDPE - aArray[index].cantidadLDPE - aArray[index].cantidadPP;
		aArray[index].cantidadBasura = pedido.cantidadBasura;
		strncpy(aArray[index].estado, "Completado", 50);

	}

	return retorno;
}

int imprimirPedidosPendientes(struct sPedidos *aArray, int cantidadPedidos, struct sClientes *arrayClientes, int cantidadClientes)
{
	int retorno = -1;
	int i;

	if((aArray != NULL && cantidadPedidos > 0) && (arrayClientes != NULL && cantidadClientes > 0))
	{
		retorno = 0;

		for(i=0;i<cantidadPedidos;i++)
		{
			if(strncmp(aArray[i].estado, "Pendiente", 50) == 0)
			{

				printf("Id Pedido: %d // Estado: %s // Cuit cliente: %s // Direccion: %s // Cantidad kilos: %d\n",
						aArray[i].idPedido,
						aArray[i].estado,
						arrayClientes[aArray[i].idCliente].cuit,
						arrayClientes[aArray[i].idCliente].direccion,
						aArray[i].cantidadKilos
						);
			}
		}
	}


	return retorno;
}

int imprimirPedidosProcesados(struct sPedidos *aArray,int cantidadPedidos, struct sClientes *arrayClientes, int cantidadClientes)
{
	int retorno = -1;
	int i;

	if((aArray != NULL && cantidadPedidos > 0) && (arrayClientes != NULL && cantidadClientes > 0))
		{
			retorno = 0;

			for(i=0;i<cantidadPedidos;i++)
			{
				if(strncmp(aArray[i].estado, "Completado", 50) == 0)
				{

					printf("Id Pedido: %d // Estado: %s // Cuit cliente: %s // Direccion: %s // Cantidad kilos: %d\n",
							aArray[i].idPedido,
							aArray[i].estado,
							arrayClientes[aArray[i].idCliente].cuit,
							arrayClientes[aArray[i].idCliente].direccion,
							aArray[i].cantidadKilos);
				}
			}
		}

	return retorno;
}
