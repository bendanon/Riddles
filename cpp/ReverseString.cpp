#include <gtest/gtest.h>
#include <algorithm>
#include <cctype>
using namespace std;

/*
Given a string A.

Return the string A after reversing the string word by word.

NOTE:

    A sequence of non-space characters constitutes a word.

    Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

    If there are multiple spaces between words, reduce them to a single space in the reversed string.

*/

string solution(string A){

    string ret;

    //reverse the entire input
    reverse(begin(A), end(A));

    vector<string> tokens;
    stringstream stream(A);
    string token;

    //Tokenize the string according to spaces
    while(stream >> token){ tokens.push_back(token); }

    //Append all the tokens to a space seperated string,
    //reversing them back into original order
    for(auto t : tokens){ 
        reverse(begin(t), end(t));
        ret += t + " ";
    }

    //Remove the last space
    if(ret.size() > 0){ ret.erase(--end(ret)); }

    return ret;
}

TEST(LengthOfLastWordSuite, Example) { 
    
    ASSERT_EQ(string{"World Hello"}, solution("Hello World"));
}

TEST(LengthOfLastWordSuite, Basic) { 

    ASSERT_EQ(string{"Hello"}, solution("Hello"));
}

TEST(LengthOfLastWordSuite, Trivial) { 
    
    ASSERT_EQ(string{""}, solution(""));
}

TEST(LengthOfLastWordSuite, Trivial_white) { 
    
    ASSERT_EQ(string{""}, solution("     "));
}

TEST(LengthOfLastWordSuite, middle_white) { 
    
    ASSERT_EQ(string{"b a"}, solution("a  b"));
}

TEST(LengthOfLastWordSuite, complex_whitespace) { 
    
    ASSERT_EQ(string{"c b a"}, solution("a    b   c "));
}

TEST(LengthOfLastWordSuite, complex) { 
    
    ASSERT_EQ(string{"h abc a"}, solution(" a abc   h "));
}

TEST(LengthOfLastWordSuite, trailing_whitespace) { 
    
    ASSERT_EQ(string{"abc a"}, solution("a abc   "));
}

TEST(LengthOfLastWordSuite, alpha_only) { 
    
    ASSERT_EQ(string{"ab%%% 123 abcd a"}, solution("a abcd 123 ab%%%"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}