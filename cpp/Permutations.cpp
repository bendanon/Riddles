#include <gtest/gtest.h>
#include <vector>
using namespace std;

/**
 * Given a collection of numbers, return all possible permutations.
 * No two entries in the permutation sequence should be the same.
 * For the purpose of this problem, assume that all the numbers in the collection are unique.
*/

vector<vector<int>> _solution(vector<vector<int>>& ans, vector<int>& A, int perm_size){

    //sol(A + {x}) = insert x in every position of sol(A)
    if(perm_size <= 1){
        ans = { A };
        return { };
    }
    
    if(A.size() == 1){
        return { { A.back() } };
    }

    int first = A.back();
    A.pop_back();
    auto t = _solution(ans, A, perm_size);
    vector<vector<int>> t2;
    for(auto v : t){
        for(auto it = std::begin(v); it != std::end(v); ++it){
            vector<int> toans = vector<int>(std::begin(v), it);
            toans.push_back(first);
            toans.insert(std::end(toans), it, std::end(v));
            if(toans.size() == perm_size){
                ans.push_back(toans);
            } else{
                t2.push_back(toans);
            }
        }
        v.push_back(first);
        if(v.size() == perm_size){
            ans.push_back(v);
        }else{
            t2.push_back(v);
        }
    }

    return t2;
}

vector<vector<int>> solution(vector<int>& A){
    vector<vector<int>> ans;
    _solution(ans, A, A.size());
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
    ASSERT_EQ(expected_output, solution(input));
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