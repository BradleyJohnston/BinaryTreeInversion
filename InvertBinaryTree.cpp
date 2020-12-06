#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node() { data = 0; left = NULL; right = NULL; }
	Node(int data) { this->data = data; left = NULL; right = NULL; }

	~Node() 
	{ 
		if (this->left)
			delete left;
		if (this->right)
			delete right;

		delete this;
	}
};

void insert(int data, Node* node);
void displayTree(Node* root);
void invertTree(Node* node);

int main()
{
	
	/*
	1\
	  2
	3/ \
		\
		 5
		/
	6\ /
	  7
	8/
	*/

	// Create the tree
	Node* root = NULL;

  int input;

  do
  {
    cout << "Enter a positive int: ";
    cin >> input;
    if (input > 0)
    {
      if (root == NULL)
      {
        root = new Node(input);
      }
      else
      {
        insert(input, root);
      }
    }
  }
  while(input > 0);

	// Display the start
	cout << "Starting tree" << endl;
	displayTree(root);
	cout << endl;
	cout << endl;

	// Invert
	invertTree(root);
	
	// Display the inverted tree
	cout << "Inverted tree" << endl;
	displayTree(root);
	cout << endl;
}


/*
This is a function to sorted insert a value to a tree
LRV where v is insert
*/
void insert(int data, Node* node)
{
  if (data < node->data)
  {
    if (node->left)
    {
      insert(data, node->left);
      return;
    }
    else
    {
      node->left = new Node(data);
      return;
    }
  }
  else
  {
    if (node->right)
    {
      insert(data, node->right);
      return;
    }
    else
    {
      node->right = new Node(data);
      return;
    }
  }
}

/*
This is a recursive function to show the data of each
node in a tree in a single line
LVR
where Visit is display
*/
void displayTree(Node* root)
{
	if (root == NULL)
		return;

	displayTree(root->left);
	cout << root->data << " ";
	displayTree(root->right);
}


/*
This is a recursive function to traverse a tree
LRV where Visit swaps the left and right children.
*/
void invertTree(Node* node)
{
	// Return on leaf nodes
	if (node == NULL)
	{
		return;
	}

	invertTree(node->left);
	invertTree(node->right);

	Node* temp;
	temp = node->left;
	node->left = node->right;
	node->right = temp;
}