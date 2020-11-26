/*
 * Cliente&Venta.h
 *
 *  Created on: 22 nov. 2020
 *      Author: Nahuel
 */

#ifndef CLIENTE_VENTA_H_
#define CLIENTE_VENTA_H_
#include "Cliente.h"
#include "Venta.h"
#include "LinkedList.h"

/**
 * @brief Da de alta a un cliente.
 *
 * @param lista Recibe una lista.
 * @param id Recibe un id maximo a guardar.
 * @return Retorna NULL si hubo error o un cliente.
 */
Cliente* ClienteyVenta_addCliente(LinkedList* lista,int* id);

/**
 * @brief Da de alta a una venta.
 *
 * @param listC Lista de Clientes.
 * @param listV Lista de Ventas.
 * @param id Recibe el id maximo a guardar.
 * @return Retorna NULL si hubo error o una Venta.
 */
Venta* ClienteyVenta_addVenta(LinkedList* listC,LinkedList* listV,int* id);

/**
 * @brief Buscar por id y devuelve un cliente.
 *
 * @param lista Lista de clientes.
 * @param id Id a buscar.
 * @return Retorna NULL si hubo error o un cliente.
 */
Cliente* ClienteyVenta_BuscarPorIdCliente(LinkedList* lista,int id);

/**
 * @brief Buscar por id y devuelve una venta.
 *
 * @param lista Lista de ventas.
 * @param id Id a biscar.
 * @return Retorna NULL si hubo error o un cliente.
 */
Venta* ClienteyVenta_BuscarPorIdVenta(LinkedList* lista,int id);

/**
 * @brief Verifica que no exista el mismo cuit.
 *
 * @param lista Lista de clientes.
 * @param cuit Cuit a buscar.
 * @return 0 si el cuit no existe, -1 si esta repetido.
 */
int ClienteyVenta_CheckCuit(LinkedList* lista,char* cuit);

/**
 * @brief Funcion criterio a usar para buscar ventas a cobrar.
 *
 * @param pElement Recibe un puntero void a un elemento.
 * @return Retorna 1 cuando sean a cobrar o 0 si no lo son.
 */
int ClienteyVenta_VentasACobrar(void* pElement);

/**
 * @brief Funcion criterio a usar para buscar ventas cobradas.
 *
 * @param pElement Recibe un puntero void a un elemento.
 * @return Retorna 1 cuando sean cobradas o 0 si no lo son.
 */
int ClienteyVenta_VentasCobradas(void* pElement);

/**
 * @brief Modifica una venta.
 *
 * @param listaC Lista de clientes.
 * @param listaV Lista de ventas.
 * @param pFunc Puntero a funcion criterio.
 * @return Retorna -1 si hubo error o 0 si todo 0k.
 */
int ClienteyVenta_ModificarVenta(LinkedList* listaC,LinkedList* listaV,int (*pFunc)(Venta*));

/**
 * @brief Modifica los campos de una venta
 *
 * @param pVenta Recibe una venta.
 * @return Retorna -1 si hubo error, 1 si no hubieron modificaciones o 0 si todo 0k.
 */
int ClienteyVenta_ModificarCamposVenta(Venta* pVenta);

/**
 * @brief Modifica el estado de la venta.
 *
 * @param pVenta Recibe una venta.
 * @return Retorna -1 si hubo error o 0 si todo 0k.
 */
int ClienteyVenta_ModificarEstadoVenta(Venta* pVenta);

/**
 * @brief
 *
 * @param pElement
 * @param arg
 * @return
 */
int ClienteyVenta_CompararAfichesCargados(void* pElement, void* arg);

#endif /* CLIENTE_VENTA_H_ */
