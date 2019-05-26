/*
 * Main.cpp
 *
 *  Created on: 15 de dez de 2017
 *      Author: cesar
 */

#include "src/mystring.hpp"

#include <cstring>
#include <iostream>
using namespace std;

int teste(){
	const char *str = "  Hello  my   beautiful  world! ";
	cout << "begin" << endl;
	std::vector<std::string> a = mystring::explode(str);
	for(unsigned i=0; i<a.size(); ++i) {
		cout << a[i].c_str() << endl;
	}
	cout << " - - - " << str << strlen(str) << endl;
	mystring oie(str, strlen(str));
	std::vector<const char *> b = oie.explode();
	for(unsigned i=0; i<b.size(); ++i) {
		cout << b[i] << endl;
	}
	cout << " - - - " << str << strlen(str) << endl;
	mystring aie = mystring (str, strlen(str));
	for(unsigned i=0; i<5; ++i) {
		cout << aie.pop_front() << endl;
	}
	cout << "yeah" << endl;
	return 0;
}

int main(){
	teste();
	return 0;
}


