#include<iostream>

using namespace std;

template <typename T>
class node
{
public:
	T data;
	char color;
	char dir;

	node* parent;
	node* left;
	node* right;
};

template <typename T>

class Binary_Tree
{
	node<T>* root;

public:
	Binary_Tree()
	{
		root = NULL;
		/*root->right = NULL;
		root->left = NULL;*/
	}

	node<T>* create_Node(T key)
	{
		node<T>* temp = new node<T>;

		temp->data = key;
		temp->color = 'r';

		temp->dir = NULL;
		temp->parent = NULL;
		temp->left = NULL;
		temp->right = NULL;

		return temp;
	}

	//void Check_for_Rotation(node<T>* &root)
	//{
	//	if (root->parent != NULL)
	//	{
	//		if (root->parent->parent != NULL)
	//		{
	//			if (root->parent->dir == 'R' && root->parent->left == NULL )
	//			{
	//				if (root->parent->parent->left == NULL)
	//				{
	//					node<T>* temp = root->parent;

	//				}
	//			}

	//			if (root->parent->dir == 'L')
	//			{

	//			}
	//		}
	//	}
	//}
	void Balance_Color(node<T>* &root, char dir)
	{

		if (root->parent->color == 'b')
			return;
	
		
		if (root->parent != NULL)
		{

		}
		if (root->parent != NULL && root->parent->dir == 'L')	//Coming on this IF means root->parent->color == red
		{
			if (root->parent->parent != NULL && root->parent->parent->right != NULL && root->parent->parent->right->color == 'b')
			{
				if (root->dir == 'L' && root->parent->right == NULL)
				{
					node<T>* temp = root->parent;
					temp->right = root->parent->parent;
					if (root->parent->parent->parent != NULL)
					{
						if (temp->right->dir == 'l')
						{
							root->parent->parent->parent->left = temp;
						}
						else
						{
							root->parent->parent->parent->right = temp;
						}

						temp->parent = temp->right->parent;
						temp->right->parent = temp;

						char coloring = temp->color;
						temp->color = temp->right->color;
						temp->right->color = coloring;

						if (temp->parent == NULL)
						{
							root = temp;
							root->color = 'b';
						}
		//				return;   //just to check temporary
					}
				}


				if (root->dir == 'R' && root->parent->left == NULL)
				{
					node<T>* temp = root->parent;
					temp->left = root->parent->parent;

					if (root->parent->parent->parent != NULL)
					{
						if (temp->left->dir == 'l')
						{
							root->parent->parent->parent->left = temp;
						}
						else
						{
							root->parent->parent->parent->right = temp;
						}

						temp->parent = temp->left->parent;
						temp->left->parent = temp;

						char coloring = temp->color;
						temp->color = temp->left->color;
						temp->left->color = coloring;

						if (temp->parent == NULL)
						{
							root = temp;
							root->color = 'b';
						}
				//		return;   //just to check temporary
					}
				}

			}




			if (root->parent->parent != NULL && root->parent->parent->right!=NULL && root->parent->parent->right->color == 'r')
			{
				if (root->parent->parent->parent != NULL)
					root->parent->parent->color = 'r';
				else
					root->parent->parent->color = 'b';

				root->parent->parent->right->color = 'b';
				root->parent->color = 'b';

				return;
			}
		}
		if (root->parent->dir == 'R')
		{
			if (root->parent->parent != NULL && root->parent->parent->left != NULL && root->parent->parent->left->color == 'b')
			{
				if (root->dir == 'R' && root->parent->left == NULL)
				{
					node<T>* temp = root->parent;
					temp->left = root->parent->parent;
					if (root->parent->parent->parent != NULL)
					{
						if (temp->left->dir == 'l')
						{
							root->parent->parent->parent->left = temp;
						}
						else
						{
							root->parent->parent->parent->right = temp;
						}

					}
					temp->parent = temp->left->parent;
					temp->left->parent = temp;

					char coloring = temp->color;
					temp->color = temp->left->color;
					temp->left->color = coloring;

					if (temp->parent == NULL)
					{
						root = temp;
						root->color = 'b';
					}

			//		return;   //just to check temporary
				}

				if (root->dir == 'L' && root->parent->right == NULL)
				{
					node<T>* temp = root->parent;
					temp->right = root->parent->parent;
					if (root->parent->parent->parent != NULL)
					{
						if (temp->right->dir == 'l')
						{
							root->parent->parent->parent->left = temp;
						}
						else
						{
							root->parent->parent->parent->right = temp;
						}
						temp->parent = temp->right->parent;
						temp->right->parent = temp;

						char coloring = temp->color;
						temp->color = temp->right->color;
						temp->right->color = coloring;

						if (temp->parent == NULL)
						{
							root = temp;
							root->color = 'b';
						}
					}
			//		return;   //just to check temporary
				}
			}
		}
	
			

		if (root->parent->parent != NULL &&root->parent->parent->left != NULL && root->parent->parent->left->color == 'r')
			{
				if (root->parent->parent->parent != NULL)
					root->parent->parent->color = 'r';

				root->parent->parent->left->color = 'b';
				root->parent->color = 'b';

				return;
			}
	
		root->color = 'b';	//when No IF Conditions Runs. Mea it is okay to turn this node black

		
	}
						
