#include "menu.hpp"
using namespace std;


void Menu::mainMenu(List<Song>& myLista){

    Song myCancion, myCancionAux;
    Date myFecha;
    List<Song>::Position pos;
    string myCadena;
    char opc;
    int op, myEntero;

    do{
    system("cls");
    op=0;
    cout<<"*******************Canciones actualmente cargadas en la lista*******************"<<endl;
        if(myLista.getLastPos()==nullptr){
            cout<<" Actualmente no hay canciones cargadas en la lista"<<endl<<endl;}
        else
            cout<<" N.Cancion N.Artista N.Compositor Duracion Lanzamiento posicion"<<endl;
            cout<<myLista.toString()<<endl<<endl;

            cout<<"*********Lista de canciones para radio*********"<<endl;
            cout<<"Selecciona la opcion que deseas realizar: "<<endl;
            cout<<" 1)Ingresar nueva cancion"<< endl;
            cout<<" 2)Vaciar lista de canciones"<< endl;
            cout<<" 3)Insertar en el punto de interes" << endl;
            cout<<" 4)Eliminar"<<endl;
            cout<<" 5)Localizar"<<endl;//
            cout<<" 6)Buscar por nombre de cancion (lineal) "<<endl;
            cout<<" 7)Buscar por nombre de cancion (binario)" << endl;
            cout<<" 8)Buscar por nombre de autor (lineal)"<<endl;
            cout<<" 9)Buscar por nombre de autor (binario) 10)Salir"<<endl;
            cin>>op;

        switch(op){
            case 1:
                system("cls");
                cout<<"*********Ingresar nueva cancion*********"<<endl;
            do{
                cin.ignore();
                cout<<"Nombre de la cancion: ";
                getline(cin, myCadena);
                myCancion.setNamesong(myCadena);
                cout<<"Nombre de el artista: ";
                getline(cin,myCadena);
                myCancion.setNameartist(myCadena);
                cout<<"Nombre de el compositor: ";
                getline(cin,myCadena);
                myCancion.setNameinterpreter(myCadena);
                cout<<"Duracion de la cancion: ";
                getline(cin,myCadena);
                myCancion.setDurationsong(myCadena);

                cout<<"Fecha de lanzamiento (dd/mm/aaaa): ";
                getline(cin,myCadena,'/');
                myFecha.setDay(stoi(myCadena));
                getline(cin,myCadena,'/');
                myFecha.setMonth(stoi(myCadena));
                getline(cin,myCadena);
                myFecha.setYear(stoi(myCadena));
                myCancion.setReleaseDate(myFecha);

                cout<<"Posicion en el ranking: ";
                cin>>myEntero;
                myCancion.setPositionranking(myEntero);
                myLista.insertData(myLista.getLastPos(),myCancion);
                cout<<"Desea guardar otra cancion s/n: ";
                cin>>opc;system("cls");

        }while(opc == 's');
        system("cls");
        break;

        case 2:
        system("cls");
        cout<<"*********Vaciar lista de canciones*********"<<endl;
        cout<<"ESTA ACCION NO SE PUEDE REVERTIR"<<endl;
        cout<<"Digita 1 si deseas continuar Digita 2 si deseas cancelar"<<endl<<endl;
        cin>>op;

            if(op == 1){
                cout<<"Eliminando lista de canciones..."<<endl;
                myLista.deleteAll();
                cout<<"Lista de canciones eliminada"<<endl;
                }

            else{
                cout<<"Operacion cancelada"<<endl;
                }
            system("pause");
            system("cls");
            break;

            case 3:
                system("cls");
                cout<<"*********Ingresar elemento en el punto de interes*********"<<endl;
                cin.ignore();
                cout<<"Nombre de la cancion: ";
                getline(cin,myCadena);
                myCancion.setNamesong(myCadena);
                cout<<"Nombre del artista: ";
                getline(cin,myCadena);
                myCancion.setNameartist(myCadena);
                cout<<"Nombre del compositor: ";
                getline(cin,myCadena);
                myCancion.setNameinterpreter(myCadena);
                cout<<"Duracion de la cancion: ";
                getline(cin,myCadena);
                myCancion.setDurationsong(myCadena);

                cout<<"Fecha de lanzamiento (dd/mm/aaaa): ";

                getline(cin,myCadena,'/');
                myFecha.setDay(stoi(myCadena));
                getline(cin,myCadena,'/');
                myFecha.setMonth(stoi(myCadena));
                getline(cin,myCadena);
                myFecha.setYear(stoi(myCadena));
                myCancion.setReleaseDate(myFecha);

                cout<<"Posicion en el ranking: ";
                cin>>myEntero;
                myCancion.setPositionranking(myEntero);
                system("cls");
                cout<<myLista.toString()<<endl<<endl;
                cout<<"Ingresa el nombre de la cancion para tomar como referencia"<<endl;
                cin.ignore();
                getline(cin, myCadena);
                myCancionAux.setNamesong(myCadena);
                pos = myLista.findData(myCancionAux,Song::compareBySongName);
                if (pos==nullptr){
                    cout<<"No se encuentra en la lista"<<endl;
                }
                else{
                    cout<< endl <<endl;
                    cout<< "Se encuentra en la posicion " <<pos<<" de la lista"<<endl<<endl;
                    cout<<myLista.retrieve(pos).toString()<<endl;
                    cout<< endl <<endl;
                    cout<<"1)Si deseas ingresar antes del punto de referencia 2)Si deseas ingresar despues del punto de referencia" <<endl;
                    cin>>op;

                    if(op==1){
                        myLista.insertData(myLista.getPrevPos(pos),myCancion);
                    }
                    else{
                        myLista.insertData(myLista.getNextPos(pos), myCancion);
                    }
                    cout<<"Cancion agregada correctamente"<<endl <<endl;
                }
            system("pause>>cls");
            cout <<endl <<endl;
            break;

            myLista.insertData(myLista.getPrevPos(myLista.getLastPos()),myCancion);

            cout<<"N. N.Cancion N.Artista N.Compositor Duracion Lanzamiento posicion "<<endl;
            cout<< myLista.toString();
            system("pause");
            system("cls");

            break;

            case 4:
            system("cls");
            cout<<"*********Eliminar cancion*********"<<endl;
            cout<<"Ingresa el nombre de la cancion a eliminar"<<endl;cin.ignore();
            getline(cin, myCadena);
            myCancion.setNamesong(myCadena);
            pos = myLista.findData(myCancion,Song::compareBySongName);
                if (pos==nullptr){
                    cout<<"No se encuentra en la lista"<<endl;
                }
                else{
                    cout<< endl <<endl;
                    cout<< "Se encuentra en la posicion " <<pos<<" de lalista"<<endl<<endl;
                    cout<<myLista.retrieve(pos).toString()<<endl;
                    cout<< endl <<endl;
                    cout<<"Eliminando registro..." <<endl;
                    myLista.deleteData(pos);
                    cout <<endl <<endl;
                }
                system("pause>>cls");
                cout <<endl <<endl;
            break;

            case 5:
            system("cls");
            cout<<"*********Localizar cancion por posicion*********"<<endl;
            cout<<"Ingresa el nombre de la cancion a localizar"<<endl;cin.ignore();
            getline(cin, myCadena);
            myCancion.setNamesong(myCadena);
            pos = myLista.findData(myCancion,Song::compareBySongName);
                if (pos==nullptr){
                    cout<<"No se encuentra en la lista"<<endl;
                }
                else{
                    cout<< endl <<endl;
                    cout<< "Se encuentra en la posicion " <<pos<<" de la lista" <<endl<<endl;
                    cout<<myLista.retrieve(pos).toString()<<endl;

                    cout<< endl <<endl;
                }

                system("pause>>cls");
                cout <<endl <<endl;
                break;

            case 6:
            system("cls");
            cout<<"*********Localizar cancion por nombre de la cancion (lineal)*********"<<endl;
            cout<<"Digita el nombre de la cancion: ";cin.ignore();
            getline(cin, myCadena);system("cls");
            myCancion.setNamesong(myCadena);
            cout<<endl<<endl;
            //pos = myLista.findDataLinear(myCancion);
            cout<<"La cancion con nombre "<<myCadena<<endl;
            if (pos == NULL){
                cout<<"No se encuentra en la lista"<<endl;
            }
            else {
                cout<<" se encuentra en la posicion: "<<pos+1<< " de la lista"<<endl<<endl;
                cout<<"Registro encontrado: "<<endl;
                cout<<"# Cancion Artista N.Compositor Duracion Lanzamiento posicion "<<endl;
                cout<< myLista.retrieve(pos).toString()<<endl;
                }
                cout<<endl<<endl;
                system("pause");
                system("cls");
            break;

            /*    case 7:
            system("cls");
            cout<<"Para utilizar este metodo es necesario ordenar la lista\n Selecciona el metodo de ordenamiento que deseas emplear: "<<endl;
            cout<<"1)Metodo bubblesort \n 2)Metodo insertSort \n 3)Metodo selecSort \n 4)Metodo shellSort\n"<<endl;
            cin>>op;
                switch(op){
                    case 1:
                    cout<<"ordenando..."<<endl;
                    myLista.sortDataBubbleC();
                    system("cls");
                    cout<<"Metodo utilizado: burbuja:"<<endl;
                    cout<<"Lista ordenada por nombre de cancion: "<<endl;
                    cout<< myLista.toString();
                    system("pause>>cls");

                break;

                case 2:
                    cout<<"ordenando..."<<endl;
                    myLista.sortDataInsertC();
                    system("cls");
                    cout<<"Metodo utilizado: insercion:"<<endl;
                    cout<<"Lista ordenada por nombre de cancion: "<<endl;
                    cout<< myLista.toString();
                    system("pause>>cls");
                    break;

                case 3:
                cout<<"ordenando..."<<endl;
                myLista.sortDataSelectC();
                system("cls");
                cout<<"Metodo utilizado: seleccion:"<<endl;
                cout<<"Lista ordenada por nombre de cancion: "<<endl;
                cout<< myLista.toString();
                system("pause>>cls");
                break;

                case 4:
                cout<<"ordenando..."<<endl;
                myLista.sortDataShellC();
                system("pause>>cls");
                cout<<"Metodo utilizado: shell:"<<endl;
                cout<<"Lista ordenada por nombre de cancion: "<<endl;
                cout<< myLista.toString();
                system("pause>>cls");
                break;

                default:
                cout<<"Selecciona una opción valida"<<endl; break;
                }

                cout<<endl<<endl;
                cout<<"*********Localizar cancion por nombre de cancion (binario)*********"<<endl;
                cout<<"Digita el nombre de la cancion: ";cin.ignore();
                getline(cin, myCadena);system("cls");
                myCancion.setNameartist(myCadena);
                cout<<endl<<endl;
                pos = myLista.findDataBinary(myCancion);
                cout<<"La cancion con nombre "<<myCadena<<endl;
                    if (pos == -1){
                        cout<<"No se encuentra en la lista"<<endl;
                    }
                    else {
                        cout<<" se encuentra en la posicion: "<<pos+1<< " de la lista "<<endl<<endl;
                        cout<<"Registro encontrado con nueva posicion: "<<endl;
                        cout<<"# Cancion Artista N.Compositor Duracion Lanzamiento posicion "<<endl;

                        cout<< myLista.retrieve(pos).toString()<<endl;
                    }
                cout<<endl<<endl;
                break;

                case 8:

                system("cls");
                cout<<"*********Localizar cancion por nombre del autor (lineal)*********"<<endl;
                cout<<"Digita el nombre del autor: ";cin.ignore();
                getline(cin, myCadena);system("cls");
                myCancion.setNameartist(myCadena);
                cout<<endl<<endl;
                pos = myLista.findDataLinear(myCancion);
                cout<<"La cancion del artista "<<myCadena<<endl;
                    if (pos == -1){
                        cout<<"No se encuentra en la lista"<<endl;
                    }
                    else {
                        cout<<" se encuentra en la posicion: "<<pos+1<< " de la lista "<<endl<<endl;
                        cout<<"Registro encontrado: "<<endl;
                        cout<<"# Cancion Artista N.Compositor Duracion Lanzamiento posicion "<<endl;
                        cout<< myLista.retrieve(pos).toString()<<endl;
                    }
                cout<<endl<<endl;
                system("pause");
                system("cls");
                break;


                  case 9:

                system("cls");
                cout<<"Para utilizar este metodo es necesario ordenar la lista\n Selecciona el metodo de ordenamiento que deseas emplear: "<<endl;
                cout<<"1)Metodo bubblesort \n 2)Metodo insertSort \n 3)Metodo selecSort \n 4)Metodo shellSort\n"<<endl;
                cin>>op;
                    switch(op){
                        case 1:
                            cout<<"ordenando..."<<endl;
                            myLista.sortDataBubbleI();
                            system("pause>>cls");
                            cout<<"Metodo utilizado: burbuja:"<<endl;
                            cout<<"Lista ordenada por artista/interprete: "<<endl;
                            cout<< myLista.toString();
                        system("pause>>cls");

                        break;

                        case 2:
                            cout<<"ordenando..."<<endl;
                            myLista.sortDataInsertI();
                            system("pause>>cls");
                            cout<<"Metodo utilizado: insercion:"<<endl;
                            cout<<"Lista ordenada por artista/interprete: "<<endl;
                            cout<< myLista.toString();
                            system("pause>>cls");
                        break;

                        case 3:
                            cout<<"ordenando..."<<endl;
                            myLista.sortDataSelectI();
                            system("pause>>cls");
                            cout<<"Metodo utilizado: seleccion:"<<endl;
                            cout<<"Lista ordenada por artista/interprete: "<<endl;
                            cout<< myLista.toString();
                            system("pause>>cls");
                        break;

                        case 4:

                            cout<<"ordenando..."<<endl;
                            myLista.sortDataShellI();
                            system("pause>>cls");
                            cout<<"Metodo utilizado: shell:"<<endl;
                            cout<<"Lista ordenada por artista/interprete: "<<endl;
                            cout<< myLista.toString();
                            system("pause>>cls");

                        break;
                        default:
                            cout<<"Selecciona una opción valida"<<endl; break;
                        }
                cout<<endl<<endl;
                cout<<"*********Localizar cancion por nombre del autor/interprete (binario)*********"<<endl;
                cout<<"Digita el nombre del autor: ";cin.ignore();
                getline(cin, myCadena);system("cls");
                myCancion.setNameartist(myCadena);
                cout<<endl<<endl;
                pos = myLista.findDataBinary(myCancion);
                cout<<"La cancion del autor "<<myCadena<<endl;
                    if (pos == -1){
                        cout<<"No se encuentra en la lista"<<endl;
                    }

                    else {
                        cout<<" se encuentra en la posicion: "<<pos+1<< " de la lista"<<endl<<endl;
                        cout<<"Registro encontrado: "<<endl;
                        cout<<"# Cancion Artista N.Compositor Duracion Lanzamiento posicion "<<endl;

                        cout<< myLista.retrieve(pos).toString()<<endl;
                    }
                    cout<<endl<<endl;
                    break;  */
            default:
            cout<<"Digita una opcion valida"<<endl;break;

            }
        }while(op>0 && op<9);system("pause");
}
