#include"AVL.h"
int AVL::getbalace(node*&x)
{
	int rightheight = 0;
	int leftheight = 0;
	
		if (x->right == NULL)
		{
			rightheight = -1;
		}
		else
		{
			rightheight = x->right->height;
		}
		if (x->left == NULL)
		{
			leftheight = -1;
		}
		else
		{
			leftheight = x->left->height;
		}
		return rightheight - leftheight;
}
void AVL::setheight(node*&x)
{
	if (x == NULL)
	{
		return;
	}
	int leftheight = 0;
	int rightheight = 0;
		if (x->left == NULL)
		{
			leftheight = -1;
		}
		else
		{
			leftheight = x->left->height;
		}
		if (x->right == NULL)
		{
			rightheight = -1;
		}
		else
		{
			rightheight = x->right->height;
		}
		x->height = max(leftheight, rightheight) + 1;
}
void AVL::rotright(node*&x)
{
	//node*p = x;
	//node*c = x->left;
	//p->left = c->right;
	//x = x->left;
	//c->right = p;
	node* temp = x->left;
	x->left = temp->right;
	temp->right = x;
	x = temp;
	setheight(x->right);
	//if (x->left != NULL)
	//{
		//setheight(x->left);
	//}
	setheight(x);
}
void AVL::rotleft(node*&x)
{
	/*node* p = x;
	node*c = x->right;
	x->right = c->left;
	x = x->right;
	c->right = x;*/
	node* temp = x->right;
	x->right = temp->left;
	temp->left = x;
	x = temp;
	setheight(x->left);
	//if (x->right != NULL)
	//{
		//setheight(x->right);
	//}
	setheight(x);
}
NodeInterface* AVL::getRootNode() const
{
	return head;
}

void AVL::balance(node*&x)
{
	if (x != NULL)
	{
		setheight(x);
		if (getbalace(x) > 1)
		{
			if (getbalace(x->right) >= 0)//right right
			{
				rotleft(x);
			}
			else//right left
			{
				rotright(x->right);
				rotleft(x);
			}
		}
		else if (getbalace(x) < -1)
		{
			if (getbalace(x->left) <= 0)//left left
			{
				rotright(x);
			}
			else
			{
				rotleft(x->left);
				rotright(x);
			}
		}
	}

}
bool AVL::add1(int data, node*& x)
{	
	
	if (x == NULL)
	{
		x = new node;
		x->data = data;
		x->height = 0;
		returnvalue = true;
	}
	else if (x->getData()>data)
	{
		 add1(data, x->left);
		 balance(x);
		
	}
	else if (x->getData() < data)
	{
		 add1(data, x->right);
		 balance(x);
		  
	}
	else
	{	
		returnvalue = false;
	}
	return returnvalue;
}
bool AVL::add(int data)
{
	return add1(data, head);

}
bool AVL::remove123(int data, node*& x)
{
	
	if (x == NULL)
	{
		returnvalue = false;
	}
	else if (x->getData() < data)
	{
		remove123(data, x->right);
		balance(x);
	}
	else if (x->getData() > data)
	{
		remove123(data, x->left);
		balance(x);
	}
	else
	{
		node* old = x;
		if (x->left == NULL)
		{
			x = x->right;
		}
		else if (x->right == NULL)
		{
			x = x->left;
		}
		else
		{
			replacement(old, x->left);
		}
		delete old;
		old = NULL;
		returnvalue= true;
		balance(x);
	}
	return returnvalue;
}
bool AVL::remove(int data)
{
	return remove123(data, head);
}
void AVL::replacement(node*& old, node*& headroot)
{
	if (headroot->right != NULL)
	{
		replacement(old, headroot->right);
		balance(headroot);
	}
	else
	{
		old->data = headroot->data;
		old = headroot;
		headroot = headroot->left;
		balance(headroot);
	}
}
void AVL::clean(int data, node*& x)
{
	while (x != NULL)
	{
		remove123(x->getData(), x);
	}
}
void AVL::clear()
{
	if (head != NULL)
	{
		clean(head->getData(), head);
	}
}