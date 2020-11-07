#include <iostream>
#include <array>
#include <vector>
#include <cmath>

using namespace std;

unsigned long long int MODULO = 1000000007;

int cool_funktion(vector<int> songs) {
	array<unsigned long long int, 4> count = {0,0,0,0};
	for (unsigned long int i = 0; i < songs.size(); i++) {
		if (songs[i] == 1) {
			count[1]++;
			count[1] %= MODULO;
		} else if (songs[i] == 2) {
			count[2] += count[2] + count[1];
			count[2] %= MODULO;
		} else if (songs[i] == 3) {
			count[3] += count[2];
			count[3] %= MODULO;
		}
	}

	return count[3];
}

int main() {
	int n;
	cin >> n;

	vector<int> songs;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		songs.push_back(s);
	}

	cout << cool_funktion(songs) % 1000000007 << endl;

	return 0;
}
