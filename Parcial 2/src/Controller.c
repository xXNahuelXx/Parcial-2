/*
 * Controller.c
 *
 *  Created on: 21 nov. 2020
 *      Author: Nahuel
 */
#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Cliente.h"
#include "Venta.h"

int controller_CargarArchivoDeTexto(char* ruta,LinkedList* lista,int (*pFunc)(FILE*,LinkedList*))
{
	int retorno=-1;
	FILE* pArchivo;
	if(ruta!=NULL && lista!=NULL)
	{
		pArchivo=fopen(ruta,"r");
		if(pArchivo!=NULL)
		{
			if(pFunc(pArchivo,lista)==0)
			{
				retorno=0;
			}
			fclose(pArchivo);
		}
	}
	return retorno;
}

int controller_ListCliente(LinkedList* list)
{
	int retorno=-1;
	if(list!=NULL)
	{
		printf("%5s %15s %15s %15s","ID","NOMBRE","APELLIDO","CUIT\n");
		printf("_____________________________________________________\n");
		ll_map(list,Cliente_Listar);
		retorno=0;
	}
	return retorno;
}

int controller_ListVenta(LinkedList* list)
{
	int retorno=-1;
	if(list!=NULL)
	{
		printf("%5s %15s %15s %15s","ID","NOMBRE","APELLIDO","CUIT\n");
		printf("_____________________________________________________\n");
		ll_map(list,Venta_Listar);
		retorno=0;
	}
	return retorno;
}

int controller_InitId(LinkedList* list,int valor)
{

	int auxId;
	int maxId;
	int i;
	void* pElement;

	if(list!=NULL)
	{
		for(i=0;i<ll_len(list);i++)
		{
			if(valor==1)
			{
				pElement=(Cliente*)ll_get(list,i);
				Cliente_getId(pElement,&auxId);
			}
			else
			{
				pElement=(Venta*)ll_get(list,i);
				Venta_getVentaId(pElement,&auxId);
			}
			if(pElement!=NULL)
			{

				if(i==0 || auxId>maxId)
				{
					maxId=auxId;
				}
			}
		}
		maxId++;
	}
	return maxId;
}

int controller_GuardarArchivoClientes(char* ruta , LinkedList* lista)
{
    int retorno=-1;
    int len;
    int i;
	FILE* pArchivo;
	Cliente* pCliente;
	Cliente bufferCliente;
	if(ruta!=NULL && lista!=NULL)
    {
		pArchivo=fopen(ruta,"w");
		if(pArchivo!=NULL)
		{
			len=ll_len(lista);
			fprintf(pArchivo,"ID,NOMBRE,APELLIDO,CUIT\n");
			for(i=0;i<len;i++)
			{
				pCliente=(Cliente*)ll_get(lista,i);
				if(pCliente!=NULL)
				{
					Cliente_getId(pCliente,&bufferCliente.idCliente);
					Cliente_getNombre(pCliente,bufferCliente.nombre);
					Cliente_getApellido(pCliente,bufferCliente.apellido);
					Cliente_getCuit(pCliente,bufferCliente.cuit);
					fprintf(pArchivo,"%d,%s,%s,%s\n",bufferCliente.idCliente,bufferCliente.nombre,bufferCliente.apellido,bufferCliente.cuit);
				}
			}
			retorno=0;
			fclose(pArchivo);
		}
    }
	return retorno;
}

int controller_GuardarArchivoVentas(char* ruta , LinkedList* lista)
{
    int retorno=-1;
    int len;
    int i;
	FILE* pArchivo;
	Venta* pVenta;
	Venta bufferVenta;
	if(ruta!=NULL && lista!=NULL)
    {
		pArchivo=fopen(ruta,"w");
		if(pArchivo!=NULL)
		{
			len=ll_len(lista);
			fprintf(pArchivo,"IDVENTA,IDCLIENTE,CANTAFICHES,ARCHIVO,ZONA,ESTADO\n");
			for(i=0;i<len;i++)
			{
				pVenta=(Venta*)ll_get(lista,i);
				if(pVenta!=NULL)
				{
					Venta_getVentaId(pVenta,&bufferVenta.idVenta);
					Venta_getIdCliente(pVenta,&bufferVenta.idCliente);
					Venta_getCantAfiches(pVenta,&bufferVenta.cantAfiches);
					Venta_getNombreArchivo(pVenta,bufferVenta.nombreArchivo);
					Venta_getZona(pVenta,&bufferVenta.zona);
					Venta_getEstado(pVenta,&bufferVenta.estado);
					fprintf(pArchivo,"%d,%d,%d,%s,%d,%d\n",bufferVenta.idVenta,bufferVenta.idCliente,bufferVenta.cantAfiches,bufferVenta.nombreArchivo,bufferVenta.zona,bufferVenta.estado);
				}
			}
			retorno=0;
			fclose(pArchivo);
		}
    }
	return retorno;
}
