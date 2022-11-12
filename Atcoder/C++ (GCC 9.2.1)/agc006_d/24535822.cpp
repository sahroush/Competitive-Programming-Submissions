#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn], b[maxn];

bool chk(int x){
	for(int i = 1 ; i < 2 * n ; i ++)
		b[i] = a[i] >= x;
	for(int i = n-1 ; i ; i --){
		if(b[i] == b[i + 1])return b[i];
		if(b[n - i + n] == b[n - i + n - 1])return b[n - i + n];
	}
	return !((n & 1) ^ b[n]);
}

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1 ; i < 2*n ; i ++)
		cin >> a[i];
	int l = 1, r = 2 * n;
	while(r - l > 1){
		int mid = ((l + r) >> 1);
		if(chk(mid))
			l = mid;
		else
			r = mid;
	}
	cout << l;
	return(0);
}
