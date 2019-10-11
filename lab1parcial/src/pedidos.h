
#ifndef PEDIDOS_H_
#define PEDIDOS_H_
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1
#define QTY_PEDIDOS 1000
#include "clientes.h"

struct sPedidos{

	int idPedido;
	int status;

	char estado[50];
	int cantidadKilos;
	int cantidadHDPE;
	int cantidadLDPE;
	int cantidadPP;
	int cantidadBasura;
	int idCliente;

};

int initLugarLibrePedidos(struct sPedidos *aArray, int cantidad);

int imprimirArrayPedidos(struct sPedidos *aArray, int cantidad);

int buscarLugarLibrePedidos(struct sPedidos *aArray, int cantidad);

int altaPedidoPorId(struct sPedidos *aArray, int cantidad,struct sPedidos pedido);

int buscarPedidoPorId(struct sPedidos *aArray, int cantidad,int id);

int procesarResiduos(struct sPedidos *aArray, int cantidad, struct sPedidos pedido);

int imprimirPedidosPendientes(struct sPedidos *aArray, int cantidadPedidos, struct sClientes *arrayClientes, int cantidadClientes);

int imprimirPedidosProcesados(struct sPedidos *aArray,int cantidadPedidos, struct sClientes *arrayClientes, int cantidadClientes);

#endif
