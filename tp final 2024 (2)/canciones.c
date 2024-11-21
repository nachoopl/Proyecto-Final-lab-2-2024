#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "canciones.h"
nodoListaCancion* iniclista()
{
    return NULL;
}

stCancion cargarUnaCancion()
{
    stCancion C;
    printf("\n ingrese el idCancion : ");
    fflush(stdin);
    scanf("%i",&C.idCancion);

    printf("\n ingrese el titulo: ");
    fflush(stdin);
    gets(C.titulo);

    printf("\n ingrese el artista: ");
    fflush(stdin);
    gets(C.artista);

    printf("\n ingrese el album: ");
    fflush(stdin);
    gets(C.album);

    printf("\n ingrese el anio: ");
    fflush(stdin);
    scanf("%i",&C.anio);

    printf("\n ingrese el genero: ");
    fflush(stdin);
    gets(C.genero);

    printf("\n ingrese comentario: ");
    fflush(stdin);
    gets(C.comentario);

    printf("\n ingrese eliminado(1/0): ");
    fflush(stdin);
    scanf("%i",&C.eliminado);
    return C;
}

nodoListaCancion* crearNodo(stCancion dato)
{
    nodoListaCancion*aux=malloc(sizeof(nodoListaCancion));
    aux->dato=dato;
    aux->siguiente=NULL;
    return aux;
}
nodoListaCancion* AgregarAlPrincipio(nodoListaCancion* lista,nodoListaCancion* nuevo)
{

    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
    }
    lista = nuevo;
    return lista;
}

void AgregarAlFinal(nodoListaCancion** lista,nodoListaCancion* nuevo)
{
    if(lista==NULL)

    {
        *lista = nuevo;
    }
    else
    {
        nodoListaCancion* seg = *lista;
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
        seg->siguiente = nuevo;
    }
}

nodoListaCancion* AgregarEnOrdenPorNombreCancion(nodoListaCancion* lista,nodoListaCancion* nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo ;
    }
    if(strcmp(lista->dato.titulo,nuevo->dato.titulo)<0)
    {
        AgregarAlPrincipio(lista, nuevo);
    }
    else
    {
        nodoListaCancion *ante = lista;
        nodoListaCancion *aux = lista;
        while(aux != NULL && strcmp(nuevo->dato.titulo,lista->dato.titulo)>0)
        {
            ante = aux;
            aux = aux->siguiente;
        }
        ante->siguiente = nuevo;
        nuevo->siguiente = aux;
    }
    return lista;
}

void mostrarUnaCancion(stCancion C)
{
    printf("\n idCancion: %i ",C.idCancion);

    printf("\n titulo: %s",C.titulo);

    printf("\n artista:%s ",C.artista);

    printf("\n album: %s",C.album);

    printf("\n anio: %i ",C.anio);

    printf("\n genero:%s ",C.genero);

    printf("\n comentario: %s ",C.comentario);

    printf("\n eliminado(1/0): %i",C.eliminado);
puts("\n---------------------------------------------");
}

void mostrarLista(nodoListaCancion* lista)
{

    while(lista!=NULL)
    {
        mostrarUnaCancion(lista->dato);
        lista = lista->siguiente;
    }

}
nodoListaCancion* buscarEnlistaPorIdCancion(nodoListaCancion* lista,int IdCancion)
{
    nodoListaCancion* seg=lista;
    while(seg)
    {
        if(seg->dato.idCancion==IdCancion)
        {
            return seg;
        }
        seg=seg->siguiente;
    }
    return NULL;
}
nodoListaCancion* borrarNodoPorIdCancion(nodoListaCancion* lista,int IdCancionAborrar)

{

    nodoListaCancion* ante;
    if(lista!=NULL && (IdCancionAborrar==lista->dato.idCancion))
    {
        nodoListaCancion* aux=lista;
        lista=lista->siguiente;
        free(aux);
    }
    else
    {
        nodoListaCancion* aux=lista;
        while(aux!=NULL && (IdCancionAborrar!=aux->dato.idCancion))
        {
            ante = aux;
            aux = aux->siguiente;
        }
        if(aux!=NULL)
        {
            ante->siguiente=aux->siguiente;
            free(aux);
        }

    }
    return lista;
}


nodoArbolCancion * inicarbol()
{
    return NULL;
}

