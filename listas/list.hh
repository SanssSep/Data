#ifndef __LIST_HH___
#define __LIST_HH___

#include<cassert>
#include<iostream>

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
			// Construlle un nodo
			Node(const T& d) 
				: data(d)
				, next(nullptr){}
			//Retorna el dato que contiene el nodo 
			const T& getData() { return data; }
			
			// Retorna un apuntador al nodo siguiente.
			Node* getNext() { return next; }

			// Define el siguiente Nodo
			void setNext(Node* n) { next = n; }
	};
	// Atributos de una lista
 
  Node* first; // Almacena la direccion del primer elemento en la lista 

public:
	List()
		: first(nullptr) {}

	
	// ----------------------------------------- Funcion Propia
	void print(){
		Node* p = first ;
		cout << endl;
		while (p -> getNext() != nullptr){
			cout << p -> getData() << ",";
			p = p -> getNext();
		}
		cout << p -> getData() << ". ";
	}
	// ----------------------------------------- Funcion Propia
	
	void push_back(const T& d){

		Node* n = new Node(d);

		if (empty()){
			first = n;
		}
		else{
			Node* p = first;
			while (p -> getNext() != nullptr){
				p = p -> getNext();
			}
			p -> setNext(n);
		}
	}

	// ----------------------------------------- Funcion Propia
		bool empty(){ return (first == nullptr);}
	// ----------------------------------------- Funcion propia.
	
	};

#endif
