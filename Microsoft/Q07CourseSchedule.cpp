// 207. Course Schedule
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.
// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.


//USED CYCLE DETECTION APPROACH IN DIRECTED GRAPH USING DFS

class Solution {
  
bool dfs(int node,  vector<int>&vis,  vector<vector<int>>&adj, vector<int>&dfsv )	
	{
	
    //mark the node visited in both vectors
     vis[node]=1;
      dfsv[node]=1;
	    
	    for(auto it:adj[node])
	    {
	        if(!vis[it]) //if not visited
	        {
	            if(dfs(it,vis,adj,dfsv)) return true;
	        }
	        
        else if(dfsv[it])   return true; 
	    }

      dfsv[node]=0;
      return false;

     
	}
  
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      
     vector<vector<int>>adj(numCourses);
        for(auto edge : prerequisites)
            adj[edge[1]].push_back(edge[0]); //make adj list 
      
      
      int V=numCourses;
      vector<int>dfsv(numCourses,0);
      vector<int>vis(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0 and dfs(i,vis,adj,dfsv))  return false; 
           
	    }
      
      return true;

    }
  
};

