#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n, m;
int a[maxn];
bool bad[maxn], mark[maxn];
vector < int > ans = {1};

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		for(int j = 2 ; j * j <= a[i] ; j ++)while(a[i] % j == 0){
			a[i] /= j;
			mark[j] = 1;
		}
		if(a[i] > 1)mark[a[i]] = 1;
	}
	for(int i = 2 ; i <= m ; i ++)if(mark[i]){
		for(int j = i ; j <= m ; j += i)
			bad[j] = 1;
	}
	for(int i = 2 ; i <= m ; i ++){
		if(!bad[i])ans.pb(i);
	}
	cout << ans.size() << endl;
	for(int i : ans)
		cout << i << endl;
	return(0);
}
