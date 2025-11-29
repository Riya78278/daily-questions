// Parenthesis Checker

#include <iostream>
using namespace std;

class Solution {
  public:
    bool isBalanced(string& s) {
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++ ) {

            if(s.size() == 1 && (s[i] == ']' || s[i] == '}' || s[i] == ')')) {
                return false;
            }

            if(s[i] == '[' || s[i] == '{' || s[i] == '(') {
                st.push(s[i]);
            }
            else if(s[i] == ']' || s[i] == '}' || s[i] == ')') {

                // *** FIX: check empty before top() ***
                if(st.empty()) return false;

                if((s[i] == ')' && st.top() == '(') ||
                   (s[i] == '}' && st.top() == '{') ||
                   (s[i] == ']' && st.top() == '[')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        
        if(!st.empty()) {
            return false;
        }
        return true;
    }
};
