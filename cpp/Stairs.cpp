#include <gtest/gtest.h>

/*
You are climbing a stair case and it takes A steps to reach to the top.
Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?

The first and the only argument contains an integer A, the number of steps.
Return an integer, representing the number of ways to reach the top.

1 <= A <= 36
*/ 

int solution(int A){
    if(A <= 1){
        return 1;
    }

    int a = 1, b = 1, tmp;
    for(int i = 0; i < A; ++i){
        tmp = b;
        b += a;
        a = tmp;
    }

    return a;
}

TEST(StairsSuite, Example_1) { 
    ASSERT_EQ(2, solution(2));
}

TEST(StairsSuite, Example_2) { 
    ASSERT_EQ(3, solution(3));
}

TEST(StairsSuite, Trivial_1) { 
    ASSERT_EQ(1, solution(1));
}

TEST(StairsSuite, Complex_4) { 
    ASSERT_EQ(5, solution(4));
    //[1111],[22], [211], [112], [121]
}

TEST(StairsSuite, Complex_5) { 
    ASSERT_EQ(8, solution(5));
    //[11111],[221],[212],[122],[2111],[1112],[1211],[1121]
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}