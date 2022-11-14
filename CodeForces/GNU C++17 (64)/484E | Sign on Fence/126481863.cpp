#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 1e5 + 10;
 
#define endl '\n'
#define pb push_back
#define mid ((l + r) >> 1)
 
int n, q, h[maxn];
vector < int > comp = {0}, pos[maxn];
 
struct node{
 struct data{
  bool f;
  int p, s, m;
  friend data operator + (data l, data r){
   data a;
   a.f = l.f & r.f;
   a.p = l.p + (l.f ? r.p : 0);
   a.s = r.s + (r.f ? l.s : 0);
   a.m = max({l.m, r.m, l.s + r.p});
   return a;
  }
 };
 data d;
 node *lc, *rc;
 node* update(int pos, int l = 1, int r = n + 1){
  node *baby = new node(*this);
  if(r - l == 1){
   baby->d = {1, 1, 1, 1};
   return baby;
  }
  if(pos < mid)
   baby->lc = lc->update(pos, l, mid);
  else
   baby->rc = rc->update(pos, mid, r);
  baby->d = baby->lc->d + baby->rc->d;
  return baby;
 }
 data get(int L, int R, int l = 1, int r = n + 1){
  if(r <= L or R <= l)return {1, 0, 0, 0};
  if(L <= l and r <= R)return this->d;
  return this->lc->get(L , R, l , mid) + this->rc->get(L, R, mid, r);
 } 
};
node *root[maxn];
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n;
 for(int i = 1 ; i <= n ; i ++)
  cin >> h[i], comp.pb(h[i]);
 sort(comp.begin(), comp.end());
 comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
 for(int i = 1 ; i <= n ; i ++)
  pos[lower_bound(comp.begin(), comp.end(), h[i]) - comp.begin()].pb(i);
 int sz = comp.size();
 root[sz] = new node();
 root[sz]->lc = root[sz]->rc = root[sz];
 for(int i = sz - 1 ; i ; i --){
  root[i] = root[i + 1];
  for(int x : pos[i])
   root[i] = root[i]->update(x);
 }
 cin >> q;
 while(q --){
  int L, R, x;
        cin >> L >> R >> x;
        int l = 1, r = sz;
        while(r - l > 1){
            if(root[mid]->get(L, R + 1).m >= x)
                l = mid;
            else
                r = mid;
        }
        cout << comp[l] << endl;
 }
 return 0;
}