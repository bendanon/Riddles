#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

/*
Given N bags, each bag contains Ai chocolates. There is a kid and a magician. 
In one unit of time, kid chooses a random bag i, eats Ai chocolates, then the magician 
fills the ith bag with floor(Ai/2) chocolates.
Given Ai for 1 <= i <= N, find the maximum number of chocolates kid can eat in K units of time.

Note: Return your answer modulo 10^9+7
*/ 

int solution(int A, vector<int>& B){

    unsigned int ret = 0;
    int mod = pow(10, 9) + 7;

    priority_queue<int> q(begin(B), end(B));

    for(int t = 0; t < A; ++t){
        
        //Get the max bag
        int max_bag = q.top();
        ret += max_bag;
        ret %= mod;

        q.pop();

        //Push max_bag / 2 back to the heap
        q.push(max_bag / 2);
    }
    
    return ret;
}

TEST(MageSuite, Exmaple) { 
    int A = 3;
    vector<int> B {6, 5};
    ASSERT_EQ(14, solution(A, B));
}

TEST(MageSuite, trivial) { 
    int A = 1;
    vector<int> B {6};
    ASSERT_EQ(6, solution(A, B));
}

TEST(MageSuite, trivial_iterations) { 
    int A = 3;
    vector<int> B {6};
    ASSERT_EQ(6 + 3 + 1, solution(A, B));
}

TEST(MageSuite, zero) { 
    int A = 6;
    vector<int> B {6};
    ASSERT_EQ(6 + 3 + 1, solution(A, B));
}

TEST(MageSuite, repetitions) { 
    int A = 5;
    vector<int> B {4, 4, 4, 4};
    ASSERT_EQ(4 + 4 + 4 + 4 + 2, solution(A, B));
}

TEST(MageSuite, complex) { 
    int A = 10;
    vector<int> B{ 2147483647, 2000000014, 2147483647 };
    ASSERT_EQ(284628164, solution(A, B));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}