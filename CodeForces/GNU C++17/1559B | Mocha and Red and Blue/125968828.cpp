#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxn = 110;
const ll mod = 1e9+7;
 
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
 
int n, q;
string s;
bool dp[maxn][maxn][2];
pii par[maxn][maxn][2];
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> q;
 while(q --){
  cin >> n;
  cin >> s;
  for(int i = 0 ; i <= n ; i ++)
   for(int j = 0 ; j <= n ; j ++)
    dp[i][j][0] = dp[i][j][1] = 0;
  dp[1][0][0] = dp[1][0][1] = 1;
  if(s[0] == 'R')dp[1][0][1] = 0;
  if(s[0] == 'B')dp[1][0][0] = 0;
  for(int i = 2 ; i <= n ; i ++){
   for(int j = 0 ; j <= n ; j ++){
    if(dp[i - 1][j][0])
     dp[i][j][1] = 1,
     par[i][j][1] = {j , 0};
    if(dp[i - 1][j][1])
     dp[i][j][0] = 1,
     par[i][j][0] = {j , 1};
    if(j && dp[i - 1][j - 1][0])
     dp[i][j][0] = 1,
     par[i][j][0] = {j - 1, 0};
    if(j && dp[i - 1][j - 1][1])
     dp[i][j][1] = 1,
     par[i][j][1] = {j - 1, 1};
    if(s[i - 1] == 'R'){
     dp[i][j][1] = 0;
    }
    else if(s[i - 1] == 'B'){
     dp[i][j][0] = 0;
    }
   }
  }
  string res = "";
  pii cur = {0 , 0};
  for(int i = 0 ; i <= n ; i ++){
   if(dp[n][i][0]){
    cur = {i , 0};
    break;
   }
   if(dp[n][i][1]){
    cur = {i , 1};
    break;
   }
  }
  while(n){
   if(cur.second)res += 'B';
   else res += 'R';
   pii nxt = par[n][cur.first][cur.second];
   cur = nxt;
   n --;
  }
  reverse(res.begin(), res.end());
  cout << res << endl;
 }
 return(0);
}