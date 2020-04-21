#include <gtest/gtest.h>
#include <algorithm>
#include <cctype>

 using namespace std;
/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.
If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.
Please make sure you try to solve this problem without using library functions. 
Make sure you only traverse the string once.
*/

int solution(const string A){

    auto alpha = [](const char c){
        return (bool)std::isalpha(c);
    };

    auto it = std::find_if(rbegin(A), rend(A), alpha);

    if(it == rend(A)){
        return 0;
    }
    
    auto it2 = std::find_if_not(it, rend(A), alpha);

    return std::distance(it, it2);
}

TEST(LengthOfLastWordSuite, Example) { 
    
    ASSERT_EQ(5, solution("Hello World"));
}

TEST(LengthOfLastWordSuite, Basic) { 
    
    ASSERT_EQ(5, solution("Hello"));
}

TEST(LengthOfLastWordSuite, Trivial) { 
    
    ASSERT_EQ(0, solution(""));
}

TEST(LengthOfLastWordSuite, Trivial_white) { 
    
    ASSERT_EQ(0, solution("     "));
}

TEST(LengthOfLastWordSuite, complex) { 
    
    ASSERT_EQ(1, solution("a abc h"));
}

TEST(LengthOfLastWordSuite, trailing_whitespace) { 
    
    ASSERT_EQ(3, solution("a abc   "));
}

TEST(LengthOfLastWordSuite, alpha_only) { 
    
    ASSERT_EQ(2, solution("a abcd 123 ab%%%\n"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}