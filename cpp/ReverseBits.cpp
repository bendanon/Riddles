#include <gtest/gtest.h>
 
/*
* Reverse the bits of an 32 bit unsigned integer A.
*/

unsigned int solution(unsigned int A){
    unsigned int out = 0;
    for(int i = 0; i < sizeof(A)*8; ++i){
        unsigned int bit = A & (1 << i);
        if(bit != 0){
            out |= (1 << (sizeof(A)*8-1 - i));
        }
    }
    return out;
}

TEST(ReverseBitsSuite, Exmaple) { 

    ASSERT_EQ(3221225472, solution(3));
}

TEST(ReverseBitsSuite, Trivial) { 
    
    ASSERT_EQ(0, solution(0));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}