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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int x;
string t;

int main(){
    migmig
    cin >> t;
    x = t.size();
    int n = 0 , s = 0 , e = 0 , w = 0;
    for(int i = 0 ; i < x ; i ++){
		if(t[i] == 'N')n++;
		if(t[i] == 'S')s++;
		if(t[i] == 'E')e++;
		if(t[i] == 'W')w++;
	} 
    if(n){
		if(!s)dokme("No");
	}
    
    if(s){
		if(!n)dokme("No");
	}
    
    if(e){
		if(!w)dokme("No");
	}
	
    if(w){
		if(!e)dokme("No");
	}
	cout << "Yes";
    return(0);
}