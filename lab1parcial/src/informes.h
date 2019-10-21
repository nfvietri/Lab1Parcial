

#ifndef INFORMES_H_
#define INFORMES_H_
#include "clientes.h"
#include "pedidos.h"

int clienteConMasPedidosPendientes(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes);

int clienteConMasPedidosCompletados(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes);

int clienteConMasPedidos(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes);

int clienteQueRecicloMasKilos(struct sClientes *arrayClientes, int cantidadClientes, struct sPedidos *arrayPedidos, int cantidadPedidos);

int clientesQueReciclaronMasDe1000(struct sClientes *arrayClientes, int cantidadClientes, struct sPedidos *arrayPedidos, int cantidadPedidos);

int imprimirPedidosProcesadosConPorcentaje(struct sPedidos *aArray,int cantidadPedidos, struct sClientes *arrayClientes, int cantidadClientes);

int cantidadKilosPolipropilenoPromedio(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes,int cantidadClientes);

int clientesQueReciclaronMenosDe100(struct sClientes *arrayClientes, int cantidadClientes, struct sPedidos *arrayPedidos, int cantidadPedidos);

int pedidosPendientesDeUnaLocalidad(struct sClientes *arrayClientes, int cantClientes, struct sPedidos *arrayPedidos, int cantPedidos, char *localidad);

int clienteQueRecicloMenosKilos(struct sClientes *arrayClientes, int cantidadClientes, struct sPedidos *arrayPedidos, int cantidadPedidos);



#endif
