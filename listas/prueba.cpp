#include <iostream>
#include "list.hh"

int main(){
	//Defino un elemento de la clase List llamado prueba
	List<int> prueba;	
	//Agreglo los datos 10,7,9,3

	cout << "Antes del push_front";
	prueba.push_back(1);
	prueba.push_back(3);
	prueba.push_back(5);
	prueba.push_back(7);
	//Imprimo los datos 
	prueba.print();
	cout << endl;
	
	//Agrego el elemento 1 al frente de la lista
	prueba.push_front(9);
	cout << "Despues del push_front";
	//Imprimo los datos
	prueba.print();
	return 0;
}
