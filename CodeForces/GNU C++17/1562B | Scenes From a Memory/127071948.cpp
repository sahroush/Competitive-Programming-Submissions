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
 for(int i = 0 ; i < n ; i ++){
  if(s[i] == '1' or s[i] == '4' or s[i] == '6' or s[i] == '8' or s[i] == '9'){
   cout << 1 << endl;
   cout << s[i] << endl;
   return;
  }
 }
 for(int i = 1 ; i < n ; i ++){
  if(s[i] == '2'){
   cout << 2 << endl;
   cout << s[i - 1] << s[i] << endl;
   return;
  }
 }
 for(int i = 1 ; i < n ; i ++){
  if(s[i] == '5'){
   cout << 2 << endl;
   cout << s[i - 1] << s[i] << endl;
   return;
  }
 }
 if(s[0] == '2'){
  for(int i = 1 ; i < n ; i ++){
   if(s[i] == '7'){
    cout << 2 << endl;
    cout << 27 << endl;
    return;
   }
  }
  cout << 2 << endl;
  cout << 33 << endl;
  return;
 }
 if(s[0] == '5'){
  for(int i = 1 ; i < n ; i ++){
   if(s[i] == '7'){
    cout << 2 << endl;
    cout << 57 << endl;
    return;
   }
  }
  cout << 2 << endl;
  cout << 33 << endl;
  return;
 }
 int cnt = 0;
 for(int i = 0 ; i < n ; i ++)cnt += s[i] == '3';
 if(cnt > 1){
  cout << 2 << endl;
  cout << 33 << endl;
  return;
 }
 cout << 2 << endl;
 cout << 77 << endl;
}
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> q;
 while(q --){
  cin >> n >> s;
  solve();
 }
 return(0);
}