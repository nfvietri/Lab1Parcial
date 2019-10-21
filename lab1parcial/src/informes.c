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

int clienteQueRecicloMasKilos(struct sClientes *arrayClientes, int cantidadClientes, struct sPedidos *arrayPedidos, int cantidadPedidos)
{
	int retorno = -1;
	int i;
	int maximo;
	int idMaximo;

	if((arrayClientes != NULL && cantidadClientes > 0) && (arrayPedidos != NULL && cantidadPedidos > 0))
	{
		retorno = 0;
		for(i=0;i<cantidadClientes;i++)
		{
			if(i==0)
			{
				maximo = cantidadKilosRecicladosPorCliente(arrayPedidos,cantidadPedidos,arrayClientes[i].idCliente);
				idMaximo = arrayClientes[i].idCliente;
			} else {
				if(cantidadKilosRecicladosPorCliente(arrayPedidos,cantidadPedidos,arrayClientes[i].idCliente) > maximo)
				{
					maximo = cantidadKilosRecicladosPorCliente(arrayPedidos,cantidadPedidos,arrayClientes[i].idCliente);
					idMaximo = arrayClientes[i].idCliente;
				}
			}
		}
		if(maximo == 0)
		{
			printf("d)No hay pedidos reciclados\n");
		} else {
			printf("d)Cliente que reciclo mas kilos: %s\n", arrayClientes[idMaximo].nombreEmpresa);
		}
	}
	return retorno;
}

int clientesQueReciclaronMasDe1000(struct sClientes *arrayClientes, int cantidadClientes, struct sPedidos *arrayPedidos, int cantidadPedidos)
{
	int retorno = -1;
	int i;
	int cantidad = 0;

	if((arrayClientes != NULL && cantidadClientes > 0) && (arrayPedidos != NULL && cantidadPedidos > 0))
	{
		retorno = 0;
		for(i=0;i<cantidadClientes;i++)
		{
			if(arrayClientes[i].status != 0)
			{
				if(cantidadKilosRecicladosPorCliente(arrayPedidos, cantidadPedidos, arrayClientes[i].idCliente) > 1000)
				{
					cantidad++;
				}
			}
		}
		printf("f)Clientes que reciclaron m�s de 1000: %d\n", cantidad);
	}
	return retorno;
}

int imprimirPedidosProcesadosConPorcentaje(struct sPedidos *aArray,int cantidadPedidos, struct sClientes *arrayClientes, int cantidadClientes)
{
	int retorno = -1;
	int i;
	int kilosTotales;
	float porcentajeReciclado;

	kilosTotales = totalKilosReciclados(aArray,cantidadPedidos);

	if((aArray != NULL && cantidadPedidos > 0) && (arrayClientes != NULL && cantidadClientes > 0))
		{
			for(i=0;i<cantidadPedidos;i++)
			{
				if(strncmp(aArray[i].estado, "Completado", 50) == 0)
				{
					porcentajeReciclado = (float) (aArray[i].cantidadHDPE + aArray[i].cantidadLDPE + aArray[i].cantidadPP) / kilosTotales;
					retorno = 0;
					printf("h)");
					printf("Id: %d // Cuit: %s // Porcentaje reciclado: %f\n",
							aArray[i].idPedido,
							arrayClientes[aArray[i].idCliente].cuit,
							porcentajeReciclado);
				}
			}
		}
	if(retorno != 0)
	{
		printf("h)No hay pedidos procesados\n");
	}

	return retorno;
}

int cantidadKilosPolipropilenoPromedio(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes,int cantidadClientes)
{
	int retorno = -1;
	int i;
	int clientesActivos = 0;
	int totalKilos;
	float promedio;

	totalKilos = totalKilosPolipropileno(arrayPedidos,cantidadPedidos);

	if((arrayPedidos != NULL && cantidadPedidos > 0) && (arrayClientes != NULL && cantidadClientes > 0))
	{
		retorno = 0;
		for(i=0;i<cantidadClientes;i++)
		{
			if(arrayClientes[i].status != 0)
			{
				clientesActivos++;
			}
		}
		promedio = (float) totalKilos / (float) clientesActivos;
	}
	printf("j)Total kilos: %d // clientes activos: %d // promedio: %f\n",totalKilos,clientesActivos, promedio);

	return retorno;
}

