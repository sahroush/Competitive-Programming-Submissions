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

int n, q;
int c[maxn], r[maxn];

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
    ll ans = (n - 2) * 1ll * (n - 2);
    for(int i = 1 ; i <= n ; i ++)
        r[i] = c[i] = n;
    int R = n, C = n;
    while(q --){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            if(x < C){
                for(int i = x ; i < C ; i ++)
                    r[i] = R;
                C = x;
            }
            ans -= r[x] - 2;
        }
        else{
            if(x < R){
                for(int i = x ; i < R ; i ++)
                    c[i] = C;
                R = x;
            }
            ans -= c[x] - 2;
        }
    }
    cout << ans;
	return(0);
}
