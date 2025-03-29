#include<iostream>

using namespace std;

int main() {
	int x1, y1, x2, y2, x, y;
	cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
	if (x > x1 && x < x2 && y > y2) {
		cout << "N";
	}
	else if (x > x1 && x < x2 && y < y1) {
		cout << "S";
	}
	else if (y > y1 && y < y2 && x < x1) {
		cout << "W";
	}
	else if (y > y1 && y < y2 && x > x2) {
		cout << "E";
	}
	else if (y > y2 && x < x1) {
		cout << "NW";
	}
	else if (y > y2 && x > x2) {
		cout << "NE";
	}
	else if (y < y1 && x < x1) {
		cout << "SW";
	}
	else if (y < y1 && x > x2) {
		cout << "SE";
	}
}
