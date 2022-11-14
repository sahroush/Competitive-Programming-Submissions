#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxn = 1e4 + 10;
const ll mod = 1e9+7;
 
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
 
int q;
int n;
int a[maxn];
vector < int > ans;
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> q;
 while(q --){
  cin >> n;
  for(int i = 1 ; i <= n ; i ++)
   cin >> a[i];
  if(a[n] == 0){
   for(int i = 1 ; i <= n + 1 ; i ++){
    cout << i << ' ';
   }
   cout << endl;
   continue;
  }
  if(a[1] == 1){
   cout << n + 1 << ' ';
   for(int i = 1 ; i <= n ; i ++){
    cout << i << ' ';
   }
   cout << endl;
   continue;
  }
  int res = -1;
  for(int i = 1 ; i < n ; i ++){
   if(a[i] == 0 and a[i + 1] == 1)
    res = i;
  }
  if(res == -1)cout << -1 << endl;
  else{
   for(int i = 1 ; i <= res ; i ++)
    cout << i << ' ';
   cout << n + 1 << ' ';
   for(int i = res + 1 ; i <= n ; i ++)
    cout << i << ' ';
   cout << endl;
  }
 }
 return(0);
}