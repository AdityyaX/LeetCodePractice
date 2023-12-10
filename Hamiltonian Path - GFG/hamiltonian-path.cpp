//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

 class Solution
{
    public:
    set<int>st;
    int n=0;
    bool dfs(int node,vector<int> adj[],int count,vector<int> &vis){
        st.insert(node);
        if(st.size()==n)return true;
        //if(count == (vis.size()-1)) return true ;
        
        vis[node] = 1 ;
        count += 1 ;
         for(auto it : adj[node]){
             if(!vis[it]){
                 if(dfs(it,adj,count,vis)) return true ;
             }
         }
         st.erase(node);
         vis[node]=0;
         return false ;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {   
        n=N;
        int count  = 1 ;
        vector<int> adj[N+1] ;
        for(auto it : Edges){
            adj[it[0]].push_back(it[1]) ;
            adj[it[1]].push_back(it[0]) ;
        }
        vector<int> vis(N+1,false) ;
        for(int i = 1 ; i <= N ; i++){
            if( dfs(i,adj,count,vis) ) return true ;
        }
        return false ;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends