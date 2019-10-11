
#ifndef CLIENTES_H_
#define CLIENTES_H_
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1
#define QTY_CLIENTES 100

struct sClientes {

	int idCliente;
	int status;

	char nombreEmpresa[50];
	char cuit[50];
	char direccion[50];
	char localidad[50];

};

int initLugarLibreClientes(struct sClientes *aArray, int cantidad);

int imprimirArrayClientes(struct sClientes *aClientes, int cantidad);

int buscarLugarLibreClientes(struct sClientes *aArray, int cantidad);

int altaClientePorId(struct sClientes *aArray, int cantidad,struct sClientes cliente);

int modificarClientePorId(struct sClientes *aArray, int cantidad,struct sClientes cliente);

int buscarClientePorId(struct sClientes *aArray, int cantidad,int id);

int bajaClientePorId(struct sClientes *aArray, int cantidad,int id);


#endif
