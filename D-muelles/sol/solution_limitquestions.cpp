#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int MAX_W = 1e5;

int num_ques = 0;

vi lc;

bool ask(int i, int j, int w) {
	cout << "? " << i << " " << j << " " << w << endl;
	string s;
	cin >> s;
	num_ques++;
	if(s == "FIRST") return true;
	return false;
}

void query_lc(int p, int l, int r, int i, vector<int>& c) {
	c.push_back(lc[p]);
	if(l < r) {
		int m = (l+r)/2;
		if(i <= m) query_lc(2*p, l, m, i, c);
		else query_lc(2*p+1, m+1, r, i, c);
	}
}

void add_lc(int p, int l, int r, int i) {
	int j = lc[p];
	if(j == -1) {
		lc[p] = i;
		return;
	}
	if(l == r) {
		if(ask(i, j, l)) {
			lc[p] = i;
		}
	}
	else {
		int m = (l+r)/2;
		bool al = ask(i, j, l);
		bool am = ask(i, j, m);
		if(al && am) {
			lc[p] = i;
			add_lc(2*p+1, m+1, r, j);
		}
		else if(al && !am) {
			add_lc(2*p, l, m, i);
		}
		else if(!al && am) {
			lc[p] = i;
			add_lc(2*p, l, m, j);
		}
		else {
			add_lc(2*p+1, m+1, r, i);
		}

	}
}

void add_lichao(int i) {
	add_lc(1, 1, MAX_W, i);
}

int main() {
	int n;
	cin >> n;
	lc = vi(4*MAX_W, -1);

	for(int i=0; i < n; ++i) {
		add_lichao(i);
	}

	while(num_ques < 20000) ask(0, 1, 1);

	num_ques = 0;

	cout << "!" << endl;

	while(true) {
		string s;
		cin >> s;
		if(s == "QUESTION") {
			int qw;
			cin >> qw;

			vector<int> cand;
			query_lc(1, 1, MAX_W, qw, cand);
			int cmx = cand[0];
			for(int i=1; i < (int)cand.size(); ++i) {
				if(cand[i] != -1) {
					if(ask(cand[i], cmx, qw)) cmx = cand[i];
				}
			}

			while(num_ques < 20) ask(0, 1, 1);

			num_ques = 0;

			cout << "! " << cmx << endl;

		}
		else break;
	}
}