nodoArbolCancion * crearnodoArbol(stCancion dato)
{
    nodoArbolCancion * aux = (nodoArbolCancion*)malloc(sizeof(nodoArbolCancion));
    aux->dato = dato;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

nodoArbolCancion * insertarNodoArbol (nodoArbolCancion * arbol, nodoArbolCancion * nuevo)
{
    if (arbol == NULL)
    {
        arbol = nuevo;
    }
    else
    {
        if(nuevo->dato.idCancion> arbol->dato.idCancion)
        {
            arbol->der = insertarNodoArbol (arbol->der, nuevo);
        }
        else
        {
            arbol->izq = insertarNodoArbol (arbol->izq, nuevo);
        }
    }
    return arbol;
}

void preorder(nodoArbolCancion* arbol)
{
    stCancion  dato;
    if(arbol!=NULL)
    {
        mostrarUnaCancion(arbol->dato);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void inorder(nodoArbolCancion * arbol)
{
    stCancion dato;
    if(arbol != NULL)
    {
        inorder(arbol->izq);
        mostrarUnaCancion(arbol->dato);
        inorder(arbol->der);
    }
}

void postorder(nodoArbolCancion* arbol)
{
    stCancion  dato;
    if(arbol!=NULL)
    {

        preorder(arbol->izq);
        preorder(arbol->der);
        mostrarUnaCancion(arbol->dato);
    }
}
nodoArbolCancion* cargarArbolcancionConArchivo(nodoArbolCancion* arbol,char ArchivoCancion[])
{
    FILE * archi = fopen("cancion.dat","rb");
    stCancion C;
    if(archi)
    {
        while(fread(&C,sizeof(stCancion),1,archi)>0)
        {
            nodoArbolCancion* nuevo=crearNodo(C);
            arbol=insertarNodoArbol(arbol,nuevo);
        }
    }
    fclose(archi);
    return arbol;
}
nodoArbolCancion * buscarCancion(nodoArbolCancion* arbol, int idcancionAbuscar)
{
    nodoArbolCancion * nuevo = NULL;
    if(arbol != NULL)
    {
        if(arbol->dato.idCancion == idcancionAbuscar)
        {
            nuevo = arbol;
        }
        else
        {
            if(idcancionAbuscar > arbol->dato.idCancion)
            {
                nuevo = buscarCancion(arbol->der, idcancionAbuscar);
            }
            else
            {
                nuevo = buscarCancion(arbol->izq, idcancionAbuscar);
            }
        }
    }
    return nuevo;
}

void cargarUnaCancionArchivo(char ArchivoCancion[],stCancion C)
{
    FILE* archi=fopen("cancion.dat","ab");
    if(archi)
    {
        fwrite(&C,sizeof(stCancion),1,archi);
        fclose(archi);
    }
}

void MostrarArchivoCanciones(char ArchivoCancion[],stCancion C)
{

     FILE* archi=fopen("cancion.dat","rb");
    if(archi)
    {
        while(fread(&C,sizeof(stCancion),1,archi)>0)
        {
            mostrarUnaCancion(C);
        }
        fclose(archi);
    }
}

void bajaLogicaCancion(char ArchivoCancion[], int idCancion)
{
    char darBaja;
    do
    {
        printf("Esta seguro que desea dar de baja en el sistema(s/n/0)?\n\ns. Si\nn. No\n0. Regresar\n\nOpcion: ");
        fflush(stdin);
        scanf("%c", &darBaja);
        system("cls");
        switch(darBaja)
        {
        case 's':
            system("cls");
            bajaCancionesArchivo("canciones.dat", idCancion);
            printf("\nLacancion fue dada de baja correctamente\n");
            system("pause");
            system("cls");
            break;
        case 'n':
            system("cls");
            printf("\nDada de baja cancelada.\n");
            system("pause");
            system("cls");
            break;
        case '0':
            system("cls");
            break;
        default:
            printf("Caracter erroneo, ingrese uno valido\n\n");
            break;
        }
    }
    while(darBaja!='0');
}

void bajaCancionesArchivo(char ArchivoCancion[], int idCancion) // Funcion que da de baja un usuario por su dni
{
    FILE* archi=fopen(ArchivoCancion,"r+b");
    stCancion aux;
    if(archi)
    {
        while(fread(&aux, sizeof(stCancion), 1, archi) > 0)
        {
            if(idCancion==aux.idCancion)
            {
                aux.eliminado=0;
                fseek(archi, (-1) * sizeof(stCancion), 1);
        fwrite(&aux, sizeof(stCancion), 1, archi);
        break;
            }
        }

        fclose(archi);
    }
}

void altaLogicaCancion(char ArchivoCancion[], int idCancion)
{
    char darAlta;
    do
    {
        printf("Esta seguro que desea dar de alta en el sistema(s/n/0)?\n\ns. Si\nn. No\n0. Regresar\n\nOpcion: ");
        fflush(stdin);
        scanf("%c", &darAlta);
        system("cls");
        switch(darAlta)
        {
        case 's':
            system("cls");
            altaCancionArchivo("conductor.bin", idCancion);
            printf("\nLa cancion fue dada de alta correctamente\n");
            system("pause");
            system("cls");
            break;
        case 'n':
            system("cls");
            printf("\nDada de alta cancelada.\n");
            system("pause");
            system("cls");
            break;
        case '0':
            system("cls");
            break;
        default:
            printf("Caracter erroneo, ingrese uno valido\n\n");
            break;
        }
    }
    while(darAlta!='0');
}

void altaCancionArchivo(char ArchivoCancion[], int idCancion)
{
    FILE * archi = fopen(ArchivoCancion,"r+b");
    stCancion aux;

    if(archi)
    {
        while(fread(&aux, sizeof(stCancion), 1, archi) > 0)
        {
            if(idCancion == aux.idCancion)
            {
                aux.eliminado = 1;

            }
        }
        fseek(archi, (-1) * sizeof(stCancion), 1);
        fwrite(&aux, sizeof(stCancion), 1, archi);
        fclose(archi);
    }
}

