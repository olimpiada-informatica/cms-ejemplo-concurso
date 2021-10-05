#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {

	ll m, n;
	cin >> m >> n;
	vi a(n);
	for(auto &x : a) cin >> x;
	ll ans = 0;
	
	for(ll i=0; i < n; ++i) {
		for(ll k=i+1; k < n && a[k]-a[i] < m; k++) {
			ans += m-(a[k]-a[i]);
		}
	}
	cout << ans << endl;
	
}