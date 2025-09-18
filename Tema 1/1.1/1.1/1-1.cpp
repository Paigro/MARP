/*@ <authors>
 * Pablo
 * Iglesias Rodrigo
 * MARP29
 *@ </authors> */

#include <iostream>
#include <fstream>

using namespace std;

#include "bintree.h";

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

// Dado un arbol devuelve -1 si no es ALV, sino la altura. Sease minMax.first el minimo elemento del arbol y minMax.second el maximo elemento del arbol.
template <class T>
int ALV(BinTree<T> arbol, std::pair<T, T>& minMax)
{
	// CASOS BASE:
	// Caso vacio; no hay niveles.
	if (arbol.empty())
	{
		return 0;
	}
	/*// Caso hoja; devuelve 1 nivel.
	if (arbol.left().empty() && arbol.right().empty())
	{
		minMax.first = arbol.root();
		minMax.second = arbol.root();
		return 1;
	}*/

	// CASOS IZQUIERDO Y DERECHO:
	std::pair<T, T> minMaxIzq; // Guarda el min y max valor del subarbol izquierdo.
	std::pair<T, T> minMaxDer; // Guarda el min y max valor del subarbol derecho.
	int izq = ALV(arbol.left(), minMaxIzq); // Subarbol izquierdo.
	int der = ALV(arbol.right(), minMaxDer); // Subarbol derecho.

	if (izq == -1 || der == -1) return -1;

	// Actualizamos el minMax global dados los auxiliares de cada subarbol.
	// Nos guardamos los valores de este nodo.
	minMax.first = arbol.root();
	minMax.second = arbol.root();
	// Comprobaciones:
	if (!arbol.left().empty())
	{
		if (minMax.first > minMaxIzq.first) // Si el minimo de la izquierda es menor que el propio nos lo guardamos,
		{
			minMax.first = minMaxIzq.first;
		}
		else // sino no es ALV.
		{
			return -1;
		}
	}
	if (!arbol.right().empty())
	{
		if (minMax.second < minMaxDer.second) // Si el maximo de la derecha es mayor al propio nos lo guardamos,
		{
			minMax.second = minMaxDer.second;
		}
		else // sino no es ALV.
		{
			return -1;
		}
	}
	// Nos quedamos con el mayor nivel entre los dos subhijos.
	int mayorNivel = izq >= der ? izq : der;

	if (abs(izq - der) > 1) // Si la diferencia de los niveles de los hijos es mayor a 1 entonces no se cumple que sea ALV.
	{
		return -1;
	}
	else // sino sumamos un nivel y pasamos al siguiente.
	{
		mayorNivel++;
	}

	// Comprobamos que los elementos estan bien ordenados. Sino, no es ALV.
	if (!arbol.left().empty() && arbol.root() < minMax.first ||
		!arbol.right().empty() && arbol.root() > minMax.second)
	{
		return -1;
	}

	return mayorNivel;
}

bool resuelveCaso()
{
	char type; // Tipo de arbol.
	std::cin >> type;

	int sol; // Solucion. Si es -1 no es un ALV.

	// Fin de la entrada.
	if (!std::cin)
		return false;

	// Casos de entrada:
	if (type == 'N')
	{
		BinTree<int> tree = read_tree<int>(std::cin);

		std::pair<int, int> minMax = { 0, 0 };

		sol = ALV(tree, minMax);
	}
	else if (type == 'P')
	{
		BinTree<std::string> tree = read_tree<std::string>(std::cin);

		std::pair<std::string, std::string> minMax = { " ", " " };

		sol = ALV(tree, minMax);
	}

	sol != -1 ? std::cout << "SI" : std::cout << "NO";
	std::cout << std::endl;

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main()
{
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	if (!in.is_open())
		std::cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout << "Pulsa Intro para salir..." << std::flush;
	std::cin.get();
#endif
	return 0;
}