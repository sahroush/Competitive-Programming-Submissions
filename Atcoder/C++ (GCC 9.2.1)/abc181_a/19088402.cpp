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
ll a[maxn] ;
ll b[maxn];

ll prt[maxn];

ll k;

int32_t main(){
    migmig;
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int i = 1 ; i <= m ; i ++)
		cin >> b[i] , prt[i] = b[i] + ((i) ? prt[i - 1] : 0);
	ll sum = 0;
	int p = m;
	int ans = 0;
	//while(prt[p] + sum > k)p --;
	for(int i = 0 ; i <= n ; i ++){
		sum += a[i];
		if(sum > k)break;
		while(prt[p] + sum > k)p --;
		ans = max(ans , i + p);
	}	
	cout << ans;
    return(0);
}
