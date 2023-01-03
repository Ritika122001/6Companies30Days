// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
// 150. Evaluate Reverse Polish Notation
// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

// Example 1:

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:

// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6

class Solution {
public:

    int evalRPN(vector<string>& tokens) 
    {

        stack<int>st; 
        int i=0;

        for(int i=0;i<tokens.size();i++) //Traverse the tokens vector
        {

          if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/") // if any operator 
            {
                //pop two top most operands from stack
                long long x = st.top(); st.pop();
                long long y = st.top(); st.pop();

                //perform operations on x and y 

                if(tokens[i]=="+")
                {
                    st.push(y+x);
                }

                else if(tokens[i]=="-")
                {
                    st.push(y-x);
                }

                else if(tokens[i]=="/")
                {
                    st.push(y/x);
                }

                else{
                    st.push(y*x);
                }
            }
            else{
                //if not a operator 
                st.push(stoi(tokens[i]));


            }


        }

        return st.top();
        
    }
};