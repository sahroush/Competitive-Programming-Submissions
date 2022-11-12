#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];
int cnt[1 << 4];
int dp[1 << 17];

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1 , u , v, w ; i < n ; i ++)
		cin >> u >> v >> w , a[u] ^= w , a[v] ^= w;
	int ans = 0;
	for(int i = 0 ; i < n ; i ++)
		cnt[a[i]] ++;
	for(int i = 1 ; i < 16 ; i ++)
		ans += cnt[i] / 2 , cnt[i] &= 1;
	for(int i = 1 ; i < 16 ; i ++)
		ans += cnt[i];
	int msk = 0;
	for(int i = 1 ; i < 16 ; i ++)msk |= (1 << i) * cnt[i];
	for(int i = msk ; i ; i = (i - 1) & msk){
		int xr = 0;
		for(int j = 1 ; j < 16 ; j ++)if(i & (1 << j)){
			if(cnt[j])xr ^= j;
			else xr = -1;
		}
		if(xr == 0)dp[i>>1] = 1;
	}
	msk >>= 1;

	for(int i = 0 ; i < 1 << 15 ; i ++)
		for(int j = i ; j ; j = (j - 1) & i)
			if(dp[j] && dp[i ^ j] && i ^ j)
				dp[i] = max(dp[i] , dp[j] + dp[i ^ j]);
	cout << ans - dp[msk];
	return(0);
}
