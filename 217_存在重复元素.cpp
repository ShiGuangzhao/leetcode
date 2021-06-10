#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 使用set
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> tmpSet;
        for(auto i: nums) {
            tmpSet.insert(i);
        }
        return tmpSet.size() != nums.size();
    }

    bool containsDuplicate2(vector<int>& nums) {
        unordered_set<int> tmpSet;
        for(auto i: nums) {
            if(tmpSet.count(i)) {
                return true;
            }
            tmpSet.insert(i);
        }
        return false;
    }
};