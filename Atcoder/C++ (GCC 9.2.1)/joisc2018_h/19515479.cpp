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

const ll maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int cur = 0;
vector < string > vec;

string nt(string s){
	string ans = "";
	for(int i = 0 ; i < (int)s.size() ; i ++)
		ans += ((s[i] == 'A') ? "B" : "A");
	return(ans);
}

void solve(){
	int sz = (1 << cur);
	cur++;
	string s = "";
	auto v = vec;
	vec.clear();
	for(int i = 0 ; i < sz ; i ++)
		s += "A";
	for(int i = 0 ; i < sz ; i ++)
		s += "B";
	vec.pb(s);
	for(auto s : v)
		vec.pb(s + s);
	for(auto s : v)
		vec.pb(nt(s) + s);
}

int32_t main(){
    migmig;
	cin >> n;
	cout << (1 << n) -1 << endl;
	while(n -- ){
		solve();
	}
	for(auto s : vec)
		cout << s << endl;
    return(0);
}
