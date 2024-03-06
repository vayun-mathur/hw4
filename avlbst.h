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
    AVLNode(const Key &key, const Value &value, AVLNode<Key, Value> *parent);
    virtual ~AVLNode();
    int8_t getBalance() const;
    void setBalance(int8_t balance);
    void updateBalance(int8_t diff);
    virtual AVLNode<Key, Value> *getParent() const override;
    virtual AVLNode<Key, Value> *getLeft() const override;
    virtual AVLNode<Key, Value> *getRight() const override;

public:
    int height;

protected:
    int8_t balance_;
};
template <typename Key, typename Value>
void Updateheight(AVLNode<Key, Value> *root);
template <typename Key, typename Value>
AVLNode<Key, Value> *LLR(AVLNode<Key, Value> *root);
template <typename Key, typename Value>
AVLNode<Key, Value> *RRR(AVLNode<Key, Value> *root);
template <typename Key, typename Value>
AVLNode<Key, Value> *LRR(AVLNode<Key, Value> *root);
template <typename Key, typename Value>
AVLNode<Key, Value> *RLR(AVLNode<Key, Value> *root);
template <typename Key, typename Value>
AVLNode<Key, Value> *Balance(AVLNode<Key, Value> *root);
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
};
template <class Key, class Value>
void Updateheight(
    AVLNode<Key, Value> *root)
{
    if (root != NULL)
    {
        int val = 1;
        if (root->getLeft() != NULL)
            val = root->getLeft()->height + 1;
        if (root->getRight() != NULL)
            val = std::max(
                val, root->getRight()->height + 1);
        root->height = val;
    }
}
template <class Key, class Value>
AVLNode<Key, Value> *LLR(
    AVLNode<Key, Value> *root)
{
    AVLNode<Key, Value> *tmpnode = root->getLeft();
    root->setLeft(tmpnode->getRight());
    if (tmpnode->getRight() != NULL)
        tmpnode->getRight()->setParent(root);
    tmpnode->setRight(root);
    tmpnode->setParent(root->getParent());
    root->setParent(tmpnode);
    if (tmpnode->getParent() != NULL && root->getKey() < tmpnode->getParent()->getKey())
    {
        tmpnode->getParent()->setLeft(tmpnode);
    }
    else
    {
        if (tmpnode->getParent() != NULL)
            tmpnode->getParent()->setRight(tmpnode);
    }
    root = tmpnode;
    Updateheight(root->getLeft());
    Updateheight(root->getRight());
    Updateheight(root);
    Updateheight(root->getParent());
    return root;
}
template <class Key, class Value>
AVLNode<Key, Value> *RRR(
    AVLNode<Key, Value> *root)
{
    AVLNode<Key, Value> *tmpnode = root->getRight();
    root->setRight(tmpnode->getLeft());
    if (tmpnode->getLeft() != NULL)
        tmpnode->getLeft()->setParent(root);
    tmpnode->setLeft(root);
    tmpnode->setParent(root->getParent());
    root->setParent(tmpnode);
    if (tmpnode->getParent() != NULL && root->getKey() < tmpnode->getParent()->getKey())
    {
        tmpnode->getParent()->setLeft(tmpnode);
    }
    else
    {
        if (tmpnode->getParent() != NULL)
            tmpnode->getParent()->setRight(tmpnode);
    }
    root = tmpnode;
    Updateheight(root->getLeft());
    Updateheight(root->getRight());
    Updateheight(root);
    Updateheight(root->getParent());
    return root;
}
template <class Key, class Value>
AVLNode<Key, Value> *LRR(
    AVLNode<Key, Value> *root)
{
    root->setLeft(RRR(root->getLeft()));
    return LLR(root);
}
template <class Key, class Value>
AVLNode<Key, Value> *RLR(
    AVLNode<Key, Value> *root)
{
    root->setRight(LLR(root->getRight()));
    return RRR(root);
}
template <class Key, class Value>
AVLNode<Key, Value> *Balance(
    AVLNode<Key, Value> *root)
{
    int firstheight = 0;
    int secondheight = 0;
    if (root->getLeft() != NULL)
        firstheight = root->getLeft()->height;
    if (root->getRight() != NULL)
        secondheight = root->getRight()->height;
    if (abs(firstheight - secondheight) == 2)
    {
        if (firstheight < secondheight)
        {

            int rightheight1 = 0;
            int rightheight2 = 0;
            if (root->getRight()->getRight() != NULL)
                rightheight2 = root->getRight()->getRight()->height;
            if (root->getRight()->getLeft() != NULL)
                rightheight1 = root->getRight()->getLeft()->height;
            if (rightheight1 > rightheight2)
            {

                root = RLR(root);
            }
            else
            {

                root = RRR(root);
            }
        }
        else
        {

            int leftheight1 = 0;
            int leftheight2 = 0;
            if (root->getLeft()->getRight() != NULL)
                leftheight2 = root->getLeft()->getRight()->height;
            if (root->getLeft()->getLeft() != NULL)
                leftheight1 = root->getLeft()->getLeft()->height;
            if (leftheight1 > leftheight2)
            {

                root = LLR(root);
            }
            else
            {

                root = LRR(root);
            }
        }
    }
    return root;
}
template <class Key, class Value>
AVLNode<Key, Value> *Insert(AVLNode<Key, Value> *root, AVLNode<Key, Value> *parent, const std::pair<const Key, Value> &new_item)
{
    Key key = new_item.first;
    if (root == NULL)
    {

        root = new AVLNode<Key, Value>(new_item.first, new_item.second, parent);
        root->height = 1;
    }
    else if (root->getKey() > key)
    {

        root->setLeft(Insert(root->getLeft(),
                             root, new_item));

        int firstheight = 0;
        int secondheight = 0;
        if (root->getLeft() != NULL)
            firstheight = root->getLeft()->height;
        if (root->getRight() != NULL)
            secondheight = root->getRight()->height;

        if (abs(firstheight - secondheight) == 2)
        {
            if (root->getLeft() != NULL && key < root->getLeft()->getKey())
            {

                root = LLR(root);
            }
            else
            {

                root = LRR(root);
            }
        }
    }
    else if (root->getKey() < key)
    {

        root->setRight(Insert(root->getRight(),
                              root, new_item));

        int firstheight = 0;
        int secondheight = 0;
        if (root->getLeft() != NULL)
            firstheight = root->getLeft()->height;
        if (root->getRight() != NULL)
            secondheight = root->getRight()->height;

        if (abs(firstheight - secondheight) == 2)
        {
            if (root->getRight() != NULL && key < root->getRight()->getKey())
            {

                root = RLR(root);
            }
            else
            {

                root = RRR(root);
            }
        }
    }
    else
    {
    }
    Updateheight(root);
    return root;
}
template <class Key, class Value>
AVLNode<Key, Value> *Delete(AVLTree<Key, Value> *tree, AVLNode<Key, Value> *root, Key key)
{
    if (root != NULL)
    {

        if (root->getKey() == key)
        {

            if (root->getRight() == NULL && root->getLeft() != NULL)
            {
                if (root->getParent() != NULL)
                {
                    if (root->getParent()->getKey() < root->getKey())
                        root->getParent()->setRight(root->getLeft());
                    else
                        root->getParent()->setLeft(root->getLeft());

                    Updateheight(root->getParent());
                }
                root->getLeft()->setParent(root->getParent());

                root->setLeft(Balance(
                    root->getLeft()));
                return root->getLeft();
            }

            else if (root->getLeft() == NULL && root->getRight() != NULL)
            {
                if (root->getParent() != NULL)
                {
                    if (root->getParent()->getKey() < root->getKey())
                        root->getParent()->setRight(root->getRight());
                    else
                        root->getParent()->setLeft(root->getRight());

                    Updateheight(root->getParent());
                }
                root->getRight()->setParent(root->getParent());

                root->setRight(Balance(root->getRight()));
                return root->getRight();
            }

            else if (root->getLeft() == NULL && root->getRight() == NULL)
            {
                if (root->getParent() != NULL)
                {
                    if (root->getParent()->getKey() < root->getKey())
                        root->getParent()->setRight(NULL);
                    else
                        root->getParent()->setLeft(NULL);
                }
                if (root->getParent() != NULL)
                    Updateheight(root->getParent());
                root = NULL;
                return NULL;
            }

            else
            {
                AVLNode<Key, Value> *tmpnode = root;
                tmpnode = tmpnode->getLeft();
                while (tmpnode->getRight() != NULL)
                {
                    tmpnode = tmpnode->getRight();
                }
                Key val = tmpnode->getKey();
                Value v = tmpnode->getValue();
                root->setLeft(Delete(tree, root->getLeft(), tmpnode->getKey()));
                AVLNode<Key, Value> *tmp = new AVLNode<Key, Value>(val, v, NULL);
                tree->nodeSwap(root, tmp);
                root = tmp;
                root = Balance(root);
            }
        }
        else if (root->getKey() < key)
        {
            root->setRight(Delete(tree, root->getRight(), key));
            root = Balance(root);
        }
        else if (root->getKey() > key)
        {
            root->setLeft(Delete(tree, root->getLeft(), key));
            root = Balance(root);
        }
        if (root != NULL)
        {
            Updateheight(root);
        }
    }
    else
    {
        std::cout << "Key to be deleted "
                  << "could not be found\n";
    }
    return root;
}
/*
 * Recall: If key is already in the tree, you should
 * overwrite the current value with the updated value.
 */
template <class Key, class Value>
void AVLTree<Key, Value>::insert(const std::pair<const Key, Value> &new_item)
{
    this->root_ = Insert<Key, Value>(static_cast<AVLNode<Key, Value> *>(this->root_), NULL, new_item);
}
/*
 * Recall: The writeup specifies that if a node has 2 children you
 * should swap with the predecessor and then remove.
 */
template <class Key, class Value>
void AVLTree<Key, Value>::remove(const Key &key)
{
    this->root_ = Delete<Key, Value>(this, static_cast<AVLNode<Key, Value> *>(this->root_), key);
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
