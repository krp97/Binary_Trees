#include "Rbt_Node.h"
#include <string>

class Rbt
{
public:
	
	Rbt();
	Rbt(Rbt_Node* root);

	~Rbt();

	void preorder(Rbt_Node* node, std::string& output);

	void inorder(Rbt_Node* node, std::string& output);

	void postorder(Rbt_Node* node, std::string& output);

	void insert(int value);

private:

	Rbt_Node * root_;

	Rbt_Node * sentinel_;

	Rbt_Node* add_node(Rbt_Node* node, Rbt_Node* parent, const int value);

	Rbt_Node* balance(Rbt_Node* node);

	Rbt_Node* get_uncle(Rbt_Node* node);

	Rbt_Node* red_uncle_fix(Rbt_Node* node, Rbt_Node* uncle);

	Rbt_Node* black_uncle_fix(Rbt_Node* node, Rbt_Node* uncle);

	Rbt_Node* rot_right(Rbt_Node* node);

	Rbt_Node* rot_left(Rbt_Node* node);

	Rbt_Node* rot_right_left(Rbt_Node* node);

	Rbt_Node* rot_left_right(Rbt_Node* node);


};
