#include <gtest/gtest.h>
#include <vector>
#include <stack>
using namespace std; 
/*
Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of
the ith histogram’s bar. Width of each bar is 1.
Find the area of largest rectangle in the histogram.
*/

int solution(vector<int>& A){
    
    int max_rectangle = 0, i = 0;

    stack<int> s;

    auto expand_rect_from_stack = [&](int width) {

         int height = A[s.top()]; s.pop();
         int rectangle_area = 0;

         if(s.empty()){ 

             // s.top() was pushed when the stack was empty
             // hence height is a low point from the left or A[0]
             // So the rectangle goes all the way to A[0]
             rectangle_area = height * width;

         } else { 

             // bars between s.top() and height are larger or equal to height
             // This is promised by the stack insertion logic
             rectangle_area = height * (width - s.top() - 1);
         }

        //Try update max with the new area
        max_rectangle = std::max(max_rectangle, rectangle_area);
    };

    
    while(i < A.size()){

        // The stack top must always be the largest unconsidered rectangle height.
        // When we encounter a high point, we push it to the stack so we expand it later
        if(s.empty() || A[s.top()] <= A[i]){

            s.push(i++);
        
        } else { 

            // This means A[i] is a low point. When we encounter 
            // such we start expanding rectangles from the stack
            // Until A[i] is a high point (or the stack is empty)
            expand_rect_from_stack(i);
        }
    }

    //This means there are still rectangles not considered
    while(!s.empty()) { expand_rect_from_stack(i); }

    return max_rectangle;
}

TEST(HistogramSuite, Example) { 
    
    vector<int> A{ 2, 1, 5, 6, 2, 3 };
    ASSERT_EQ(10, solution(A));
}

TEST(HistogramSuite, Basic_two_histograms) { 

    vector<int> A{ 2, 1 };
    ASSERT_EQ(2, solution(A));
}

TEST(HistogramSuite, Basic_one_histogram_zero) { 

    vector<int> A{ 2, 0 };
    ASSERT_EQ(2, solution(A));
}

TEST(HistogramSuite, Basic_three_histograms) { 
    
    vector<int> A{ 1, 2, 1 };
    ASSERT_EQ(3, solution(A));
}

TEST(HistogramSuite, trivial_empty) { 
    
    vector<int> A{ };
    ASSERT_EQ(0, solution(A));
}

TEST(HistogramSuite, trivial_one) { 
    
    vector<int> A{ 1 };
    ASSERT_EQ(1, solution(A));
}

TEST(HistogramSuite, complex_height) { 
    
    vector<int> A{ 1, 1, 7, 1, 1, 1 };
    ASSERT_EQ(7, solution(A));
}

TEST(HistogramSuite, complex_width) { 
    
    vector<int> A{ 1, 1, 7, 1, 1, 1, 1, 1 };
    ASSERT_EQ(8, solution(A));
}

TEST(HistogramSuite, complex_hole) { 
    
    vector<int> A{ 2, 2, 0, 4, 3 };
    ASSERT_EQ(6, solution(A));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}