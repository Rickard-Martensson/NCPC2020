#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	unsigned long int n;
	cin >> n;

	vector<int> songs;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		songs.push_back(s);
	}

	unsigned long long int num = 0;

	for (unsigned long int i = 0; i < n; i++) {
//		cout << "i " << i << " " << songs[i] << endl;
		if (songs[i] == 1) {
			for (unsigned long int j = n - 1; j > i; j--) {
//			cout << "j " << j << " " << songs[j] << endl;
				if (songs[j] == 3) {
					unsigned long int twos = 0;
					for (unsigned long int k = i+1; k < j; k++) {
						if (songs[k] == 2) {
							twos++;
						}
					}
//					cout << twos << endl;
					num += pow(2, twos) - 1;
					num %= (unsigned long long int)(1000000007);
				}
			}
		}
	}

	cout << num << endl;

	return 0;
}
