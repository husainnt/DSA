#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node*left;
    Node*right;
Node(int data)
{
    this->data=data;
    this->left=nullptr;
    this->right=nullptr;
}
};
class BST
{
    public:
    Node*root;
    void Insert_inBST(Node*root,int data)
    {
        if(root==nullptr)
        {
            return new Node(data);
        }
        else
        {
            if(data<root->data)
            {
                root->left=Insert_inBST(root->left,data);
            }
            else
            {
                root->right=Insert_inBST(root->right,data);
            }
        }
        return root;
    }
    void Delete_inBST(Node*root,int data)
    {
        if(root==nullptr)
        {
            return root;
        }
        if(data<root->data)
        {
            root->left=Delete_inBST(root->left,data);
        }
        else if(data>root->data)
        {
            root->right=Delete_inBST(root->right.data);

        }
        else
        {
            if(root->left&&root->right)
            {
                Node*temp=Find_Max(root->left);
                root->data=temp=data;
                root->left=Delete_inBST(root->left,temp->data);
            }
            else
            {
                Node*temp=root;
                if(root->left==nullptr)
                {
                    root=root->right;
                }
                else if(root->right==nullptr)
                {
                    root=root->left;
                }
                delete temp;
                
            }
        }
        return root;
    }
    void Search_inBST(Node*root,int data)
    {
        if(root==nullptr||root->data==data)
        {
            return root;
        }
        else
        {
            if(data<root->data)
            {
                return Search_inBST(root->left,data);
            }
            else if(data>root->data)
            {
                return Search_inBST(root->right,data);
            }
        }
    }
    Node*Find_Max(Node*root)
    {
        if(root==nullptr)
        {
            return nullptr;
        }
        else if(root->right==nullptr)
        {
            return root;
        }
        else
        {
            return Find_Max(root->rigth);
        }
    }
    Node*Find_Min(Node*root)
    {
        if(root==nullptr)
        {
            return nullptr;

        }
        else if(root->left==nullptr)
        {
            return root;
        }
        else
        {
            return Find_Min(root->left);
        }
    }
    
};
