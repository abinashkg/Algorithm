//OM
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <sstream>
#include <algorithm>
using  namespace  std;

#define  x first
#define  y second
#define  pb push_back
#define  mp make_pair
#define  PI (acos(-1.0))
#define  mem(a,b) memset(a,b,sizeof(a))
#define  Sort(x) sort(x.begin(),x.end())
#define  FOR(i, b, e) for(int i = b; i <= (int)(e); i++)
#define  FORR(i, b, e) for(int i = b; i >=(int)(e); i--)
#define  FORI(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define  pr(x) cout<<x<<"\n"
#define  prs(x) cout<<x<<" "
#define  pr2(x,y) cout<<x<<" "<<y<<"\n"
#define  pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define  ppr(a) cout<<a.x<<" "<<a.y<<"\n"

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  vector <int> vi;
typedef  vector <pii> vpii;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

#define  EPS 1e-9
#define  MAX 100007


/// Miller Rabin Primarility Testing{
ll  bigmod(ll a,ll b,ll mod) { //Bigmod
    ll ans=0;
    while(b){
        if (b&1)
            ans=(ans+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return ans;
}
// Random Number Generator
ll  randomll () {
    ll  ans = 0;
    FOR(i,0,3)
        ans = (ans << 16) ^ rand();
    return ans;
}
// Binary Represt.
ll  binByMod(ll  a, ll  to, ll  mod) {
    ll ans=1;
    while(to){
        if(to&1)
            ans=bigmod(ans,a,mod);
        a=bigmod(a,a,mod);
        to>>=1;
    }
    return ans;
}
// Prime Testing
bool isPrime(ll  n) {
    if (n % 2 == 0 && n != 2||n==1)
        return false;
    FOR(i,0,20) {
        ll  a = (randomll () % (n - 1));
        if (a < 0) a += n - 1;
        a++;
        a = binByMod(a, (n - 1) / 2, n);
        if (a != n - 1 && a != 1)
            return false;
    }
    return true;
}
///}

bool mark[1000005];
int prime[80005];
int  prime_gen(int n)
{
    for(int i=3;i*i<=n;i+=2)
        if(!mark[i])
            for(int j=i*i,k=i<<1;j<=n;j+=k)
            mark[j]=true;
    int k=0;
    prime[k++]=2;
    for(int i=3;i<=n;i+=2)if(!mark[i])prime[k++]=i;
    return k;
}
bool isquare(ll m)
{
    ll sq=(ll)(sqrt(m)+0.5);
    return sq*sq==m;
}
ll divisor_count(ll  n,int pc)
{
    ll divisor=1,pow;
    for(int i=0;prime[i]*prime[i]*prime[i]<=n&&i<pc;i++)
    {
        if(n%prime[i]==0)
        {
            pow=0;
            while(n%prime[i]==0)
            {
                pow++;
                n/=prime[i];
            }
            divisor*=(pow+1);
        }
    }
    if(isPrime(n))divisor*=2;
    else if(isquare(n))
    {
        ll sq=(ll)(sqrt(n)+EPS);
        if(isPrime(sq))divisor*=3;
    }
    else if(n!=1)divisor*=4;
    return divisor;
}
int main()
{
    int pcnt=prime_gen(1000001);
    pr(divisor_count(62899,pcnt));
    return 0;
}
