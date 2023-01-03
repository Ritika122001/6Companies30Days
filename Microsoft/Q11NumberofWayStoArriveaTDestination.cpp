// 1976. Number of Ways to Arrive at Destination
// You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

// You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

// Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.
// Example 1:

// Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
// Output: 4
// Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
// The four ways to get there in 7 minutes are:
// - 0 ➝ 6
// - 0 ➝ 4 ➝ 6
// - 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
// - 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
// Example 2:

// Input: n = 2, roads = [[1,0,10]]
// Output: 1
// Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.



class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        long long mod=(long long)(1e9+7);
        vector<pair<long long,long long>>adj[n]; //ADJ LIST
        for(auto &c :roads)
        {
                adj[c[0]].push_back({c[1],c[2]});
                adj[c[1]].push_back({c[0],c[2]});
        }
            priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
            vector<long long>w(n,0); //ways vector
            pq.push({0,0});
            vector<long long>dist(n,LONG_MAX);  //distance vector 
            w[0]=1;
            dist[0]=0; 
          
            while(!pq.empty())
            {
                    auto c =pq.top();
                    long long dis=c.first;
                    long long node=c.second;
                    pq.pop();

                for(auto c:adj[node])
                {
                    long long adjnode=c.first;
                    long long it=c.second;
                    if(it+dis<dist[adjnode]) //if it+dist becomes < dist[adjnode] -> add it to pq and update both vectors
                    {
                        w[adjnode]=w[node];
                        dist[adjnode]=it+dis;
                        pq.push({it+dis,adjnode});
                    }
                    else if(it+dis==dist[adjnode]) //if it + dist becomes equal to dist[adjnode]
                    {
                        w[adjnode]=(w[node]+ w[adjnode])%mod;
                    }
                }
    }
    return (w[n-1])%mod;
    }
};