/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e7 + 100;
const ll mod =998244353;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int fact[maxn+1];
int inv[maxn+1];

int c(int r , int n){
	return((fact[n] * 1LL * inv[r])%mod * inv[n - r])%mod;
}

int f(int x){
	return(c(x , n) * 1LL * pw(2 , n - x))%mod;
}	

int32_t main(){
    migmig;
	fact[0] = inv[0] = 1;
	for(int i = 1 ; i <= maxn ; i ++)
		fact[i] = (fact[i - 1] * 1LL * i)%mod;
	inv[maxn] = pw(fact[maxn] , mod - 2);
	for(int i = maxn - 1 ; i > 0 ; i --)
		inv[i] = (inv[i + 1] * 1LL * (i + 1))%mod;
	cin >> n;
	ll ans = pw(3 , n);
	for(int i = n/2 + 1 ; i <= n ; i ++)
		ans = (ans - f(i) * 2LL + mod * 10)%mod;
	cout << ans;
    return(0);
}
