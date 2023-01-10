// 1169. Invalid Transactions
// A transaction is possibly invalid if:

// the amount exceeds $1000, or;
// if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
// You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.

// Return a list of transactions that are possibly invalid. You may return the answer in any order.
// Example 1:

// Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
// Output: ["alice,20,800,mtv","alice,50,100,beijing"]
// Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
// Example 2:

// Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
// Output: ["alice,50,1200,mtv"]
// Example 3:

// Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
// Output: ["bob,50,1200,mtv"]


class Solution {
public:

vector<string> solve(string &s){
    vector<string> v;
    string t;
    for(auto it : s){
        if(it == ','){
            v.push_back(t);
            t.clear();
        }else{
            t.push_back(it);
        }
    }
    v.push_back(t);
    return v;
}

vector<string> invalidTransactions(vector<string>& transactions) {
    
    unordered_map<string , vector<string>> mp;
    for(int i=0;i<transactions.size();i++){
        mp[transactions[i]] = solve(transactions[i]);
    }
    
    vector<string>vec;
    for(int i=0;i<transactions.size();i++){
        vector<string> s = mp[transactions[i]];
        if(stoi(s[2]) > 1000){
            vec.push_back(transactions[i]);
            continue;
        } 
        for(int j=0;j<transactions.size();j++){
            if(i != j){
                vector<string> t = mp[transactions[j]];
                if( abs(stoi(t[1]) - stoi(s[1])) <= 60){
                    if(t[0] == s[0] && t[3] != s[3]){
                       vec.push_back(transactions[i]);
                        break;
                    } 
                } 
            }
        }
    }
    return vec;
}

};
