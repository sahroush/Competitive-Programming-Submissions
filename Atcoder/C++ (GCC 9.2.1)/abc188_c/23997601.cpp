#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];

vector < int > l , r;

int solve(int l , int r){
	if(l == 1 and r == (1 << n) and r - l == 1){
		return ((a[1] > a[2]) ? 2 : 1);
	}
	if(r - l == 1){
		return ((a[l] > a[r]) ? l : r);
	}
	int c = solve(l , (l + r) >> 1);
	int b = solve(((l + r) >> 1) + 1 , r);
	if(l == 1 and r == (1 << n)){
		return ((a[c] > a[b]) ? b : c);
	}
	return ((a[c] > a[b]) ? c : b);
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= (1 << n) ; i ++)
		cin >> a[i] , r.pb(i);
	cout << solve(1 , (1 << n));
	return(0);
}
