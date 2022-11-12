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
int a[maxn];
int b[maxn];

ld med(int* x){
	sort(x , x + n);
	if(n%2)
		return(x[n/2]);
	return((x[n/2] + x[n/2 - 1])/2.0);
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> a[i] >> b[i];
	ld l = med(a);
	ld r = med(b);
	if(n%2)
		cout << int(r - l) + 1;
	else
		cout << int((r - l)/0.5) + 1;
    return(0);
}
