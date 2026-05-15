#include <iostream>
#include <string>
#include <stack>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2) { 
            return false;
        }
        stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push(')');
            } else if (c == '[') {
                st.push(']');
            } else if (c == '{') {
                st.push('}');
            } else {
                if (st.empty() || st.top() != c) {
                    return false; 
                }
                st.pop(); // 出栈
            }
        }
        return st.empty(); 
    }
};

int main() {
    Solution s;
    string test1 = "()[]{}";
    string test2 = "([)]";

    cout << "Test 1 (Expected true): " << s.isValid(test1) << endl;
    cout << "Test 2 (Expected false): " << s.isValid(test2) << endl;
    
    return 0;
}