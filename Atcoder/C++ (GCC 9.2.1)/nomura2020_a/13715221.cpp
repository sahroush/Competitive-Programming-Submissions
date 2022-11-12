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

ll ans = 1;
int n;
string s , t;

int main(){
    migmig
    cin >> n;
    cin >> s >> t;
	int i = 0;
	int prev = 0;
	for(; i < n ; i ++){
		int cur = (s[i] == t[i]);
		if(cur){
			if(prev == 0){
				ans*=3;
				ans%=mod;
			}
			if(prev == 1){
				ans = (ans + ans)%mod;
			}
			prev = 1;
		}
		else{
			if(prev == 0){
				ans*=6;
				ans%=mod;
			}
			if(prev == 1){
				ans = (ans + ans)%mod;
			}
			if(prev == 2){
				ans = ans*3 %mod;
			}
			prev = 2;
			i++;
		}
	}
    
    cout << ans << endl;
    
    return(0);
}