#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxn = 1e4 + 10;
const ll mod = 1e9+7;
 
#define pb push_back
//#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
 
int n, k;
int a[maxn];
int Or[maxn], And[maxn], Xor[maxn];
 
int32_t main(){
 cin.tie(0)->sync_with_stdio(0);
 cin >> n >> k;
 cout << "or " << 1 << ' ' << 2 << endl;
 cin >> Or[1];
 cout << "or " << 2 << ' ' << 3 << endl;
 cin >> Or[2];
 cout << "or " << 3 << ' ' << 1 << endl;
 cin >> Or[3];
 cout << "and " << 1 << ' ' << 2 << endl;
 cin >> And[1];
 cout << "and " << 2 << ' ' << 3 << endl;
 cin >> And[2];
 cout << "and " << 3 << ' ' << 1 << endl;
 cin >> And[3];
 Xor[1] = And[1] ^ Or[1];
 Xor[2] = And[2] ^ Or[2];
 Xor[3] = And[3] ^ Or[3];
 a[1] |= And[1];
 a[2] |= And[1];
 a[2] |= And[2];
 a[3] |= And[2];
 a[3] |= And[3];
 a[1] |= And[3];
 for(int bit = 0 ; bit < 30 ; bit ++){
  if(Xor[1] & (1 << bit)){
   if(And[2] & (1 << bit)){
    a[2] |= (1 << bit);
    //continue;
   }
   else if(And[3] & (1 << bit)){
    a[1] |= (1 << bit);
    //continue;
   }
   else if(Or[2] & (1 << bit)){
    a[2] |= (1 << bit);
    //continue;
   }
   else if(Or[3] & (1 << bit)){
    a[1] |= (1 << bit);
    //continue;
   }
  }
  if(Xor[2] & (1 << bit)){
   if(And[3] & (1 << bit)){
    a[3] |= (1 << bit);
    //continue;
   }
   else if(And[1] & (1 << bit)){
    a[2] |= (1 << bit);
    //continue;
   }
   else if(Or[3] & (1 << bit)){
    a[3] |= (1 << bit);
    //continue;
   }
   else if(Or[1] & (1 << bit)){
    a[2] |= (1 << bit);
    //continue;
   }
  }
  if(Xor[3] & (1 << bit)){
   if(And[1] & (1 << bit)){
    a[1] |= (1 << bit);
    //continue;
   }
   else if(And[2] & (1 << bit)){
    a[3] |= (1 << bit);
    //continue;
   }
   else if(Or[1] & (1 << bit)){
    a[1] |= (1 << bit);
    //continue;
   }
   else if(Or[2] & (1 << bit)){
    a[3] |= (1 << bit);
    //continue;
   }
  }
 }
 for(int i = 4 ; i <= n ; i ++){
  int x, y;
  cout << "and " << 1 << ' ' << i << endl;
  cin >> x;
  cout << "or " << 1 << ' ' << i << endl;
  cin >> y;
  a[i] = x;
  x ^= y;
  x ^= (x & a[1]);
  a[i] |= x;
 }
 sort(a + 1 , a + n + 1);
 cout << "finish " << a[k] << endl;
 return(0);
 
}