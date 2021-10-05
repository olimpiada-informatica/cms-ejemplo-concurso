#include<iostream>
#include<set>
#include<random>

using namespace std;

int main() {
	int m_min, m_max, n_min, n_max, a_min, a_max, seed;
	cin >> m_min >> m_max >> n_min >> n_max >> a_min >> a_max >> seed;

	mt19937 gen(seed);

	uniform_int_distribution<> m_dist(m_min, m_max);
	uniform_int_distribution<> n_dist(n_min, n_max);
	uniform_int_distribution<> a_dist(a_min, a_max);

	int m = m_dist(gen);
	int n = n_dist(gen);

	set<int> a_set;
	for(int i=0; i < n; ++i) {
		int a;
		do {
			a = a_dist(gen);
		} while(a_set.find(a) != a_set.end());
		a_set.insert(a);
	}
	cout << m << " " << n << endl;
	for(auto it = a_set.begin(); it != a_set.end(); ++it) cout << *it << " ";
	cout << endl;

}