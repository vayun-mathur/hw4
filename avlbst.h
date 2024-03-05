#ifndef AVLBST_H
#define AVLBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <map>
#include "bst.h"

struct KeyError
{
};

/**
 * A special kind of node for an AVL tree, which adds the balance as a data member, plus
 * other additional helper functions. You do NOT need to implement any functionality or
 * add additional data members or helper functions.
 */
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
    // Constructor/destructor.
    AVLNode(const Key &key, const Value &value, AVLNode<Key, Value> *parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    int8_t getBalance() const;
    void setBalance(int8_t balance);
    void updateBalance(int8_t diff);

    // Getters for parent, left, and right. These need to be redefined since they
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value> *getParent() const override;
    virtual AVLNode<Key, Value> *getLeft() const override;
    virtual AVLNode<Key, Value> *getRight() const override;

public:
    AVLNode<Key, Value>* rotateLeft();
    AVLNode<Key, Value>* rotateRight();

protected:
    int8_t balance_; // effectively a signed char
};

/*
  -------------------------------------------------
  Begin implementations for the AVLNode class.
  -------------------------------------------------
*/

/**
 * An explicit constructor to initialize the elements by calling the base class constructor
 */
template <class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key &key, const Value &value, AVLNode<Key, Value> *parent) : Node<Key, Value>(key, value, parent), balance_(0)
{
}

/**
 * A destructor which does nothing.
 */
template <class Key, class Value>
AVLNode<Key, Value>::~AVLNode()
{
}

/**
 * A getter for the balance of a AVLNode.
 */
template <class Key, class Value>
int8_t AVLNode<Key, Value>::getBalance() const
{
    return balance_;
}

/**
 * A setter for the balance of a AVLNode.
 */
template <class Key, class Value>
void AVLNode<Key, Value>::setBalance(int8_t balance)
{
    balance_ = balance;
}

/**
 * Adds diff to the balance of a AVLNode.
 */
template <class Key, class Value>
void AVLNode<Key, Value>::updateBalance(int8_t diff)
{
    balance_ += diff;
}

/**
 * An overridden function for getting the parent since a static_cast is necessary to make sure
 * that our node is a AVLNode.
 */
template <class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getParent() const
{
    return static_cast<AVLNode<Key, Value> *>(this->parent_);
}

/**
 * Overridden for the same reasons as above.
 */
template <class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getLeft() const
{
    return static_cast<AVLNode<Key, Value> *>(this->left_);
}

/**
 * Overridden for the same reasons as above.
 */
template <class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getRight() const
{
    return static_cast<AVLNode<Key, Value> *>(this->right_);
}

template <class Key, class Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::rotateLeft()
{
    AVLNode<Key, Value>* y = this->getRight();  
    if(y == NULL)
        return this;
    AVLNode<Key, Value>* T2 = y->getLeft();  
  
    // Perform rotation 
    y->setLeft(this);
    this->setParent(y);
    this->setRight(T2);
    if(T2 != NULL)
        T2->setParent(this);

    return y;
}

template <class Key, class Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::rotateRight()
{
    AVLNode<Key, Value>* x = this->getLeft();  
    if(x == NULL)
        return this;
    AVLNode<Key, Value>* T2 = x->getRight();  
  
    // Perform rotation
    x->setRight(this);
    this->setParent(x);
    this->setLeft(T2);
    if(T2 != NULL)
        T2->setParent(this);

    return x; 
}

template <class Key, class Value>
int height(AVLNode<Key, Value> *node)
{
    if (node == NULL)
        return 0;
    return 1 + std::max(height(node->getLeft()), height(node->getRight()));
}

/*
  -----------------------------------------------
  End implementations for the AVLNode class.
  -----------------------------------------------
*/

template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
    virtual void insert(const std::pair<const Key, Value> &new_item);
    virtual void remove(const Key &key);

