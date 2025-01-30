#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define Yes cout<<"YES"<<endl;
#define No cout<<"NO"<<endl;
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(V) V.begin(),V.end()
#define srt(V) sort(all(V))
#define rall(n) n.rbegin(), n.rend()
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define tcase() ll t;cin>>t;while(t--)

const int mx=1e5+123;
vector<bool>vis(mx,0);
vector<int>adj[mx];
stack<int>st;

void findToposort(int node){
	vis[node]=1;
	for(int it:adj[node]){
		if(vis[it]==0){
			findToposort(it);
		}
	}
	st.push(node);
}
vector<int>topoSort(int n){
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			findToposort(i);
		}
	}
	vector<int>topo;
	while(!st.empty()){
		topo.push_back(st.top());
		st.pop();
	}
	return topo;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	vector<int>ans=topoSort(n);
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

//for the example graph ans is 5 4 2 3 1 0

