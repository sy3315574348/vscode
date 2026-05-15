#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        string res = "";
        string num = "";
        stack<string> st;
        
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                num += c;
            }
            else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                res += c;
            }
            else if (c == '[') {
                st.push(num);
                num = "";
                st.push(res);
                res = "";
            }
            else if (c == ']') {
                string prev_str = st.top(); // 括号前的前缀字符串
                st.pop();
                string time_str = st.top(); // 重复次数
                st.pop();
                
                int t = atoi(time_str.c_str());
                string temp = "";
                for (int i = 0; i < t; i++) {
                    temp += res; // 把当前括号里的内容重复 t 次
                }
                res = prev_str + temp; 
                num = ""; 
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    string str = "3[a]2[bc]";
    cout<<s.decodeString(str)<<endl;
}