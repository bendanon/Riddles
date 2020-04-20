#include <gtest/gtest.h>
#include <limits>
#include <cmath>
 
/*
*Implement atoi to convert a string to an integer.

    Questions:

    Q1. Does string contain whitespace characters before the number?
    A. Yes

    Q2. Can the string have garbage characters after the number?
    A. Yes. Ignore it.

    Q3. If no numeric character is found before encountering garbage characters, what should I do?
    A. Return 0.

    Q4. What if the integer overflows?
    A. Return INT_MAX if the number is positive, INT_MIN otherwise. 
*/

int solution(const std::string A){

    //Make sure it starts either with whitespace, number or sign
    if(A.find_first_of("+-   0123456789") != 0){
        return 0;
    }

    //find the beginning of the number
    std::size_t num_start = A.find_first_of("+-0123456789");
    if(num_start == std::string::npos){
        return 0;
    }

    //Remove the '-' sign if its there
    int negative = false;
    if(A[num_start] == '-'){
        negative = true;
        num_start++;
    } else if(A[num_start] == '+'){
        num_start++;
    }

    //Find the end of the number, get rid of garbage in the end    
    std::size_t num_end = A.find_first_not_of("0123456789", num_start);
    num_end = (num_end == std::string::npos) ? A.size() - 1 : num_end - 1;

    std::string maxint_str = std::to_string(std::numeric_limits<int>::max());

    int num_len = num_end - num_start + 1;

    //Find overflows
    if(num_len > maxint_str.size() || 
      (num_len == maxint_str.size() && A.compare(num_start, num_len, maxint_str) >= 0)){
        return negative ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
    }

    int ret = 0;
    int radix = num_len - 1;
    for(int i = num_start; i <= num_end; ++i){
        
        int digit = (int)(A[i] - 48);
        ret += digit * (std::pow(10, radix));
        --radix;
    }

    return negative ? -ret : ret;
}

TEST(AtoiSuite, Example) { 
    
    ASSERT_EQ(9, solution("9 2704"));
}

TEST(AtoiSuite, NegativeBasic) { 
    
    ASSERT_EQ(-2704, solution("-2704"));
}

TEST(AtoiSuite, PositiveWithSign) { 
    
    ASSERT_EQ(2704, solution("+2704"));
}

TEST(AtoiSuite, NearOverflowNegative) { 
    
    ASSERT_EQ(std::numeric_limits<int>::min(), solution(std::to_string(std::numeric_limits<int>::min())));
}

TEST(AtoiSuite, OverflowPositive) { 
    
    ASSERT_EQ(std::numeric_limits<int>::max(), solution("2147483648"));
}

TEST(AtoiSuite, OverflowNegative) { 
    
    ASSERT_EQ(std::numeric_limits<int>::min(), solution("-2147483649"));
}

TEST(AtoiSuite, NearOverflowPositive) { 
    
    ASSERT_EQ(std::numeric_limits<int>::max(), solution(std::to_string(std::numeric_limits<int>::max())));
}

TEST(AtoiSuite, Trivial) { 
    
    ASSERT_EQ(0, solution(""));
}

TEST(AtoiSuite, GarbageBefore) { 
    
    ASSERT_EQ(0, solution("&19"));
}

TEST(AtoiSuite, GarbageAfter) { 
    
    ASSERT_EQ(34, solution("34*^ "));
}

TEST(AtoiSuite, WhitespacePrefix) { 
    
    ASSERT_EQ(19, solution("   19"));
}

TEST(AtoiSuite, Complex){
    ASSERT_EQ(-88297, solution("-88297 248252140B12 37239U4622733246I218 9 1303 44 A83793H3G2 1674443R591 4368 7 97"));
}

TEST(AtoiSuite, Complex_2){
    ASSERT_EQ(std::numeric_limits<int>::min(), solution("-15620769845D3431 491E4 8X644 465 P18078"));
}

TEST(AtoiSuite, Complex_3){
    ASSERT_EQ(0, solution("0 14119 16368 66S5265 5109 2 5K 53 3G 39654000"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}