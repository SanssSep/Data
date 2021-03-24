#include <iostream>
#include "list.hh"

int main(){
	List<int> prueba;	
	cout << prueba.empty() << endl;
	prueba.push_back(11);
	prueba.push_back(88);
	cout << prueba.empty();
	prueba.print();
	prueba.push_front(66);
	prueba.print();
	return 0;
}
