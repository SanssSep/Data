#include <iostream>
#include "list.hh"

int main(){
	List<int> prueba;	
	cout << prueba.empty() << endl;
	prueba.push_back(11);
	cout << prueba.empty();
	prueba.print();
	return 0;
}
