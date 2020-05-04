#include <gtest/gtest.h>
#include <vector>
using std::vector;
using std::map;
using std::pair;

/*
Given an array of size n, find the majority element. 
The majority element is the element that appears more than floor(n/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.
*/

int solution(const vector<int>& A){

    int maj_index = 0, count = 1;

    for(int i = 1; i < A.size(); ++i){

        count += A[maj_index] == A[i] ? 1 : -1;

        //This means A[maj_index] was not seen more times than it was seen
        if(count == 0){
            maj_index = i;
            count = 1;
        }
    }

    return A[maj_index];
}

TEST(MajorityElementSuite, example) { 
    vector<int> A {2, 1, 2};    
    ASSERT_EQ(2, solution(A));
}

TEST(MajorityElementSuite, trivial) { 
    vector<int> A {1};    
    ASSERT_EQ(1, solution(A));
}

TEST(MajorityElementSuite, single_repetition) { 
    vector<int> A {1, 1, 1, 1};    
    ASSERT_EQ(1, solution(A));
}

TEST(MajorityElementSuite, close_call) { 
    vector<int> A {1, 2, 1, 2, 1, 2, 1};    
    ASSERT_EQ(1, solution(A));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}