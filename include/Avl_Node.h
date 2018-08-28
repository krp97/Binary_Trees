#include <string>

class Avl_Node
{
	friend class Avl;
public:
	
	Avl_Node();

	Avl_Node(int value, int height, Avl_Node* up, Avl_Node* left, Avl_Node* right);

	Avl_Node& operator=(Avl_Node& rhs);

	std::string to_string();

	~Avl_Node();

private:

	int height_;	// Height of the subtree this node is a root of.
	int value_;
	
	Avl_Node* up_;
	Avl_Node* left_;
	Avl_Node* right_;
};
