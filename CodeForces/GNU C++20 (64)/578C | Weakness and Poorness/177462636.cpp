/**********************GOD**********************/
 
 
/******************includings******************/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <iterator>
#include <map>
/***********************************************/
 
/*******************definings*******************/
#define len             length()
#define pii             pair<int,int>
#define pll             pair<long long,long long>
#define phb(x)          push_back(x)
#define ppb             pop_back
#define all(x)          x.begin(),x.end()
#define MP              make_pair
#define fs              first
#define sc              second
#define ll              long long
/***********************************************/
 
using namespace std;
 
const ll MAXN=200000+10;
ll n;
double a[MAXN],dp[MAXN],s[MAXN];
map<ll,ll> mp;
 
double make(double x)
{
    for(ll i=1;i<=n;i++){
        s[i]=dp[i]*1.0-i*1.0*x;
    }
 
    double mn=0;
    double j1=0;
    for(ll i=1;i<=n;i++){
        j1=max(j1,(s[i]-mn));
        mn=min(s[i],mn);
    }
 
    double mx=0;
    double j2=0;
    for(ll i=1;i<=n;i++){
        j2=min(j2,s[i]-mx);
        mx=max(mx,s[i]);
    }
 
    return max(j1,abs(j2));
}
 
bool check(double x)
{
    double f=make(x-0.00000000001);
    double g=make(x);
    return g<=f;
}
 
double solve()
{
    double l=-1e5,r=1e5;
    for(ll i=0;i<100;i++){
        double mid=(l*1.0+r*1.0)/2.0;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    return l;
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=dp[i-1]+a[i];
    }
 
    double ans=solve();
    double jav=make(ans);
 
    cout<<setprecision(10)<<fixed<<jav;
 
    return 0;
}
 
/*
~ahkh
*/