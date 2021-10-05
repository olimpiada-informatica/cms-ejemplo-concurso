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

	vector<int> v(n);
	for(int i=0; i < n; ++i) {
		v[i] = i;
	}
	shuffle(v.begin(), v.end(), gen);
	for(int i=0; i < n; ++i) {
		cout << v[i] << " ";
	}
	
	cout << endl;

	


}