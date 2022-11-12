#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 6e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n;
ll d[maxn];
ll q , x;
ll dp[maxn];
ll mn[maxn];

int main(){
    migmig
    cin >> n >> dp[0];
    mn[n]=1;
    for(int i = 1 ; i <= n ; i ++)
		cin >> d[i];
    for(int i = 1 ; i <= n ; i ++)
		dp[i] = min(dp[i - 1], abs(d[i] - dp[i - 1]));
    for(int i = n-1 ; i ; i --)
		mn[i] = mn[i + 1] + ((d[i+1] < 2 * mn[i + 1])?d[i+1]:0);
    cin >> q;
	while(q--){
		cin >> x;
		cout << ((dp[x-1] >= mn[x])?"YES":"NO")<< endl;
	}
    return(0);
}