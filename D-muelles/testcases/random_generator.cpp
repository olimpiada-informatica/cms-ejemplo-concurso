#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;

const int MAX_WEIGHT = 1e5;

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	int min_n = atoi(argv[1]);
	int max_n = atoi(argv[2]);
	ll min_a = atol(argv[3]);
	ll max_a = atol(argv[4]);
	ll min_b = atol(argv[5]);
	ll max_b = atol(argv[6]);
	int min_q = atoi(argv[7]);
	int max_q = atoi(argv[8]);

	int n = rnd.next(min_n, max_n);

	cout << n << endl;

	for(int i=0; i < n; ++i) {
		cout << rnd.next(min_a, max_a) << " ";
		cout << rnd.next(min_b, max_b) << endl;
	}

	int q = rnd.next(min_q, max_q);

	cout << q << endl;

	for(int i=0; i < q; ++i) {
		cout << rnd.next(1, MAX_WEIGHT) << endl;
	}



	
    return 0;
}