//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
//#pragma GCC target("avx,avx2,sse,sse2,fma")
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

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll fact[maxn];

ll inv[maxn];

ll n , k;

ll a[maxn];

ll sum[maxn];

int32_t main(){
    migmig;
	cin >> n >> ::k;
	fact[0] = inv[0] = 1;
	for(int i = 1 ; i <= ::k ; i ++)
		fact[i] = (fact[i - 1] * i)%mod , inv[i] = pw(fact[i] , mod - 2);
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int i = 0 ; i <= ::k ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			sum[i] = (sum[i] + pw(a[j] , i))%mod;
	for(int x = 1 ; x <= ::k ; x ++){
		ll ans = 0;
		for(int k = 0 ; k <= x ; k ++){
			ll res = (sum[k] * sum[x - k])%mod;
			res = (res * inv[k])%mod;
			res = (res * inv[x - k])%mod;
			ans = (ans + res)%mod;
		}
		ans = (ans * fact[x])%mod;
		ans = (ans - (sum[x] * pw(2 , x))%mod + mod)%mod;
		cout << (ans*pw(2 , mod - 2))%mod << endl;
	}
    return(0);
}
