#include"node.h"
#include<algorithm>
int node::getData() const
{
	return data;
}
NodeInterface* node::getLeftChild() const
{
	return left;
}
NodeInterface* node::getRightChild() const
{
	return right;
}
int node::getHeight()
{
	return height;
}