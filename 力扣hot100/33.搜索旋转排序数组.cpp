#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int nums_len = nums.size();
        int left = 0, right = nums_len - 1;
       
        while (left <= right) {
            int mid = (left + right)/2;
            if (target == nums[mid]) {
                return mid;
            } 
            //[left, mid)有序
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            //(mid, right]有序
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

        }
        return -1;
    }
};
int main()
{
    vector<int> nums={4,5,6,7,0,1,2};
    int target=0;
    Solution s;
    cout<<s.search(nums,target)<<endl;
}