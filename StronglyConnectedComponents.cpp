
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


void strongConnComp(vector<int> Graph[], vector<bool> &visited,stack<int> &stack, int s)
{
	if(visited[s])
		return;
	visited[s] = 1;
	
	for(vector<int>::iterator itr=Graph[s].begin();itr!=Graph[s].end();++itr)
	{
		if(!visited[*itr])
		{
			strongConnComp(Graph,visited,stack, *itr);
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
    vector<int > Graph[V+1],GraphT[V+1];
    rep(E)
    {
		int u,v;
		cin>>u>>v;
		
		Graph[u].pb(v);
		//In case of Bidirectional
		GraphT[v].pb(u);
		
	}
	// Start Node.
	//~ int s = 1;
	
	vector <bool> visited(V+1,0);
	vector <bool> visitedT(V+1,0);
	stack<int> stack,stack2;
	rep1(V)
	{
		if(visited[i]==0)
		{
			strongConnComp(Graph,visited,stack,i);
		}
	}
	
	while(!stack.empty())
	{
		int curr=stack.top();
		stack.pop();
		cout<<curr<<' ';
		if(visitedT[curr]==0)
		{
			strongConnComp(GraphT, visitedT, stack2, curr);
			while(!stack2.empty())
			{
				int curr=stack2.top();
				stack2.pop();
				cout<<curr<<' ';
			}
			cout<<endl;
		}
		
		
	}
	
	return 0;
}  



