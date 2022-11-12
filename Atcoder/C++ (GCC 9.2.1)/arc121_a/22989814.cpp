//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll , ll> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

#define x first
#define y second

int n , srt[maxn];
pii a[maxn];

priority_queue < ll > st;

set < pii > s;

bool cmpx(int i , int j){
	return a[i].x > a[j].x;
}

bool cmpy(int i , int j){
	return a[i].y > a[j].y;
}

void add(int i , int j){
	if(i > j)swap(i , j);
	if(i == j)return;
	if(s.count({i , j}))return;
	s.insert({i , j});
	st.push(max(abs(a[i].x - a[j].x) , abs(a[i].y - a[j].y)));
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> a[i].x >> a[i].y , srt[i] = i;
	sort(srt , srt + n , cmpx);
	for(int i = 0 ; i < 3 ; i ++)
		for(int j = 0 ; j < 3 ; j ++)
			add(srt[i] , srt[n-j - 1]);
	sort(srt , srt + n , cmpy);
	for(int i = 0 ; i < 3 ; i ++)
		for(int j = 0 ; j < 3 ; j ++)
			add(srt[i] , srt[n-j - 1]);
	st.pop();
	cout << st.top();
	return(0);
}
