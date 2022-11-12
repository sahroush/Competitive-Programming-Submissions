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

const ll maxn  = 5e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
int a[maxn];

ll fact[maxn];
ll inv[maxn];


ll c(ll r , ll n){
	ll ans = 1;
	for(int i = 1 ; i <= r ; i ++){
		ans = ans * pw(i , mod - 2);
		ans%=mod;
		ans = ans * (n - i + 1);
		ans%=mod;
	}
	dokme(ans);
}

int32_t main(){
    migmig;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i  ++)
		cin >> a[i] , m-=a[i] , a[0]+=a[i];
	if(m == 0)dokme(1);
	if(m < 0)dokme(0);
	cout << c(n + a[0], n + a[0] + m);
    return(0);
}
