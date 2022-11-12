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
string t;

string s = "";

int32_t main(){
    migmig;
	cin >> n;
	cin >> t;
	if(n == 1){
		if(t == "1"){
			cout << pw(10 , 10 , 1e18)*2;
		}
		else{
			cout << pw(10 , 10 , 1e18);
		}
		return(0);
	}
	if(n == 2){
		if(t == "00")dokme(0);
		if(t == "11")dokme((ll)1e10);
		if(t == "10")dokme((ll)1e10);
		dokme((ll)1e10 - 1);
	}
	for(int i = 1 ; i < n ; i ++)
		if(t[i] == '0' and t[i - 1] == '0')
			dokme(0);
	string kir = "110";
	int cur = 0;
	if(t[0] == '0'){
		cur = 2;
	}
	if(t[0] == '1' and t[1] == '0'){
		cur = 1;
	}
	if(t[0] == '1' and t[1] == 1){
		cur = 0;
	}
	for(int i = 0 ; i < n ; i ++)
		if(t[i]!=kir[(cur + i)%3])dokme(0);
	ll sz = n + cur;
	sz = (sz + 2)/3;
	cout << (ll)1e10 - sz + 1;
    return(0);
}
