#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {

	if(argc != 4) {
		cerr << "Usage ./generator n_min n_max seed" << endl;
		return 0;
	}
	int n_min, n_max, seed;
	n_min = atoi(argv[1]);
	n_max = atoi(argv[2]);
	seed = atoi(argv[3]);

	mt19937 gen(seed);

	int n = uniform_int_distribution<>(n_min, n_max)(gen);

	cout << n << endl;

	int l = uniform_int_distribution<>(0, n-1)(gen);
	int r = l;

	vector<int> v(n);
	v[l] = 0;
	l--;
	r++;

	for(int i=1; i < n; ++i) {
		if(l >= 0 && (uniform_int_distribution<>(0, 1)(gen) || r == n)) {
			v[l] = i;
			l--;
		}
		else {
			v[r] = i;
			r++;
		}
	}
	for(int i=0; i < n; ++i) {
		cout << v[i] << " ";
	}
	cout << endl;

	


}