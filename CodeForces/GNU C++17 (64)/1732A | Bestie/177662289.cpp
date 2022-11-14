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
int a[30];
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> q;
 while(q --){
  cin >> n;
  for(int i = 1 ; i <= n ; i ++)
   cin >> a[i]; 
  int gc = a[1];
  for(int i = 1 ; i <= n ; i ++)
   gc = __gcd(gc, a[i]);
  if(gc == 1){
   cout << 0 << endl;
   continue;
  }
  if(__gcd(gc, __gcd(a[n], n)) == 1){
   cout << 1 << endl;
   continue;
  }
  if(__gcd(gc, __gcd(a[n-1], n-1)) == 1){
   cout << 2 << endl;
   continue;
  }
  cout << 3 << endl;
 }
 return(0);
}