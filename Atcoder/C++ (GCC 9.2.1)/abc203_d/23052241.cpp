//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 810;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

#define sz(x) int(x.size())

int n , k;
int a[maxn][maxn];
vector < int > v;

int b[maxn][maxn];

bool chk(int x){
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			b[i][j] = a[i][j] <= x , b[i][j] = b[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
	for(int i = k ; i <= n 	; i ++){
		for(int j = k ; j <= n; j ++){
			int res = b[i][j] - b[i - k][j] - b[i][j - k] + b[i-k][j-k];
			if(res >= k*k-res)return 1;
		}
	}
	return 0;
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1; j <= n ; j ++)
			cin >> a[i][j] , v.pb(a[i][j]);
	sort(v.begin() , v.end());
	v.resize(unique(v.begin() , v.end()) - v.begin());
	int l = -1 , r = sz(v)-1;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(chk(v[mid]))
			r = mid;
		else 
			l = mid;
	}
	cout << v[r];
	return(0);
}
