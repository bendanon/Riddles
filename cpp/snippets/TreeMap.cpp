#include <gtest/gtest.h>
#include <map> 

TEST(MapSuite, map) { 

    //m is a red-black tree. 
    //the keys are unique
    //we inserted two new elements in initialization
    std::map<int, std::string> m { {1, "one"}, {2, "two"}};

    //insert a new element, O(logN)
    m[3] = "three";
    m[4] = "four";
    m[5] = "five";

    //Remove a key, O(logN)
    m.erase(5);

    //Determine if the key exists, O(logN)
    ASSERT_TRUE(m.find(4) != std::end(m));

    //Retrieve the pair with key
    auto three = m[3];

    //Find min key, O(logN)
    ASSERT_EQ(1, std::begin(m)->first);

    //Find max key, O(logN) 
    ASSERT_EQ(4, std::rbegin(m)->first);

    //Iterate the keys in sorted order (inorder), O(N)
    for(auto& e : m){
        std::cout << e.second << "\n";        
    }

    //Find the closest key K > 3 O(logN)
    ASSERT_EQ(4, m.upper_bound(3)->first);

    //Find the closest key K <= 3, O(logN)
    ASSERT_EQ(3, m.lower_bound(3)->first);

    //Find the closest key K < 3
    ASSERT_EQ(2, (----m.upper_bound(3))->first);

    //Find the number of elements in the tree
    ASSERT_EQ(4, m.size());

}

TEST(MapSuite, multimap){

}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}