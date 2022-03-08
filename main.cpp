#include <iostream>
#include "staticQueue.h"
using namespace std;

void menu() {
    Queue<int> q;
    int opc,e;
    do{
            system("cls");
    cout<<"-----MENU-----\n"
        <<"1) Encolar\n"
        <<"2) Desencolar\n"
        <<"3) Mostrar frente\n"
        <<"4) Mostrar ultimo\n"
        <<"5) Salir\n"
        <<"Seleccione una opcion: ";
    cin>>opc;

    switch(opc) {
        case 1:
            cout<<"Ingrese un numero: ";
            cin>>e;
            q.enqueue(e);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            cout<<q.getFirst()<<endl;
            system("pause");
            break;
        case 4:
            cout<<q.getLast();
            system("pause");
            break;
        }


    }while(opc != 5);
}

int main() {
    menu();
    return 0;
    }
