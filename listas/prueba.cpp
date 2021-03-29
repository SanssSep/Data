#include<iostream>
#include "list.hh"

int main(){

	List<int> lista;
	lista.push_back(1);
	lista.push_back(2);
	lista.push_back(3);
	lista.push_back(4);
	lista.print();
	lista.pop_back();
	lista.push_back(5);
	lista.push_back(6); 
	lista.pop_front();
	lista.push_back(7);
	lista.push_back(8);
	lista.push_back(9);
	lista.push_front(8);
	lista.remove(7);
	lista.print();
	lista.print_backwards();
	return 0;
}