	void Insert_Val_rec(node<T>* &root, T key, node<T>* abba = NULL, char dir = NULL)
	{
		if (root != NULL)
		{
			if (key > root->data && root->right == NULL && root->left == NULL && root->parent == NULL)
			{
				node<T>* temp = create_Node(key);

				//temp->dir = dir;
				temp->left = root;
				root->parent = temp;
				root->dir = 'L';
				root->color = 'r';

				root = temp;
				root->color = 'b';

				return;
			}
		}
		if (root == NULL)
		{
			root = create_Node(key);
			root->parent = abba;
			root->dir = dir;
			if (root->parent == NULL)
			{
				root->color = 'b';
			}
			else
			{
				Balance_Color(root, dir);
			}

			return;
		}

		if (key <= root->data)
		{
			Insert_Val_rec(root->left, key,root,'L');
		}
		else
		{
			Insert_Val_rec(root->right, key,root,'R');
		}
	}

	void Insert_value(T key)
	{
		Insert_Val_rec(root, key);
	}

	void Print_Tree__pre_Ordser_rec(node<T>* root)
	{
		if (root == NULL)
			return;

		cout << root->data << " ";
		if (root->color == 'r')
			cout << "(Red)  \t";
		else
			cout << "(Black)\t";
		
		cout << "Parent : ";
		if (root->parent != NULL)
			cout << root->parent->data << " ";	//Checking for Parents
		else
			cout << "None";
		cout << "\tDirection : ";
		if (root->dir != NULL)
			cout << root->dir;	//Checking for Direction
		else
			cout << "None";
		cout << "\n";

		Print_Tree__pre_Ordser_rec(root->left);

		Print_Tree__pre_Ordser_rec(root->right);
	}


	void Print_Tree__in_Ordser_rec(node<T>* root)
	{
		if (root == NULL)
			return;

		Print_Tree__in_Ordser_rec(root->left);

		cout << root->data << " ";
		if (root->color == 'r')
			cout << "(Red)  \t";
		else
			cout << "(Black)\t";

		cout << "Parent : ";
		if (root->parent != NULL)
			cout << root->parent->data << " ";	//Checking for Parents
		else
			cout << "None";
		cout << "\tDirection : ";
		if (root->dir != NULL)
			cout << root->dir;	//Checking for Direction
		else
			cout << "None";
		cout << "\n";

		Print_Tree__in_Ordser_rec(root->right);
	}

	void Print_Tree__post_Ordser_rec(node<T>* root)
	{
		if (root == NULL)
			return;

		Print_Tree__post_Ordser_rec(root->left);

		Print_Tree__post_Ordser_rec(root->right);

		cout << root->data << " ";
		if (root->color == 'r')
			cout << "(Red)  \t";
		else
			cout << "(Black)\t";

		cout << "Parent : ";
		if (root->parent != NULL)
			cout << root->parent->data << " ";	//Checking for Parents
		else
			cout << "None";
		cout << "\tDirection : ";
		if (root->dir != NULL)
			cout << root->dir;	//Checking for Direction
		else
			cout << "None";
		cout << "\n";
	}


	void Print_Tree()
	{
		int choice;
		cout << "\nPrinting 1 : Pre-Order.";
		cout << "\nPrinting 2 : In-Order.";
		cout << "\nPrinting 3 : Post-Order.";

		cout << "\n\nPriniting : ";
		cin >> choice;
		cout << "\n\n";
		if (root == NULL)
		{
			cout << "\n\nEmpty Tree!";
			return;
		}
		switch (choice)
		{
		case 1:
			Print_Tree__pre_Ordser_rec(root);
			break;
		case 2:
			Print_Tree__in_Ordser_rec(root);
			break;
		case 3:
			Print_Tree__post_Ordser_rec(root);
			break;
		}
	}

	T get_max(node<T>* root)
	{

		if (root->left == NULL && root->right == NULL)
		{
			//	node<T>* temp = root;
			T val = root->data;
			delete root;
			root = NULL;

			//	delete temp;
			//	temp = NULL;
			return val;
		}
		else if (root->left != NULL && root->right == NULL)
		{
			T val = root->data;

			if (root->dir == 'L')
			{
				root->parent->left = root->left;
			}
			else if (root->dir == 'R')
			{
				root->parent->right = root->left;
			}
			if (root->left != NULL)
				root->left->parent = root->parent;

			delete root;
			root = NULL;

			return val;
		}
		else
		{
			return  get_max(root->right);
		}
	}

