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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
ll a[maxn];
ll prt[maxn];

int main(){
    migmig
	cin >> n;
	for(int i = 0 ; i <= n ; i ++){
		cin >> a[i];
	}
    if(n == 0){
		dokme(((a[0] == 1)?1:-1))
	}
    for(int i = n ; i >= 0 ; i --){
		prt[i] = prt[i+1]+a[i];
	}
	ll ans = 0;
	ll cur = 1;
	for(int i = 0 ; i <= n ; i ++){
		ans+=cur;
		if(cur < a[i]){
			dokme(-1);
		}
		cur -= a[i];
		cur = min(cur * 2 , prt[i+1]);
	}
	cout << ans;
    return(0);
}