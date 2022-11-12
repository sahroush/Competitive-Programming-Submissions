/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
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
int p[maxn];
set < pii > st;

vector < int > ans;
int mark[maxn];

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> p[i];
	for(int i = 1 ; i < n ; i ++){
		if(p[i] > p[i + 1])st.insert({p[i] , i});
	}
	while(st.size()){
		pii X = *st.rbegin();
		st.erase(X);
		int x = X.second;
		mark[x] = 1;
		ans.pb(x);
		swap(p[x] , p[x + 1]);
		if(x -1 > 0 and !mark[x - 1] and p[x -1] > p[x])st.insert({p[x - 1] , x-1});
		if(x+1 != n and !mark[x+1] and p[x+1] > p[x + 2])st.insert({p[x + 1] , x+1});
		if(x-1 > 0 and p[x-1] < p[x] and st.count({p[x-1] , x-1}))st.erase({p[x - 1], x-1});
		if(x+1 !=n and p[x+2] > p[x+1] and st.count({p[x+1] , x+1}))st.erase({p[x+1] , x + 1});
	}
	for(int i = 1 ; i <= n; i ++)if(p[i]!=i)dokme(-1);
	if(ans.size()!=n-1)dokme(-1);
	for(int x : ans)cout << x << endl;



    return(0);
}
