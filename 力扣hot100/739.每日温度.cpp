#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        vector<int>res(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++)
        {
            while(!st.empty()&&temperatures[i]>temperatures[st.top()])
            {
                res[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int>temperatures={73,74,75,71,69,72,76,73};
    vector<int>res=s.dailyTemperatures(temperatures);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    return 0;
}