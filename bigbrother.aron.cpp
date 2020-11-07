#include <iostream>
#include <list>
#include <utility>
using namespace std;

int main(int argc, char **argv) {
	int n;
	cin >> n;

	list<pair<int, int>> floor;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		floor.push_back(make_pair(x, y));
	}

	return 0;
}
