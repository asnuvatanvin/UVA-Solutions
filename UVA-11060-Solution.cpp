#include <bits/stdc++.h>

/*............................*/

#define uint uint64_t
#define mx 200001
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
vector<int> node[101];
//bool visited[101];
vector<int> ans;
unordered_map<string, int> mm;
map<int, string> mpp;
int indegree[101];
int n, m;
// void dfs(int u)
// {
//    visited[u] = true;
//    for (int i = 0; i < node[u].size(); i++)
//    {
//       int v = node[u][i];
//       if (!visited[v])
//       {
//          indegree[v]--;
//          dfs(v);
//       }
//    }
//    //ans.pb(u);
// }
void topological_sorting()
{
   ans.clear();
   // memset(visited, false, sizeof(visited));
   // for (int i = 1; i <= n; i++)
   // {
   //    if (!visited[i])
   //    {
   //       dfs(i);
   //    }
   // }
   //reverse(ans.begin(), ans.end());
   //topological sorting in lexicographocal order
   priority_queue<int,vector<int>,greater<int> >pq;
   for(auto i:mpp)
   {
      if(indegree[i.first]==0)
      {
         pq.push(i.first);
      }
   }
   while(!pq.empty())
   {
      int q = pq.top();
      pq.pop();
      ans.pb(q); 
      for(int i=0;i<node[q].size();i++)
      {
         int v = node[q][i];
         indegree[v]--;
         if(indegree[v]==0)
         {
            pq.push(v);
         }
      }
   }
}
int main()
{
   int p = 1;
   while (sc(n) == 1)
   {
      mm.clear();
      mpp.clear();
      int a, b;
      string str, stt;
      for (int i = 0; i < n; i++)
      {
         cin >> str;
         mm[str] = i + 1;
         mpp[i + 1] = str;
      }
      sc(m);
      memset(indegree, 0, sizeof(indegree));
      while (m--)
      {
         cin >> str >> stt;
         node[mm[str]].pb(mm[stt]);
         indegree[mm[stt]]++;
      }
      topological_sorting();
      printf("Case #%d: Dilbert should drink beverages in this order: ", p++);
      for (int i = 0; i < ans.size() - 1; i++)
      {
         cout << mpp[ans[i]] << ' ';
      }
      cout << mpp[ans[ans.size() - 1]] << '.' << "\n\n";
      for (int i = 0; i < 101; i++)
      {
         node[i].clear();
      }
   }
   return 0;
}
