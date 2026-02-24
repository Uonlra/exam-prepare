#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
            if (counts[num] > 1) {
                return true;
            }
        }
        return false;
    }
};