#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "canciones.h"
#include "usuario.h"
#include "playlist.h"
///ARREGLODELISTAS
int alta(stCelda ADL[],int validos,stUsuario A,stCancion C);
int pasarArchivoToADL(char ArchivoUsuario[],stCelda ADL[]);
void mostrarADL(stCelda ADL [],int validos);
void cargarArchivoDecanciones(char ArchivoCancion []);
void cargarArchivoDeUsuario( char ArchivoUsuario[]);
void cargarPlaylistArchivo(char Archivoplaylist[]);
void mostrarArchivoPlaylist(char Archivoplaylist[],stPlaylist nuevaPlaylist);
int pasarArchivoPlaylistToADL(char Archivoplaylist[], stCelda ADL[], int validos, nodoArbolCancion *arbol);
void mostrarADL(stCelda ADL [],int validos);
int main()
{
    stCancion C;
    stUsuario A;
    stPlaylist nuevaPlaylist;
    //cargarArchivoDecanciones("cancion.dat");
    //MostrarArchivoCanciones("cancion.dat", C);
    cargarArchivoDeUsuario("usuario.dat");
    mostrarArchivoUsuario("usuario.dat",A);
    cargarPlaylistArchivo("playlist.dat");
    mostrarArchivoPlaylist("playlist.dat", nuevaPlaylist);



    menu();
    return 0;
}


