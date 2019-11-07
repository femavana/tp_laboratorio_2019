
//crea y retorna una nueva lista. Es el constructor se crea la struct y se la valores inciales
LinkedList* ll_newLinkedList(void)
{
LinkedList* LinkedList = (LinkedList*)malloc(sizeof(LinkedList));
 LinkedList->pFirstnode=0;
 LinkedList->size=2;
// LinkedList->lista = (LinkedList**)malloc(sizeof(LinkedList*)*LinkedList->size); 
}return LinkedList;

// retorna el tamaño de la lista
int ll_len(LinkedList* this)
{

}


Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

// agrega un elemento al final de la lista
int ll_add(LinkedList* this, void* pElement);
{


}

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
