/*************************************************************************
    > File Name: 3.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月12日 星期五 16时53分54秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void print(vector<int> &nums) {
    auto nsize = nums.size();
    for(auto i = 0; i < nsize; ++i) {
        cout << nums[i] << "    ";
    }
    cout << endl;
}

int findSame_wrong1(vector<int> &nums) {
    auto nsize = nums.size();
    for(auto i = 0; i < nsize; ++i) {
        int temp = nums[i];
        if(i != temp) {
            if(nums[temp] == temp) {
                return temp;
            }
            // 把数字移动到对应index上
            swap(nums[i], nums[temp]);
        }
    }
    return 0;
}

// int findSame(vector<int> &num) {
    // std::set<int> numCount;
    // for(auto i: num) {
        // if(numCount.find(i) == numCount.end()) {
            // numCount.insert(i);
        // }
        // else {
            // return i;
        // }
    // }
    // return -1;
// }

int findSame_wrong2(vector<int> &nums) {
    auto nsize = nums.size();
    for(auto i = 0; i < nsize; ++i) {
        int temp = nums[i];
        while(i != temp) {
            cout << "round: " << i <<endl;
            print(nums);
            if(nums[temp] == temp) {
                return temp;
            }
            // 把数字移动到对应index上
            swap(nums[i], nums[temp]);
        }
    }
    return 0;
}

int findSame(vector<int> &nums) {
    auto nsize = nums.size();
    for(auto i = 0; i < nsize; ++i) {
        while(i != nums[i]) {
            int temp = nums[i];
            if(nums[temp] == temp) {
                return temp;
            }
            // 把数字移动到对应index上
            swap(nums[i], nums[temp]);
        }
    }
    return 0;
}

int main(void) {
    vector<int> n{2, 3, 5, 6, 4, 7, 1, 5, 0};
    vector<int> m{2, 3, 5, 6, 4, 7, 1, 5, 0};
    cout << findSame(n) << endl;
    // cout << "正确答案为" << findSame(n) << endl;
    // cout << "错误答案为" << findSame_wrong(m) << endl;
}
