#include <iostream>     // kniznica na pracu so subormi 
#include <fstream>      // na file
#include "Tree.h"       // prilinkovanie hlavickoveho suboru 
#include <direct.h>

int main()
{
    srand(time(nullptr));
    Tree morse_tree;                                // Vytvorenie objektu morseovky
	time_t startTime = time(nullptr);

    morse_tree.Zacatek_prekladu("Text.txt");        // volanie funkcie so vstupnym textom
    cout << endl;

	time_t endTime = time(nullptr);
    cout << "Time taken:" << endTime - startTime <<"s"<< endl;
	return 0;
}