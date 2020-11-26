/*
 * Controller.h
 *
 *  Created on: 21 nov. 2020
 *      Author: Nahuel
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"

/**
 * @brief Llama al parser dentro de esta misma.
 *
 * @param ruta Recibe la ruta del archivo a abrir.
 * @param lista Recibe la lista de Clientes o de Ventas.
 * @param pFunc Recibe un puntero a funcion, en este caso para llamar al parser de Clientes o al de Ventas.
 * @return Retorna -1 si hubo error o 0 si todo 0k.
 */
int controller_CargarArchivoDeTexto(char* ruta,LinkedList* lista,int (*pFunc)(FILE*,LinkedList*));

/**
 * @brief Lista los Clientes.
 *
 * @param list Recibe la lista de Clientes.
 * @return Retorna -1 si hubo error o 0 si todo 0k.
 */
int controller_ListCliente(LinkedList* list);

/**
 * @brief Devuelve un maximo id.
 *
 * @param list Recibe una lista.
 * @param valor Recibe un valor para devolver un maximo Id de Clientes o de Ventas.
 * @return Retorna el maximo Id.
 */
int controller_InitId(LinkedList* list,int valor);

/**
 * @brief Guarda el arhivo de Clientes.
 *
 * @param ruta Recibe la ruta donde see guarda el archivo.
 * @param lista Recibe la lista de Clientes.
 * @return Retorna -1 si hubo error o 0 si todo 0k.
 */
int controller_GuardarArchivoClientes(char* ruta , LinkedList* lista);

/**
 * @brief Guarda el archivo de Ventas.
 *
 * @param ruta Recibe la ruta donde see guarda el archivo.
 * @param lista Recibe la lista de Ventas.
 * @return Retorna -1 si hubo error o 0 si todo 0k.
 */
int controller_GuardarArchivoVentas(char* ruta , LinkedList* lista);

#endif /* CONTROLLER_H_ */
