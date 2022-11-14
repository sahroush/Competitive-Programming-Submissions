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
 
int x;
string s;
 
int w[8] = {-1 , 4, 4, 4, 4, 5, 5, 4};
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> x; 
 cin >> s >> s;
 if(s == "month"){
  if(x <= 29)dokme(12);
  if(x == 30)dokme(11);
  if(x == 31)dokme(7);
 }
 else{
  cout << w[x] + 48;
 }
 return(0);
}