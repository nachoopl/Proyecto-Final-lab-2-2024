#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include "canciones.h"
typedef struct
{
    int idUsuario;
    char nombreUsuario[30];
    char pass[20];
    int anioNacimiento;
    char genero;
    char pais[20];
    int eliminado;   // indica 1 o 0 si el cliente fue eliminado
} stUsuario;
typedef struct
{
    stUsuario A;
    nodoListaCancion * listaCanciones;
} stCelda;
void cargarUnusuarioArchivo(char ArchivoUsuario[],stUsuario A);
int buscarPosUsuario(stCelda ADL[],int IDusuario,int validos);
int agregarUsuario(stCelda ADL[],stUsuario A,int validos);
stUsuario cargarUnusuario();
void mostrarArchivoUsuario(char ArchivoUsuario[],stUsuario A);
void mostrarUsuario(stUsuario A);
stUsuario mostrarDatosUsuarioBuscado(char ArchivoUsuario[], int dato);
int buscarUsuarioPorID(char ArchivoUsuario[], int dato);
#endif // USUARIO_H_INCLUDED
