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

void bfs(vector<pair<int,int> > Graph[], vector<int> &dist,int s)
{
	queue<int> queue;
	
	dist[s]=0;
	queue.push(s);
	
	while(!queue.empty())
	{
		int curr = queue.front();
		queue.pop();
		
		for(vector<pair<int,int> >::iterator itr = Graph[curr].begin(); itr != Graph[curr].end(); ++itr)
		{
			if(dist[itr->fr] > dist[curr]+itr->sc)
			{
				dist[itr->fr] = dist[curr]+itr->sc;

				queue.push(itr->fr);
			}
		}
	} 
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
    // v,weight
    vector<pair<int,int> > Graph[V+1];
    rep(E)
    {
		int u,v,w = 1;
		cin>>u>>v;
		
		Graph[u].pb(mp(v,w));
		//In case of Bidirectional
		Graph[v].pb(mp(u,w));
		
	}
	// Start Node.
	int s = 1;
	vector<int> dist(V+1,INT_MAX);
	
	bfs(Graph,dist,s);
	
	int q;
	cin>>q;
	
	while(q--)
	{
		int x;
		cin >> x;
		cout<<dist[x]<<endl;
	}
	return 0;
}  


