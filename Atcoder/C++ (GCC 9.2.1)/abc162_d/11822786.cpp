#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);
 
#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
 
 
 
int main(){
    migmig
  	int n;
  cin >> n;
  ll ans = 0;
  for(ll i = 1 ; i <= n ; i ++){
    if(i%3 and i%5){
      ans+=i;
    }
  }
  cout << ans;
 
    return(0);
}