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

int n , m;
int a[110][110];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
 int mn = 200;
  for(int i = 0 ; i < n ; i ++)
    	for(int j = 0 ; j < m ; j ++)
          	cin >> a[i][j], mn = min(mn , a[i][j]);
  int ans =0 ;
 for(int i = 0 ; i < n ; i ++)
   	for(int j = 0 ; j < m ; j ++)
      	ans += a[i][j] - mn;
 	
cout << ans;
	return(0);
}
