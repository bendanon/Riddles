#include <gtest/gtest.h>
 

int solution(){
    return 2;
}

TEST(TemplateSuite, TemplateTest) { 
    
    ASSERT_EQ(1, solution());
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}