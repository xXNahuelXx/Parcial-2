/*
 * Informes.c
 *
 *  Created on: 21 nov. 2020
 *      Author: Nahuel
 */
#include <stdio.h>
#include <stdlib.h>
#include "Informes.h"


int Informe_GenerarInfoDeCobros(LinkedList* listaC,LinkedList* listaV,int (*pFunc)(void*),int estado)
{
	LinkedList* listaClonada;
	Cliente* pCliente;
	int i;
	int retorno=-1;
	int cont=0;
	int bufferIdCliente;
	if(listaC!=NULL && listaV!=NULL)
	{
		listaClonada=ll_clone(listaV);
		if(listaClonada!=NULL)
		{
			if(ll_filter(listaClonada,pFunc)==0)
			{
				for(i=0;i<ll_len(listaC);i++)
				{
					pCliente=(Cliente*)ll_get(listaC,i);
					if(pCliente!=NULL)
					{
						Cliente_getId(pCliente,&bufferIdCliente);
						Informes_CantVentasxCli(listaClonada,bufferIdCliente,&cont);
						if(estado==A_COBRAR)
						{
							Cliente_setCantVentasACobrar(pCliente,cont);
						}
						else if(estado==COBRADO)
						{
							Cliente_setCantVentasCobradas(pCliente,cont);
						}
						retorno=0;
					}
				}
			}
		}
		ll_deleteLinkedList(listaClonada);
	}
	return retorno;
}

int Informes_CantVentasxCli(LinkedList* listaClonada,int id, int* cont)
{
	int i;
	int retorno=-1;
	int bufferIdClienteEnVenta;
	Venta* pVenta;
	if(listaClonada!=NULL && id>0 && cont!=NULL)
	{
		for(i=0;i<ll_len(listaClonada);i++)
		{
			pVenta=(Venta*)ll_get(listaClonada,i);
			if(pVenta!=NULL)
			{
				Venta_getIdCliente(pVenta,&bufferIdClienteEnVenta);
				if(id==bufferIdClienteEnVenta)
				{
					(*cont)++;
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

int Informes_GuardarCobradas(char* ruta,LinkedList* lista)
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
			fprintf(pArchivo,"ID,NOMBRE,APELLIDO,CUIT,COBRADAS\n");
			for(i=0;i<len;i++)
			{
				pCliente=(Cliente*)ll_get(lista,i);
				if(pCliente!=NULL)
				{
					Cliente_getId(pCliente,&bufferCliente.idCliente);
					Cliente_getNombre(pCliente,bufferCliente.nombre);
					Cliente_getApellido(pCliente,bufferCliente.apellido);
					Cliente_getCuit(pCliente,bufferCliente.cuit);
					Cliente_getCantVentasCobradas(pCliente,&bufferCliente.cantVentasCobradas);
					fprintf(pArchivo,"%d,%s,%s,%s,%d\n",bufferCliente.idCliente,bufferCliente.nombre,bufferCliente.apellido,bufferCliente.cuit,bufferCliente.cantVentasCobradas);
				}
			}
			retorno=0;
			fclose(pArchivo);
		}
	}
	return retorno;
}

int Informes_GuardarACobrar(char* ruta,LinkedList* lista)
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
			fprintf(pArchivo,"ID,NOMBRE,APELLIDO,CUIT,A COBRAR\n");
			for(i=0;i<len;i++)
			{
				pCliente=(Cliente*)ll_get(lista,i);
				if(pCliente!=NULL)
				{
					Cliente_getId(pCliente,&bufferCliente.idCliente);
					Cliente_getNombre(pCliente,bufferCliente.nombre);
					Cliente_getApellido(pCliente,bufferCliente.apellido);
					Cliente_getCuit(pCliente,bufferCliente.cuit);
					Cliente_getCantVentasACobrar(pCliente,&bufferCliente.cantVentasACobrar);
					fprintf(pArchivo,"%d,%s,%s,%s,%d\n",bufferCliente.idCliente,bufferCliente.nombre,bufferCliente.apellido,bufferCliente.cuit,bufferCliente.cantVentasACobrar);
				}
			}
			retorno=0;
			fclose(pArchivo);
		}
	}
	return retorno;
}

void* Informes_contDeAfiches(LinkedList* listV,LinkedList* listC, int* cant,int caso)
{
	int max;
	int min;
	int i;
	Cliente* pClient;
	int bufferId;
	int acum;
	void* retorno;

	for(i = 0; i < ll_len(listC);i++)
	{
		acum = 0;
		pClient = ll_get(listC,i);
		Cliente_getId(pClient,&bufferId);
		acum = ll_reduceInt2(listV,ClienteyVenta_CompararAfichesCargados,&bufferId);
		if((i == 0 || acum > max) && caso==1)
		{
			max = acum;
			*cant = max;
			retorno = pClient;
		}
		else if((i == 0 || acum < min) && caso==0)
		{
			min = acum;
			*cant = min;
			retorno = pClient;
		}
	}
	return retorno;
}

void* Informes_VentasConMasAfichesVendidos(LinkedList* listV, int* cant,int caso)
{
	int max;
	int min;
	int i;
	Venta* pVenta;
	int cantAfiches;
	int estado;
	void* retorno;

	for(i = 0; i < ll_len(listV);i++)
	{
		pVenta=ll_get(listV,i);
		Venta_getCantAfiches(pVenta,&cantAfiches);
		Venta_getEstado(pVenta,&estado);

		if((i == 0 || cantAfiches > max) && caso==1 && estado==COBRADO)
		{
			max = cantAfiches;
			*cant = max;
			retorno = pVenta;
		}
		else if((i == 0 || cantAfiches < min) && caso==0  && estado==COBRADO)
		{
			min = cantAfiches;
			*cant = min;
			retorno = pVenta;
		}
	}
	return retorno;
}
