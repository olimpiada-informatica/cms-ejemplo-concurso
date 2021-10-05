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
		int l = -1;
		int r = n;
		while(l+1 < r) {
			int mid = (l+r)/2;
			if(ask(i, mid)) {
				l = mid;
			}
			else {
				r = mid;
			}
		}
		h = max(h, l+1);
	}
	cout << "! " << h << endl;
}