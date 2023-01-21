// 1054. Distant Barcodes
// In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].

// Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.
// Example 1:

// Input: barcodes = [1,1,1,2,2,2]
// Output: [2,1,2,1,2,1]
// Example 2:

// Input: barcodes = [1,1,1,1,2,2,3,3]
// Output: [1,3,1,3,1,2,1,2]
 
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> ans(barcodes.size(), 0);
        unordered_map<int, int> m;
        for (int i: barcodes) {
            m[i]++;
        }
	
        priority_queue<pair<int, int>> pq;
        for (auto it=m.begin(); it != m.end(); ++it) {
            pq.push({it->second, it->first});
        }
	    int index = 0;
        int key, value;
        while (!pq.empty()) {
            key = pq.top().second;
            value = pq.top().first;
            pq.pop();
            while (value != 0) {
                if (index >= ans.size()) index = 1;
                ans[index] = key;
                --value;
                index += 2;
            }
        }
        return ans;
    }
};
