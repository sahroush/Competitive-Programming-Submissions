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
 
int n;
string s[maxn];
 
string shift(string s, int d){
 string ans = "";
 for(int i = d ; ; i ++ , i %= (int)s.size()){
  if(ans.size() and i == d){
   return ans;
  } 
  ans += s[i];
 } 
}
 
int dist(string a, string b){
 int sz = a.size();
 if(a.size() != b.size())return 1e9;
 for(int i = 0 ; i < sz ; i ++)
  if(shift(b , i) == a)return i;
 return 1e9;
}
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n;
 for(int i = 1 ; i <= n ; i ++)
  cin >> s[i];
 ll ans = 1e9;
 for(int i = 0 ; i < (int)s[1].size() ; i ++){
  string T = shift(s[1], i);
  ll res = 0;
  for(int j = 2 ; j <= n ; j ++)
   res += dist(T, s[j]);
  ans = min(ans,  res + i);
 }
 cout << ((ans == 1e9) ? -1 : ans);
 return(0);
}