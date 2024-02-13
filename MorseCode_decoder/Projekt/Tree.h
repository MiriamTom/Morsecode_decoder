#pragma once
using namespace std;
#include <string>

/*!
*	@brief Hlavickovy subor
*
*	@author Miriam Tomasova (TOM0468)
*	@version 1.0
*	@date 13.05.2023
*
*	@class Tree
*	Jedina hlavna trieda, ktora je potrebna pre spravne prochadzanie celeho grafu
*	Detailne popisy su uvedene nizsie
*/

class Tree
{
private:
	//! ukladanie botky, alebo ciarky
	//! prislusne pismeno
	char znak;     
	
	//! prava strana stromu 
	Tree* carka; 
	//! lava strana stromu 
	Tree* tecka; 
public:
	//! prazdny konstruktor
	/*!
	*	Definovany strom, strom sa rozvetvuje cez vetvu ciarka alebo tecka, 
	*	posuvanie sa nom cez char ('.') alebo char ('-')
	*/
	Tree();
	//!  konstruktor znaku, obsahuje znak c co je pismeno abecedy 
	/*!
	*	 @param c parameter obsahujuci znak
	*/
	Tree(char c);
	
	//!posuvanie na vetvach stromu na zaklade tecky
	/*!
	*	@return navraca sa posunuty strom o vetvu podla tecky
	*/
	Tree* posunuti_tecka();
	//!	posuvanie na vetvach stromu na zaklade carky
	/*!
	*	@return navraca sa posunuty strom o vetvu podla ciarky
	*/
	Tree* posunuti_carka();
	//!	vypis znaku so stromu s parametrami ziskanimi
	/*!
	*	@return navracia znak
	*/
	char get_znak();
	/*!
	*	hlavna funkca ktora otvori subor, vezme cely text ako jedno pole charov a zacne prehladat strom od aktualnej polohy zhora, premena typu bool capital sa nastavi na True kedze zaciatok prekladu a Zaciatok Vety sa zacina vzdy velkym pismenom,
	*	V cykle while sa prechadza cely subor az do konca, vo vnorenom cykle for, prechadza znak po znaku, 
	*	v cykle je podmienka na koniec vety ktora dalsie pismeno nastavi na bool capital = true.
	*
	*	Ak sa znak vyhlada v strome, zapise sa do terminalu a v strome sa presuniem opat na vrchol.
	*	@param nazov_suboru premena obsahujici nazev suboru, ktory obsahuje potrebna data pre graf (cesta k suboru je relativna)
	*/
	void Zacatek_prekladu(string nazov_suboru);
};

