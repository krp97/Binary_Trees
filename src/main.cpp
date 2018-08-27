#include <iostream>

#include "../include/Rbt.h"
#include "../include/Bst.h"
#include "../include/Avl.h"
#include <time.h>


void draw(std::string preorder, std::string inorder, std::string postorder, std::string title);

int main()
{

    Avl test_avl = Avl();
    Bst test_bst = Bst();

    srand(time(NULL));
    std::cout << "Input keys: \n";
    int number;

    for(int i = 0; i < 11; ++i)   
    {
        number = rand() % 20 + 1;
        test_bst.insert(number);
        test_avl.insert(number);
        std::cout << number << " ";
    } 

    std::cout << "\n\n";
    draw(test_bst.preorder(), test_bst.inorder(), test_bst.postorder(), " Example BST: ");
    
    std::cout << "\n\n";
    std::cout << "Notation:\n";
    std::cout << "key : height\n\n";

    draw(test_avl.preorder(), test_avl.inorder(), test_avl.postorder(), "Example AVL: ");

    getchar();
}

void draw(std::string preorder, std::string inorder, std::string postorder, std::string title)
{
    int data_length = preorder.length();
    int line_chars = 4; // 2x space and 2x "|"
    int line_length = data_length + line_chars;

    std::cout << std::string((line_length - title.length())/2, '-');
    std::cout << title;
    std::cout << std::string((line_length - title.length())/2, '-');
    std::cout << std::endl;
    std::cout << "| Preorder:" << std::string(data_length - 10, ' ') << "  |\n";
    std::cout << "| " << preorder << " |\n";
    std::cout << "| Inorder:" << std::string(data_length - 9, ' ') << "  |\n";
    std::cout << "| " << inorder << " |\n";
    std::cout << "| Postorder:" << std::string(data_length - 11, ' ') << "  |\n";
    std::cout << "| " << postorder << " |\n";
    std::cout << std::string(line_length, '-') << std::endl;
}