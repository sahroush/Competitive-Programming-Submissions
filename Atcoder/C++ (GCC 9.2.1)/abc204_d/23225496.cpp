//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#pragma GCC optimize("Ofast")
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

int n;
int t[maxn];
bitset < maxn > bs;

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	int sum = 0;
	for(int i = 1 ; i <= n ; i ++)cin >> t[i] , sum += t[i];
	bs[0] = 1;
	for(int i = 1 ; i <= n ; i ++)
		bs |= (bs << t[i]);
	int ans = 1e9;
	for(int i = 0 ; i < maxn ; i ++)if(bs[i])
		ans = min(ans , max(i , sum - i));
	cout << ans;
	return(0);
}
