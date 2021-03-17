# ifndef __VECTOR_HH__
# define __VECTOR_HH__

#include<cassert>
#include<iostream>
using namespace std;

template <typename T>
class Vector{

private:

	unsigned int sz; // Tamaño ocupado del vector.
	unsigned int capacity; // Capacidad total del vector
	double policy; //Politica de crecimiento.
	T* storage;

public:

// Funciones Constructoras del vector.

	Vector() { 

		sz = 0;
		capacity = 8;
		policy = 1.5;
		storage = new T[capacity];
	}

	Vector(unsigned int c, double p = 1.5){ // Permite agregar el argumento "c" de tamaño
// Si la politica de crecimiento es menor que cero, el resize disminuiria el tamaño del vector.

		assert(p > 1.0); 
		sz = 0;
		capacity = c;
		policy = p;
		storage = new T[capacity];
	}

	Vector(const Vector<T>& other) { // Funcion para copiar un vector.
		sz = other.sz;
		capacity = other.capacity;
		policy = other.policy;
		storage = new T[capacity];
		for (unsigned int i = 0; i < sz; i++) {
			storage[i] = other.storage[i];
		}
	}
	
	Vector<T>& operator=(const Vector<T>& other){
		if(this != &other){
			sz = other.sz;
			capacity = other.capacity;
			storage = new T[capacity];
			policy = other.policy;
			for (unsigned int i = 0; i < sz; i++){
				storage[i] = other.storage[i];
			}
		}
		return *this;
	}

// Deconstrulle el vector automaticamente despues de su uso
	~Vector(){ delete[] storage; } 

// retorna el tamaño ocupado del vector 
	unsigned int size() {return sz;} 
	
	void push_back(const Vector<T>& other){

	// Adiciona todos los elementos del vector other al final de este vector.
	// Solo debe hacer un resize!
	}

	// Agrega un elemento al final del vector.
	void push_back(const T& e){ 

		if (sz == capacity){
			resize();
		}
		storage[sz] = e;
		sz = sz + 1;
	}
	
	void push_front(const Vector<T>& other){

		// adiciona todos los elementos del vector other al inicio de este vector.
		// Solo debe hacer un resize!
	}		

	// Agrega un elemento al inicio del vector.
	void push_front(const T& e){

		if (sz == capacity){
			resize();
		}
		for (unsigned int i = 0; i < sz; i++) {
			storage[i + 1] = storage[i];
		}
		storage[0] = e;
		sz = sz + 1;
	}
	
	void insert(const T& e, unsigned int p){ // Inserta e en el vector en la posicion p.
		
	}
	void insert(const Vector<T>& other, unsigned int p){

		//inserta los elementos de other a partir de la posicion p.
		}

	// Verifica que la posicion "pos" se encuentre dentro del vector.
	bool isValid(unsigned pos) {return pos >= 0 && pos < sz;}

	// intercambia los elementos de un vector
	void swap(unsigned int i, unsigned int j){

		if (!isValid(i)){
			cout << i << " : no es valida" << sz << endl;
		}
		if (!isValid(j)) {
			cout << j << " : no es valida" << sz << endl;
		}
		assert(i >= 0 && i < sz && "Primera poscion no es valida");
		assert(j >= 0 && j < sz && "Segunda poscion no es valida");

		T tmp = storage[i];
		storage[i] = storage[j];
		storage[j] = tmp;
	}
	
	unsigned int find(int e){

		for(unsigned int i = 0;i < sz; i++){
			
			if (e == storage[i]){
				return i;
			}
		
	}
		return sz;
	}

private:

	// Reconstruye el vector con capacidad aumentada (capacity * policy)
	void resize() {

		unsigned int newCapacity = capacity * policy;
		T* newStorage = new T[newCapacity];
		for (unsigned int i = 0; i < sz; i++) {
			newStorage[i] = storage[i];
		}
		delete[] storage;
		storage = newStorage;
		capacity = newCapacity;
	}

public:

	// Retorna el elemento que se encuentre en la posicion "p"
	T& at(unsigned int p) {

		assert(p >= 0 && p < sz && "Posicion no valida dentro del vector");
		return storage[p];
	}

	// retorna un valor booleano True si el vector esta vacio.
	bool empty() {return sz == 0;}

	// Retorna el primer elemento del vector.
	T& front (){

		assert(!empty() && "El vector no puede estar vacio");
		return storage[0];
	}

	// Retorna el ultimo elemento
	T& back(){

		assert(!empty() && "El vector no puede estar vacio");
		return storage[sz - 1];
	}
	
	// Imprime todos los elementos
	void print(){

		for(unsigned int i = 0; i < sz; i++){cout << " ," << at(i);
		}
	cout << endl;	
	}

	// Organiza los elementos por el metodo burbuja
	void bsort() {

		for (unsigned int i = 0; i < sz; i++) {
			for (unsigned int j = 0; i < sz - i - 1; ++j) {
				if(storage[j] > storage[j + 1]) {
					swap(j, j + 1);
				}
			}
		}
	}


	/* Operaciones pedagogicas */

	size_t usedMem() {
		return sizeof(T*) + 2 * sizeof(unsigned int) + sizeof(double) + capacity * sizeof(T);
	}

	size_t usefulMem(){
		return sizeof(T*) + 2 * sizeof(unsigned int) + sizeof(double) + sz * sizeof(T);
	}
};

#endif
