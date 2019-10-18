

#ifndef INFORMES_H_
#define INFORMES_H_
#include "clientes.h"
#include "pedidos.h"

int clienteConMasPedidosPendientes(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes);

int clienteConMasPedidosCompletados(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes);

int clienteConMasPedidos(struct sPedidos * arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes);

int clienteQueRecicloMasKilos(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes);

int clienteQueRecicloMenosKilos(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes);

int clientesQueReciclaronMasDe1000(struct sPedidos *arrayPedidos, int cantidadPedidos, struct sClientes *arrayClientes);

#endif
