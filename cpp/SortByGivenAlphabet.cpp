#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <algorithm>

auto solution(std::vector<std::string>& words, std::string alphabet){

    std::sort(std::begin(words), std::end(words),
    [&alphabet] (const auto& a, const auto& b){

        std::size_t i = 0, min_len = std::min(a.size(), b.size());
        while(i <= min_len && (alphabet.find(a[i]) == alphabet.find(b[i]))) { ++i; } 
        return i == min_len || (alphabet.find(a[i]) < alphabet.find(b[i]));
    });

    return words;
}

TEST(SortByGivenAlphabetSuite, Basic) { 
    
    auto words = std::vector<std::string>{"aaa", "bbb", "ccc"};
    auto expected_result = std::vector<std::string>{"aaa", "bbb", "ccc"};
    ASSERT_EQ(expected_result, solution(words, "abc"));
}

TEST(SortByGivenAlphabetSuite, Reverse) { 
    
    auto words = std::vector<std::string>{"aaa", "bbb", "ccc"};
    auto expected_result = std::vector<std::string>{"ccc", "bbb", "aaa"};
    ASSERT_EQ(expected_result, solution(words, "cba"));
}

TEST(SortByGivenAlphabetSuite, Real) { 
    
    auto words = std::vector<std::string>{"aab", "aac", "aaa"};
    auto expected_result = std::vector<std::string>{"aac", "aab", "aaa"};
    ASSERT_EQ(expected_result, solution(words, "cba"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}