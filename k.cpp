#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

f(string a, string b) {
	for (int i = 0; i < a.size(); i++) {
	}
}

int main() {
	string a, b;
	cin >> a >> b;

	string c, d;
	if (a.size() > b.size()) {
		b.insert(0, a.size() - b.size(), '0');
	} else {
		a.insert(0, b.size() - a.size(), '0');
	}

	cout << a << endl << b << endl;

	

	return 0;
}
