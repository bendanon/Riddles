#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Given a collection of numbers, return all possible permutations.
 * No two entries in the permutation sequence should be the same.
 * For the purpose of this problem, assume that all the numbers in the collection are unique.
*/

void _solution(vector<vector<int>>& ans, vector<int>& A, size_t start){

    if(start == A.size() - 1){
        ans.push_back(A);
        return;
    }

    for(int i = start; i < A.size(); ++i){
        swap(A[start], A[i]);
        _solution(ans, A, start + 1);
        swap(A[start], A[i]);
    }

}

vector<vector<int>> solution(vector<int>& A){
    vector<vector<int>> ans;
    _solution(ans, A, 0);
    return ans;
}

TEST(PermutationsSuite, Example) { 

    auto input = vector<int> { 1, 2, 3 };
    auto expected_output = vector<vector<int>> { { 1, 2, 3 }, 
                                                 { 1, 3, 2 },
                                                 { 2, 1, 3 },
                                                 { 2, 3, 1 },
                                                 { 3, 1, 2 }, 
                                                 { 3, 2, 1 }};
    auto output = solution(input);
    sort(begin(output), end(output));
    ASSERT_EQ(expected_output, output);
}

TEST(PermutationsSuite, Trivial_0) { 

    auto input = vector<int> { };
    auto expected_output = vector<vector<int>> { };
    ASSERT_EQ(expected_output, solution(input));
}

TEST(PermutationsSuite, Trivial_1) { 

    auto input = vector<int> { 1 };
    auto expected_output = vector<vector<int>> { { 1 } };
    ASSERT_EQ(expected_output, solution(input));
}

TEST(PermutationsSuite, Trivial_2) { 

    auto input = vector<int> { 1, 2 };
    auto expected_output = vector<vector<int>> { { 1, 2 }, 
                                                 { 2, 1 } };
    ASSERT_EQ(expected_output, solution(input));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}