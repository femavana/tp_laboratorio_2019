#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
LinkedList* this=(LinkedList*)malloc(sizeof(LinkedList));

   if(this!=NULL)
    {
    	this->size=0;
    	this->pFirstNode=NULL;
    }

return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
int ret=-1;

    if(this!=NULL)
    {
    	ret=this->size;
    }

return ret;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)

{

Node* pNode=NULL;
int i;
int size=ll_len(this);

        if(this!=NULL && nodeIndex >=0 && nodeIndex <size)
	    {
		  pNode=this->pFirstNode;

		for(i=0;i<nodeIndex;i++)
		{
		    if(pNode!=NULL)
           {
		      pNode=pNode->pNextNode;
		   }
	    }
       }

 return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
 int ret=-1;
 Node* pNode=(Node*)malloc(sizeof(Node));
 Node* pAuxNode;
 int size=ll_len(this);

    if(this != NULL)
    {
    	if(pNode !=NULL && nodeIndex >=0 && nodeIndex <=size)
    	{
    	  if(nodeIndex ==0)
    	  {
               pNode->pNextNode=this->pFirstNode;
               this->pFirstNode=pNode;
               pNode->pElement=pElement;
               this->size++;
               ret=0;
    	  }
    	  else
    	  {
    	      pAuxNode=getNode(this,nodeIndex-1);
    	      pNode->pNextNode=pAuxNode->pNextNode;
    	      pAuxNode->pNextNode=pNode;
    	      pNode->pElement=pElement;
    	      this->size++;
    	      ret=0;
    	  }

        }
    }

 return ret;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
 int ret=-1;
 int size=ll_len(this);

      if(this !=NULL)
    {
      if(!addNode(this,size,pElement))
      {
       ret=0;
      }
    }

return ret;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
void* ret=NULL;
int size=ll_len(this);
Node* pNode;

    if(this !=NULL && index >=0 && index <=size)
    {
    	 pNode=getNode(this,index);
          if(pNode !=NULL)
         {
    	   ret=pNode->pElement;
         }
    }

return ret;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
 int ret=-1;
 int size=ll_len(this);
 Node* pNode;

    if(this !=NULL)
    {
       if(index >=0 && index <=size)
       {
         pNode=getNode(this,index);
         if(pNode !=NULL)
         {
    	 pNode->pElement=pElement;
    	 ret=0;
         }
       }
    }

return ret;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	 int ret=-1;
	 Node* pNode=(Node*)malloc(sizeof(Node));
	 Node* pAuxNode;
	 int size=ll_len(this);

	    if(this != NULL)
	    {
	    	if(pNode !=NULL && index >=0 && index <size)
	    	{
	    	  if(index ==0)
	    	  {
	    	       this->pFirstNode=pNode->pNextNode;
	               free(pNode);
	               this->size--;
	    	  }
	    	  else
	    	  {
	    		  pNode=getNode(this,index);
	    		  pAuxNode=getNode(this,index-1);
	    		  pAuxNode->pNextNode=pNode->pNextNode;
	    		  free(pNode);
	    	      this->size--;
	    	  }
	    	  ret=0;
	        }
	    }

return ret;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
 int ret=-1;
 int i;
 int size=ll_len(this);
 Node* pNode;

    if(this!=NULL)
    {
    	for(i=0;i<size;i++)
    	{
    	  pNode=ll_get(this,i);
    	  ll_remove(this,i);
    	  free(pNode);
    	}
    	ret=0;
    }

return ret;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
int ret=-1;

    if(this!=NULL)
    {
    	ll_clear(this);
    	free(this);
    	ret=0;
    }

return ret;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
 int ret=-1;
 int size=ll_len(this);
 Node* pNode;
 int i;

    if(this !=NULL)
    {
    	for(i=0;i<size;i++)
    	{
    	   pNode=getNode(this,i);
	     if(pNode->pElement==pElement)
	     {
	       ret=i;
	       break;
	     }
    	}
    }
return ret;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
 int ret=-1;
 int size=ll_len(this);

    if(this !=NULL)
    {
    	if(size>0)
    	{
    	  ret=0;
    	}
    	else
    	{
          ret=1;
    	}
    }

return ret;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	 int ret=-1;
	 int size=ll_len(this);

	    if(this!=NULL)
	    {
	      if(index >=0 && index <=size)
	      {

	      if(!addNode(this,size,pElement))
	      {
	       ret=0;
	      }
	      }
	    }

return ret;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
void* ret=NULL;
int size=ll_len(this);

         if(this!=NULL)
        {
         if(index >=0 && index <size)
         {
          	  ret=ll_get(this,index);
          	  ll_remove(this,index);
         }
        }

return ret;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
int ret=-1;
int i;
int size=ll_len(this);
Node* pNode=NULL;

     if(this!=NULL)
     {
       for(i=0;i<=size;i++)
       {
    	 pNode=getNode(this,i);
        if(pNode !=NULL && pElement == pNode->pElement)
        {
          ret=1;
          break;
        }
        else
        {
          ret=0;
        }
       }
     }

return ret;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
int ret=-1;
int i;
int returnAux;
Node* pNode=NULL;
int size=ll_len(this2);


     if(this!=NULL && this2!=NULL)
     {
    	 for(i=0;i<size;i++)
    	 {
    		 pNode=getNode(this2,i);
    		 if(pNode !=NULL)
    	    {
    			 returnAux=ll_contains(this,pNode->pElement);
    	    }
         }

    	 if(returnAux == 1)
    	 {
    		 ret=1;
    	 }
    	 else
    	 {
    		 ret=0;
    	 }
     }

return ret;
}
/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
LinkedList* cloneArray=NULL;
int i;
void* pElement=NULL;
int size=ll_len(this);

       if(this !=NULL)
       {
    	  if((from >=0 && from <=size) && (to >=from && to <=size))
    	  {
    	   cloneArray=ll_newLinkedList();
    	   for(i=from;i<to;i++)
    	   {
    		 pElement=ll_get(this,i);
    		 if(pElement !=NULL)
    		 {
    		  ll_add(cloneArray,pElement);
    	     }
    	   }
          }
       }

return cloneArray;
}


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
LinkedList* cloneArray = NULL;
int size=ll_len(this);

         if(this !=NULL)
         {
        	 cloneArray=ll_subList(this,0,size);
         }

return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
*/
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int ret =-1;
    int i;
	int j;
	int size=ll_len(this);
    void* pElement1=NULL;
    void* pElement2=NULL;
    void* pAux=NULL;
    int   returnAux;

       if(this!=NULL && pFunc!=NULL &&(order==0 || order==1))
       {
           for(i=0; i<size-1; i++)
           {
               pElement1=ll_get(this,i);
               for(j=i+1; j<size; j++)
               {
                   pElement2=ll_get(this,j);
                   if(pElement1 !=NULL && pElement2 !=NULL)
                   {
                	returnAux=pFunc(pElement1,pElement2);
                   if(order==1 && returnAux ==1)
                   {
                           pAux=pElement1;
                           pElement1=pElement2;
                           pElement2=pAux;
                   }
                   else if(order==0 && returnAux ==-1)
                   {
                           pAux=pElement2;
                           pElement2=pElement1;
                           pElement1=pAux;
                   }
                   ll_set(this,j,pElement2);
                   ll_set(this,i,pElement1);
                  }
              }
          }
           ret=0;
       }

return ret;
}
