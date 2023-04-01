#include <stdio.h>
#include <iostream>
#include <list>
#include <locale.h>
#include <conio.h>

using namespace std;


class Item {
  public:
    string name;
    int power;

  public:
    Item(string n, int p ){
        this->name = n;
        this->power = p;
    }

    Item(){}
};


list<Item> inventario;
list<Item>::iterator ite;


void consultar(){
   cout << "======================= itens do inventario: ===========================" << endl;

   for( ite = inventario.begin(); ite != inventario.end(); ite++ ){
        cout << "  Nome:  " << ite->name;
        cout << " // Poder: " << ite->power << endl;
   }
   cout << "=======================================================================" << endl;
}

void resetar()  {
    inventario.clear();
}

template <typename T> void adicionar(const T& pers){
    inventario.push_back(pers);
}



void remover(string nomeRemover){
    bool achou = false;

    for( ite = inventario.begin(); ite != inventario.end(); ite++ ){
      /*
      Item itemObj = *ite;
      cout << "ite->name:  " << ite->name << endl;
      cout << "itemObj.name:  " << itemObj.name << endl;
      cout << " (*ite).name:  " << (*ite).name << endl;
      cout << "&ite:  " << &ite << endl;
      */

      if( ite->name == nomeRemover){
            achou = true;
            cout << "-------> O item " << ite->name << " foi removido!! <-------" << endl;
            ite = inventario.erase(ite); // retorna o o proximo iterador de depois do item apagado
            --ite; //voltando para o elemento anterior ao elemento apagado
      } 
    }
    if(achou==false){
            cout << endl << "Item nao encontrado no inventario...." << endl;
    }
}


void encerrarOperacao(){
      string enter;
      cout << endl << "Aperte ENTER para continuar...." << endl;
      getch(); //espera ate a tecla ENTER ser pressionada
}


int main() {
    bool isRunning = true;

    Item ak = Item("ak-47", 2002);
    Item m4 = Item("m4", 1950);
    Item katana = Item("katana", 108);
    Item pistola ("pistola", 506);// segunda forma de instanciar a classe

    //adicionando no inventario manualmente:
    inventario.push_back(ak);
    inventario.push_back(m4);
    inventario.push_back(katana);

    //adicionando no inventario via template function:
    adicionar<Item>( pistola );
    adicionar<Item>( Item("faca de mesa", 806) );
    adicionar<Item>( Item("shotgun", 1206) );
    adicionar<Item>( Item("handgun", 700) );
   

    while(isRunning){
        cout << endl << "<======================= MENU ===========================>" << endl;
        cout << " O que deseja fazer? (Digite o numero de acordo com a opcao que vc deseja...)" << endl;
        cout << endl << "1- Adicionar um item ao inventario: " << endl;
        cout << "2- Retirar um item do inventario: " << endl;
        cout << "3- Visualizar inventario: " << endl;
        cout << "4- Resetar inventario: " << endl;
        cout << "5- Sair " << endl;
        cout << "<================================================================>" << endl;

        int option =0;
        string name;
        int power;

        cin >> option;

        switch(option){
            case 1:
                cout << "Escreva o nome da arma: " << endl;
                cin >> name;
                cout << "Qual o seu poder? " << endl;
                cin >> power;

                adicionar<Item>( Item(name, power) );

                cout << "-------> "<< name << " adicionado(a) ao inventario! <-------" << endl;
                encerrarOperacao();
                break;

            case 2:
                consultar();
                cout << "Escreva o nome da arma que deseja apagar... " << endl;
                cin >> name;
                remover(name);
                encerrarOperacao();
                break;
 
            case 3:
                consultar();
                encerrarOperacao();
                break;

            case 4:
                inventario.clear();
                cout << "-------> O inventario foi resetado!! <-------" << endl;
                encerrarOperacao();
                break;

            case 5:
                isRunning =false;
                cout << endl << "  Saindo....... ";
                break;
        }
    }

    return 0;
}




// Use o comando abaixo para compilar: 
// "gcc++ -o <nome-do-executavel-q-sera-criado> <nome-do-arquivo-com-codigo>.cpp" compila e gera um executavel

// comando q executa o programa pelo CMD:
// "./<nome-do-executavel>.cpp" 
