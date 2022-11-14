#pragma GCC optimize("O2")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef uint64_t ll;
using uint = uint32_t;
 
const int maxn = 4e6 + 10;
const ll o = 1;
 
#define endl '\n'
#define dokme(x) cout << x , exit(0)
 
uint ex[maxn], sum[maxn];
uint mod, n;
 
uint add(uint a, uint b){
 if(a >= mod)a -= mod;
 if(b >= mod)b -= mod;
 if(a + b >= mod) return a + b - mod;
 return a + b;
}
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n >> mod;
 ex[n] = sum[n] = 1;
 for(uint i = n - 1 ; i >= 1 ; i --){
  ex[i] = sum[i + 1];
  for(uint j = 2 ; j * i <= n ; j ++){
   ex[i] = add(ex[i], add(sum[j * i] , mod - sum[min(n, j * i + j - 1) + 1]));
  }
  sum[i] = add(sum[i + 1], ex[i]);
 }
 cout << ex[1];
 return(0);
}