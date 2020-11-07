#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

unsigned long long int binom(unsigned long long int a, unsigned long long int b) {
	unsigned long long int num = 1;
	unsigned long long int den = 1;

	for (unsigned long long int i = 1; i <= a; i++) {
		num *= i;
	}

	for (unsigned long long int i = 1; i <= b; i++) {
		den *= i;
	}

	unsigned long long int tmp = 1;
	for (unsigned long long int i = 1; i <= a - b; i++) {
		tmp *= i;
	}

	den *= tmp;

	cout << num << " " << den << endl;

	return num/den;
}

pair<int, int> find_ones(int start, int end, vector<int> array) {
	int a = -1, b = end;

	// find first one
	for (int i = start; i < end; i++) {
		if (array[i] == 1) {
			a = i;
			break;
		}
	}

	// find last one
	for (int i = a + 1; i < end; i++) {
		if (array[i] != 1) {
			b = i;
			break;
		}
	}

	return make_pair(a, b);
}

pair<pair<int, int>, int> find_twos(int start, int end, vector<int> array) {
	int a = -1, b = end;
	int num_twos = 0;

	// find first two
	for (int i = start; i < end; i++) {
		if (array[i] == 2) {
			a = i;
			num_twos = 1;
			break;
		}
	}

	// find last non-consecutive two
	for (int i = a + 1; i < end; i++) {
		if (array[i] == 2) {
			num_twos++;
			b = i;
		}
	}

	return make_pair(make_pair(a, b), num_twos);
}

pair<int, int> find_threes(int start, int end, vector<int> array) {
	int a = -1, b = end;

	// find first one
	for (int i = start; i < end; i++) {
		if (array[i] == 3) {
			a = i;
			break;
		}
	}

	// find last one
	for (int i = a + 1; i < end; i++) {
		if (array[i] != 3) {
			b = i;
			break;
		}
	}

	return make_pair(a, b);
}

int main() {
	int n;
	cin >> n;
	
	unsigned int num = 0;

	vector<int> songs;

	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		songs.push_back(s);
	}

	for (int i = 0; i < n; i++) {
		pair<int, int> ones = find_ones(i,n,songs);
		cout << "ones: " << ones.first << " " << ones.second << endl;
		if (ones.first == -1) {
			break;
		}
		for (int j = ones.second; j < n; j++) {
			pair<pair<int, int>, int> twos = find_twos(j, n, songs);
			pair<int, int> tworange = twos.first;
			cout << "twos: " << twos.first.first << " " << twos.first.second << " " << twos.second << endl;
			if (twos.first.first == -1) {
				break;
			}
			for (int k = tworange.second; k < n; k++) {
				pair<int, int> threes = find_threes(k,n,songs);
				cout << "threes: " << threes.first << " " << threes.second << endl;
				if (threes.first == -1) {
					break;
				}
				k = threes.second;

				unsigned int tmp = 0;
				tmp += ones.second - ones.first;
				tmp *= threes.second - threes.first;
				tmp *= pow(2, twos.second-twos.first) - 1;
				num += tmp;
			}
			j = twos.second;
		}
		i = ones.second;
	}

	cout << num << endl;
	return 0;
}
