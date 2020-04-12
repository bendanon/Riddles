#include <gtest/gtest.h>
#include <math.h>

using namespace std; 
/**
 * Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.
 * Make sure the combinations are sorted.
 * To elaborate,
    Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
    Entries should be sorted within themselves.
 **/

void _combine(vector<vector<int>>& ans, vector<int> prefix, int start, int end, int B){

    if(B == 0){

        //This means the length of prefix is B, so add it to the answer
        ans.push_back(prefix);
        return;
    }

    if(start > end){
        return;
    }

    //Add all combinations starting with prefix + start
    prefix.push_back(start);    
    _combine(ans, prefix, start + 1, end, B - 1);
    
    //Add all combinations with prefix without start
    prefix.pop_back();
    _combine(ans, prefix, start + 1, end, B);
}

vector<vector<int>> combine(int A, int B){
    vector<vector<int>> ans;
    _combine(ans, vector<int>{}, 1, A, B);
    return ans;
}

TEST(CombinationsSuite, Trivial){
    auto expected_result = vector<vector<int>> { { 1 } };

    ASSERT_EQ(expected_result, combine(1, 1));
}

TEST(CombinationsSuite, Trivial_2){
    auto expected_result = vector<vector<int>> { { 1 }, { 2 }, { 3 }, { 4 } };

    ASSERT_EQ(expected_result, combine(4, 1));
}


TEST(CombinationsSuite, Example) { 
    
    auto expected_result = vector<vector<int>>{ { 1, 2 }, 
                                                { 1, 3 }, 
                                                { 1, 4 },
                                                { 2, 3 }, 
                                                { 2, 4 },
                                                { 3, 4 }};
    ASSERT_EQ(expected_result, combine(4, 2));
}

TEST(CombinationsSuite, Complex) { 
    
    auto expected_result = vector<vector<int>>{ { 1, 2, 3 }, 
                                                { 1, 2, 4 }, 
                                                { 1, 2, 5 },
                                                { 1, 3, 4 }, 
                                                { 1, 3, 5 },
                                                { 1, 4, 5 }, 
                                                { 2, 3, 4 }, 
                                                { 2, 3, 5 }, 
                                                { 2, 4, 5 }, 
                                                { 3, 4, 5 }};
    ASSERT_EQ(expected_result, combine(5, 3));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}