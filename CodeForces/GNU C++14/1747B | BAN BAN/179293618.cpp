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
 
int q, n;
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> q;
 while(q --){
  cin >> n;
  if(n%2){
   cout << (n + 1) / 2 << endl;
   for(int i = 1 ; i <= n/2 ; i ++){
    cout << (3 * (i - 1)) + 1 << ' ' << (3*(n - i)) + 2 << endl;
   }
   cout << (3 * (n/2) + 1) << ' ' << 3*n << endl;
  }
  else{
   cout << n/2 << endl;
   for(int i = 1 ; i <= n/2 ; i ++){
    cout << (3 * (i - 1)) + 1 << ' ' << (3*(n - i)) + 2 << endl;
   }
  }
 
 }
 return(0);
}