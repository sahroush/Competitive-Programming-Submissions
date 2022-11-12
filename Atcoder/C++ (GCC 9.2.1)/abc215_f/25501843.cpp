#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1010;
const ll mod = 998244353;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
string s;
int dp[2][(1 << 10)][10];

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> s;
	for(int i = 0 ; i < n ; i ++){
		int v = i&1, nv = 1-v;
		ms(dp[v], 0);
		int c = s[i] - 'A';
		dp[v][1 << c][c] = 1;
		for(int j = 0 ; j < (1 << 10) ; j ++){
			for(int k = 0 ; k < 10 ; k ++){
				dp[v][j][k] = (dp[v][j][k] + dp[nv][j][k])%mod;
				if(j & (1 << c)){
					if(k == c){
						dp[v][j][k] = (dp[v][j][k] + dp[nv][j][k])%mod;
					}
				}
				else{
					dp[v][j | (1 << c)][c] = (dp[v][j | (1 << c)][c] + dp[nv][j][k])%mod;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0 ; i < (1 << 10) ; i ++){
		for(int j = 0 ; j < 10 ; j ++){
			ans = (ans + dp[(n^1)&1][i][j])%mod;
		}
	}
	cout << ans;
	return(0);
}
//bargh raft :T