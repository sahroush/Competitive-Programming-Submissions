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

string s;
int n;
int cnt[11];

int32_t main(){
    migmig;
	cin >> s;
	n = s.size();
	if(n == 1){
		if(s == "8")dokme("Yes");
		dokme("No");
	}
	if(n == 2){
		int y = s[1] - '0';
		int d = s[0] - '0';
		if((d * 10 + y)%8 == 0)dokme("Yes");
		if(y and (y * 10 + d)%8 == 0)dokme("Yes");
		dokme("No");
	}
	for(int i = 0 ; i < n ; i ++)cnt[s[i] - '0'] ++;
	for(int i = 0 ; i < 10 ; i ++)
		for(int j = 0 ; j < 10 ; j ++)
			for(int k = 0 ; k < 10 ; k ++){
				if((i*100 + j * 10 + k )%8)continue;
				if(n == 3 and !i)continue;
				int cn[11];
				ms(cn , 0);
				cn[i]++ , cn[j]++ , cn[k]++;
				bool ok = 1;
				int bz = 0;
				for(int h = 0 ; h < 10 ; h ++)if(cn[h] > cnt[h])ok = 0;
				if(!ok)continue;
				for(int h = 0 ; h < 10 ; h ++)bz += cn[h];
				bz -= cn[0];
				if(bz == n - cnt[0] and n != 3)continue;
				dokme("Yes");
			}
	dokme("No");
    return(0);
}
