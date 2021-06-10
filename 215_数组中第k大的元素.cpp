#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	// 直接排序
    int findKthLargest1(vector<int>& nums, int k) {
		std::sort(nums.begin(), nums.end(), std::greater<int>());
		return nums[k];
    }
	
	// 堆排序
    int findKthLargest2(vector<int>& nums, int k) {
		priority_queue<int> heap;
		for(auto i: nums) {
			heap.push(i);
		}
		while(--k > 0) {
			heap.pop();
		} 
		return heap.top();

	}

	// 堆排序：不使用额外空间
    int findKthLargest(vector<int>& nums, int k) {
		std::make_heap(nums.begin(), nums.end());
		auto end = nums.end();
		while(--k > 0) {
			std::pop_heap(nums.begin(), end--);
		} 
		return nums[0];


	}

	// // 基于快速排序
    // int findKthLargest(vector<int>& nums, int k) {
	// }
};