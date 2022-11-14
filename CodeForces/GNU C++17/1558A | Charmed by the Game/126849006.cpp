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
int a, b;
int n;
vector < int > ans;
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> q;
 while(q --){
  cin >> a >> b;
  n = a + b;
  ans.clear();
  int A = (n + 1) / 2, B = n - A;
  for(int i = 0 ; i <= a and i <= B ; i ++){
   if(a - i <= A)ans.pb(i + A - (a - i));
  }
  A = n / 2, B = n - A;
  for(int i = 0 ; i <= a and i <= B ; i ++){
   if(a - i <= A)ans.pb(i + A - (a - i));
  }
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  cout << ans.size() << endl;
  for(int x : ans)
   cout << x << ' ';
  cout << endl;
 }
 return(0);
}