743. Network Delay Time

// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
// Example 1:

// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2
// Example 2:

// Input: times = [[1,2,1]], n = 2, k = 1
// Output: 1
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int>costs(n+1,INT_MAX);
        
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(auto i:times)
        {
            adj[i[0]].push_back({i[2],i[1]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        costs[k]=0;
        
        pq.push({0,k});
        
        while(pq.size() > 0)
        {
            pair<int,int> p = pq.top();
            pq.pop();
            
            for(auto i : adj[p.second])
            {
                int x = costs[p.second] + i.first;
                if(costs[i.second] > x)
                {
                    costs[i.second] = x;
                    pq.push({x,i.second});
                }
            }
        }
        
        int time = INT_MIN;
        
        for(int i=1; i<costs.size(); i++)
        {
            time = max(time,costs[i]);
        }
        
        if(time == INT_MAX)
        return -1;
        
        else
        return time;
    }
    
};
