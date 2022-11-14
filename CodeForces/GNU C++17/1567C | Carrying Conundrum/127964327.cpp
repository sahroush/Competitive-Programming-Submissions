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
string n;
ll dp[11][100], digit[11];
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> q;
 while(q --){
  cin >> n;
  ms(dp, 0);
  for(int i = 0 ; i < (int)n.size() ; i ++)
   digit[(int)n.size() - i] = n[i] - '0';
  dp[0][0] = 1;
  for(int i = 1 ; i <= (int)n.size() ; i ++){
   for(int j = 0 ; j < 100 ; j ++){
    for(int a = 0 ; a < 10 ; a ++)for(int b = 0 ; b < 10 ; b ++){
     int sum = a + b + j % 10;
     if(sum % 10 != digit[i])continue;
     int nxt = j / 10 + 10 * (sum / 10);
     dp[i][nxt] += dp[i - 1][j];
    }
   }
  }
  cout << dp[(int)n.size()][0] - 2 << endl;
 }
 return(0);
}