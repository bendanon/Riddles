#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
 * Given an array A of integers and another non negative integer k, 
 * find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
 * Return 0 / 1 for this problem.
 * */ 

int solution(const vector<int> &A, int B){

    if(A.size() <= 1){
        return 0;
    }
    
    unordered_map<int, int> map { };
    
    int i = 0;
    std::for_each(std::begin(A), std::end(A),
    [&map, &i](int num) { 
        map[num] = i;
        ++i;
    });

    i = 0;
    return std::any_of(std::begin(A), std::end(A), 
    [&map, B, &i](int num) {
        auto a = map.find(num + B);
        auto b = map.find(num - B);
        if((a != end(map)) && (a->second != i)) { return true; }
        if((b != end(map)) && (b->second != i)) { return true; }
        ++i;
        return false;
    }) ? 1 : 0;
}

TEST(Hashing_diffkII, Example) { 

    auto input = vector<int> { 1, 2, 3 };
    auto k = 2;
    ASSERT_EQ(1, solution(input, k));
}

TEST(Hashing_diffkII, False) { 

    auto input = vector<int> { 1, 2, 3, 3, 5, 4 };
    auto k = 5;
    ASSERT_EQ(0, solution(input, k));
}

TEST(Hashing_diffkII, Zero) { 

    auto input = vector<int> { 1, 2, 3 };
    auto k = 0;
    ASSERT_EQ(0, solution(input, k));

    input.push_back(3);
    ASSERT_EQ(1, solution(input, k));

    input = vector<int> { 1, 3, 0 };
    ASSERT_EQ(1, solution(input, 1));
    ASSERT_EQ(1, solution(input, 3));
}

TEST(Hashing_diffkII, Trivial) { 

    auto input = vector<int> { 1 };
    auto k = 0;
    ASSERT_EQ(0, solution(input, k));
    input.pop_back();
    ASSERT_EQ(0, solution(input, k));
}

TEST(Hashing_diffkII, Negative) { 

    auto input = vector<int> { 1, -2, 3, -3, 5, 4 };
    auto k = 5;
    ASSERT_EQ(1, solution(input, 3)); //1 - (-2)
    ASSERT_EQ(1, solution(input, 4)); //1 - (-3)
    ASSERT_EQ(1, solution(input, 8)); //5 -(-3)
    ASSERT_EQ(1, solution(input, 1)); //-2 -(-3)
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}