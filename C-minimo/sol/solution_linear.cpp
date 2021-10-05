#include<bits/stdc++.h>

using namespace std;

int n;
bool ask(int x, int y) {
	if(y == n) return false;
	cout << "? " << x << " " << y << endl;

	char r;
	cin >> r;

	if(r == '-') exit(0);
	if(r == '<') return true;
	return false;
}

int main() {
	cin >> n;

	for(int i=0; i < n; ++i) {
		if(ask(i, i+1)) {
			cout << "! " << i << endl;
			exit(0);
		}
	}
	
	
}