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
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n;
 if(n <= 3)dokme("NO");
 if(n % 2 == 0){
  cout << "YES" << endl;
  for(int i = n ; i > 4 ; i -= 2){
   cout << i << " - " << i - 1 << " = 1" << endl;
   cout << "1 * 1 = 1" << endl;
  }
  cout << "1 * 2 = 2" << endl;
  cout << "2 * 3 = 6" << endl;
  cout << "6 * 4 = 24" << endl;
 }
 else{
  cout << "YES" << endl;
  for(int i = n ; i > 5 ; i -= 2){
   cout << i << " - " << i - 1 << " = 1" << endl;
   cout << "1 * 1 = 1" << endl;
  }
  cout << "5 + 1 = 6" << endl;
  cout << "6 * 4 = 24" << endl;
  cout << "3 - 2 = 1" << endl;
  cout << "1 * 24 = 24" << endl;
 }
 return(0);
}