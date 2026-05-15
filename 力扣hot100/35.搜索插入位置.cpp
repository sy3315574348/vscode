#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(target==nums[mid])
            {
                return mid;
            }
            if(target<nums[mid])
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return left;
    }
};
int main()
{
    Solution s;
    vector<int> nums={1,3,5,6};
    int target=5;
    cout<<s.searchInsert(nums,target)<<endl;
    return 0;
}