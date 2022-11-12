#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SZ = (2 << 16), LG = 18, INF = 1e9 * 1e6;
ll n, m;
ll grid[LG][LG], inter[SZ], dp[SZ], mx[SZ];

int main() {
	fastInp;

	cin >> n >> m;

	for (int i = 0; i < LG; i++) {
		for (int j = 0; j < LG; j++) grid[i][j] = INF;
	}

	ll sum = 0;
	for (int i = 0; i < m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		sum += c;
		u--; v--;
		grid[u][v] = c;
		grid[v][u] = c;
	}

	ll pw = (1ll << n);
	for (int i = 0; i < pw; i++) {
		ll cur = 0;
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (((i >> k) & 1) && ((i >> j) & 1) && grid[k][j] != INF) {
					cur += grid[k][j];
				}
			}
		}

		inter[i] = cur;
	}

	for (int i = 0; i < pw; i++) {
		for (int j = 0; j < LG; j++) dp[i] = -INF;
	}

	for (int i = 0; i < LG; i++) dp[(1ll << i)] = 0;
	dp[1] = 0;
	for (int i = 2; i < pw; i++) {
		for (int j = 0; j < LG; j++) {
			for (int k = 0; k < LG; k++) {
				if (j != k && (i & (1ll << k)) && (i & (1ll << j)) && grid[j][k] != INF) {
					ll msk = i ^ (1ll << j);
					dp[i] = max(dp[i], dp[msk] + grid[k][j]);
				}
			}
		}
	}

	ll ans = -INF;

	for (int i = 0; i < pw; i++) {
		if (!(i & 1)) continue;
		if (!((i >> (n - 1)) & 1)) continue;
		for (int sub = i; true; sub = ((sub - 1) & i)) {
			for (int j = 0; j < LG; j++) {
				if ((i >> j) & 1) {
					ll msk = (i ^ sub);
					if ((msk & 1) && ((msk >> (n - 1)) & 1)) dp[i] = max(dp[i], dp[msk] + inter[sub | (1ll << j)]);
				}
			}
			if (sub == 0) break;
		}
		ans = max(ans, dp[i]);
	}

	cout << sum - ans;

	return 0;
}