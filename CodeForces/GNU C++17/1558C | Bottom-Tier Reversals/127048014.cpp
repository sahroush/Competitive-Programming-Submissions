#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxn = 2024;
const ll mod = 1e9+7;
 
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
 
int n, q;
int a[maxn], pos[maxn];
vector < int > ans;
 
void fuck(int x){
 if(x <= 1)return;
 for(int i = 1 ; i <= x / 2 ; i ++)
  swap(a[i] , a[x - i + 1]);
 for(int j = 1 ; j <= n ; j ++)
  pos[a[j]] = j;
 ans.pb(x);
}
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> q;
 while(q --){
  cin >> n;
  for(int i = 1 ; i <= n ; i ++)
   cin >> a[i], pos[a[i]] = i;
  ans.clear();
  bool ok = 1;
  for(int i = 1 ; i <= n ; i ++)if(a[i] % 2 != i % 2)
   ok = 0;
  for(int i = n ; i > 1 ; i -=2){
   if(!ok)break;
   if(a[i] == i and a[i - 1] == i - 1){
    continue;
   }
   fuck(pos[i]);
   fuck(pos[i - 1] - 1);
   fuck(pos[i - 1] + 1);
   fuck(3);
   fuck(i);
   if(a[i] != i or a[i - 1] != i - 1){
    ok = 0;
   }
  }
  ok &= a[1] == 1;
  if(!ok){
   cout << -1 << endl;
   continue;
  }
  cout << ans.size() << endl;
  for(int x : ans)
   cout << x << ' ';
  if(ans.size())cout << endl;
 }
 
 return(0);
}