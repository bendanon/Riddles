#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int solution(vector<int>& A){
    sort(A.begin(), A.end());
    int min_val = std::numeric_limits<int>::max();

    for(int i = 1; i < A.size(); ++i){
        min_val = std::min(min_val, A[i-1] ^ A[i]);
    }
    
    return min_val;
}

TEST(MinXorValueSuite, Example1) { 

    vector<int> A{ 0, 2, 5, 7};
    ASSERT_EQ(2, solution(A));
}

TEST(MinXorValueSuite, Example2) { 

    vector<int> A{ 0, 4, 7, 9};
    ASSERT_EQ(3, solution(A));
}

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}