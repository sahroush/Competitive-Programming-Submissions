#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(a)  (a).begin(),(a).end()



int main() {

ll N,M;
cin >> N >> M;

vector<ll> aa((1+N)/2);
vector<ll> bb((1+N)/2);

vector<ll> hh(N);
vector<ll> ww(M);

for(ll i=0;i<N;i++) cin >> hh[i];

for(ll i=0;i<M;i++) cin >> ww[i];

sort(ALL(hh));
ll ans=INF;

aa[0]=0;
for(ll i=1;i<(N+1)/2;i++){
aa[i]=aa[i-1]+hh[2*i-1]-hh[2*i-2];
}

for(ll i=(N-2)/2;i>=0;i--){
bb[i]=bb[i+1]+hh[2*i+2]-hh[2*i+1];
}

for(auto gg : ww){
ll x=lower_bound(ALL(hh),gg)-hh.begin();
 if(x & 1) x^=1;
 chmin(ans,aa[x/2]+bb[x/2]+abs(gg-hh[x]));


}

cout << ans << endl;








}