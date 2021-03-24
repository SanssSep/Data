#include <iostream>
#include "list.hh"

int main(){
	//Defino un elemento de la clase List llamado prueba
	List<int> prueba;	
	List<int> vacio;
	//Agreglo los datos <1,3,5,7>
	cout << "Antes del push_front";
	prueba.push_back(1);
	prueba.push_back(3);
	prueba.push_back(5);
	prueba.push_back(7);

	//Imprimo los datos 
	prueba.print();
	
	//Agrego el elemento 9 al frente de la lista <9,1,3,5,7>
	prueba.push_front(9);
	cout << "Despues del push_front";
	//Imprimo los datos
	prueba.print();
	cout << "Vector vacio";
	//Imprimo un vector vacio
	vacio.print();
	return 0;
}
