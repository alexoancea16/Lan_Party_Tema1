#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player
{
    char* firstName;
    char* secondName;
    int points;
};

typedef struct Player PLAYER;

struct Team
{
    int number_of_comp;
    char *team_name;
    PLAYER *competitor;
    float points_team;
};

typedef struct Team Data;

struct Node
{
    Data val;
    struct Node *next;
};

typedef struct Node Node;

struct match
{
    char *team1;
    char *team2;
    float score1;
    float score2;
};

typedef struct match MATCH;

struct Node_match
{
    MATCH val;
    struct Node_match *next;
};

typedef struct Node_match Node_match;

struct Queues
{
    Node_match *fronts, *rear;
};

typedef struct Queues QUEUE;

struct Competitor
{
    char *team;
    float score;
};

typedef struct Competitor COMP;

struct Node_comp
{
    COMP val;
    struct Node_comp *next;
};

typedef struct Node_comp Node_comp;

struct Node_tree
{
    COMP val;
    struct Node_tree *left, *right;
};

typedef struct Node_tree Node_tree;

struct Node_avl
{
    int hight;
    COMP val;
    struct Node_avl *left, *right;
};

typedef struct Node_avl Node_avl;

void addAtBeginning(Node **head, Data v);

void addAtEnd(Node **head, Data v);

void delete_elem(Node **head, float v);

void addAtBeginning_top(Node_comp **head, COMP v);

void addAtEnd_top(Node_comp **head, COMP v);

void deleteList_Team(Node **head);

QUEUE *createQueue();

int isEmpty(QUEUE *top);

void enQueue(QUEUE *q, MATCH v);

MATCH deQueue(QUEUE *q);

void push(Node_comp **top, COMP v);

COMP pop(Node_comp **top);

void deleteStack(Node_comp **S);

Node_tree *newNode(COMP data);

Node_tree *insert_n(Node_tree *node, COMP key);

void inorder(Node_tree *root);

void inorder_avl(Node_avl *root);

int nodeHight(Node_avl *root);

int maxi(int a, int b);

Node_avl *RightRotation(Node_avl *z);

Node_avl *LeftRotation(Node_avl *z);

Node_avl *LRRotation(Node_avl *z);

Node_avl *RLRotation(Node_avl *z);

Node_avl *insert_avl(Node_avl *node, COMP key);

void deleteList_Top(Node_comp **head);
