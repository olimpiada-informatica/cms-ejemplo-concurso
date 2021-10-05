#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {

	if(argc != 6) {
		cerr << "Usage ./generator n_min n_max h_min h_max seed" << endl;
		return 0;
	}
	int n_min, n_max, h_min, h_max, seed;
	n_min = atoi(argv[1]);
	n_max = atoi(argv[2]);
	h_min = atoi(argv[3]);
	h_max = atoi(argv[4]);
	seed = atoi(argv[5]);

	mt19937 gen(seed);

	int n = uniform_int_distribution<>(n_min, n_max)(gen);

	h_min = min(h_min, n);
	h_max = min(h_max, n);

	cout << n << endl;

	for(int i=0; i < n; ++i) {
		cout << uniform_int_distribution<>(h_min, h_max)(gen) << " ";
	}
	cout << endl;

	


}