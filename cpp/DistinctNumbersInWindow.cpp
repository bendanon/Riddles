#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
using namespace std;


/*
You are given an array of N integers, A1, A2 ,…, AN and an integer K. 
Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains 
number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

If K > N, return empty array.
A[i] is a signed integer

*/

vector<int> solution(vector<int>& A, int B){
    vector<int> ret;
    if(B > A.size()){
        return ret;
    }

    unordered_map<int, int> m;
    
    for(int i = 0; i < B; ++i){ ++m[A[i]]; }
    ret.push_back(m.size());

    for(int i = 1; i <= A.size() - B; ++i){
        
        if(m[A[i-1]] > 1){
            --m[A[i - 1]];
        } else{
            m.erase(A[i - 1]);
        }        

        ++m[A[i + B - 1]];

        ret.push_back(m.size());
    }
    
    return ret;
}

TEST(WindowSuite, example) { 
    vector<int> A {1, 2, 1, 3, 4, 3};
    int K = 3;

    vector<int> exp {2, 3, 3, 2};
    ASSERT_EQ(exp, solution(A, K));
}

TEST(WindowSuite, complex) { 
    vector<int> A {3, 5, 2, 7, 4, 5, 4, 5, 3, 5, 6, 4, 345, 56, 56, 1};
    int K = 4;

    vector<int> exp {4, 4, 4, 3, 2, 3, 3, 3, 4, 4, 4, 3, 3};
    ASSERT_EQ(exp, solution(A, K));
}

TEST(WindowSuite, trivial_n_lt_k) { 
    vector<int> A {1, 2};
    int K = 3;
    
    vector<int> exp {};
    ASSERT_EQ(exp, solution(A, K));
}

TEST(WindowSuite, trivial_n_eq_k) { 
    vector<int> A {1, 2, 3};
    int K = 3;
    vector<int> exp { 3 };

    ASSERT_EQ(exp, solution(A, K));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}