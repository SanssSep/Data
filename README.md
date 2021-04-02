<link rel="stylesheet" href="css/retro.css">


# Estructura de datos

<img src="img/utp.png" alt="Logo UTP" width="150" height="150"> 

Repositorio creado para hostear el codigo desarrollado en Estructura de
datos 

## Historial de cambios

- ### [Lista doblemente enlazada](https://github.com/SanssSep/Data/commit/d5011dcea11a356b56c6cff5c48e03eb9b4217cd)
	- Agrego un apuntador a nodos "Pre" como atributo de la clase nodo para apuntar al nodo anterior     						

``` c++ 
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


```
- ### [Funcion remove()](https://github.com/SanssSep/Data/commit/fce6b16f298c671df82267dfd4cb08bd2a39bcff)
	- Elimina el primer nodo que contenga el dato "d"

```c++
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

```
