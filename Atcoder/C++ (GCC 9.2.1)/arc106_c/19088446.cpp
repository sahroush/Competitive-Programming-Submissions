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

ll n;

int32_t main(){
    migmig;
	cin >> n;
	ll p5 = 1;
	for(int i = 0 ; i <= 26 ; i ++){
		if(p5 >=  n)break;
		ll p3 = 1;
		int j = 0;
		while(n - p5 > p3){
			p3*=3;
			j++;
		}
		if(n - p5 == p3 and i > 0 and j > 0){
			cout << j << ' ' << i;
			return(0);
		}
		p5 = p5 * 5;
	}
	cout << -1;
    return(0);
}
