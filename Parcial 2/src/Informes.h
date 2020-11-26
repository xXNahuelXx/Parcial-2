/*
 * Informes.h
 *
 *  Created on: 21 nov. 2020
 *      Author: Nahuel
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "Cliente&Venta.h"

/**
 * @brief Genera el informa de Cobros.
 *
 * @param listaC Recibe la lista de Clientes.
 * @param listaV Recibe la lista de Ventas.
 * @param pFunc Recibe un puntero a funcion que sirve de criterio para el filter.
 * @param estado Recibe un estado que es para generar el informe del estado COBRADAS o A_COBRAR.
 * @return Retorna -1 si hubo error o 0 si todo 0k.
 */
int Informe_GenerarInfoDeCobros(LinkedList* listaC,LinkedList* listaV,int (*pFunc)(void*),int estado);

/**
 * @brief Cuenta la cantidad de Ventas por Cliente.
 *
 * @param listaClonada Recibe una lista clonada.
 * @param id Recibe el id a comparar si existe o no.
 * @param cont Recibe un puntero al contador.
 * @return Retorna -1 si hubo error o 0 si todo 0k.
 */
int Informes_CantVentasxCli(LinkedList* listaClonada,int id, int* cont);

/**
 * @brief Guarda las cantidad de ventas Cobradas.
 *
 * @param ruta Recibe la ruta donde se guarda el archivo.
 * @param lista Recibe la lista de Clientes.
 * @return Retorna -1 si hubo error o 0 si todo 0k.
 */
int Informes_GuardarCobradas(char* ruta,LinkedList* lista);

/**
 * @brief Guarda la cantidad de ventas A Cobrar.
 *
 * @param ruta Recibe la ruta donde se guarda el archivo.
 * @param lista Recibe la lista de Clientes.
 * @return Retorna -1 si hubo error o 0 si todo 0k.
 */
int Informes_GuardarACobrar(char* ruta,LinkedList* lista);

/**
 * @brief Devuelve un maximo de la cantidad de afiches cobrados.
 *
 * @param listV Recibe la lista de Ventas.
 * @param cant Recibe un puntero a la cantidad.
 * @param caso Recibe el caso en que se quiera el minimo o el maximo.
 */
void* Informes_VentasConMasAfichesVendidos(LinkedList* listV, int* cant,int caso);

/**
 * @brief Cuenta la cantidad de afiches.
 *
 * @param listV Recibe la lista de Ventas.
 * @param listC Recibe la lista de Clientes.
 * @param cant Recibe un puntero a la cantidad.
 * @param caso Recibe el caso en que se quiera el minimo o el maximo.
 */
void* Informes_contDeAfiches(LinkedList* listV,LinkedList* listC, int* cant,int caso);

#endif /* INFORMES_H_ */
