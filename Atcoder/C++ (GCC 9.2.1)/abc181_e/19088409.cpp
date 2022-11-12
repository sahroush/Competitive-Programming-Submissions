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
int x[maxn] , y[maxn];

bool chk(int a , int b , int c){
	if(a == b or b == c or a == c)
		return(0);
	ll difx = x[b] - x[a];
	ll dify = y[b] - y[a];
	ll diffx = x[c] - x[b];
	ll diffy = y[c] - y[b];
	if(difx * diffy == diffx*dify)
		return(1);
	return(0);
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> x[i] >> y[i];
	for(int i = 0 ; i < n ; i ++)
		for(int j = 0 ; j < n ; j ++)
			for(int k =0 ; k < n ; k ++)
				if(chk(i , j , k))
					dokme("Yes");
	cout << "No";
    return(0);
}
