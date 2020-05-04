#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array A, of N integers A.
Return the highest product possible by multiplying 3 numbers from the array.
NOTE: Solution will fit in a 32-bit signed integer.
*/

//O(n)
int solution(const vector<int>& A){
    if(A.size() < 3){
        return 0;
    }
    if(A.size() == 3){
        return A[0] * A[1] * A[2];
    }

    int maxes[3];
    int mins[2];

    vector<int> tmp = A;
    auto max = max_element(begin(tmp), end(tmp)); maxes[0] = *max; tmp.erase(max);
    max = max_element(begin(tmp), end(tmp)); maxes[1] = *max; tmp.erase(max);
    max = max_element(begin(tmp), end(tmp)); maxes[2] = *max; tmp.erase(max);

    if(A.size() == 4){
        return maxes[0] * maxes[1] * maxes[2];
    }

    auto min = min_element(begin(tmp), end(tmp)); mins[0] = *min; tmp.erase(min);
    min = min_element(begin(tmp), end(tmp)); mins[1] = *min; tmp.erase(min);

    vector<int> options { maxes[0] * maxes[1] * maxes[2], 
                          mins[0] * mins[1] * maxes[0], 
                          mins[0] * mins[1] * maxes[1], 
                          mins[0] * mins[1] * maxes[2] };

    return *max_element(begin(options), end(options));
}


//O(nlogn)
int solution_2(vector<int>& A){
    sort(A.begin(), A.end());
    int n = A.size();
    int max3 = A[n-1]*A[n-2]*A[n-3];
    int min2max = A[n-1]*A[0]*A[1];
    return max(max3, min2max);
}

TEST(MajorityElementSuite, example) { 
    vector<int> A {1, 2, 3, 4};    
    ASSERT_EQ(24, solution(A));
    ASSERT_EQ(24, solution_2(A));

}

TEST(MajorityElementSuite, basic) { 
    vector<int> A {1, 2, -3};    
    ASSERT_EQ(-6, solution(A));
    ASSERT_EQ(-6, solution_2(A));
}

TEST(MajorityElementSuite, example_2) { 
    vector<int> A {0, -1, 3, 100, 70, 50};    
    ASSERT_EQ(350000, solution(A));
    ASSERT_EQ(350000, solution_2(A));
}

TEST(MajorityElementSuite, trivial) { 
    vector<int> A {1};    
    ASSERT_EQ(0, solution(A));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}