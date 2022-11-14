#include <bits/stdc++.h>
 
using namespace std;
 
#define int ll
 
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
 
int n, q;
string s;
 
int calc(){
 int ans = 0;
 for(int i = 0 ; i < n ; i ++)
  if(s[i] == 'L')
   ans += i;
  else
   ans += n - i - 1;
 return ans;
}
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> q;
 while(q --){
  cin >> n >> s;
  int l = -1, r = n;
  int ans = calc();
  for(int i = 0 ; i < n ; i ++){
   while(r - l > 1){
    if(l + 1 < n - r){
     l ++;
     if(s[l] == 'L'){ //L -> R
      ans -= l, ans += n - l - 1;
      break;
     }
    }
    else{
     r --;
     if(s[r] == 'R'){ //R -> L
      ans -= n - r - 1, ans += r;
      break;
     }
    }
   }
   cout << ans << ' ';
  }
  cout << endl;
 }
 return(0);
}