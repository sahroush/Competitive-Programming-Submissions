#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int , int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxn = 1e5 + 10;
const int sq = 720;
 
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
 
int n, m;
int a[maxn];
bool in[maxn];
int c[maxn], cc[maxn], ans[maxn], cnt[maxn];
 
struct Data{
 int l, r, ind;
 friend bool operator < (Data &a, Data &b){
  if(a.l / sq == b.l / sq)
   return (((a.l / sq) & 1) ? a.r < b.r : a.r > b.r);
  return a.l < b.l;
 }
}q[maxn];
 
bitset < maxn > bs;
priority_queue < int , vector < int > , greater < int > > pq;
 
void modify(int x){
 in[x] ^= 1;
 if(in[x]){
  cc[c[a[x]]] --;
  c[a[x]] ++;
  cc[c[a[x]]] ++;
  if(c[a[x]] == sq)
   bs[a[x]] = 1;
 }
 else{
  cc[c[a[x]]] --;
  c[a[x]] --;
  cc[c[a[x]]] ++;
  if(c[a[x]] == sq - 1)
   bs[a[x]] = 0;
 }
}
 
int solve(){
 int ans = 0, lst = 0;
 for(int i = 1 ; i < sq ; i ++){
  cnt[i] = cc[i];
 }
 for(int i = 1 ; i < sq ; i ++)if(cnt[i] > 0){
  if(lst){
   cnt[i] --;
   if(i + lst >= sq)pq.push(i + lst);
   else cnt[i + lst] ++;
   ans += i + lst;
  }
  lst = (cnt[i] & 1) ? i : 0;
  cnt[i]>>=1;
  ans += (i << 1) * cnt[i];
  if((i << 1) >= sq) 
   for(int j = 1 ; j <= cnt[i] ; j ++)
    pq.push(i << 1);
  else
   cnt[i << 1] += cnt[i];
 }
 if(lst)pq.push(lst);
 for(int x = bs._Find_first() ; x < maxn ; x = bs._Find_next(x))pq.push(c[x]);
 while(pq.size() > 1){
  int v = pq.top();pq.pop();
  int u = pq.top();pq.pop();
  ans += u + v;
  pq.push(u + v);
 }
 if(pq.size())pq.pop();
 return ans;
}
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n;
 for(int i = 1 ; i <= n ; i ++)
  cin >> a[i];
 cin >> m;
 for(int i = 1 ; i <= m ; i ++)
  cin >> q[i].l >> q[i].r, q[i].ind = i;
 sort(q + 1 , q + m + 1);
 int l = 1, r = 1;
 modify(1);
 for(int i = 1 ; i <= m ; i ++){
  while(l > q[i].l)l -- , modify(l);
  while(r < q[i].r)r ++ , modify(r);
  while(l < q[i].l)modify(l) , l ++;
  while(r > q[i].r)modify(r) , r --; 
  ans[q[i].ind] = solve();
 } 
 for(int i = 1 ; i <= m ; i ++)
  cout << ans[i] << endl;
 return(0);
}