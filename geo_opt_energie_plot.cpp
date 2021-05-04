#include <iostream>
#include <fstream>
#include <regex>
#include <boost/algorithm/string.hpp>

using namespace std;

int main() {
	ifstream geo_opt_f("2-PorYPc-1stGEO-pos-1.xyz");
	ofstream ergebnisse_f("Energies.dat");
	std::string line;
	std::regex energie("(\\s*)(i =)(\\s*[0-9]*,)\\s*(E =)\\s*([+-]?([0-9]*[.])?[0-9]+)");
	std::string iter_num;
	std::string iter_ene;
	// (^|\n)Um die Anfang eines linie zu finden
	// * : heisst Egal wie viele von diese Ausdruck
	// \\s : heisst \ fuer C++ compilatoren, \s ein leeres Ausdruck

	if (geo_opt_f.is_open()) {
	 while (getline(geo_opt_f,line)) {
			if (regex_match(line, energie)){
				//iter_num = line.substr(0,line.find(","));
				iter_num = line.substr(10,3);
				iter_ene = line.substr(line.find("-"));

				cout << iter_num << " " << iter_ene << endl;
				ergebnisse_f << iter_num << "  " << iter_ene << endl;
			}
	}
	geo_opt_f.close();
	ergebnisse_f.close();
	}

	else cout << "Datei koennte nicht herunterladen" << endl;

	return 0;
}
