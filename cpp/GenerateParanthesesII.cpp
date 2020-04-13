#include <gtest/gtest.h>
#include <vector>
using namespace std;
/**
 * Given n pairs of parentheses, write a function to generate all 
 * combinations of well-formed parentheses of length 2*n.
 * Make sure the returned list of strings are sorted.
 **/ 

void _solution(vector<string>& ans, string current, int open, int close, int n)
{
    if((open == close) && (open == n)){
        ans.push_back(current);
        return;
    }

    if(close > open){
        return;
    }

    if(open < n){
        current.push_back('(');
        _solution(ans, current, open + 1, close, n);
        current.pop_back();
    }

    if(close < n){
        current.push_back(')');
        _solution(ans, current, open, close + 1, n);
        current.pop_back();
    }
}

vector<string> solution(int A){
    vector<string> ans;
    _solution(ans, string{}, 0, 0, A);
    return ans;
}

TEST(GenerateParenthesesIISuite, Example) { 
    
    auto expected_result = vector<string> { {"((()))"},
                                            {"(()())"},
                                            {"(())()"},
                                            {"()(())"},
                                            {"()()()"}};    
    ASSERT_EQ(expected_result, solution(3));
}
TEST(GenerateParenthesesIISuite, Trivial_2) { 

    auto expected_result = vector<string> {{"(())"},
                                           {"()()"}};
    ASSERT_EQ(expected_result, solution(2));
}
TEST(GenerateParenthesesIISuite, Trivial_1) { 

    auto expected_result = vector<string> { {"()"} };
    ASSERT_EQ(expected_result, solution(1));
}

TEST(GenerateParenthesesIISuite, Complex) {
    auto expected_result = vector<string> { "(((())))", 
                                            "((()()))", 
                                            "((())())",
                                            "((()))()", 
                                            "(()(()))", 
                                            "(()()())", 
                                            "(()())()", 
                                            "(())(())", 
                                            "(())()()",  
                                            "()((()))",
                                            "()(()())", 
                                            "()(())()", 
                                            "()()(())", 
                                            "()()()()"};
    ASSERT_EQ(expected_result, solution(4));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}