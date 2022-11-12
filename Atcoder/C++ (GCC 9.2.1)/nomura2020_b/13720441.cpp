#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3000;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string s[maxn];
int prt[maxn][maxn];
int n , m;
stack < int > stk;

int main(){
    migmig
    cin >> n >> m;
    for(int i =0 ; i < n ; i ++)
		cin >> s[i];
	for(int i = 1 ; i < n ; i ++){
		for(int j = m-2 ; j >= 0 ; j --){
			int sum = 0;
			if(s[i][j] == '#')sum++;
			if(s[i][j+1] == '#')sum++;
			if(s[i-1][j] == '#')sum++;
			if(s[i-1][j+1] == '#')sum++;
			if(sum != 1 and sum!=3){
				prt[i][j]=prt[i][j+1]+1; 
			}
		}
	}
    for(int i = 1 ; i < n ; i ++)
		for(int j = 0 ; j < m ; j ++)
			prt[i][j]++;
	int ans = 0;
	for(int j = m-1 ; j >= 0 ; j --){
		while(stk.size())stk.pop();
		stk.push(0);
		for(int i = 1 ; i <= n ; i ++){
			while(stk.size() and prt[stk.top()][j] > prt[i][j]){
				int v = prt[stk.top()][j];
				stk.pop();
				ans = max(ans , v * (i - stk.top()));
			}
			stk.push(i);
		}
	}
	ans = max(ans , n);
	ans = max(ans , m);
    cout << ans;
    return(0);
}