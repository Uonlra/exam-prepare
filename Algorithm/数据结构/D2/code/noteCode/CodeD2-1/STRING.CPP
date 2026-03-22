#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t){
        if (s.length() != t.length()){
            return false;
        }
        // 统计s中每个字符出现的次数
        int count[26] = {0};

        for (int i = 0; i < (int)s.length(); i++){
            count[s[i] - 'a']++; // 增加s中每个字符出现的次数
            count[t[i] - 'a']--; // 减少t中每个字符出现的次数
        }
        for (int count_i : count){
            if (count_i != 0){
                return false; // 如果有任何字符的计数不为0，说明s和t不是字母异位词
            }
        }

        return true;
    }
};