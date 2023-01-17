// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
// Example 1:
// Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
// Output: 3
// Explanation: The figure above describes the graph. 
// The neighboring cities at a distanceThreshold = 4 for each city are:
// City 0 -> [City 1, City 2] 
// City 1 -> [City 0, City 2, City 3] 
// City 2 -> [City 0, City 1, City 3] 
// City 3 -> [City 1, City 2] 
// Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
// Example 2:
// Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
// Output: 0
// Explanation: The figure above describes the graph. 
// The neighboring cities at a distanceThreshold = 2 for each city are:
// City 0 -> [City 1] 
// City 1 -> [City 0, City 4] 
// City 2 -> [City 3, City 4] 
// City 3 -> [City 2, City 4]
// City 4 -> [City 1, City 2, City 3] 
// The city 0 has 1 neighboring city at a distanceThreshold = 2.


class Solution {
public:

vector<pair<int,int>> adj[105];
vector<pair<int,int>> ans;

bool static cmp(const pair<int,int> p1 ,const pair<int,int> p2)
{
    if(p1.first != p2.first)
        return p1.first < p2.first;
    
    return p1.second > p2.second;
}

void solve(int S, int n, int distanceThreshold)
    {

        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,S});
        vector<int>dist(n+1,1e9);
        dist[S]=0;
        
        while(!pq.empty())
        {  
            pair<int,int>r = pq.top();
            int dis = r.first;
            int node = r.second;
            pq.pop();
            
            for(auto it : adj[node])
            {
                int  adjNode = it.first;
                int edgeweight = it.second;

                if(dis + edgeweight < dist[adjNode])
                {
                   dist[adjNode] = dis + edgeweight;
                   pq.push({dist[adjNode],adjNode});

                }
        }
        
        }


    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(i != S && dist[i] <= distanceThreshold)
            cnt++;
    }
    
ans.push_back({cnt, S});
        
    }


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        for(auto c : edges)
        {
            adj[c[0]].push_back({c[1],c[2]});
            adj[c[1]].push_back({c[0],c[2]});
        }

        for(int i=0;i<n;i++)
        {
           solve(i,n,distanceThreshold);
            
        }

        sort(ans.begin(), ans.end(),cmp);
        return ans[0].second;
    }
};
