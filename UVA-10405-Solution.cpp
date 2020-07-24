#include <bits/stdc++.h>

/*............................*/

#define uint uint64_t
#define mx 1001
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
int dp[mx][mx];
int lcs(int i, int j, string str1, string str2)
{
   if (i == str1.length() || j == str2.length())
   {
      return 0;
   }
   if (dp[i][j] != -1)
   {
      return dp[i][j];
   }
   int ans = 0;
   if (str1[i] == str2[j])
   {
      ans = 1 + lcs(i + 1, j + 1, str1, str2);
   }
   else
   {
      int val1 = lcs(i + 1, j, str1, str2);
      int val2 = lcs(i, j + 1, str1, str2);
      ans = max(val1, val2);
   }
   dp[i][j] = ans;
   return dp[i][j];
}
int main()
{
   string str,st;
   while(getline(cin,str))
   {
      getline(cin,st);
      memset(dp,-1,sizeof(dp));
      printf("%d\n",lcs(0,0,str,st));
   }
   return 0;
}
