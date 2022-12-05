#include <stdio.h>
#include <stdlib.h>

struct nodo{
    struct nodo* hijo_izq;
    struct nodo* hijo_der;
    int dato;
};

struct nodo* nuevoNodo(int dato){
    size_t tam_nodo = sizeof(struct nodo); //size_t es un tipo de dato y sizeof mide el tamaño del struct
    struct nodo* nuevo_nodo = (struct nodo*) malloc(tam_nodo); //mallo = memory allocation, aloja un valor en nuevo_nodo
    nuevo_nodo -> dato = dato;
    nuevo_nodo -> hijo_izq = NULL;
    nuevo_nodo -> hijo_der = NULL;
    return nuevo_nodo;
}

void insertarNodo(struct nodo* nd, int dato){
    if(dato > nd->dato){
        if(nd -> hijo_der == NULL){
            nd -> hijo_der = nuevoNodo(dato);
        }else{
            insertarNodo(nd -> hijo_der, dato);
        }
    }else{
        if(nd -> hijo_izq == NULL){
            nd -> hijo_izq = nuevoNodo(dato);
        }else{
            insertarNodo(nd -> hijo_izq, dato);
        }
    }
}
void preorden(struct nodo* nd) {
    if (nd != NULL) {
        printf("%d,",nd ->dato);
        preorden(nd -> hijo_izq);
        preorden(nd->hijo_der);
    }
}
void inorden(struct nodo *nd) {
    if (nd != NULL) {
        inorden(nd->hijo_izq);
        printf("%d,", nd->dato);
        inorden(nd->hijo_der);
    }
}
void postorden(struct nodo *nd) {
    if (nd != NULL) {
        postorden(nd->hijo_izq);
        postorden(nd->hijo_der);
        printf("%d,", nd->dato);
    }
}
void imprimirArbol (struct nodo *nd){
    if (nd != NULL){
        imprimirArbol (nd ->hijo_izq);
        printf ("%d, ", nd -> dato);
        imprimirArbol (nd ->hijo_der);
    }
}
struct nodo * buscar(struct nodo *nd,int valor){
    if (nd == NULL){
        return NULL;
    }else{
        if (valor == nd->dato){
            return nd;
        }else{
            if (valor < nd->dato){
                return buscar (nd->hijo_izq, valor);
            }else{
                return buscar (nd->hijo_der, valor);
            }
        }
    }
}
int alturaArbolNodo (struct nodo* nd, int valor){
    int altura=0;
    struct nodo* actual= nd;
    while (actual!=NULL){
        if (valor == actual->dato){           
            return altura;
        }else{
            altura++;
            if (valor < actual->dato){               
                actual=actual->hijo_izq;
            }else{
                if (valor > actual->dato){               
                    actual=actual->hijo_der;
                }
            }
        }
    }
printf("\nNo existe ese valor en el nodo.\n");
return 0;
}
int main(){
    struct nodo* raiz = NULL;
    int valor;
    raiz = nuevoNodo(8);
    insertarNodo(raiz, 6);
    insertarNodo(raiz, 3);
    insertarNodo(raiz, 4);
    insertarNodo(raiz, 3);
    insertarNodo(raiz, 1);
    insertarNodo(raiz, 8);
    insertarNodo(raiz, 5);
    insertarNodo(raiz, 12);
    insertarNodo(raiz, 21);
    imprimirArbol(raiz);
    printf("\nIngrese el numero que desea buscar:");
    scanf("%d",&valor);
    struct nodo *buscador = buscar(raiz, valor);
    if (buscador == NULL)
    {
        printf("%d no existe en el árbol\n", valor);
    }
    else
    {
        printf("%d sí existe en el árbol\n", valor);
    }
    int altura = alturaArbolNodo(raiz,valor);
    printf("\nLa altura del nodo es:%d",altura);
}
