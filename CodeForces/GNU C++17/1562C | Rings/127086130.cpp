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
int n;
string s;
 
void solve(){
 int h = n / 2;
 for(int i = h ; i < n ; i ++){
  if(s[i + 1] == '0'){
   cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << endl;
   return;
  }
 }
 for(int i = 1 ; i <= h ; i ++)if(s[i] == '0'){
  cout << i << ' ' << n << ' ' << i + 1 << ' ' << n << endl;
  return;
 }
 if(n % 2 == 0){
  cout << 1 << ' ' << n << ' ' << 1 << ' ' << h << endl;
  return;
 }
 cout << 1 << ' ' << ' ' << n - 1 << ' ' << 1 << ' ' << h << endl;
}
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> q;
 while(q --){
  cin >> n >> s;
  s = "6" + s;
  solve();
 }
 return(0);
}