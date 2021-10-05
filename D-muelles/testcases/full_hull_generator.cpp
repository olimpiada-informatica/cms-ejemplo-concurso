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
	ll min_gap = atol(argv[3]);
	ll max_gap = atol(argv[4]);
	int min_q = atoi(argv[5]);
	int max_q = atoi(argv[6]);

	int n = rnd.next(min_n, max_n);

	cout << n << endl;

	vi a(n);
	vi b(n);

	ll curx = 1;
	a[0] = 1;
	b[0] = 1e17;

	curx += rnd.next(min_gap, max_gap);

	for(ll i=1; i < n; ++i) {
		a[i] = i+1;
		b[i] = -(i+1)*curx + a[i-1]*curx+b[i-1];

		curx += rnd.next(min_gap, max_gap);

		if(curx > 1e5) return 1;

	}

	vi p(n);
	for(int i=0; i < n; ++i) p[i] = i;

	::shuffle(p.begin(), p.end());



	for(int i=0; i < n; ++i) {
		cout << a[p[i]] << " " << b[p[i]] << endl;
	}

	int q = rnd.next(min_q, max_q);

	cout << q << endl;

	for(int i=0; i < q; ++i) {
		cout << rnd.next(1, MAX_WEIGHT) << endl;
	}



	
    return 0;
}