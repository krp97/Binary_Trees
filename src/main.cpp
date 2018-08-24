#include "../include/Rbt.h"
#include <iostream>

int main()
{
    Rbt test_rbt = Rbt();

    test_rbt.insert(10);
    test_rbt.insert(8);
    test_rbt.insert(7);
    test_rbt.insert(3);
    //test_rbt.insert(15);

    std::cout << std::endl << test_rbt.preorder() << std::endl;
    getchar();
    return 0;
}