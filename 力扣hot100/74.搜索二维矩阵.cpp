#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m=matrix.size();
       int n=matrix[0].size();
       int l=0,r=m*n-1;
       while(l<=r)
       {
            int mid=(r+l)/2;
            int midX=mid/n;
            int midY=mid%n;
            if(matrix[midX][midY]<target)
            {
                l=mid+1;
            }
            else if(matrix[midX][midY]>target)
            {
                r=mid-1;
            }
            else
            {
                return true;
            }
       } 
        return false;
    }
};
int main()
{
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=3;
    Solution s;
    cout<<s.searchMatrix(matrix,target)<<endl;
}