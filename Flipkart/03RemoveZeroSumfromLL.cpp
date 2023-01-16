1171. Remove Zero Sum Consecutive Nodes from Linked List
// Medium
// 1.8K
// 80
// Companies
// Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

// After doing so, return the head of the final linked list.  You may return any such answer.
// (Note that in the examples below, all sequences are serializations of ListNode objects.)

// Example 1:

// Input: head = [1,2,-3,3,1]
// Output: [3,1]
// Note: The answer [1,2,1] would also be accepted.
// Example 2:

// Input: head = [1,2,3,-3,4]
// Output: [1,2,4]
// Example 3:

// Input: head = [1,2,3,-3,-2]
// Output: [1]


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

ListNode *dummy = new ListNode(0);
        dummy -> next = head;

       unordered_map<int,ListNode*>mp;
       mp[0] = dummy;
        ListNode* p =head;
        int sum=0;
        while(p!=NULL)
        {
        
            sum+=p->val;
            if(mp.find(sum)==mp.end())
            {
                mp[sum] = p;
            }

            else{

               
          ListNode* curr = mp[sum]->next;
            int removedsum = sum;

            while(curr!=p)
            {
                removedsum+=curr->val;
                mp.erase(removedsum);
                curr = curr->next;

            }

            mp[sum]->next = p->next;                


            }

            p = p->next;


        }


        return dummy->next; 
        
    }
};
