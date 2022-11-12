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

const ll maxn  = 2e5 + 100;
const ll mod =998244353;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
string x;

ll f[maxn];
ll ans[maxn];

ll calc(int a){
	string s = "";
	string rs= "";
	for(int i = 0 ; i < a ; i ++)	
		s += x[i] , rs += ((x[i] == '0')? '1' : '0');
	ll ans = 0;
	ll p2 = 1;
	for(int i = a-1 ; i >= 0 ; i --)
		ans = (ans +  p2*(s[i] == '1'))%mod , p2 = (p2 + p2)%mod;
	string res = "";
	int cur = 0;
	while((int)res.size()!=n)
		res += ((cur)?rs : s) , cur = 1 - cur;
	return((ans + (res <= x))%mod);
}

int32_t main(){
    migmig;
	cin >> n >> x;
	ll ans = 0;
	for(int i = 1 ; i <= n ; i ++)if((2*n)%(i*2) == 0 and ((2*n)/(i*2))%2){
		f[i] = calc(i);
		for(int j = 1 ; j < i ; j ++)if(i%j == 0)
			f[i] = (f[i] - f[j] + mod)%mod;
		ans = ((f[i]*(2*i))%mod + ans)%mod;
	}
	cout << ans;
    return(0);
}
