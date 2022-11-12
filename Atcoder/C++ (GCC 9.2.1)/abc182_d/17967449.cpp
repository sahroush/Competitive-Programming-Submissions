/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int cnt[maxn];
int a[maxn];

int32_t main(){
    migmig;
	cin >> n;
  	for(int i = 0 ; i < n ; i ++){
     cin >> cnt[i];
    }
	int mx = 2;
  for(int i = 2 ; i <= 1000 ; i ++){
    	for(int j = 0 ; j < n ; j ++)
          	if(cnt[j]%i == 0) 	a[i] ++;
   if(a[i] > a[mx])mx = i; 
  }

	cout << mx;
    return(0);
}
