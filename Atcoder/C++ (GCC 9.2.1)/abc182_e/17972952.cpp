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

string s;
int a[20];
int ans;
int cnt[3];

int32_t main(){
    migmig;
	cin >> s;
	int n = s.size();
	int sum = 0 ;
	for(int i = 0 ; i < n ; i ++){
		a[i] = (s[i] - '0')%3;
		cnt[a[i]] ++;
		sum += a[i];
	}
	sum%=3;
	if(sum == 0){
		dokme(0);
	}
	
	if(sum == 1){
		if(cnt[1]){
			if(cnt[0]+cnt[2]+cnt[1]-1)
				dokme(1);
			else
				dokme(-1);
		}
		if(cnt[2] > 1){
			if(cnt[0]+cnt[1] + cnt[2]   - 2)
				dokme(2);
			dokme(-1);
		}
		if(cnt[1]+cnt[0])
		dokme(cnt[2]);
		else
		dokme(-1);
	}
	if(cnt[2]){
		if(cnt[1] + cnt[0])
		dokme(1);
		else dokme(-1);
	}
	if(cnt[1] > 1){
		if(cnt[1] + cnt[0] + cnt[2] - 2)
		dokme(2);
		else dokme(-1);
	}
	if(cnt[0] + cnt[2])
	dokme(cnt[1]);
	dokme(-1);



    return(0);
}
