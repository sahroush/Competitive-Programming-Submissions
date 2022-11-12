#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 998244353;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll dp[5050][5050];
bool visited[5050][5050];

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int N;
  ll a,b;
  cin >> N;
  vector<ll> A(N),B(N);
  vector<pii> v;
  for(int i=0;i<N;i++){
  	cin >> A[i];
  }
  for(int i=0;i<N;i++){
  	cin >> B[i];
  }
  for(int i=0;i<N;i++){
  	v.emplace_back(A[i], B[i]);
  }
  sort(v.begin(), v.end());
  dp[0][0] = 1;
  visited[0][0] = true;
  ll end = v[v.size()-1].first;
  ll ans = 0;
  for(int i=0;i<N;i++){
    a = v[i].first;
    b = v[i].second;
  	for(int j=0;j<=end;j++){
    	if(visited[i][j]){
            if(j+b <= end){
            	dp[i+1][j+b] = (dp[i+1][j+b] + dp[i][j])%mod;
                visited[i+1][j+b] = true;
            }
            dp[i+1][j] = (dp[i+1][j] + dp[i][j])%mod;
            visited[i+1][j] = true;
            if(j+b <= a)
              ans = (ans + dp[i][j])%mod;
        }
    }
  }
  cout << ans << endl;

	return(0);
}
