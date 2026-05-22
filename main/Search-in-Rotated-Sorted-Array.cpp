1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int index=-1;
5        int low=0;
6        int high=nums.size()-1;
7        while(low<=high){
8            int mid=low+(high-low)/2;
9            if(nums[mid]==target){
10                index=mid;
11                break;
12            }
13            else if(nums[low]<=nums[mid]){
14                 if(target >= nums[low] && target < nums[mid])
15                    high = mid - 1;
16                else
17                    low = mid + 1;
18            }
19            else{
20                  if(target > nums[mid] && target <= nums[high])
21                    low = mid + 1;
22                else
23                    high = mid - 1;
24            }
25        }
26        return index;
27    }
28};