//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e6 + 10;
const ll mod = 998244353;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll fact[maxn] , inv[maxn] , n , m , ans;

ll C(ll r , ll n){return ((fact[n] * inv[r] % mod) * inv[n - r] % mod);}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	fact[0] = inv[0] = 1;
	for(int i = 1 ; i < maxn ; i ++) fact[i] = (fact[i - 1] * i) % mod , inv[i] = pw(fact[i] , mod - 2);
	cin >> n >> m;
	if(n > m)swap(n , m);
	for(int i = 1 ; i <= n ; i ++) ans = (ans + (C(i , 2*i) * C(n - i , n + m - 2*i) % mod))%mod;
	cout << (ans * pw(C(n , n + m)*2 , mod - 2) + m)%mod;
	return(0);
}
