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
 
int n, q;
int a[maxn];
 
int solve(int x){
 stack < int > s[2];
 ll ans = 0;
 for(int i = 1 ; i <= n ; i ++){
  if(i & 1){
   if(a[i] == x)continue;
   if(s[!a[i]].size()){
    ans += i - s[!a[i]].top();
    s[!a[i]].pop();
   }
   else s[a[i]].push(i);
  }
  else{
   if(a[i] ^ x)continue;
   if(s[!a[i]].size()){
    ans += i - s[!a[i]].top();
    s[!a[i]].pop();
   }
   else s[a[i]].push(i);
  }
 }
 return ans;
}
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> q;
 while(q --){
  cin >> n;
  int cnt = 0;
  for(int i = 1 ; i <= n ; i ++){
   cin >> a[i];
   a[i] &= 1;
   cnt += a[i];
  }
  if(cnt != n/2 and cnt != (n + 1) / 2){
   cout << -1 << endl;
   continue;
  }
  int ans = 0;
  if(n & 1){
   if(cnt == (n+1) / 2){
    ans = solve(1);
   }
   else{
    ans = solve(0);
   }
  }
  else{
   ans = min(solve(1), solve(0));
  }
  cout << ans << endl;
 }
 return(0);
}