protected:
    virtual void nodeSwap(AVLNode<Key, Value> *n1, AVLNode<Key, Value> *n2);

    // Add helper functions here
    static AVLNode<Key, Value> *insertHelper(AVLNode<Key, Value> *node, const std::pair<const Key, Value> &new_item);
    AVLNode<Key, Value> * removeHelper(AVLNode<Key, Value> *node, const Key &key);
    void rebalance(AVLNode<Key, Value> *n);
};

template <class Key, class Value>
AVLNode<Key, Value> *AVLTree<Key, Value>::insertHelper(AVLNode<Key, Value> *node, const std::pair<const Key, Value> &new_item)
{
    Key key = new_item.first;
    if (node == NULL)
    {
        return new AVLNode<Key, Value>(new_item.first, new_item.second, NULL);
    }

    if (key < node->getKey())
    {
        AVLNode<Key, Value> *left = insertHelper(node->getLeft(), new_item);
        node->setLeft(left);
        left->setParent(node);
    }
    else if (key > node->getKey())
    {
        AVLNode<Key, Value> *right = insertHelper(node->getRight(), new_item);
        node->setRight(right);
        right->setParent(node);
    }
    else
    {
        node->setValue(new_item.second);
        return node;
    }

    node->setBalance(height(node->getLeft()) - height(node->getRight()));

    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = node->getBalance();

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->getLeft()->getKey())
    {
        return node->rotateRight();
    }

    // Right Right Case
    if (balance < -1 && key > node->getRight()->getKey())
    {
        return node->rotateLeft();
    }
    // Left Right Case
    if (balance > 1 && key > node->getLeft()->getKey())
    {
        AVLNode<Key, Value>* new_left = node->getLeft()->rotateLeft();
        node->setLeft(new_left);
        new_left->setParent(node);
        return node->rotateRight();
    }

    // Right Left Case
    if (balance < -1 && key < node->getRight()->getKey())
    {
        AVLNode<Key, Value>* new_right = node->getRight()->rotateRight();
        node->setRight(new_right);
        new_right->setParent(node);
        return node->rotateLeft();
    }
    return node;
}

/*
 * Recall: If key is already in the tree, you should
 * overwrite the current value with the updated value.
 */
template <class Key, class Value>
void AVLTree<Key, Value>::insert(const std::pair<const Key, Value> &new_item)
{
    this->root_ = insertHelper(static_cast<AVLNode<Key, Value> *>(this->root_), new_item);
}

template<class Key, class Value>
AVLNode<Key, Value> *AVLTree<Key, Value>::removeHelper(AVLNode<Key, Value> *node, const Key &key)
{
    if (node == NULL) 
        return node; 
 
    if ( key < node->getKey() ) {
        AVLNode<Key, Value> *left = removeHelper(node->getLeft(), key);
        node->setLeft(left);
        if(left != NULL)
            left->setParent(node);
    }
 
    // If the key to be deleted is greater 
    // than the root's key, then it lies 
    // in right subtree 
    else if( key > node->getKey() ) {
        AVLNode<Key, Value> *right = removeHelper(node->getRight(), key);
        node->setRight(right);
        if(right != NULL)
            right->setParent(node);
    }
 
    // if key is same as root's key, then 
    // This is the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if( (node->getLeft() == NULL) ||
            (node->getRight() == NULL) ) 
        { 
            AVLNode<Key, Value> *temp = node->getLeft() ? 
                         node->getLeft() : 
                         node->getRight();
 
            // No child case 
            if (temp == NULL) 
            {
                node = NULL;
            } 
            else {
                if(node->getParent() != NULL)
                {
                    if(node->getParent()->getLeft() == node)
                        node->getParent()->setLeft(temp);
                    else
                        node->getParent()->setRight(temp);
                    temp->setParent(node->getParent());
                }
                node = temp;
            }
        } 
        else
        {
            AVLNode<Key, Value>* temp = static_cast<AVLNode<Key, Value>*>(this->predecessor(node));
            nodeSwap(node, temp);
            AVLNode<Key, Value> *left = removeHelper(temp->getLeft(), key);
            temp->setLeft(left);
            if(left != NULL)
                left->setParent(temp);
            
            node = temp;
        } 
    } 
 
    // If the tree had only one node
    // then return 
    if (node == NULL) 
        return node; 
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    node->setBalance(height(node->getLeft()) - height(node->getRight()));
 
    // STEP 3: GET THE BALANCE FACTOR OF 
    // THIS NODE (to check whether this 
    // node became unbalanced) 
    int balance = node->getBalance();
    // If this node becomes unbalanced, 
    // then there are 4 cases 
 
    // Left Left Case 
    if (balance > 1 && node->getLeft()->getBalance() >= 0) 
        return node->rotateRight(); 
 
    // Left Right Case 
    if (balance > 1 && node->getLeft()->getBalance() < 0) 
    { 
        AVLNode<Key, Value>* new_left = node->getLeft()->rotateLeft();
        node->setLeft(new_left);
        new_left->setParent(node);
        return node->rotateRight(); 
    } 
 
    // Right Right Case 
    if (balance < -1 && node->getRight()->getBalance() <= 0) 
        return node->rotateLeft();
 
    // Right Left Case 
    if (balance < -1 && node->getRight()->getBalance() > 0) 
    { 
        AVLNode<Key, Value>* new_right = node->getRight()->rotateRight();
        node->setRight(new_right);
        new_right->setParent(node);
        return node->rotateLeft(); 
    } 
 
    return node; 
}

