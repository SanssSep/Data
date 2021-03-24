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
  Node* last; // Almacena la direccion del ultimo elemento en la lista 

public:
	// Construye un lista
	List()
		: first(nullptr)
 		, last(nullptr)	{}

	//Verifica si la lista esta vacia
	bool empty(){ return (first == nullptr);}
	
	// Imprime la lista  
	void print(){
		
		if(empty()){
			cout << endl << "<>" << endl;
		}
		else {
			Node* p = first ;
			cout << endl << "<";
			while (p -> getNext() != nullptr){
				cout << p -> getData() << ",";
				p = p -> getNext();
			}
			cout << p -> getData() << "." << ">" << endl;
		}
	}	

	//Agrega un elemento al final de la lista
	void push_back(const T& d){

		Node* n = new Node(d);

		if (empty()){
			first = n;
		}
		else{
			last ->setNext(n);
		}
		last = n;
		}

	//Agrega un elemento al inicio de la lista
	void push_front(const T& d){

		Node* n = new Node(d);
		n -> setNext(first);
		if (empty()){
			last = n;
		}
		first = n;
	}

};

#endif
