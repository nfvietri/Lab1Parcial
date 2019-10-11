#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "pedidos.h"

static int generarId(void)
{
	static int id = -1;
	id++;
	return id;
}

int initLugarLibreClientes(struct sClientes *aArray, int cantidad){
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

int imprimirArrayClientes(struct sClientes *aClientes, int cantidad){
	int i;
	int retorno = -1;



	if(aClientes != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			if(aClientes[i].status != 0)
			{



				printf("Id: %d // Status: %d // Empresa: %s // Cuit: %s // Direccion: %s // Localidad: %s\n",
									aClientes[i].idCliente,
									aClientes[i].status,
									aClientes[i].nombreEmpresa,
									aClientes[i].cuit,
									aClientes[i].direccion,
									aClientes[i].localidad);
			}




		}
	}
	return retorno;
}

int buscarLugarLibreClientes(struct sClientes *aArray, int cantidad)
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

int altaClientePorId(struct sClientes *aArray, int cantidad,struct sClientes cliente)
{
	int retorno = -1;
	int index;

	if(buscarLugarLibreClientes(aArray,QTY_CLIENTES) != -1)
	{
		index = buscarLugarLibreClientes(aArray,cantidad);
		aArray[index] = cliente;
		aArray[index].status = STATUS_NOT_EMPTY;
		aArray[index].idCliente = generarId();
		retorno = 0;
	}

	return retorno;
}

int modificarClientePorId(struct sClientes *aArray, int cantidad,struct sClientes cliente)
{
	int retorno;
	int i;

	for(i=0;i<cantidad;i++)
	{
		if(aArray[i].idCliente == cliente.idCliente)
		{
			retorno = 0;
			strncpy(aArray[i].direccion, cliente.direccion, 50);
			strncpy(aArray[i].localidad, cliente.localidad, 50);
			break;
		}
	}

	return retorno;
}

int buscarClientePorId(struct sClientes *aArray, int cantidad,int id)
{
	int retorno = -1;
	int i;

	if(aArray != NULL && cantidad > 0)
	{
		for(i=0; i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_NOT_EMPTY)
			{
				if(aArray[i].idCliente == id)
				{
					retorno = i;
					break;
				}

			}

		}
	}

	return retorno;
}

int bajaClientePorId(struct sClientes *aArray, int cantidad,int id)
{
	int retorno = -1;
	int i;

	if(aArray != NULL && cantidad > 0)
	{
		retorno = 0;
		for(i=0; i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_NOT_EMPTY)
			{
				if(aArray[i].idCliente == id)
				{
					retorno = 0;
					aArray[i].status = STATUS_EMPTY;
					break;
				}
			}
		}


	}

	return retorno;
}

int cantPedidosPendientesPorId(int id, struct sPedidos *aArray, int cantPedidos);

