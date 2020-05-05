#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array A, of N integers A.
Return the highest product possible by multiplying 3 numbers from the array.
NOTE: Solution will fit in a 32-bit signed integer.
*/

//O(n)
int solution(vector<int>& A){
    if(A.size() < 3){
        return 0;
    }
    if(A.size() == 3){
        return A[0] * A[1] * A[2];
    }

    int maxes[3];
    int mins[2];

    //The largest positive element
    auto max = max_element(begin(A), end(A)); 
    maxes[0] = *max; 
    A.erase(max);

    //Second largest
    max = max_element(begin(A), end(A)); 
    maxes[1] = *max; 
    A.erase(max);

    //Third largest
    max = max_element(begin(A), end(A)); 
    maxes[2] = *max; 
    A.erase(max);

    //This means originally A.size() was 4
    if(A.size() == 1){
        return std::max(maxes[0] * maxes[1] * maxes[2], /*The three largest*/ 
                        A.back() * maxes[2] * maxes[0]  /*two negatives and largest*/);
    }

    //Smallest (possibly negative)
    auto min = min_element(begin(A), end(A)); 
    mins[0] = *min; 
    A.erase(min);

    //Second smallest (possibly negative)
    min = min_element(begin(A), end(A)); 
    mins[1] = *min;
    A.erase(min);

    return std::max(maxes[0] * maxes[1] * maxes[2], /*the three largest*/
                    mins[0] * mins[1] * maxes[0]    /*two negatives and largest*/);
}


//O(nlogn)
int solution_2(vector<int>& A){
    sort(A.begin(), A.end());
    int n = A.size();
    int max3 = A[n-1]*A[n-2]*A[n-3];
    int min2max = A[n-1]*A[0]*A[1];
    return max(max3, min2max);
}

TEST(MajorityElementSuite, example) { 
    vector<int> A {1, 2, 3, 4};    
    ASSERT_EQ(24, solution(A));
    //ASSERT_EQ(24, solution_2(A));

}

TEST(MajorityElementSuite, basic) { 
    vector<int> A {1, 2, -3};    
    ASSERT_EQ(-6, solution(A));
    //ASSERT_EQ(-6, solution_2(A));
}

TEST(MajorityElementSuite, example_2) { 
    vector<int> A {0, -1, 3, 100, 70, 50};    
    ASSERT_EQ(350000, solution(A));
    //ASSERT_EQ(350000, solution_2(A));
}

TEST(MajorityElementSuite, trivial) { 
    vector<int> A {1};    
    ASSERT_EQ(0, solution(A));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}