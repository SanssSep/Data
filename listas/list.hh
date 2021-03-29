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
				T data;      //(Contiene el dato del nodo)
				Node* next; // (apuntador al nodo siguiente)
				Node* pre; //  (apuntador al nodo previo)

			public:
				// Construye un nodo
				Node(const T& d) 
					: data(d)
						, next(nullptr)
						 ,	pre(nullptr){}

				//Retorna el dato que contiene el nodo.
				const T& getData() { return data; }

				// Retorna el atributo "next".
				Node* getNext() { return next; }

				// Retorna el atributo "pre".
				Node* getPre() {return pre;}

				// Define el atributo "next".
				void setNext(Node* n) { next = n; }

				// Define el atributo "pre".
				void setPre(Node * n) { pre = n;}
		};
		// Atributos de una lista

		unsigned int sz; //(Contiene el tamaño de la lista)
		Node* first;    // (Apuntador al primer nodo de la lista.)
		Node* last;    //  (Apuntador al ultimo nodo de la lista.)

	public:

		// Construye un lista
		List()
			: first(nullptr)
				, last(nullptr)	{
				sz = 0;
				}

		//Retorna el atributo sz
		unsigned int size(){return sz;}

		//Verifica si la lista esta vacia
		bool empty(){ return (sz == 0);}

		// Imprime la lista (Funcion diferente a la del profesor, podria tener errores) 
		void print(){

			if(empty()){
				cout << endl << "<>" << endl;
			}
			else {
				Node* p = first;
				cout << endl << "<";
				while (p -> getNext() != nullptr){
					cout << p -> getData() << ",";
					p = p -> getNext();
				}
				cout << p -> getData() << "." << ">" << endl;
			}
		}	

		// Imprime la lista al revez (funcion de prueba)
		void print_backwards(){
			if(empty()){
				cout << endl << "<>" << endl;
			}
			else {
				Node* p = last;
				cout << endl << "<";
				while (p -> getPre() != nullptr){
					cout << p -> getData() << ",";
					p = p -> getPre();
				}
				cout << p -> getData() << "." << ">" << endl;
			}
		}	

		//Agrega un nodo de dato "d" al final de la lista
		void push_back(const T& d){

			Node* n = new Node(d);

			if (empty()){
				first = n;
				sz = sz + 1;
			}
			else{
				last -> setNext(n);
				n -> setPre(last);
				sz = sz + 1;
			}
			last = n;
			
		}

		//Agrega un nodo de dato "d" al inicio de la lista
		void push_front(const T& d){

			Node* n = new Node(d);
			first -> setPre(n);
			n -> setNext(first);

			if (empty()){
				last = n;
				sz = sz + 1;
			}
			first = n;
			sz = sz + 1;
		}

		//Elimina el primer nodo.
		void pop_front(){

			assert(!empty() && "lista vacia");
			Node* n = first;
			first = first -> getNext();
			if(first == nullptr){
				last = nullptr;
				sz = 0;
			}
			first -> setPre(nullptr);
			sz = sz - 1;
			delete n;
		}

		//Elimina el ultimo nodo.	
		void pop_back(){

			assert(!empty() && "lista vacia");
			if (first == last){
				delete last;
				first = nullptr;
				last = nullptr; 
				sz = 0;
			}
			else{
				Node *n = first;
				while(n -> getNext() != last){
					n = n -> getNext();
				}
				n -> setNext(nullptr);
				delete last;
				last = n;
				sz = sz - 1;
			}
		}

		// ---------------------------------------------Inicio de funcion propia

		// Elimina el primer nodo que contenga el dato "d"
		void remove(const T& d){

			assert(!empty() && "lista vacia");
			Node* n = first;

			// Si el dato del primer nodo es igual a el dato que buscamos "d" 
			// usar la funcion pop_front()
			if (first -> getData() == d){
				pop_front();
			}
			else {
				 //Mientras que el dato del nodo siguiente a "n" sea diferente del dato que buscamos "d" y
				//No estemos en el ultimo nodo de la lista.
				while(n -> getNext() != nullptr && n -> getNext() -> getData() != d) {
					n = n -> getNext();
				}
				 // Si estamos en el ultimo nodo y el dato que contiene es igual al dato "d" que buscamos
				// utilizar la funcion pop_back()
				if (n == last){
					if (n -> getData() == d){					
						pop_back();
					}
					else {
						cout << "No se encontro el dato " << d << " en la lista :C";
					}
				}
				//Si el while para porque el dato del nodo siguiente a n es igual que el dato "d" que buscamos
				else {
					//Creamos un apuntador "e" al siguiente nodo de "n"
					Node* e = n -> getNext();
					//Definimos el siguiente nodo de "n" como el siguiente nodo de "e"
					n -> setNext(e -> getNext());
					//Apuntamos con "n" al siguiente nodo de "e"
					n = e -> getNext();
					//Definimos el nodo previo a "n" como el nodo previo a "e"
					n -> setPre(e -> getPre());
					//Eliminamos e
					delete e;
					//Disminuimos el tamaño de sz.
					sz = sz - 1;
				}
			}
		}

		// ---------------------------------------------Final de funcion propia
};

#endif
