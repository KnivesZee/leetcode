#include "../pub.h"

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> arr(nums.size());
        int i = 0;
        for (auto& x : nums) {
            arr[i++] = static_cast<double>(x);
        }
        return process(arr);
    }
    bool process(vector<double>& nums) {
        int len = static_cast<int>(nums.size());
        if (len == 0) {
            return false;
        }
        if (len == 1) {
            return abs(nums[0] - 24) < 1e-6;
        }
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (i != j) {
                    vector<double> nums2;
                    for (int k = 0; k < len; k++) {
                        if (k != i && k != j) {
                            nums2.push_back(nums[k]);
                        }
                    }
                    for (int k = 0; k < 4; k++) {  // 对应+, *, -, /
                        if (k < 2 && j > i) {   // +, * 满足交换律, -, /不满足交换律
                            continue;
                        } else if (k == 0) {
                            nums2.push_back(nums[i] + nums[j]);
                        } else if (k == 1) {
                            nums2.push_back(nums[i] * nums[j]);
                        } else if (k == 2) {
                            nums2.push_back(nums[i] - nums[j]);
                        } else if (k == 3 && nums[j] != 0) {
                            nums2.push_back(nums[i] / nums[j]);
                        } else {
                            continue;
                        }
                        if (process(nums2)) {
                            return true;
                        }
                        // rollback
                        nums2.pop_back();
                    }
                }
            }
        }
        return false;
    }
};
