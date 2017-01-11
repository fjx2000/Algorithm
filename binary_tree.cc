/************************************************************************************************************************************
This file demonstrate how to build binary tree with c++ code, it also provides 3 ways to traverse the tree.

************************************************************************************************************************************/

#include <iostream>
#include <memory>

using namespace std;
static uint16_t counter = 0;

template <typename T>
class BtNode
{
public:
  BtNode() : lChild(nullptr), rChild(nullptr) {};
  BtNode(T data)  : lChild(nullptr), rChild(nullptr)
  {
    this->data = data;
  };
  shared_ptr<BtNode> getLChild()
  {
    return this->lChild;
  };
  shared_ptr<BtNode> getRChild()
  {
    return this->rChild;
  };
  void setLChild(shared_ptr<BtNode> node)
  {
    this->lChild = node;
  };
  void setRChild(shared_ptr<BtNode> node)
  {
    this->rChild = node;
  };
  void setData(T data)
  {
    this->data = data;
  };
  T    getData()
  {
    return this->data;
  };

private:
  shared_ptr<BtNode> lChild;
  shared_ptr<BtNode> rChild;
  T data;
};

typedef shared_ptr<BtNode<int>> BtNodeIntSharedPtr;

class BiTree
{

public:
  typedef enum
  {
    PRE_ORDER = 1,
    POST_ORDER,
    INTE_ORDER
  } TraverseOrder;
  BiTree() : root(nullptr) {};
  shared_ptr<BtNode<int>> getRoot()
  {
    return this->root;
  };
  void createBiTree();
  void insertNode(shared_ptr<BtNode<int>> node, shared_ptr<BtNode<int>>& root);
  void traverseBiTree(shared_ptr<BtNode<int>> root, TraverseOrder order);
public:
  shared_ptr<BtNode<int>> root;
};

void BiTree::createBiTree()
{
  int data;
  cout<<"Input new tree node, with 0 to end the tree"<<endl;
  cin>>data;
  while(data) //end the tree
  {
    if(root == nullptr)
    {
      cout<<"Root is created"<<endl;
      root = make_shared<BtNode<int>>(data);
    }
    else
    {
      insertNode(make_shared<BtNode<int>>(data), root);
    }
    cin>>data;
  }

}

void BiTree::insertNode(shared_ptr<BtNode<int>> node, shared_ptr<BtNode<int>>& startPoint )
{
  if(node->getData() > startPoint->getData())  //insert to right child
  {
    shared_ptr<BtNode<int>> rChild = startPoint->getRChild();
    if(rChild.get() == nullptr) // insert node.  shared_ptr overloaded ==, without calling get() is same
    {
      startPoint->setRChild(node);
      return;
    }
    else   // continue trying
      insertNode(node, rChild);
  }
  else
  {
    shared_ptr<BtNode<int>> lChild = startPoint->getLChild();
    if(lChild == nullptr) // insert node
    {
      startPoint->setLChild(node);
      return;
    }
    else   // continue trying
      insertNode(node, lChild);
  }
}

void BiTree::traverseBiTree(shared_ptr<BtNode<int>> root, TraverseOrder order)
{
  if(root == nullptr)
  {
    return;
  }
  else
  {
    switch (order)
    {
    case PRE_ORDER:
      traverseBiTree(root->getLChild(), order);
      cout<<"PreOrder: node"<<counter++<<" is :"<<root->getData()<<endl;
      traverseBiTree(root->getRChild(), order);
      break;
    case POST_ORDER:
      traverseBiTree(root->getRChild(), order);
      cout<<"PostOrder: node"<<counter++<<" is :"<<root->getData()<<endl;
      traverseBiTree(root->getLChild(), order);
      break;
    case INTE_ORDER:
      cout<<"InteOrder: node"<<counter++<<" is :"<<root->getData()<<endl;
      traverseBiTree(root->getLChild(), order);
      traverseBiTree(root->getRChild(), order);
      break;
    default:
      cout<<"Unsupported order"<<endl;
    }
  }
}

int main()
{
  shared_ptr<BiTree> bt = make_shared<BiTree>();
  bt->createBiTree();
  cout<<"data in root is :"<<bt->getRoot()->getData()<<endl;
  counter = 0;
  bt->traverseBiTree(bt->getRoot(),  BiTree::PRE_ORDER);
  counter = 0;
  bt->traverseBiTree(bt->getRoot(),  BiTree::POST_ORDER);
  counter = 0;
  bt->traverseBiTree(bt->getRoot(),  BiTree::INTE_ORDER);
  return 0;
}


/**************************************************************************************************************************************
Tset Result:

esekilxxen2768: ~/test_c/algorithm  > g++ -std=c++0x binary_tree.cc
esekilxxen2768: ~/test_c/algorithm  > 
esekilxxen2768: ~/test_c/algorithm  > ./a.out
Input new tree node, with 0 to end the tree
12
Root is created
23
6
7
3
2
45
67
43
3
5
0
data in root is :12
PreOrder: node0 is :2
PreOrder: node1 is :3
PreOrder: node2 is :3
PreOrder: node3 is :5
PreOrder: node4 is :6
PreOrder: node5 is :7
PreOrder: node6 is :12
PreOrder: node7 is :23
PreOrder: node8 is :43
PreOrder: node9 is :45
PreOrder: node10 is :67
PostOrder: node0 is :67
PostOrder: node1 is :45
PostOrder: node2 is :43
PostOrder: node3 is :23
PostOrder: node4 is :12
PostOrder: node5 is :7
PostOrder: node6 is :6
PostOrder: node7 is :5
PostOrder: node8 is :3
PostOrder: node9 is :3
PostOrder: node10 is :2
InteOrder: node0 is :12
InteOrder: node1 is :6
InteOrder: node2 is :3
InteOrder: node3 is :2
InteOrder: node4 is :3
InteOrder: node5 is :5
InteOrder: node6 is :7
InteOrder: node7 is :23
InteOrder: node8 is :45
InteOrder: node9 is :43
InteOrder: node10 is :67

***************************************************************************************************************************************/
