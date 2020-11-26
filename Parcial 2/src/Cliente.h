/*
 * Cliente.h
 *
 *  Created on: 21 nov. 2020
 *      Author: Nahuel
 */
#ifndef CLIENTE_H_
#define CLIENTE_H_
#define ID_LEN 128
#define NOMBRE_LEN 128
#define APELLIDO_LEN 128
#define CUIT_LEN 128

typedef struct
{
	int idCliente;
	char nombre[NOMBRE_LEN];
	char apellido[APELLIDO_LEN];
	char cuit[CUIT_LEN];
	int cantVentasCobradas;
	int cantVentasACobrar;
}Cliente;

/*
 * \brief Pide memoria para un nuevo cliente
 * \param void
 * \return int Return puntero con espacio de memoria con tipo Client*
 */
Cliente* Cliente_new();

/*
 * \brief Pide memoria para un nuevo cliente y setea los campos en el espacio de memoria requerido
 * \param idStr char* id que va a setear
 * \param nameStr char* nombre que va a setear
 * \param lastNameStr char* apellido que va a setear
 * \param cuitStr char* cuit que va a setear
 * \return int Return puntero con espacio de memoria con tipo Client* con los campos ya seteados
 */
Cliente* Cliente_newParametros(char*,char*,char*,char*);

/*
 * \brief Carga el id en el campo del cliente (tratado como texto) y valida que el dato sea correcto
 * \param this Client* puntero a cliente
 * \param id char* puntero al id que va a cargar
 * \return int Return (-1) ERROR - Si el puntero a Client* es NULL o si e puntero al id es NULL
 * 					  (0) EXITO
 */
int Cliente_setIdChar(Cliente*,char*);

/*
 * \brief Carga el id en el campo del cliente
 * \param this Client* puntero a cliente
 * \param id int id a cargar
 * \return int Return (-1) ERROR - Si el puntero a Client* es NULL o si el id no es valido
 * 					  (0) EXITO
 */
int Cliente_setIdInt(Cliente*,int);

/*
 * \brief Obtiene el id del cliente
 * \param this Client* puntero a cliente
 * \param id int* puntero al espacio donde va a guardar el id obtenido
 * \return int Return (-1) ERROR - Si el puntero a Client* es NULL o si e puntero al id es NULL
 * 					  (0) EXITO
 */
int Cliente_getId(Cliente*,int*);

/*
 * \brief Carga el nombre en el campo del cliente y valida que el dato sea correcto
 * \param this Client* puntero a cliente
 * \param name char* puntero al nombre que va a cargar
 * \return int Return (-1) ERROR - Si el puntero a Client* es NULL o si e puntero al nombre es NULL
 * 					  (0) EXITO
 */
int Cliente_setNombre(Cliente*,char*);

/*
 * \brief Obtiene el nombre del cliente
 * \param this Client* puntero a cliente
 * \param name char* puntero al espacio donde va a guardar el nombre obtenido
 * \return int Return (-1) ERROR - Si el puntero a Client* es NULL o si e puntero al nombre es NULL
 * 					  (0) EXITO
 */
int Cliente_getNombre(Cliente*,char*);

/*
 * \brief Carga el apellido en el campo del cliente y valida que el dato sea correcto
 * \param this Client* puntero a cliente
 * \param lastName char* puntero al apellido que va a cargar
 * \return int Return (-1) ERROR - Si el puntero a Client* es NULL o si e puntero al apellido es NULL
 * 					  (0) EXITO
 */
int Cliente_setApellido(Cliente*,char*);

/*
 * \brief Obtiene el apellido del cliente
 * \param this Client* puntero a cliente
 * \param lastName char* puntero al espacio donde va a guardar el apellido obtenido
 * \return int Return (-1) ERROR - Si el puntero a Client* es NULL o si e puntero al apellido es NULL
 * 					  (0) EXITO
 */
int Cliente_getApellido(Cliente*,char*);

/*
 * \brief Carga el cuit en el campo del cliente y valida que el dato sea correcto
 * \param this Client* puntero a cliente
 * \param cuit char* puntero al cuit que va a cargar
 * \return int Return (-1) ERROR - Si el puntero a Client* es NULL o si e puntero al cuit es NULL
 * 					  (0) EXITO
 */
int Cliente_setCuit(Cliente*,char*);

/*
 * \brief Obtiene el cuit del cliente
 * \param this Client* puntero a cliente
 * \param cuit char* puntero al espacio donde va a guardar el cuit obtenido
 * \return int Return (-1) ERROR - Si el puntero a Client* es NULL o si e puntero al cuit es NULL
 * 					  (0) EXITO
 */
int Cliente_getCuit(Cliente*,char*);

/*
 * \brief Carga la cantidad de ventas por estado en el campo del cliente
 * \param this Client* puntero a cliente
 * \param qty int cantidad a cargar
 * \return int Return (-1) ERROR - Si el puntero a Client* es NULL o si la cantidad no es valida
 * 					  (0) EXITO
 */
int Cliente_setCantVentasACobrar(Cliente*,int);

/*
 * \brief Obtiene la cantidad de ventas por estado del cliente
 * \param this Client* puntero a cliente
 * \param qty int* puntero al espacio donde va a guardar la cantidad obtenida
 * \return int Return (-1) ERROR - Si el puntero a Client* es NULL o si e puntero a qty es NULL
 * 					  (0) EXITO
 */
int Cliente_getCantVentasACobrar(Cliente*,int*);

/*
 * \brief Carga la cantidad de ventas por estado en el campo del cliente
 * \param this Client* puntero a cliente
 * \param qty int cantidad a cargar
 * \return int Return (-1) ERROR - Si el puntero a Client* es NULL o si la cantidad no es valida
 * 					  (0) EXITO
 */
int Cliente_setCantVentasCobradas(Cliente* pCliente,int cantVentasCobradas);

/*
 * \brief Obtiene la cantidad de ventas por estado del cliente
 * \param this Client* puntero a cliente
 * \param qty int* puntero al espacio donde va a guardar la cantidad obtenida
 * \return int Return (-1) ERROR - Si el puntero a Client* es NULL o si e puntero a qty es NULL
 * 					  (0) EXITO
 */
int Cliente_getCantVentasCobradas(Cliente* pCliente,int* cantVentasCobradas);

/**
 * @brief Muestra la cabecera de los datos de venta.
 *
 */
void Venta_CabeceraListar(void);

/**
 * @brief Lista los Clientes.
 *
 * @param pElement Recibe un puntero a void para poder usarla como un puntero a funcion.
 * @return Retorna -1 si hubo error, o 0 si todo 0k.
 */
int Cliente_Listar(void* pElement);

/*
 * \brief Libera espacio de memoria de un cliente
 * \param this Client* puntero a cliente
 * \return void
 */
void Cliente_delete(Cliente* pElement);
#endif /* CLIENTE_H_ */
