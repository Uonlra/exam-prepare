    int hammingWeight(unsigned int n) {
        int count = 0;
        while (n) {
            ++count;
            n &= (n - 1);  // 每次消去最右侧的 1
        }
        return count;
    }