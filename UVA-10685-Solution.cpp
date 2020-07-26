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
vector<int>node[5001];
int visited[5001];
int dfs(int u)
{
    int c=0;
    visited[u]=true;
    for(int i=0;i<node[u].size();i++)
    {
        int v=node[u][i];
        if(!visited[v])
        {
           c++;
           c+=dfs(v);
        }
    }
    return c;
}
int main()
{
   int n,r;
   while(scc(n,r) && n)
   {
      string str,st;
      unordered_map<string,int>m;
      for(int i=0;i<n;i++)
      {
         cin>>str;
         m[str]=i+1;
      }
      for(int i=0;i<r;i++)
      {
         cin>>str>>st;
         //You can consider that if A is predator of B then they are in the same chain.
         node[m[st]].pb(m[str]);
         node[m[str]].pb(m[st]);
      } 
      getchar();
      int ans=-1;
      for(int i=1;i<=n;i++)
      {
         memset(visited,false,sizeof(visited));
         ans=max(ans,dfs(i));
      }
      pf(ans + 1);
      for(int i=0;i<5001;i++)
      {
         node[i].clear();
      }
   }
   return 0;
}
