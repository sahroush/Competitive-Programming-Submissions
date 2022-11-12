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

ll a , b;

ll s1(){
	if(a<=b)
		return(b - a);
	return(1e18);
}

ll s2(){
	if(-a <= b)
		return(b + a + 1);
	return(1e18);
}

ll s3(){
	if(-a <= -b)
		return(a-b + 2);
	return(1e18);
}

ll s4(){
	if(a <= -b){
		return(-b-a+1);
	}
	return(1e18);
}

int main(){
    migmig
    cin >> a >> b;
    ll ans = 1e18;
    ans = min(ans , s1());
    ans = min(ans , s2());
    ans = min(ans , s3());
    ans = min(ans , s4());
    cout << ans;
    return(0);
}