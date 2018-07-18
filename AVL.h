#pragma once
#include"AVLInterface.h"
#include"node.h"
#include<algorithm>
class AVL :public AVLInterface
{
public:
	AVL() {}
	~AVL() {
		//clear();
	}
	NodeInterface * getRootNode() const;
	int getbalace(node*&x);
	void rotright(node*&x);
	void rotleft(node*&x);
	bool add(int data);
	void setheight(node*&x);
	void balance(node*&x);
	bool add1(int data, node*&x);
	void replacement(node*&old, node*&x);
	bool remove123(int data, node*&x);
	bool remove(int data);
	void clear();
	void clean(int data, node*&x);
	node* head = NULL;
	bool returnvalue = true;
	int u = 0;
};

