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

int n;
char aa , ab , ba , bb;

ll F[maxn];

ll f(int x){
	if(x <= 1)return(F[x] = 1);
	if(F[x])return(F[x]);
	return( F[x] = (f(x - 1) + f(x - 2))%mod );
}

int32_t main(){
    migmig;
	cin >> n >> aa >> ab >> ba >> bb;
	if(n <= 3)dokme(1);
	if(aa == ab && ab == ba && ba == bb)dokme(1);
	if(ab == 'B'){
		if(bb == 'B')dokme(1);
		if(ba == 'A')dokme(pw(2 , n - 3));
		dokme(f(n - 2));
	}
	if(aa == 'A')dokme(1);
	if(ba == 'B')dokme(pw(2 , n - 3));
	dokme((f(n - 2)));
	
    return(0);
}
