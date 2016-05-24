//      main.cpp
//      Copyright (C) 2015 lengagne (lengagne@gmail.com)
// 
//      This program is free software: you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation, either version 3 of the License, or
//      (at your option) any later version.
// 
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
// 
//      You should have received a copy of the GNU General Public License
//      along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//		from 2015:  Université Blaise Pascal / axis : ISPR / theme MACCS

#include <iostream>

void print_help()
{
	std::cout<<"Voici l'aide"<<std::endl;
}

int main (int argv, char *argc[])
{
	
	
	if (argv == 1)
	{
		print_help();
		return 1;
	}
	std::cout<<" Programme de gestion d'emploi du temps"<<std::endl;
	return 1;
	
}
