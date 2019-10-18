#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "informes.h"
#include "clientes.h"
#include "pedidos.h"
#include "utn.h"


int clienteConMasPedidosPendientes(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes)
{
	int retorno = -1;
	int i;
	int maximo;
	int idMaximo;

	if(arrayPedidos != NULL && cantidadPedidos > 0){
		retorno = 0;

		for(i=0;i<cantidadPedidos;i++)
		{
			if(i==0)
			{
				maximo = cantidadPedidosPendientes(arrayPedidos,cantidadPedidos,arrayPedidos[i].idCliente);
				idMaximo = arrayPedidos[i].idCliente;
			} else {
				if(cantidadPedidosPendientes(arrayPedidos,cantidadPedidos,arrayPedidos[i].idCliente) > maximo)
				{
					maximo = cantidadPedidosPendientes(arrayPedidos,cantidadPedidos,arrayPedidos[i].idCliente);
					idMaximo = arrayPedidos[i].idCliente;
				}
			}
		}
		printf("a)Cliente con más pedidos pendientes: Id-%d, Nombre-%s, Cuit-%s\n",
				arrayClientes[idMaximo].idCliente,
				arrayClientes[idMaximo].nombreEmpresa,
				arrayClientes[idMaximo].cuit);
	}
	return retorno;
}

int clienteConMasPedidosCompletados(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes)
{
	int retorno = -1;
	int i;
	int maximo;
	int idMaximo;

		if(arrayPedidos != NULL && cantidadPedidos > 0){
			retorno = 0;

			for(i=0;i<cantidadPedidos;i++)
			{
				if(i==0)
				{
					maximo = cantidadPedidosCompletados(arrayPedidos,cantidadPedidos,arrayPedidos[i].idCliente);
					idMaximo = arrayPedidos[i].idCliente;
				} else {
					if(cantidadPedidosCompletados(arrayPedidos,cantidadPedidos,arrayPedidos[i].idCliente) > maximo)
					{
						maximo = cantidadPedidosCompletados(arrayPedidos,cantidadPedidos,arrayPedidos[i].idCliente);
						idMaximo = arrayPedidos[i].idCliente;
					}
				}
			}
			if(maximo == 0)
			{
				printf("b)No existen pedidos completados\n");
			} else {
				printf("b)Cliente con más pedidos completados: Id-%d, Nombre-%s, Cuit-%s\n",
								arrayClientes[idMaximo].idCliente,
								arrayClientes[idMaximo].nombreEmpresa,
								arrayClientes[idMaximo].cuit);
			}

		}
	return retorno;
}

int clienteConMasPedidos(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes)
{
	int retorno = -1;
	int i;
	int maximo;
	int idMaximo;

	if((arrayPedidos != NULL && cantidadPedidos > 0) && arrayClientes != NULL)
	{
		retorno = 0;
		for(i=0;i<cantidadPedidos;i++)
		{
			if(i==0)
			{
				maximo = cantidadPedidosPorCliente(arrayPedidos,cantidadPedidos,arrayPedidos[i].idCliente);
				idMaximo = arrayPedidos[i].idCliente;
			} else {
				if((cantidadPedidosPorCliente(arrayPedidos,cantidadPedidos,arrayPedidos[i].idCliente) > maximo))
				{
					maximo = cantidadPedidosPorCliente(arrayPedidos,cantidadPedidos,arrayPedidos[i].idCliente);
					idMaximo = arrayPedidos[i].idCliente;
				}
			}
		}
		printf("c)Cliente con más pedidos: %s, Cantidad de pedidos: %d\n", arrayClientes[idMaximo].nombreEmpresa, maximo);

	}
	return retorno;
}

int clienteQueRecicloMasKilos(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes)
{
	int retorno = -1;
	int i;
	int maximo;
	int idMaximo;

	for(i=0;i<cantidadPedidos;i++)
	{
		if(i==0)
		{
			maximo = cantidadKilosPorCliente(arrayPedidos,cantidadPedidos,arrayPedidos[i].idCliente);
			idMaximo = arrayPedidos[i].idCliente;
		} else {
			if(cantidadKilosPorCliente(arrayPedidos,cantidadPedidos,arrayPedidos[i].idCliente) > maximo)
			{
				maximo = cantidadKilosPorCliente(arrayPedidos,cantidadPedidos,arrayPedidos[i].idCliente);
				idMaximo = arrayPedidos[i].idCliente;
			}
		}
	}

	printf("d)Cliente que recicló más kilos: %s\n", arrayClientes[idMaximo].nombreEmpresa);
	retorno = 0;

	return retorno;
}

int clienteQueRecicloMenosKilos(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes)
{
	int retorno = -1;
	int i;
	int minimo;
	int idMinimo;

	for(i=0;i<cantidadPedidos;i++)
	{
		if(i==0)
		{
			minimo = cantidadKilosPorCliente(arrayPedidos,cantidadPedidos,arrayPedidos[i].idCliente);
			idMinimo = arrayPedidos[i].idCliente;
		} else {
			if(cantidadKilosPorCliente(arrayPedidos,cantidadPedidos,arrayPedidos[i].idCliente) < minimo)
			{
				minimo = cantidadKilosPorCliente(arrayPedidos,cantidadPedidos,arrayPedidos[i].idCliente);
				idMinimo = arrayPedidos[i].idCliente;
			}
		}
	}

	printf("e)Cliente que recicló menos kilos: %s\n", arrayClientes[idMinimo].nombreEmpresa);
	retorno = 0;

	return retorno;
}

int clientesQueReciclaronMasDe1000(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes)
{
	int retorno = -1;
	int i;
	int cantidad = 0;

	if((arrayPedidos != NULL && cantidadPedidos > 0) && arrayClientes != NULL)
	{
		retorno = 0;
		for(i=0;i<cantidadPedidos;i++)
		{
			if(cantidadKilosPorCliente(arrayPedidos,cantidadPedidos,arrayPedidos[i].idCliente) > 1000)
			{
				cantidad++;
			}

		}
		printf("f)Cantidad que reciclaron más de 1000 kilos: %d\n", cantidad);
	}
	return retorno;
}

int cantidadPedidosPorLocalidad(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes, char *localidad)
{
	int retorno = -1;
	int i;



	return retorno;


}
