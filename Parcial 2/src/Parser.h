/*
 * Parser.h
 *
 *  Created on: 21 nov. 2020
 *      Author: Nahuel
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"

/**
 * @brief Trae los datos del archivo Cliente a memoria.
 *
 * @param Recibe le puntero al archivo.
 * @param Recibe la lista de Clientes.
 * @return Retorna -1 si hubo error, 0 si todo 0k.
 */
int parser_ClienteDeTexto(FILE*, LinkedList*);

/**
 * @brief Trae los datos del archivo Venta a memoria.
 *
 * @param Recibe le puntero al archivo.
 * @param Recibe la lista de Ventas.
 * @return Retorna -1 si hubo error, 0 si todo 0k.
 */
int parser_VentaDeTexto(FILE*, LinkedList*);

#endif /* PARSER_H_ */
