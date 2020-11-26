/*
 * Venta.h
 *
 *  Created on: 21 nov. 2020
 *      Author: Nahuel
 */

#ifndef VENTA_H_
#define VENTA_H_
#define IDVENTA_LEN 128
#define IDCLIENTE_LEN 128
#define CANTAFICHES_LEN 128
#define NOMBREARCH_LEN 128
#define ZONA_LEN 128
#define ESTADO_LEN 128
#define A_COBRAR 1
#define COBRADO 0
#define ZONA_SUR 1
#define ZONA_OESTE 2
#define CABA 3

typedef struct
{
	int idVenta;
	int idCliente;
	int cantAfiches;
	char nombreArchivo[NOMBREARCH_LEN];
	int zona;
	int estado;
}Venta;

/**
 * @brief Busca espacio en memoria para una Venta.
 *
 * @return Retorna NULL si no encuentra espacio o una Venta.
 */
Venta* Venta_new();

/**
 * @brief Busca espacio en memoria para una Venta y le carga datos que trae desde el archivo.
 *
 * @param idVentaStr Recibe el id de tipo texto que trae del archivo.
 * @param idClienteStr Recibe el id cliente de tipo texto que trae del archivo.
 * @param cantAfichesStr Recibe la cantidad de fiches de tipo texto que trae del archivo.
 * @param nombreArchivoStr Recibe el nombre de tipo texto que trae del archivo.
 * @param zonaStr Recibe la zona de tipo de texto que trae del archivo.
 * @param estadoStr Recibe el estado de tipo texto que teae del archivo.
 * @return Retorna NULL si no encuentra espacio o una Venta cargada.
 */
Venta* Venta_newParametros(char* idVentaStr,char* idClienteStr,char*cantAfichesStr,char* nombreArchivoStr,char* zonaStr,char* estadoStr);

/**
 * @brief Setea el id de Venta en el campo IdVenta.
 *
 * @param pVenta Recibe una venta.
 * @param idVenta Recibe el Id a cargar.
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_setIdVentaChar(Venta* pVenta,char* idVenta);

/**
 * @brief Setea el id de Venta en el campo IdVenta.
 *
 * @param pVenta Recibe una venta.
 * @param idVenta Recibe un Id de tipo char que luego es casteado a int.
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_setIdVentaInt(Venta* pVenta,int idVenta);

/**
 * @brief Obtiene el id de la venta.
 *
 * @param pVenta Recibe una venta.
 * @param idVenta Recibe la direccion de memoria donde se va a guardar el dato pedido.
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_getVentaId(Venta* pVenta,int* idVenta);

/**
 * @brief Setea el campo idCliente de Venta.
 *
 * @param pVenta Recibe una venta.
 * @param idCliente Recbie el dato a guardar.
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_setIdClienteChar(Venta* pVenta,char* idCliente);

/**
 * @brief Setea el campo idCliente de Venta.
 *
 * @param pVenta Recibe una venta.
 * @param idCliente Recibe el dato a guardar.
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_setIdClienteInt(Venta* pVenta,int idCliente);

/**
 * @brief Obtiene el id de cliente de venta.
 *
 * @param pVenta Recibe una venta.
 * @param idCliente Recibe la direccion de memoria donde se va a guardar el dato pedido.
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_getIdCliente(Venta* pVenta,int* idCliente);

/**
 * @brief Setea la cantidad de afiches en venta.
 *
 * @param pVenta Recibe una venta.
 * @param cantAfiches Recibe el dato a guardar.
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_setCantAfichesChar(Venta* pVenta,char* cantAfiches);

/**
 * @brief Setea la cantidad de afiches en venta.
 *
 * @param pVenta Recibe una venta.
 * @param cantAfiches Recibe el dato a guardar.
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_setCantAfichesInt(Venta* pVenta,int cantAfiches);

/**
 * @brief Obtiene la cantidad de afiches.
 *
 * @param pVenta Recibe una venta.
 * @param cantAfiches Recibe la direccion de memoria donde se va a guardar el dato pedido.
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_getCantAfiches(Venta* pVenta,int* cantAfiches);

/**
 * @brief Setea el nombre del archivo
 *
 * @param pVenta Recibe una venta.
 * @param nombreArchivo Recibe el dato a guardar.
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_setNombreArchivo(Venta* pVenta,char* nombreArchivo);

/**
 * @brief Obtiene el nombre del archivo.
 *
 * @param pVenta Recibe una venta.
 * @param nombreArchivo Recibe la direccion de memoria donde se va a guardar el dato pedido.
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_getNombreArchivo(Venta* pVenta,char* nombreArchivo);

/**
 * @brief Setea la zona.
 *
 * @param pVenta Recibe una venta.
 * @param zona Recibe el dato a guardar.
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_setZonaChar(Venta* pVenta,char* zona);

/**
 * @brief Setea la zona.
 *
 * @param pVenta Recibe una venta.
 * @param zona Recibe el dato a guardar.
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_setZonaInt(Venta* pVenta,int zona);

/**
 * @brief Obtiene la zona.
 *
 * @param pVenta Recibe una venta.
 * @param zona Recibe la direccion de memoria donde se va a guardar el dato pedido.
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_getZona(Venta* pVenta,int* zona);

/**
 * @brief Setea el estado.
 *
 * @param pVenta Recibe una venta.
 * @param estado Recibe el dato a guardar.
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_setEstadoChar(Venta* pVenta,char* estado);

/**
 * @brief Setea el estado.
 *
 * @param pVenta Recibe una venta.
 * @param estado Recibe el dato a guardar
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_setEstadoInt(Venta* pVenta,int estado);

/**
 * @brief Obtiene el estado.
 *
 * @param pVenta Recibe una venta.
 * @param estado Recibe la direccion de memoria donde se va a guardar el dato pedido.
 * @return Retorna -1 si hubo error o 0 si esta todo 0k.
 */
int Venta_getEstado(Venta* pVenta,int* estado);

/**
 * @brief Muestra la cabecera de los datos de venta.
 *
 */
void Venta_CabeceraListar(void);

/**
 * @brief Lista las ventas.
 *
 * @param pElement Recibe un puntero a void para poder usarla como un puntero a funcion.
 * @return
 */
int Venta_Listar(void* pElement);

/**
 * @brief Borra una venta.
 *
 * @param pElement Recibe una venta.
 */
void Venta_delete(Venta* pElement);

#endif /* VENTA_H_ */
