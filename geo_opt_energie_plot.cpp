#include <iostream>
#include <fstream>
#include <regex>
#include <boost/algorithm/string.hpp>

using namespace std;

int main() {
	ifstream geo_opt_f("2-PorYPc-1stGEO-pos-1.xyz");
	ofstream ergebnisse_f("Energies.dat");
	string line;
	regex energie("(\\s*)(i =)(\\s*[0-9]*,)\\s*(E =)\\s*([+-]?([0-9]*[.])?[0-9]+)");
	// (^|\n)Um die Anfang eines linie zu finden
	// * : heisst Egal wie viele von diese Ausdruck
	// \\s : heisst \ fuer C++ compilatoren, \s ein leeres Ausdruck

	if (geo_opt_f.is_open()) {
	 while (getline(geo_opt_f,line)) {
			if (regex_match(line, energie)){
				cout << line << endl ;
				ergebnisse_f << line << endl;
			}
	}
	geo_opt_f.close();
	ergebnisse_f.close();
	}

	else cout << "Datei koennte nicht heruntergeladen" << endl;

	return 0;
}
