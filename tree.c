#include "date.h"

Node_tree *newNode(COMP data)
{
    Node_tree *node = (Node_tree*)malloc(sizeof(Node_tree));
    node->val.team = (char*)malloc(strlen(data.team)*sizeof(char));
    strcpy(node->val.team,data.team);
    node->val.score = data.score;
    node->left = node->right = NULL;
    return node;
}

Node_tree *insert_n(Node_tree *node, COMP key)
{
    if(node == NULL)
        return newNode(key);
    if(key.score < node->val.score)
        node->left = insert_n(node->left, key);
    else
        if(key.score > node->val.score)
            node->right = insert_n(node->right, key);
        else
            if(strcmp(key.team,node->val.team)>0)
                node->left = insert_n(node->left, key);
            else
                node->right = insert_n(node->right, key);
    return node;
}

void inorder(Node_tree *root)
{
    if(root)
    {
        inorder(root->right);
        printf("%s",root->val.team);
        printf("%f\n",root->val.score);
        inorder(root->left);
    }
}

void inorder_avl(Node_avl *root)
{
    if(root)
    {
        inorder_avl(root->right);
        printf("%s",root->val.team);
        printf("%f\n",root->val.score);
        inorder_avl(root->left);
    }
}
int nodeHight(Node_avl *root)
{
    if(root == NULL)
        return -1;
    return root->hight;
}

int maxi(int a, int b)
{
    return ((a>b)?a:b);
}

Node_avl *RightRotation(Node_avl *z)
{
    Node_avl *y = z->left;
    Node_avl *T3 = y->right;
    y->right = z;
    z->left = T3;
    z->hight = maxi(nodeHight(z->left),nodeHight(z->right))+1;
    y->hight = maxi(nodeHight(y->left),nodeHight(y->right))+1;
    return y;
}

Node_avl *LeftRotation(Node_avl *z)
{
    Node_avl *y = z->left;
    Node_avl *T2 = y->right;
    y->right = z;
    z->left = T2;
    z->hight = maxi(nodeHight(z->left),nodeHight(z->right))+1;
    y->hight = maxi(nodeHight(y->left),nodeHight(y->right))+1;
    return y;
}

Node_avl *LRRotation(Node_avl *z)
{
    z->left = LeftRotation(z->left);
    return RightRotation(z);
}

Node_avl *RLRotation(Node_avl *z)
{
    z->right = RightRotation(z->right);
    return LeftRotation(z);
}

Node_avl *insert_avl(Node_avl *node, COMP key)
{
    if(node == NULL)
    {
        node = (Node_avl*)malloc(sizeof(Node_avl));
        node->val.team = (char*)malloc(strlen(key.team)*sizeof(char));
        strcpy(node->val.team,key.team);
        node->val.score = key.score;
        node->hight = 0;
        node->left = node->right = NULL;
        return node;
    }
    if(key.score < node->val.score)
        node->left = insert_avl(node->left,key);
    else
        if(key.score > node->val.score)
            node->right = insert_avl(node->right,key);
        else
            if(strcmp(key.team,node->val.team) < 0)
                node->left = insert_avl(node->left,key);
            else
                if(strcmp(key.team,node->val.team) > 0)
                    node->right = insert_avl(node->right,key);
                else
                    return node;
    node->hight = 1 + maxi(nodeHight(node->left),nodeHight(node->right));
    int k = (nodeHight(node->left)-nodeHight(node->right));
    if(k>1 && key.score < node->left->val.score)
        return RightRotation(node);
    if(k<-1 && key.score > node->right->val.score)
        return LeftRotation(node);
    if(k>1 && key.score > node->left->val.score)
        return RLRotation(node);
    if(k<-1 && key.score < node->right->val.score)
        return LRRotation(node);
    if(k>1 && key.score == node->left->val.score && strcmp(key.team,node->val.team) > 0)
        return RightRotation(node);
    if(k<-1 && key.score == node->right->val.score && strcmp(key.team,node->val.team) < 0)
        return LeftRotation(node);
    if(k>1 && key.score == node->left->val.score && strcmp(key.team,node->val.team) < 0)
        return RLRotation(node);
    if(k<-1 && key.score == node->right->val.score && strcmp(key.team,node->val.team) > 0)
        return LRRotation(node);
    return node;
}