void menu()
{
    stUsuario A;
    stCancion C;
    int validos = 0;
    int user, login, adm, listusuarios,usua;
    int idUsuario;
    char admin[20];
    char contraAdmin[20];

    stCelda* ADL = malloc((validos + 1) * sizeof(stCelda));


    do
    {
        puts("\n-----------------Gestion Musica-------------------------");
        printf("\n\nElija el tipo:(1/2/3/0): \n\n1. Administrador\n2. Usuario\n3. Registrarse\n0. Salir\n\nModo de usuario: ");
        fflush(stdin);
        scanf("%d", &user);
        system("cls");

        switch(user)
        {
        case 1: // Modo Administrador
            printf("Usuario de Admin: \n");
            fflush(stdin);
            scanf("%s",admin);
            if(strcmp(admin,"A")==0)
            {
                printf("\nIngrese contraseña: \n");
                scanf("%s",contraAdmin);
                if(strcmp(contraAdmin,"B")==0)
                {
                    system("cls");
                    puts("\n-_-_-_-_-_-_-_-");
                    printf("Bienvenido Admin\n");
                    do
                    {
                        printf("Elija donde acceder(1/2/0): \n\n1. Usuarios\n2. Canciones\n0. Regresar\n\nOpcion: ");
                        fflush(stdin);
                        scanf("%d", &adm);
                        system("cls");

                        switch(adm)
                        {
                        case 1:
                            do
                            {
                                printf("Admin->Usuario\n");
                                printf("Que quiere hacer(1/2/3/4/5/0): \n\n1. Alta\n2. Baja\n3. Modificacion\n5.Consulta\n6.Listados\n0. Regresar\n\nOpcion: ");
                                fflush(stdin);
                                scanf("%d", &usua);
                                system("cls");
                                switch(usua)
                                {

                                case 1: //Alta Usuario

                                    printf("ingrese el IdUsuario a dar de alta: \n");
                                    scanf("%i",&idUsuario);
                                    int buscar=buscarUsuarioPorID("usuario.dat",idUsuario);
                                    if(buscar==1)
                                    {
                                        A=mostrarDatosUsuarioBuscado("usuario.dat",idUsuario);
                                        if(A.eliminado==0)
                                        {
                                            altaLogicaUsuario("usuario.dat",idUsuario);
                                            printf("Usuario reactivado correctamente.\n");
                                        }
                                    }
                                    else
                                    {
                                        char t='s';
                                        printf("\nUsuario inexistente.\n\n");
                                        printf("desea registrarlo?(s/n)\n");
                                        scanf(" %c",&t);
                                        if(t=='s')
                                        {
                                            A=cargarUnusuario();
                                            cargarUnusuarioArchivo("usuario.dat",A);
                                            printf("Usuario registrado exitosamente.\n");
                                        }
                                    }
                                    system("pause");
                                    system("cls");
                                    break;
                                case 2: //Baja Usuario
                                    printf("ingrese el IdUsuario a dar de baja: \n");
                                    scanf("%i",&idUsuario);
                                    buscar=buscarUsuarioPorID("usuario.dat",idUsuario);
                                    if(buscar==1)
                                    {
                                        A=mostrarDatosUsuarioBuscado("usuario.dat",idUsuario);
                                        if(A.eliminado==1)
                                        {
                                            bajaLogicaUsuario("usuario.dat",idUsuario);
                                            printf("Usuario desactivado correctamente.\n");
                                        }
                                    }
                                    else
                                    {
                                        printf("\nUsuario inexistente.\n\n");
                                    }
                                    system("pause");
                                    system("cls");
                                    break;
                                case 6:
                                    // Muestra todos los usuarios registrados en el sistema
                                    mostrarArchivoUsuario("usuario.dat", A);
                                    system("pause");
                                    system("cls");

                                    switch(usua)
                                    case 2:
                                    printf("Admin->Canciones\n");
                                    printf("Que quiere hacer(1/2/3/4/5/0): \n\n1. Alta\n2. Baja\n3. Modificacion\n5.Consulta\n6.Listados\n0. Regresar\n\nOpcion: ");
                                    fflush(stdin);
                                    scanf("%d", &adm);
                                    system("cls");
                                    // Muestra todas las canciones registrados en el sistema
                                    MostrarArchivoCanciones("cancion.dat", C);
                                    system("pause");
                                    system("cls");
                                    break;
                                case 0://regresar
                                    break;

                                default:
                                    printf("Opción no válida.\n");
                                    system("pause");
                                    system("cls");
                                    break;
                                }
                            }
                            while (usua != 0);
                            break;

                        case 2: // Modo Administrador - Canciones
                            printf("Admin -> Canciones\n");
                            printf("Mostrando todas las canciones registradas en el sistema:\n");
                            MostrarArchivoCanciones("cancion.dat", C);
                            system("pause");
                            system("cls");
                            break;

                        case 0: // Regresar
                            break;

                        default:
                            printf("Opción no válida.\n");
                            system("pause");
                            system("cls");
                            break;
                        }
                    }
                    while (adm != 0);
                }
                else
                {
                    printf("Contraseña incorrecta.\n");
                    system("pause");
                    system("cls");
                }
            }
            else
            {
                printf("Usuario de administrador incorrecto.\n");
                system("pause");
                system("cls");
            }
            break;

        case 2: // Modo Usuario
            printf("Modo Usuario aún no implementado.\n");
            system("pause");
            system("cls");
            break;

        case 3: // Registrarse
            printf("Funcionalidad de registro aún no implementada.\n");
            system("pause");
            system("cls");
            break;

        case 0: // Salir
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opción no válida.\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while (user != 0);

}
int alta(stCelda ADL[],int validos,stUsuario A,stCancion C)
{
    nodoListaCancion* aux=crearNodo(C);
    int pos=buscarPosUsuario(ADL,A.idUsuario,validos);
    if(pos==-1)
    {
        A=cargarUnusuario();
        validos=agregarUsuario(ADL,A,validos);
        pos=validos-1;
    }
    ADL[pos].listaCanciones=AgregarEnOrdenPorNombreCancion(ADL[pos].listaCanciones,aux);
    return validos;
}

void cargarPlaylistArchivo(char Archivoplaylist[])
{
    FILE* archi=fopen("playlist.dat","ab");
    char control='s';
    stPlaylist nuevaPlaylist;
    int i=0;

    if(archi)
    {
        while(control=='s')
        {
            nuevaPlaylist.idPlaylist=i;
            printf("Ingrese el id del Usuario: ");
            fflush(stdin);
            scanf("%i", &nuevaPlaylist.idUsuario);

            int buscar=buscarUsuarioPorID("usuario.dat",nuevaPlaylist.idUsuario);
            if(buscar==1)

            {
                printf("Ingrese el id de la Cancion: ");
                fflush(stdin);
                scanf("%i", &nuevaPlaylist.idCancion);
                fwrite(&nuevaPlaylist, sizeof(stPlaylist), 1, archi);
                i++;
            }
            else
            {
                printf("\nUsuario inexistente");

            }
            printf("\ncargar otro?(s)\n");
            fflush(stdin);
            scanf(" %c",&control);

        }
    }
    fclose(archi);
}
void mostrarArchivoPlaylist(char Archivoplaylist[],stPlaylist nuevaPlaylist)
{
    FILE* archi=fopen("playlist.dat","rb");

    {
        if(archi)
        {
            while(fread(&nuevaPlaylist,sizeof(stPlaylist),1,archi)>0)
            {



                printf("IdPlaylits: %i\n",nuevaPlaylist.idPlaylist);
                printf("IdUsuario: %i\n",nuevaPlaylist.idUsuario);
                printf("IdCancion: %i\n",nuevaPlaylist.idCancion);
                printf("-----------------------------\n");
            }
        }
        fclose(archi);
    }
}

int pasarArchivoPlaylistToADL(char Archivoplaylist[], stCelda ADL[], int validos, nodoArbolCancion *arbol)
{
    stUsuario A;
    stCancion C;
    FILE *archi = fopen("playlist.dat", "rb");
    if (archi)
    {

        stPlaylist playlist;
        while (fread(&playlist, sizeof(stPlaylist), 1, archi) > 0)
        {

            int pos = buscarPosUsuario(ADL, playlist.idUsuario, validos);

            if (pos == -1)
            {
                validos=alta(ADL,validos,A,C);
            }
            nodoArbolCancion *cancionBuscada = buscarCancion(arbol,playlist.idCancion);

            if (cancionBuscada != NULL)
            {
                nodoListaCancion *nuevaCancion = crearNodo(cancionBuscada->dato);


                ADL[pos].listaCanciones = AgregarEnOrdenPorNombreCancion(ADL[pos].listaCanciones,nuevaCancion);
            }
        }
        fclose(archi);
    }

    return validos;
}

void mostrarADL(stCelda ADL [],int validos)
{
    int i=0;
    for(i; i<validos; i++)
    {
        printf("\nIdUsuario:%i ",ADL[i].A.idUsuario);
        printf("\nNombre de Usuario: %s ",ADL[i].A.nombreUsuario);
        nodoListaCancion* aux=ADL[i].listaCanciones;
        if(aux!=NULL)
        {
            while(aux!=NULL)
            {

                printf("\nIdCancion: %i",aux->dato.idCancion);
                printf("\nCancion: %s",aux->dato.titulo);
                aux=aux->siguiente;
            }
        }
        else
        {
            printf("EL usuario no tiene canciones\n");

        }
    }
}

void cargarArchivoDecanciones(char ArchivoCancion [])
{
    FILE* archi=fopen("cancion.dat","ab");
    char control='s';
    stCancion C;
    if(archi)
    {
        while(control=='s')
        {
            C=cargarUnaCancion();
            fwrite(&C,sizeof(stCancion),1,archi);
            printf("cargar mas?(s)\n");
            fflush(stdin);
            scanf("%c",&control);
        }
    }
    fclose(archi);
}

void cargarArchivoDeUsuario( char ArchivoUsuario[])
{
    FILE* archi=fopen("usuario.dat","ab");
    char control='s';
    stUsuario A;
    if(archi)
    {
        while(control=='s')
        {
            A=cargarUnusuario();
            fwrite(&A,sizeof(stUsuario),1,archi);
            printf("cargar mas?(s)\n");
            fflush(stdin);
            scanf(" %c",&control);
        }
    }
    fclose(archi);
}

