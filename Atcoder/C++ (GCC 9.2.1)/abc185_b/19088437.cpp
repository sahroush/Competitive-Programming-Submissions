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
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 3e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

const int lg = 31;

int n , q;
int a[maxn];
int fen[lg][maxn];

void add(int x , int pos , int (&fen)[maxn]){
	for(pos += 5 ; pos < maxn ; pos += pos & -pos)
		fen[pos] += x;
}

int get(int pos , int (&fen)[maxn]){
	int ans = 0;
	for(pos += 5 ; pos ; pos -= pos & -pos)
		ans += fen[pos];
	return(ans);
}

int get(int l , int r , int (&fen)[maxn]){
	return(get(r , fen) - get(l - 1 , fen));
}

void add(int x){
	for(int i = 0 ; i < lg ; i ++)
		if(a[x]&(1 << i))
			add(1 , x , fen[i]);
}

void rm(int x){
	for(int i = 0 ; i < lg ; i ++)
		if(a[x]&(1 << i))
			add(-1 , x , fen[i]);
}

int get(int l , int r){
	int ans = 0;
	for(int i = 0 ; i < lg ; i ++)
		if(get(l , r , fen[i])%2)
			ans += (1 << i);
	return(ans);
}

int32_t main(){
    migmig;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] , add(i);
	while(q --){
		int t , l , r;
		cin >> t >> l >> r;
		if(t == 1){
			rm(l);
			a[l] ^= r;
			add(l);
		}
		else{
			cout << get(l , r) << endl;
		}
	}
    return(0);
}
