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

int q;
ll n , s , k;

ll phi(ll n) {
    ll result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

ll inv(ll x, ll mod){
	return pw(x, phi(mod)-1, mod);
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> q;
	while( q--){
		cin >> n >> s >> k;
		s = n - s;
		if(s % __gcd(n, k)){
			cout << -1 << endl;
			continue;
		}
		ll gc = __gcd(n, __gcd(s, k));
		s /= gc, n /= gc, k /= gc;
		cout << (s * inv(k, n))%n << endl;
	}
	return(0);
}
