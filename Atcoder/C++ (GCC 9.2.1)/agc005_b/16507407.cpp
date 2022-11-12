#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SZ = 2e5 + 10, INF = INT64_MAX;
ll n, x, dp[SZ];
vector<ll> vec;

void input() {
	cin >> n >> x;
	vec.resize(n);
	for (int i = 0; i < n; i++) cin >> vec[i];
}

ll badsol() {
	for (int i = 0; i < n; i++) {
		dp[i + 1] = dp[i] + vec[i] + vec[i] * 4 + x;
		ll curAm = 1, curD = 0;
		for (int j = i - 1; j >= 0; j--) {
			curD += (vec[j + 1] - vec[j]) * (curAm + 1) * (curAm + 1);
			curAm++;
			dp[i + 1] = min(dp[i + 1], vec[i] + dp[j] + curD + (vec[j] * (curAm + 1) * (curAm + 1)) + x);
		}
	}

	return dp[n] + n * x;
}

vector<ll> par;
set<ll> u;
pair < ll, vector<ll>> bst = { INF, {} };

ll cnt() {
	ll curVl = 0;
	vector<bool> vis(n);

	for (int i = n - 1; i >= 0; i--) {
		if (vis[i]) continue;

		ll v = i;
		curVl += vec[i] + x;
		ll k = 2;
		while (par[v] != -1) {
			curVl += (vec[v] - vec[par[v]]) * (k * k);
			k++;
			v = par[v];
			vis[v] = 1;
		}
		curVl += vec[v] * k * k;
	}
	curVl += n * x;

	return curVl;
}

ll sol() {
	ll ans = INF;

	par.resize(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			par[j] = -1;
		}
		ll k = 0;
		for (int j = i; j < n; j++) {
			par[j] = k;
			k++;
		}
		ans = min(ans, cnt());
	}

	return ans;
}

ll sol_tern() {
	ll ans = INF;

	par.resize(n);
	int l = 1, r = n;
	while (r - l > 3) {
		int mid = (l + r) / 2;
		ll vl1, vl2;
		for (int j = 0; j < mid; j++) {
			par[j] = -1;
		}
		ll k = 0;
		for (int j = mid; j < n; j++) {
			par[j] = k;
			k++;
		}
		vl1 = cnt();

		for (int j = 0; j < mid + 1; j++) {
			par[j] = -1;
		}
		k = 0;
		for (int j = mid + 1; j < n; j++) {
			par[j] = k;
			k++;
		}
		vl2 = cnt();

		ans = min(ans, min(vl1, vl2));
		
		if (vl2 > vl1) {
			r = mid + 1;
		}
		else {
			l = mid;
		}

	}
	
	for (int i = l; i <= r; i++) {
		if (i < n) {
			ll vl1, vl2;
			for (int j = 0; j < i; j++) {
				par[j] = -1;
			}
			ll k = 0;
			for (int j = i; j < n; j++) {
				par[j] = k;
				k++;
			}
			vl1 = cnt();
			ans = min(ans, vl1);
		}
	}

	return ans;
}

void rand_test() {
	n = rand() % 1000 + 1, x = rand() % 100000 + 1;
	vec.resize(n);
	for (int i = 0; i < n; i++) {
		vec[i] = rand() % 100000 + 1;;
	}
	sort(vec.begin(), vec.end());

	for (int i = 1; i < n; i++) {
		if (vec[i] <= vec[i - 1]) vec[i] = vec[i - 1] + 1;
	}
}

void recur(int ind) {
	if (ind == n) {
		ll curVl = cnt();
		
		bst = min(bst, make_pair(curVl, par));
	}
	else {
		par[ind] = -1;
		for (int i = 0; i < ind; i++) {
			if (u.find(i) == u.end()) {
				u.insert(i);
				par[ind] = i;
				recur(ind + 1);
				par[ind] = -1;
				u.erase(i);
			}
		}

		par[ind] = -1;
		recur(ind + 1);
	}
}

ll stresses() {
	bst.first = INF;
	par.resize(n);
	recur(0);
	return bst.first;
}

int main() {
	fastInp;

	input();

	cout << sol_tern();
	/*srand(1020);
	ll t = 10000;
	while (t--) {
		rand_test();
		ll q = sol(), q3 = sol_tern();


		if (q != q3) {
			cout << n << " " << x << " " << q << " " << q3 << "\n";
			for (auto cur : vec) cout << cur << " ";
			cout << "\n";
			for (auto cur : bst.second) cout << cur << " ";
			cout << "\n";
		}
	}*/

	
	return 0;
}