#ifndef __LIST_HH___
#define __LIST_HH___

#include<cassert>
#include <iostream>

using namespace std;

template <typename T>
class List {

private:
	class Node {

		private:
			//Atributos de un nodo
			T data;
			Node* next;

		public:
			Node(const T& d) 
				: data(d)
				, next(nullptr){}
			const T& getData() { return data; }
			Node* getNext() { return next; }
			void setNext(Node* n) { next = n; }
	};
	// Atributos de una lista
  Node* first; // Almacena la direccion del primer elemento en la lista 

public:
	List()
		: first(nullptr) {}
};

#endif
