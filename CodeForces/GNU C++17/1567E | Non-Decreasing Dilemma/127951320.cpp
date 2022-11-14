#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxn = 2e5 + 10;
const ll mod = 1e9+7;
 
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
 
int n, q;
int a[maxn];
 
ll C(ll x){
 return x * (x + 1) / 2;
}
 
struct node{
 ll ans, p, s;
 int f, l, r;
 node(int x):
  ans(0), p(1), s(1), f(1), l(x), r(x){}
 node():
  ans(0), p(0), s(0), f(0), l(0), r(0){}
 friend node operator + (node l, node r){
  node v;
  v.l = l.l, v.r = r.r;
  if(l.r <= r.l){
   if(l.f and r.f){
    v.ans = 0;
    v.s = l.s + r.s;
    v.p = l.p + r.p;
    v.f = 1;
   }
   if(l.f and !r.f){
    v.ans = r.ans;
    v.p = l.p + r.p;
    v.s = r.s;
    v.f = 0;
   }
   if(!l.f and r.f){
    v.ans = l.ans;
    v.p = l.p;
    v.s = r.s + l.s;
    v.f = 0;
   }
   if(!l.f and !r.f){
    v.p = l.p;
    v.s = r.s;
    v.ans = l.ans + r.ans + C(l.s + r.p);
    v.f = 0;
   }
  }
  else{
   v.p = l.p;
   v.s = r.s;
   v.ans = l.ans + r.ans;
   v.f = 0;
   if(!l.f)v.ans += C(l.s);
   if(!r.f)v.ans += C(r.p);
  }
  return v;
 }
}seg[maxn << 2];
 
#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)
 
void build(int v = 1, int l = 1, int r = n + 1){
 if(r - l == 1){
  seg[v] = node(a[l]);
  return;
 }
 build(lc, l, mid);
 build(rc, mid, r);
 seg[v] = seg[lc] + seg[rc];
}
 
void modify(int pos, int x, int v = 1, int l = 1, int r = n + 1){
 if(r - l == 1){
  a[l] = x;
  seg[v] = node(a[l]);
  return;
 }
 if(pos < mid)
  modify(pos, x, lc, l, mid);
 else
  modify(pos, x, rc, mid, r);
 seg[v] = seg[lc] + seg[rc];
}
 
node get(int L, int R, int v = 1, int l = 1, int r = n + 1){
 if(L <= l and r <= R){
  return seg[v];
 }
 if(L >= mid){
  return get(L , R, rc, mid, r);
 }
 if(R <= mid){
  return get(L, R, lc, l, mid);
 }
 return get(L, R, lc, l, mid) + get(L, R, rc, mid, r);
}
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n >> q;
 for(int i = 1 ; i <= n ; i ++)
  cin >> a[i];
 build();
 while(q --){
  int t, a,  b;
  cin >> t >> a >> b;
  if(t == 1){
   modify(a, b);
  }
  if(t == 2){
   auto res = get(a, b + 1);
   res.ans += C(res.p);
   if(!res.f) res.ans += C(res.s);
   cout << res.ans << endl;
  }
 }
 return(0);
}