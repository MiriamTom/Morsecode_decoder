#include "Tree.h"
#include <fstream>  
#include <iostream>
using namespace std;

Tree::Tree(char c)					
{
	this->znak = c;
	this->tecka = nullptr;
	this->carka = nullptr;
}

Tree::Tree()
{

	this->znak = ' ';
	this->tecka = new Tree('e');
	this->tecka->tecka = new Tree('i');
	this->tecka->tecka->tecka = new Tree('s');
	this->tecka->tecka->tecka->tecka = new Tree('h');
	this->tecka->tecka->tecka->carka = new Tree('v');

	this->tecka->tecka->carka = new Tree('u');
	this->tecka->tecka->carka->tecka = new Tree('f');
	
	this->tecka->carka = new Tree('a');
	this->tecka->carka->tecka = new Tree('r');
	this->tecka->carka->tecka->tecka = new Tree('l');

	this->tecka->carka->carka = new Tree('w');
	this->tecka->carka->carka->tecka = new Tree('p');
	this->tecka->carka->carka->carka = new Tree('j');
	

	this->carka = new Tree('t');
	this->carka->tecka = new Tree('n');
	this->carka->tecka->tecka = new Tree('d');
	this->carka->tecka->tecka->tecka = new Tree('b');
	this->carka->tecka->tecka->carka = new Tree('x');

	this->carka->tecka->carka = new Tree('k');
	this->carka->tecka->carka->tecka = new Tree('c');
	this->carka->tecka->carka->carka = new Tree('y');

	this->carka->carka = new Tree('m');
	this->carka->carka->tecka = new Tree('g');
	this->carka->carka->tecka->tecka = new Tree('z');
	this->carka->carka->tecka->carka = new Tree('q');

	this->carka->carka->carka = new Tree('o');
	
}

Tree* Tree::posunuti_tecka()					
{
	return this->tecka;
}

Tree* Tree::posunuti_carka()					
{
	return this->carka;
}

char Tree::get_znak()							
{
	return this->znak;
}

void Tree::Zacatek_prekladu(string nazov_suboru)
{
	ifstream file(nazov_suboru);				
	string line;																
	Tree* current = this;						
	bool capital = true;						

	if (!file.is_open()) {
		cout << "Error: cannot open file " <<endl;
		
	}
	while (getline(file, line))													
	{
		for (size_t i = 0; i < line.length(); i++)								
		{	
			if (line[i] == '/' && line[i + 1] == '/' && line[i + 2] == '/')		
			{
				cout << current->get_znak();
				cout << ".";
				
				capital = true;
				current = this;													
			}
			else if (line[i] == '/' && line[i + 1] == '/' && line[i+2] != '/')
			{
				cout << current->get_znak();
				cout << " ";
				
				current = this;													
			}

			else if (line[i] == '/')											
			{
				if (current != nullptr && current->get_znak() != ' ')			
				{	
					if (capital == true)
					{
						char letter = current->get_znak();
						letter = toupper(letter);
						cout << letter;
						capital = false;
					}
					
					else
					{
						cout << current->get_znak();
						
						
					}
				}
				current = this;													 
				
			}
			else if (line[i] == '.')											
			{
				current = current->posunuti_tecka();
				
			}
			else if (line[i] == '-') 
			{
				current = current->posunuti_carka();
				
			}
			
		}
	}
	if (current != nullptr && current->get_znak() != ' ')					
	{
		cout << current->get_znak();
		capital = false;
	}
	file.close();
}