int clientesQueReciclaronMenosDe100(struct sClientes *arrayClientes, int cantidadClientes, struct sPedidos *arrayPedidos, int cantidadPedidos)
{
	int retorno = -1;
	int i;
	int contador = 0;
	int cantidadKilos;

	if((arrayClientes != NULL && cantidadClientes > 0) && (arrayPedidos != NULL && cantidadPedidos > 0))
	{
		retorno = 0;
		for(i=0;i<cantidadClientes;i++)
		{
			if(arrayClientes[i].status != 0)
			{
				cantidadKilos = cantidadKilosRecicladosPorCliente(arrayPedidos,cantidadPedidos,arrayClientes[i].idCliente);

				if(cantidadKilos > 0 && cantidadKilos < 100)
				{
					contador++;
				}
			}

		}
		printf("g)Cantidad de clientes que reciclaron menos de 100: %d\n",contador);
	}
	return retorno;
}

int pedidosPendientesDeUnaLocalidad(struct sClientes *arrayClientes, int cantClientes, struct sPedidos *arrayPedidos, int cantPedidos, char *localidad)
{
	int retorno = -1;
	int i;
	int contador = 0;

	if((arrayClientes != NULL && cantClientes > 0) && (arrayPedidos != NULL && cantPedidos > 0))
	{
		retorno = 0;
		for(i=0;i<cantClientes;i++)
		{
			if(strncmp(arrayClientes[i].localidad, localidad, 50) == 0)
			{
				contador = contador + cantidadPedidosPendientes(arrayPedidos,cantPedidos,arrayClientes[i].idCliente);
			}
		}

		printf("Cantidad de pedidos pendientes en %s: %d\n",localidad,contador);
	}

	return retorno;
}

int clienteQueRecicloMenosKilos(struct sClientes *arrayClientes, int cantidadClientes, struct sPedidos *arrayPedidos, int cantidadPedidos)
{
	int retorno = -1;
	int i;
	int flag = 1;
	int cantKilos;
	int minimo = 0;
	int idMinimo;

	if((arrayClientes != NULL && cantidadClientes > 0) && (arrayPedidos != NULL && cantidadPedidos > 0))
	{
		retorno = 0;
		for(i=0;i<cantidadClientes;i++)
		{
			if(arrayClientes[i].status != 0)
			{
				cantKilos = cantidadKilosRecicladosPorCliente(arrayPedidos,QTY_PEDIDOS,arrayClientes[i].idCliente);

				if(cantKilos > 0 && flag == 1)
				{
					flag = 0;
					minimo = cantKilos;
					idMinimo = arrayClientes[i].idCliente;
				}
				if(flag == 0 && cantKilos < minimo && cantKilos != 0)
				{
					minimo = cantKilos;
					idMinimo = arrayClientes[i].idCliente;
				}
			}
		}
		if(minimo == 0)
		{
			printf("e)No hay pedidos reciclados\n");
		} else {
			printf("e)Cliente que reciclo menos: %s\n",arrayClientes[idMinimo].nombreEmpresa);
		}
	}
	return retorno;
}

int cantidadDeKilosDeUnTipoPorCuit(struct sClientes *arrayClientes, int cantClientes, struct sPedidos *arrayPedidos,int cantPedidos, char *cuit, char *plastico)
{
	int retorno = -1;
	int i;
	int idCliente;
	int cantKilos = 0;

	if((arrayClientes != NULL && cantClientes > 0) && (arrayPedidos != NULL && cantPedidos > 0))
	{
		retorno = 0;
		idCliente = buscarClientePorCuit(arrayClientes,cantClientes,cuit);

		for(i=0;i<cantPedidos;i++)
		{
			if(arrayPedidos[i].idCliente == idCliente)
			{
				if(strncmp(plastico, "PP", 50) == 0)
				{
					cantKilos = arrayPedidos[i].cantidadPP;
					break;
				} else if(strncmp(plastico, "HDPE", 50) == 0)
				{
					cantKilos = arrayPedidos[i].cantidadHDPE;
					break;
				} else if ((strncmp(plastico, "LDPE", 50) == 0))
				{
					cantKilos = arrayPedidos[i].cantidadLDPE;
				}

			}
		}
		printf("K)Cantidad de kilos del plastico ingresado: %d\n",cantKilos);
	}
	return retorno;
}
