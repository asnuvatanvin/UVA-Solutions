#include <bits/stdc++.h>

/*............................*/

#define uint uint64_t
#define mx 100001
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
int parent[100001], nodes[100001];
void initialize()
{
   for (int i = 0; i < 100001; i++)
   {
      parent[i] = i;
      nodes[i] = 0;
   }
}
int find_parent(int v)
{
   return parent[v] = (parent[v] == v) ? v : find_parent(parent[v]);
}
int union_set(int a, int b)
{
   a = find_parent(a);
   b = find_parent(b);
   if (a != b)
   {
      parent[a] = b; 
      nodes[b] += nodes[a] + 1;
   }
   return nodes[b];
}
int main()
{
   int t;
   sc(t);
   while (t--)
   {
      int n;
      sc(n);
      map<string, int> m;
      string str, st;
      int i = 1;
      initialize();
      while (n--)
      {
         cin >> str >> st;
         if (m[str] == 0)
         {
            m[str] = i++;
         }
         if (m[st] == 0)
         {
            m[st] = i++;
         }
         cout<<union_set(m[str], m[st]) + 1<<'\n';
      }
   }
   return 0;
}
