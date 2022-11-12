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

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;

int32_t main(){
    migmig;
	cin >> n >> m;
	if(m < 0)
		dokme(-1);
	if(m and m+2 > n)
		dokme(-1);
	int l , r;
	l = 1e6 , r = 1e6;
	for(int i = 0 ; i < m+1 ; i ++){
		cout << l << ' ' << l + 1 << endl;
		l = l + 2;
		n--;
	}
	if(m)cout << 1e6 - 1 << ' ' << l << endl, n--;
	l = 2e5 , r = 2e5;
	while(n--)
		cout << --l << ' ' << ++r << endl;
    return(0);
}
