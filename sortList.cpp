#include <stdio.h>
#include <iostream>
#include <list>

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
 
    for( ite = inventario.begin(); ite != inventario.end(); ite++ ){
      /*
      Item itemObj = *ite;
      cout << "ite->name:  " << ite->name << endl;
      cout << "itemObj.name:  " << itemObj.name << endl;
      cout << " (*ite).name:  " << (*ite).name << endl;
      cout << "&ite:  " << &ite << endl;
      */

      if( ite->name == nomeRemover){
          cout << "O item " << ite->name << " foi removido!!" << endl;
          ite = inventario.erase(ite); // retorna o o proximo iterador de depois do item apagado
          --ite; //voltando para o elemento anterior ao elemento apagado
      }
    }
}



int main() {
  
    Item ak = Item("ak-47", 2002);
    Item m4 = Item("m4", 1950);
    Item katana = Item("katana", 108);
    Item pistola ("pistola", 506);

    //adicionando no inventario manualmente:
    inventario.push_back(ak);
    inventario.push_back(m4);
    inventario.push_back(katana);

    //adicionando no inventario via template function:
    adicionar<Item>( pistola );
    adicionar<Item>( Item("faca de mesa", 806) );
    adicionar<Item>( Item("shotgun", 1206) );
    adicionar<Item>( Item("handgun", 700) );
   

    consultar();
    remover("faca");
    consultar();

   

    return 0;
}





// o comando "gcc -o ola ./sortList.cpp" compila e gera um executavel
// o comando "./sortList.cpp" executa o programa na linha de comando
