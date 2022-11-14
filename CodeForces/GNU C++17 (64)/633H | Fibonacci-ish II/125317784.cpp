#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define uint uint32_t
typedef long double ld;
typedef pair<int , int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxn = 3e4 + 10;
const ll mod = 1e9+7;
const uint64_t o = 1;
 
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
 
uint n, m;
uint q;
uint l, r;
uint a[maxn], b[maxn], c[maxn], sz;
uint fib[maxn];
bitset < maxn > mark;
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n >> m;
 fib[1] = fib[2] = 1;
 for(int i = 3 ; i < maxn ; i ++)
  fib[i] = fib[i - 1] + fib[i - 2], fib[i] = ((fib[i] > m) ? fib[i] - m : fib[i]);
 for(int i = 1 ; i <= n ; i ++)
  cin >> a[i], b[i] = a[i];
 sort(b + 1 , b + n + 1);
 sz = unique(b + 1 , b + n + 1) - b - 1;
 for(int i = 1 ; i <= n ; i ++)
  c[i] = lower_bound(b + 1, b + sz + 1, a[i]) - b;
 cin >> q;
 while(q --){
  cin >> l >> r;
  int cnt = 1;
  uint64_t ans = 0;
  for( ; l <= r ; l ++)if(!mark[c[l]]){
   mark[c[l]] = 1;
  }
  for(int i = mark._Find_first() ; i < maxn ; i = mark._Find_next(i))
   ans = (ans + (b[i] * o * fib[cnt ++]))%m;
  cout << ans << endl;
  mark = 0;
 }
 return(0);
}