/*@ <authors>
 * Pablo
 * Iglesias Rodrigo
 * MARP29
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>

#include "TreeSet_AVL.h";

 /*@ <answer>

  

  @ </answer> */


  // ================================================================
  // Escribe el código completo de tu solución aquí debajo
  // ================================================================
  //@ <answer>

 
  
class PaigroSet : public Set<int>
{

  

};
  
// 
int buscarKesimo(Set<int> arbol, int k)
{
	return 0;
}

bool resuelveCaso()
{
	// LECTURA:
	int nElems; // Numero de elementos del arbol.
	std::cin >> nElems;

	// Fin de la salida.
	if (nElems == 0)
		return false;

	// Se leen los elementos del arbol.
	Set<int> arbol;
	std::vector<int> auxArbol(nElems);
	for (int i = 0; i < nElems; i++)
	{
		std::cin >> auxArbol[i];
		arbol.insert(auxArbol[i]);
	}
	// Se leen los elementos que se tendran que buscar.
	std::cin >> nElems;
	std::vector<int> elemsBuscar(nElems);
	for (int i = 0; i < nElems; i++)
	{
		std::cin >> elemsBuscar[i];
	}

	// RESOLUCION:
	std::vector<int> sol(nElems);
	for (int i = 0; i < nElems; i++)
	{
		//sol[i] = buscarKesimo(arbol, elemsBuscar[i]);
	}

	// ESCRITURA:
	for (int i = 0; i < nElems; i++)
	{
		if (sol[i] != -1)
		{
			std::cout << sol[i] << " ";
		}
		else
		{
			std::cout << "???";
		}
	}
	std::cout << std::endl << "---" << std::endl;


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