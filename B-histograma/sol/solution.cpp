#include<bits/stdc++.h>

using namespace std;

int n;
bool ask(int x, int y) {
	if(y == n) return false;
	cout << "? " << x << " " << y << endl;

	int r;
	cin >> r;

	if(r == -1) exit(0);
	if(r == 1) return true;
	return false;
}

int main() {
	cin >> n;

	int h = 0;
	for(int i=0; i < n; ++i) {
		while(ask(i, h)) h++;
	}
	cout << "! " << h << endl;
}