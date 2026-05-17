#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>l(n,-1);
        vector<int>r(n,n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            //右边界
            while(!st.empty()&&heights[i]<heights[st.top()])
            {
                r[st.top()]=i;
                st.pop();
            }
            ///左边界
            if(!st.empty())
            {
                l[i]=st.top();
            }
            st.push(i);
        }
        int maxArea=0;
        for(int i=0;i<n;i++)
        {
            int w=r[i]-l[i]-1;
            int area=w*heights[i];
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};
int main()
{
    Solution s;
    vector<int>heights={2,1,5,6,2,3};
    int res=s.largestRectangleArea(heights);
    cout<<res;
    return 0;
}