template<class Key, class Value>
AVLNode<Key, Value>* print_balances_rec(AVLNode<Key, Value> *node, std::map<AVLNode<Key, Value>*, int> &hh)
{
    if(node == NULL)
        return NULL;
    if(node->getLeft() == NULL && node->getRight() == NULL) {
        hh[node] = 1;
        return node;
    }
    node->setLeft(print_balances_rec(node->getLeft(), hh));
    node->setRight(print_balances_rec(node->getRight(), hh));
    if(node->getLeft() != NULL)
        node->getLeft()->setParent(node);
    if(node->getRight() != NULL)
        node->getRight()->setParent(node);
    hh[node] = 1 + std::max(hh[node->getLeft()], hh[node->getRight()]);
    int balance = hh[node->getLeft()] - hh[node->getRight()];

    if (balance > 1 && node->getLeft()->getBalance() >= 0) 
        return node->rotateRight(); 
 
    // Left Right Case 
    if (balance > 1 && node->getLeft()->getBalance() < 0) 
    { 
        AVLNode<Key, Value>* new_left = node->getLeft()->rotateLeft();
        node->setLeft(new_left);
        new_left->setParent(node);
        return node->rotateRight(); 
    } 
 
    // Right Right Case 
    if (balance < -1 && node->getRight()->getBalance() <= 0) 
        return node->rotateLeft();
 
    // Right Left Case 
    if (balance < -1 && node->getRight()->getBalance() > 0) 
    { 
        AVLNode<Key, Value>* new_right = node->getRight()->rotateRight();
        node->setRight(new_right);
        new_right->setParent(node);
        return node->rotateLeft(); 
    } 
    return node;
}

template<class Key, class Value>
AVLNode<Key, Value> * print_balances(AVLNode<Key, Value> * node)
{
    std::map<AVLNode<Key, Value>*, int> hh;
    return print_balances_rec<Key, Value>(node, hh);
}

/*
 * Recall: The writeup specifies that if a node has 2 children you
 * should swap with the predecessor and then remove.
 */
template <class Key, class Value>
void AVLTree<Key, Value>::remove(const Key &key)
{
    this->root_ = removeHelper(static_cast<AVLNode<Key, Value> *>(this->root_), key);
    this->root_ = print_balances<Key, Value>(static_cast<AVLNode<Key, Value> *>(this->root_));
}

template <class Key, class Value>
void AVLTree<Key, Value>::nodeSwap(AVLNode<Key, Value> *n1, AVLNode<Key, Value> *n2)
{
    BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
    int8_t tempB = n1->getBalance();
    n1->setBalance(n2->getBalance());
    n2->setBalance(tempB);
}

#endif
