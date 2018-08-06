
#include "Bst.h"
#include "Avl_Node.h"
#include "string"

class Avl :
	public Bst
{
	friend class Avl_Node;

public:
	Avl();

	Avl(Avl_Node& root);

	Avl(Avl& avl_tree);

	virtual ~Avl();

	std::string to_string() override;

	void insert(int value) override;

	bool popRoot() override;

	Avl_Node* get_root() const override { return root_; };
	
	/*----- Methods inherited (not overriden) from base class-------------

	 * void inorder(Bst_Node* node, std::string& output);

	 * void preorder(Bst_Node* node, std::string& output);

	 * void postorder(Bst_Node* node, std::string& output);

	 * bool load_from_file(const std::string& filepath);
	
	 * bool save_to_file(const std::string& filepath);
	
	-----------------------------------------------------*/

private:

	Avl_Node* root_;

};
