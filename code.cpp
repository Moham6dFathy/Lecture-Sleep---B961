#include <bits/stdc++.h>

using namespace std;

#define testcases int testcases = 1 ; cin>>testcases ; while(testcases--)
#define Moham6d_Fathy ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define loop(n) for(int i=0;i<n;i++)
#define loop1(n) for(int i=1;i<=n;i++)
#define rloop(n) for(int i=n-1;i>=0;i--)
#define ll  long long
#define ld  long double
#define all(n) n.begin() , n.end()
#define rall(v) v.rbegin(),v.rend()
#define endl "\n"
#define pi 3.14159265359

ll mod = 1e9+7;

ll _gcd(ll n1,ll n2)
{
    while (n2!=0)
    {
        ll temp=n1;
        n1=n2;
        n2=temp%n1;
    }
    return n1;
}

ll _lcm(ll n1,ll n2)
{
    return (n1/ _gcd(n1,n2))*n2;
}

int fact(ll i)
{
    if (i <= 1) return 1;
    else return i*fact(i-1);
}

bool comp(pair<ll,ll>p1,pair<ll,ll>p2)
{
    if(p1.first==p2.first)
        return (p1.second<p2.second);

    return (p1.first<p2.first);

}
int lcs( string X, string Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
///////////-_-//////////////////////////////*Solve*/////////////////////////////////-_-////////////
bool cmp(pair<string,int>p1,pair<string,int>p2)
{
    return (p1.second>p2.second);
}
void solve()
{
    int n,k;
    cin>>n>>k;
    
    int arr[n+1]={},t[n+1],a[n+1]={};
    loop1(n)cin>>arr[i];
    int sum(0);
    loop1(n)
    {
        cin>>t[i];
        if(t[i])sum+=arr[i],arr[i]=0;
    }

    partial_sum(arr+1,arr+n+1,a+1);

    int res=0;
    for(int i=1;i<=n-k+1;i++)
    {
        int s=(a[i+k-1]-a[i-1]);
        res=max(res,s);
    }
    cout<<res+sum;
}

int main()
{
    Moham6d_Fathy;

#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    //testcases
    {
        solve();
    }

    return 0;
}
