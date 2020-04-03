#include <gtest/gtest.h>
 
int to_test(){
    return 1;
}

TEST(TemplateSuite, TemplateTest) { 
    ASSERT_EQ(1, to_test());
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}