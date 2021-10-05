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

	int l = 0;
	int r = n-1;
	while(l < r) {
		int mid = (l+r)/2;
		if(ask(mid, mid+1)) {
			r = mid;
		}
		else {
			l = mid+1;
		}
	}
	
	cout << "! " << l << endl;
}