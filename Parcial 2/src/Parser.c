/*
 * Parser.c
 *
 *  Created on: 21 nov. 2020
 *      Author: Nahuel
 */
#include <stdio.h>
#include <stdlib.h>
#include "Parser.h"
#include "LinkedList.h"
#include "Cliente.h"
#include "Venta.h"

int parser_ClienteDeTexto(FILE* pArchivo , LinkedList* listaDeClientes)
{
	int retorno=-1;
	char cabecera[51];
	char idCliente[ID_LEN];
	char nombre[NOMBRE_LEN];
	char apellido[APELLIDO_LEN];
	char cuit[CUIT_LEN];
	Cliente* pCliente;


	if(pArchivo!=NULL && listaDeClientes!=NULL)
	{

		fscanf(pArchivo,"%[^\n]\n",cabecera);
		do
		{

			if(fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",idCliente,nombre,apellido,cuit)==4)
			{

				pCliente=Cliente_newParametros(idCliente,nombre,apellido,cuit);
				if(pCliente!=NULL)
				{

					ll_add(listaDeClientes,pCliente);
					retorno=0;
				}
			}
		}while(!feof(pArchivo));
	}

	return retorno;
}

int parser_VentaDeTexto(FILE* pArchivo , LinkedList* listaDeVentas)
{
	int retorno=-1;
	char cabecera[51];
	char idVenta[IDVENTA_LEN];
	char idCliente[IDCLIENTE_LEN];
	char cantAfiches[CANTAFICHES_LEN];
	char nombreArchivo[NOMBREARCH_LEN];
	char zona[ZONA_LEN];
	char estado[ESTADO_LEN];
	Venta* pVenta;


	if(pArchivo!=NULL && listaDeVentas!=NULL)
	{

		fscanf(pArchivo,"%[^\n]\n",cabecera);
		do
		{

			if(fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVenta,idCliente,cantAfiches,nombreArchivo,zona,estado)==6)
			{

				pVenta=Venta_newParametros(idVenta,idCliente,cantAfiches, nombreArchivo,zona,estado);
				if(pVenta!=NULL)
				{
					ll_add(listaDeVentas,pVenta);
					retorno=0;
				}
			}
		}while(!feof(pArchivo));
	}
	return retorno;
}
