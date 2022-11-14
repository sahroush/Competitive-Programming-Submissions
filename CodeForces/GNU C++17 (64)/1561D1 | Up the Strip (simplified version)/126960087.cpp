#pragma GCC optimize("O2")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef uint64_t ll;
#define uint uint32_t
 
const int maxn = 4e6 + 10;
const ll o = 1;
 
#define endl '\n'
#define dokme(x) cout << x , exit(0)
 
uint ex[maxn];
uint mod, n;
 
uint squirt(uint x){
 uint ans = 0;
 while(ans * ans <= x)ans ++;
 return ans - 1;
}
 
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n >> mod;
 ex[n] = 1;
 uint cur = 0;
 uint sq = squirt(n);
 for(uint i = n ; i >= 1 ; i --){
  uint v = (cur + ex[i]);
  if(v > mod)v -= mod;
  while(sq * sq > i)sq --;
  if(i == 1)dokme(v);
  cur = (cur + v);
  if(cur > mod)cur -= mod;
  for(uint j = 2 ; j <= sq ; j ++){
   uint p = i / j;
   ex[p] = (ex[p] + v);
   if(ex[p] > mod)ex[p] -= mod;
  }
  sq = max(uint(1) , sq);
  uint l = sq + 1, r = i + 1;
  while(l < r){
   uint p = i/l;
   uint nx = i / p + 1;
   ex[p] = (ex[p] + (nx - l) * o * v % mod);
   if(ex[p] > mod)ex[p] -= mod;
   l = nx;
  }
 }
 return(0);
}