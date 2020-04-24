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

    stack<int> larger_stack;

    auto try_update_max = [&](int bar_index) {

         int larger_prev_idx = larger_stack.top(); larger_stack.pop();
         int rectangle_area = 0;

         if(larger_stack.empty()){ 

             // This means no smaller elements before prev 
             //so the rectangle goes all the way from prev to start
             rectangle_area = A[larger_prev_idx] * bar_index;

         } else { 

             // We don't know how small are the elements before prev
             //so we cut the rectangle at index s.top(). If they are
             //as big as i, we will catch them in the next round
             rectangle_area = A[larger_prev_idx] * (bar_index - larger_stack.top() - 1);
         }

        //Try update max with the new area
        max_rectangle = std::max(max_rectangle, rectangle_area);
    };

    while(i < A.size()){

        if(larger_stack.empty() || A[larger_stack.top()] <= A[i]){

            larger_stack.push(i++);
        
        } else { // A[i] < A[larger_stack.top()]

            try_update_max(i);
        }
    }

    //This means there are still larger elements not considered
    while(!larger_stack.empty()) { try_update_max(i); }

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