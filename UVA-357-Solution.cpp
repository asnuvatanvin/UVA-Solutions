#include <bits/stdc++.h>

/*............................*/

#define uint uint64_t
#define mx 30001
#define ll long long int
#define ull unsigned long long int
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define mod 100000007
#define pi acos(-1)
#define eps 1e-8
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / __gcd(a, b)
#define input(ara, n)          \
   for (int i = 0; i < n; i++) \
   scanf("%d", &ara[i])
#define inputl(ara, n)                   \
   for (long long int i = 0; i < n; i++) \
   scanf("%lld", &ara[i])
#define printcase(p) printf("Case %d: ", p)
#define pf(a) printf("%d\n", a);
#define pfl(a) printf("%lld\n", a);
#define pfi(a) printf("%d ", a);
#define pfll(a) printf("%lld ", a);
#define sc(a) scanf("%d", &a)
#define scc(a, b) scanf("%d %d", &a, &b)
#define sccdbl(a, b) scanf("%lf %lf", &a, &b)
#define sccc(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scccdbl(a, b, c) scanf("%lf %lf %lf", &a, &b, &c)
#define scl(a) scanf("%lld", &a)
#define sccl(a, b) scanf("%lld %lld", &a, &b)
#define scccl(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
using namespace std;
#define nn 5
ll coin[nn] ={ 1, 5, 10, 25, 50 };
ll dp[mx];
ll n;
int main()
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (ll i = 0; i < nn; i++)
    {
        for (ll j = coin[i]; j < mx; j++)
        {
            if (coin[i] <= j)
            {
                dp[j] = dp[j] + dp[j - coin[i]];
            }
        }
    }
    while (scl(n)==1)
    {
       if(dp[n]>1)
       {
          printf("There are %lld ways to produce %lld cents change.\n",dp[n],n);
       }
       else
       {
          printf("There is only 1 way to produce %lld cents change.\n",n);
       }
        //pfl(func(0, n));
    }
    return 0;
}
