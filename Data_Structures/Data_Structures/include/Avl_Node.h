
#include "Bst_Node.h"
class Avl_Node
{
	friend class Avl;
public:
	
	Avl_Node();

	Avl_Node(int value, int bal_factor, Avl_Node* up, Avl_Node* left, Avl_Node* right);

	void operator=(Avl_Node& rhs);

	std::string to_string();

	~Avl_Node();

private:

	int bal_factor_;
	int value_;
	Avl_Node* up_;
	Avl_Node* left_;
	Avl_Node* right_;
};