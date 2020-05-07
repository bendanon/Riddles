#include <gtest/gtest.h>
#include <vector>
using namespace std;

/*
Given numRows, generate the first numRows of Pascal’s triangle.
Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
*/

vector<vector<int>> solution(int A){
    vector<vector<int>> ret { };
    
    if(A == 0){
        return ret;
    }

    ret.push_back({1});

    for(int i = 1; i < A; ++i){

        vector<int> row{1};

        for(int j = 1; j < i; ++j){
            row.push_back(ret[i - 1][j] + ret[i - 1][j - 1]);
        }

        row.push_back(1);

        ret.push_back(row);
    }

    return ret;
}

TEST(PascalSuite, example) { 
    vector<vector<int>> expected {{1},
                                  {1,1},
                                  {1, 2, 1}, 
                                  {1, 3, 3, 1}, 
                                  {1, 4, 6, 4, 1}};

    ASSERT_EQ(expected, solution(5));
}

TEST(PascalSuite, basic) { 
    vector<vector<int>> expected {{1},
                                  {1,1},
                                  {1, 2, 1}}; 

    ASSERT_EQ(expected, solution(3));
}

 
TEST(PascalSuite, trivial_1) { 
    vector<vector<int>> expected {{1}};
    ASSERT_EQ(expected, solution(1));
}

TEST(PascalSuite, trivial_0) { 
    vector<vector<int>> expected {};
    ASSERT_EQ(expected, solution(0));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}