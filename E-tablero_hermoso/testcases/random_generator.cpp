#include<iostream>
#include<set>
#include<random>

using namespace std;

int main(int argc, char** argv) {
	if(argc != 7) {
		cerr << "Usage ./generator n_min n_max m_min m_max even seed" << endl;
	}
	int n_min, n_max, m_min, m_max, even, seed;
	n_min = atoi(argv[1]);
	n_max = atoi(argv[2]);
	m_min = atoi(argv[3]);
	m_max = atoi(argv[4]);
	even = atoi(argv[5]);
	seed = atoi(argv[6]);


	mt19937 gen(seed);

	if(even) {
		m_max /= 2;
		n_max /= 2;
	}

	uniform_int_distribution<> m_dist(m_min, m_max);
	uniform_int_distribution<> n_dist(n_min, n_max);

	int n = n_dist(gen);
	int m = m_dist(gen);

	if(even) {
		n *= 2;
		m *= 2;
	}

	cout << n << " " << m << endl;

}