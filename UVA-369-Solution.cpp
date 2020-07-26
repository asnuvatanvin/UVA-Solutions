#include <bits/stdc++.h>

/*............................*/

#define uint uint64_t
#define mx 5001
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
//formula for each cell in a pascals triangle is nCr
int main()
{
   uint pascal[101][101]={0};
   pascal[1][0]=pascal[1][1]=1;
   for(ll i=2;i<101;i++)
   {
      pascal[i][0]=1;
      for(ll j=1;j<i;j++)
      {
         pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
      } 
      pascal[i][i]=1;
   }
   int n,m;
   while(scc(n,m) && n && m)
   {
      printf("%d things taken %d at a time is %lld exactly.\n",n,m,pascal[n][m]);
   }
   // for(ll i=0;i<101;i++)
   // {
   //    for(ll j=0;j<=i;j++)
   //    {
   //       cout<<pascal[i][j]<<' ';
   //    }
   //    cout<<'\n';
   // }
   return 0;
}
