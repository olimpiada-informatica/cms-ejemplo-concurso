
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;


void WA() {
	cout << "0.0\n";
	exit(0);
}

void AC() {
	cout << "1.0\n";
	exit(0);
}

int main(int argc, char **argv) {

	FILE *finp = fopen(argv[1], "r");
	//FILE *fres = fopen(argv[2], "r");
	freopen(argv[3], "r", stdin);
	

	int n, m;
	fscanf(finp, "%d", &n);
	fscanf(finp, "%d", &m);

	string ans;
	cin >> ans;
	if(n&1 || m&1) {
		if(ans == "NO") AC();
		else WA();
	}
	else {
		if(ans != "SI") WA();
	}

	vvi v(n, vi(m, 0));

	for(int i=0; i < n; ++i) {
		string s;
		if(!(cin >> s)) WA();
		if(s.length() != m) WA();
		for(int j=0; j < m; ++j) {
			if(s[j] != '.' && s[j] != '#') WA();
			if(s[j] == '#') v[i][j] = 1;
		}
	}

	int b = 0;
	int w = 0;
	int ae = 0;
	int ad = 0;

	for(int i=0; i < n; ++i) {
		for(int j=0; j < m; ++j) {
			if(v[i][j]) b++;
			else w++;
			if(j+1 < m) {
				if(v[i][j] == v[i][j+1]) ae++;
				else ad++;
			}
			if(i+1 < n) {
				if(v[i][j] == v[i+1][j]) ae++;
				else ad++;
			}

		}
	}
	if(b == w && ae == ad) AC();
	WA();
	return 0;

}

