#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxn = 5010;
const ll mod = 1e9+7;
 
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
 
int q;
int n, sz;
string s;
int dp[maxn][maxn], pd[maxn][maxn];
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> q;
 while(q --){
  cin >> n >> s;
        s += '`';
  for(int i = 0 ; i <= n + 5 ; i ++)
            fill(dp[i], dp[i] + n + 5, 0),
            fill(pd[i], pd[i] + n + 5, 0);
        int ans = 0;
        for(int i = n - 1 ; i >= 1 ; i --){
            for(int j = n - i - 1 ; j >= 0 ; j --){
                if(s[j] == s[j + i])
                    pd[j][j + i] = pd[j + 1][j + i + 1] + 1;
            }
        }
        for(int i = 0 ; i < n ; i ++){
            for(int sz = 1 ; sz + i <= n ; sz ++){
                dp[i][sz] ++;
                ans = max(ans , dp[i][sz]);
                dp[i][sz + 1] = max(dp[i][sz + 1], dp[i][sz]);
            }
            for(int j = i + 1 ; j < n ; j ++){
                int lcp = pd[i][j];
                if(s[i + lcp] < s[j + lcp])
                    dp[j][lcp + 1] = max(dp[j][lcp + 1], dp[i][n - i]);
                else if(lcp > 1)
                    dp[j][lcp] = max(dp[j][lcp], dp[i][lcp - 1]);
            }
        }
        cout << ans << endl;
 }
 return(0);
}