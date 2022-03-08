#include <iostream>
#include "staticQueue.h"
#include "validate.h"
#include <string>

using namespace std;

void menu() {
    Queue<int> q;
    int opc,e;
    string str_opc,str_e;

    do{
        q.showQueue();
            system("cls");
    cout<<"-----MENU-----\n"
        <<"1) Encolar\n"
        <<"2) Desencolar\n"
        <<"3) Mostrar frente\n"
        <<"4) Mostrar ultimo\n"
        <<"5) Salir\n";
        do{
            cout <<"Seleccione una opcion: ";
            cin>>str_opc;
        }while(!(isInt(str_opc) and str_opc.length() == 1));
    opc= stoi(str_opc);

    switch(opc) {
        case 1:
            do{
            cout<<"Ingrese un numero: ";
            cin>>str_e;
            }while(!(isInt(str_e) and str_e.length() == 1));
            e=stoi(str_e);
            q.enqueue(e);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            if(q.isEmpty())
                cout<<"Cola vacia"<<endl;
            else
                cout<<q.getFirst()<<endl;
            system("pause");
            break;
        case 4:
            if(q.isEmpty())
                cout<<"Cola vacia"<<endl;
            else
                cout<<q.getLast()<<endl;
            system("pause");
            break;
        }


    }while(opc != 5);
}

int main() {
    menu();
    return 0;
    }
