#pragma once
#include"NodeInterface.h"
#include<iostream>
class node :public NodeInterface
{
	friend class AVL;
	node()
	{
		left = NULL;
		right = NULL;
		data = 0;
		height = 0;
	}
	~node() {}
	int getData() const;
	NodeInterface * getLeftChild() const;
	NodeInterface * getRightChild() const;
	int getHeight();
protected:
	node* left;
	node* right;
	int height;
	int data;
};