/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =998244353;
const ld PI = acos((ld)-1);
#define int ll
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , m;
ll e[maxn];
ll p[maxn];
ll cnt[maxn];
ll dp[maxn];
ll f[maxn];

int32_t main(){
    migmig;
	cin >> n >> m;
	p[0] = 1;
	fill(dp , dp + maxn , 1);
	for(int i = 0 ;  i < m ; i ++){
		int u , v;
		cin >> u >> v;
		u-- , v--;
		e[i] = (1 << u) | (1 << v);
		p[i+1] = (p[i] * 2LL)%mod;
	}
	for(int i = 0 ; i  < (1 << n) ; i ++)
		for(int j = 0 ; j < m ; j ++)
			if((i&e[j]) == e[j])
				cnt[i]++;
	for(int i = 0 ; i  < (1 << n) ; i ++)
		for(int j = i ; j ; j = (j - 1) & i )
			dp[i] += p[cnt[i] - cnt[j] - cnt[i ^ j]] , dp[i]%=mod;
	dp[0] = 0;
	for(int i = 0 ; i < (1 << n) ; i ++){
		f[i] = dp[i];
		for(int j = i  ; j  ; j = (j - 1) & i)
			if(j&(i&-i))
				f[i] = (f[i] - (f[j] * dp[i^j])%mod)%mod , f[i] += mod , f[i]%=mod;
	}
	f[(1 << n) - 1] = (f[(1 << n) - 1] * pw(2 , mod - 2))%mod;
	cout << f[(1 << n) - 1];
    return(0);
}
