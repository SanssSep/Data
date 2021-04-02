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
