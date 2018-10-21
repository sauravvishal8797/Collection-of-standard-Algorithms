#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define clr(a) memset(a, 0, sizeof(a))
#define rep(n) for(long i=0; i<n; i++)
#define repc(i, n) for(int i=0; i<n; i++)
#define rep1(n) for(long i=1; i<=n; i++)
#define repc1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a+n
#define endl "\n" 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
//.............................................................
int findParent(vector<int> &parent,int u)
{
	if(parent[u]==-1)
		return u;
	return findParent(parent,parent[u]);
}

int main(int argc, char const *argv[])
{
	//~ ios_base::sync_with_stdio(false);
    //~ cin.tie(NULL);
    
    //~ #ifndef ONLINE_JUDGE
 //~ freopen("./input.txt", "r", stdin);    
 //~ freopen("./output.txt", "w", stdout);
//~ #endif
    int V,E;
    cin>>V>>E;
    // weight, u, v
    vector<pair<int,pair<int,int> > > Edges;
    rep(E)
    {
		int u,v,w;
		cin>>u>>v>>w;
		
		Edges.pb(mp(w,mp(u,v)));
		
	}
	// parent array.
	vector<int> parent(V+1,-1);
	
	sort(all(Edges));
	int cnt=0;
	int totalDist=0;
	rep(E)
	{
		if(findParent(parent,Edges[i].sc.fr)==findParent(parent,Edges[i].sc.sc))
		{
			cout<<"cycle";
			continue;
		}
		totalDist+=Edges[i].fr;
		cnt++;
		if(cnt==V-1)
			break;
		parent[Edges[i].sc.fr] = parent[Edges[i].sc.sc];
	}
	cout<<"no cycle";
	cout<<totalDist;
	return 0;
}  



