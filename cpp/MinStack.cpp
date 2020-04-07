#include <gtest/gtest.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

class MinStack { 

public:
    MinStack() {
    }

    void push(int x) {
        s.push_back(x);
        if(s_min.empty()){
            s_min.push_back(x);
        } else {
            s_min.push_back(std::min(x, s_min.back()));
        }
    }

    void pop() {
        if(s.empty()){
            return;
        }
        s.pop_back();
        s_min.pop_back();
    }

    int top() {
        if(s.empty()){
            return -1;
        }
        return s.back();
    }

    int getMin() {
        if(s_min.empty()){
            return -1;
        }
        return s_min.back();
    }

private:
    std::vector<int> s;
    std::vector<int> s_min;   
};


TEST(MinStackSuite, StackBasicTests) { 
    std::vector<int> v = {-8, 4, 3, -10, 2, 1};
    std::priority_queue<int, std::vector<int>, std::greater<int> > q;
    MinStack s;

    s.pop(); // should be OK
    ASSERT_EQ(-1 , s.getMin());
    ASSERT_EQ(-1 , s.top());

    for(int i : v){
        s.push(i);
        ASSERT_EQ(s.top(), i);
        q.push(i);
        ASSERT_EQ(s.getMin(), q.top());
    }

    ASSERT_EQ(-10, s.getMin());
    s.pop();
    ASSERT_EQ(-10, s.getMin());
    s.pop();
    ASSERT_EQ(-10, s.getMin());
    s.pop();
    ASSERT_EQ(-8, s.getMin());
    s.pop();
    ASSERT_EQ(-8, s.getMin());
    s.pop();
    s.push(-9);
    ASSERT_EQ(-9, s.getMin());
    s.pop();
    ASSERT_EQ(-8, s.getMin());
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}