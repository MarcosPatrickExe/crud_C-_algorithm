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
   for( ite = inventario.begin(); ite != inventario.end(); ite++ ){
        cout << "Nome:  " << ite->name;
        cout << "   Poder: " << ite->power << endl;
    }

   /*
      
        Item value = Item("katana", 1001);
        int num = 2323;
        Item* weaponAddress = &value;

     //   Item value2 = ite.getValue;
        cout << "1.Valor do ponteiro = endereco de num: " << weaponAddress;
        cout << "2. endereco de do ponteiro: " << &weaponAddress;
        cout << "3. valor de num: " << (*weaponAddress->name );
       // cout << *ite << " ";
    */
}

void resetar()  {
    inventario.clear();
}

void adicionar(Item pers){
    inventario.push_back(pers);
}



void remover(string nomeRemover){
 
 
    for( ite = inventario.begin(); ite != inventario.end(); ite++ ){
      Item itemObj = *ite;
      cout << "ite-> " << ite->name << endl;
      cout << "ite.name " << itemObj.name << endl;
      cout << "&ite " << &ite << endl;


      if( ite->name == nomeRemover){
          cout << "passou no if" << endl;
          //itemToBeRemoved = ite;
          /*
          cout << "O item " << ite->name << " foi removido!!";
          Item itemToBeRemoved = *ite;
          inventario.remove( itemToBeRemoved);
          */
      }
    }

  
}



int main() {
   
    Item ak = Item("ak 47", 502);
    Item faca = Item("faca", 18);
    Item pistola = Item("pistola", 206);
   
    consultar(); 

    inventario.push_back(ak);
    inventario.push_back(faca);
    inventario.push_back(pistola);
    adicionar( Item("faca de mesa", 806) );

 
  //  inventario.clear();
   
    consultar();

    remover("faca");

    consultar();
   

   // cout << "Hello, world! " << a.name;

 
    return 0;
}

// o comando "gcc -o ola ./sortList.cpp" compila e gera um executavel
// o comando "./sortList.cpp" executa o programa na linha de comando

