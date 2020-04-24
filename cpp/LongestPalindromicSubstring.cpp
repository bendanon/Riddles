#include <gtest/gtest.h>
#include <algorithm>
#include <cctype>

 using namespace std;
/*
Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).
*/

size_t expand_pal(string::iterator& start, string::iterator& end, string& A){

    while(start != std::begin(A) && 
          end != std::end(A) && 
          *(start-1) == *(end+1)) { 
              --start; 
              ++end; 
          }
    return end - start;
}

string solution(string A){

    string::iterator ret_start = begin(A), ret_end = begin(A);

    for(auto center = std::begin(A); center != std::end(A); ++center){

        auto start = center;
        auto end = center;
        auto max_len = ret_end - ret_start;

        if(expand_pal(start, end, A) > max_len){
           ret_start = start;
           ret_end = end;
        }

        start = center;
        end = center + 1;
        
        if(*start == *end && expand_pal(start, end, A) > max_len){
           ret_start = start;
           ret_end = end;
        }
    }

    size_t start_index = ret_start - begin(A);
    size_t length = ret_end - ret_start + 1;

    return A.substr(start_index, length);
}

TEST(LengthOfLastWordSuite, Example) { 
    
    ASSERT_EQ(string{"aaabbaaa"}, solution("aaaabbaaa"));
}

TEST(LengthOfLastWordSuite, Basic) { 
    
    ASSERT_EQ(string{"ll"}, solution("Hello"));
}

TEST(LengthOfLastWordSuite, Trivial) { 
    
    ASSERT_EQ(string{""}, solution(""));
}

TEST(LengthOfLastWordSuite, pal_only_whitespace) { 
    
    ASSERT_EQ(string{"   "}, solution("   "));
}

TEST(LengthOfLastWordSuite, benign) { 
    
    ASSERT_EQ(string{"a"}, solution("abcdef"));
}

TEST(LengthOfLastWordSuite, pal_included_whitespace) { 
    
    ASSERT_EQ(string{"  a  "}, solution("  a  "));
}

TEST(LengthOfLastWordSuite, whole_is_pal) { 
    
    ASSERT_EQ(string{"123454321"}, solution("123454321"));
}

TEST(LengthOfLastWordSuite, complex) { 
    
    ASSERT_EQ(string{"1 123454321 1"}, solution("112211 123454321 123456789"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}