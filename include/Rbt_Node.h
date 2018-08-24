#include <string>

class Rbt_Node
{
	friend class Rbt;

public:
	
	Rbt_Node();

	Rbt_Node(int value, char color, Rbt_Node* up, Rbt_Node* left, Rbt_Node* right);

	Rbt_Node& operator=(Rbt_Node& rhs);

	std::string to_string();
	~Rbt_Node();

private:

	int value_;
	char color_;

	Rbt_Node* up_;
	Rbt_Node* left_;
	Rbt_Node* right_;
};
