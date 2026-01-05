// Parsing A Boolean Expression
#include<iostream>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char c : expression) {
            if (c == ',') continue;

            if (c != ')') {
                st.push(c);
            } else {
                bool hasTrue = false, hasFalse = false;

                // evaluate inside (...)
                while (st.top() != '(') {
                    char val = st.top();
                    st.pop();
                    if (val == 't') hasTrue = true;
                    if (val == 'f') hasFalse = true;
                }
                st.pop(); // remove '('

                char op = st.top();
                st.pop();

                if (op == '!') {
                    st.push(hasFalse ? 't' : 'f');
                } 
                else if (op == '&') {
                    st.push(hasFalse ? 'f' : 't');
                } 
                else { // '|'
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }
        return st.top() == 't';
    }
};