	int get_min(node<T>* &root)
	{
		if (root->left == NULL && root->right == NULL)
		{

			int val = root->data;
			delete root;
			root = NULL;

			//	delete temp;
			//	temp = NULL;
			return val;
		}
		else if (root->left == NULL)
		{
			return  get_min(root->right)
		}

		return  get_min(root->left)
	}

	void Do_Coloring(node<T>* &root,char color)		//color is color of deleted node
	{
		if (color == 'r')
		{
			if (root->left != NULL)
			{
				root->left->color = 'r';
				Do_Coloring(root->left, 'r');
			}
			if (root->right != NULL)
			{
				root->right->color = 'r';
				Do_Coloring(root->right, 'r');
			}
			if (root->left == NULL && root->right == NULL)
			{
				root->color = 'r';		//OR I can also say root->color = color;
				return;
			}
		}

		if (color == 'b')
		{
			if (root->left != NULL)
			{
				root->left->color = 'b';
				Do_Coloring(root->left, 'b');
			}
			if (root->right != NULL)
			{
				root->right->color = 'b';
				Do_Coloring(root->right, 'b');
			}
			if (root->left == NULL && root->right == NULL)
			{
				root->color = 'b';		//OR I can also say root->color = color;
				return;
			}
		}
	}

	void Delete_val_rec(node<T>* &root, T key, node<T>* abba = NULL)
	{
		if (root->left == NULL && root->right == NULL)
		{
			if (root->data == key)
			{
				//node<T>* temp = root;
				//delete temp;
				//temp = NULL;
				delete root;
				root = NULL;
				return;
			}
		}

		else if (root->left == NULL && root->right != NULL)
		{
			if (root->data == key)
			{
				node<T>* temp = root;
				root = root->right;
				
				root->parent = temp->parent;		//This for parent

				if (temp->color == 'r')				
				{
					Do_Coloring(root, 'r');
				}
				else if (temp->color == 'b')
				{
					Do_Coloring(root, 'b');
				}
				delete temp;
				temp = NULL;

				return;
			}

			Delete_val_rec(root->right, key);
		}

		else if (root->left != NULL && root->right == NULL)
		{
			if (root->data == key)
			{
				node<T>* temp = root;
				root = root->left;

				root->parent = temp->parent;		//This for parent

				if (temp->color == 'r')				//Coloring
				{
					Do_Coloring(root, 'r');
				}
				else if (temp->color == 'b')
				{
					Do_Coloring(root, 'b');
				}

				delete temp;
				temp = NULL;
				return;
			}
			Delete_val_rec(root->left, key);
		}

		else if (root->left != NULL && root->right != NULL)
		{
			if (root->data == key)
			{
				char coloring = root->color;
				root->data = get_max(root->left);

				if (coloring == 'r')				//Coloring
				{
					Do_Coloring(root, 'r');
				}
				else if (coloring == 'b')
				{
					Do_Coloring(root, 'b');
				}
			}
		}
		else
		{
			if (key < root->data)
			{
				Delete_val_rec(root->left, key);
			}
			else
			{
				Delete_val_rec(root->right, key);
			}
		}

	}

	void Delete_val(T key)
	{
		if (Search(key))
			Delete_val_rec(root, key);
		else
		{
			cout << "\n\nValue " << key << " is Not Found in the Tree!";
		}
	}

	bool Search_rec(node<T>* root, T key, bool &flag)
	{
		if (root == NULL)
			return 0;
		if (root->data == key)
			flag = 1;
		else if (root->data < key)
		{
			return Search_rec(root->left, key, flag);
		}
		else
		{
			return Search_rec(root->right, key, flag);
		}

		if (flag == 1)
			return 1;
		return 0;
	}

	bool Search(T key)
	{
		bool flag = 0;
		return Search_rec(root, key, flag);
	}
};


void menu()
{
	cout
		<< "Task No. 1 : Insert a Value."
		<< "\nTask No. 2 : Binary Search "
		<< "\nTask No. 3 : Delete Value "
		<< "\nTask No. 4 : Printing."


		<< "\n\nTask No.  : ";
}

void main()
{
	int choice, key;

	Binary_Tree<int> list;
	while (true)
	{
		menu();
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter Value you want to Insert : ";
			cin >> key;
			list.Insert_value(key);
			break;

		case 2:
			cout << "Enter Value which you want to Search : ";
			cin >> key;
			if (list.Search(key))
			{
				cout << "\nFound!";
			}
			else
			{
				cout << "\nNot Found!";
			}
			break;

		case 3:
			cout << "Enter Value you want to Delete : ";
			cin >> choice;
			list.Delete_val(choice);
			break;
		case 4:

			list.Print_Tree();
			break;
		}
		cout << "\n\n";
	}
}