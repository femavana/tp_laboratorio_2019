//Lista dinamica de punteros
//tipo: void* para usar todo los tipos


LinkedList*  lista;

lista=ll_newLinkedList( );
ll_add(lista,&p);
ll_get(lista,2);
size=ll_len(lista);

Cuando hago add crea un nodo. El nodo tiene dos espacios una para el puntero al elemento y otra para el proximo.

  

LinkedList* ll_newLinkedList(void);//incializador lista
//crea y retorna una nueva lista. Es el constructor se crea la struct y se la valores inciales
int ll_len(LinkedList* this);// retorna el tamaño de la lista
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);// agrega un elemento al final de la lista
void* ll_get(LinkedList* this, int index);// retorma un puntero al elemento que se encuentra en el indice especificado
int ll_set(LinkedList* this, int index,void* pElement);
int ll_remove(LinkedList* this,int index);// elimina un elemento de la lista en el indice especificado
int ll_clear(LinkedList* this);// borra la lista 
int ll_deleteLinkedList(LinkedList* this); // elimina la lista / free
int ll_indexOf(LinkedList* this, void* pElement); // Si la verificación falla o no encuentra el
elemento la función retorna (-1) y si encuentra el elemento retorna su índice.
int ll_isEmpty(LinkedList* this);// Retorna cero si contiene elementos y uno si no los tiene.
int ll_push(LinkedList* this, int index, void* pElement);//cambio en los elementos
void* ll_pop(LinkedList* this,int index);
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);// ordenamiento
