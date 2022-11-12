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

int n;
vector < int > vc = {0};

bool chk(int x){
 	vc[0] ++;
  if(vc[0] == 8){
   vc[0] = 0;
    int pos = 1;
    while(pos < vc.size()){
     vc[pos]++;
      if(vc[pos] == 8){
       vc[pos] = 0;
        pos++;
      }
      else
        break;
    }
    if(vc.back() == 0)vc.pb(1);
  }
  for(int x : vc)if(x == 7)return 0;
  while(x){
   if(x % 10 == 7)return 0;
    x /= 10;
  }
  return 1;
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
  	cin >> n;
  int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
      	ans += chk(i);
cout << ans;
	return(0);
}
