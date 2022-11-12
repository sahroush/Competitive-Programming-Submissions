#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e5+5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int mxval[520][maxn];
int w[(1 << 18)+5] , v[(1 << 18)+5];
int q;
int w2[20];
int v2[20];

void solve(int x){
    int pos = x;
    int cnt = 0;
    while(x!=0){
        w2[cnt] = w[x];
        v2[cnt++] = v[x];
        x/=2;
    }
    for(int i = 0 ; i < (1 << cnt) ; i ++){
        int sum = 0;
        int val = 0;
        for(int j = 0 ; j < cnt ; j ++){
            if(i&(1 << j))
                sum+=w2[j] , val+=v2[j];
        }
        if(sum <= 100000)
            mxval[pos][sum] = max(mxval[pos][sum] , val);
    }
    for(int i = 1 ; i < maxn ; i ++)
        mxval[pos][i] = max(mxval[pos][i] , mxval[pos][i-1]);
}

void prep(){
    for(int i = 1 ; i <= min(n,510) ; i ++){
        solve(i);
    }
}

void solve(int x , int l){
    int mx = 0;
    int cnt = 0;
    while(x>510){
        w2[cnt] = w[x];
        v2[cnt++] = v[x];
        x/=2;
    }
    for(int i = 0 ; i < (1 << cnt) ; i ++){
        int sum = 0;
        int val = 0;
        for(int j = 0 ; j < cnt ; j ++){
            if(i&(1 << j))
                sum+=w2[j] , val+=v2[j];
        }
        if(sum <= l)mx = max(mx , val);
        if(l >= sum)mx = max(mx , val + mxval[x][l - sum]);
    }
    cout << mx << endl;
}

int main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> v[i] >> w[i];
    prep();
    cin >> q;
    while(q -- ){
        int x , l;
        cin >> x >> l;
        if(x <= 510){
            cout << mxval[x][l] << endl;
            continue;
        }
        solve(x , l);
    }
    return(0);
}