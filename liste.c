#include "date.h"

void addAtBeginning(Node **head, Data v)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->val = v;
	newNode->next = *head;
	*head = newNode;
}

void addAtEnd(Node **head, Data v)
{
	Node *headcopy=*head;
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->val = v;
	if (*head == NULL)
        addAtBeginning(head, v);
	else
	{
		while (headcopy->next!=NULL)
            headcopy = headcopy->next;
		headcopy->next = newNode;
		newNode->next = NULL;
	}
}

void delete_elem(Node **head, float v)
{
    if(*head == NULL)
        return;
    Node *headcopy = *head;
    if(headcopy->val.points_team == v)
    {
        *head = (*head)->next;
        free(headcopy);
        return;
    }
    Node *prev = *head;
    while(headcopy != NULL)
    {
        if(headcopy->val.points_team != v)
        {
            prev = headcopy;
            headcopy = headcopy->next;
        }
        else
        {
            prev->next = headcopy->next;
            free(headcopy);
            return;
        }
    }
}

void addAtBeginning_top(Node_comp **head, COMP v)
{
	Node_comp* newNode = (Node_comp*)malloc(sizeof(Node_comp));
	newNode->val = v;
	newNode->next = *head;
	*head = newNode;
}

void addAtEnd_top(Node_comp **head, COMP v)
{
	Node_comp *headcopy=*head;
	Node_comp *newNode = (Node_comp*)malloc(sizeof(Node_comp));
	newNode->val = v;
	if (*head == NULL)
        addAtBeginning_top(head, v);
	else
	{
		while (headcopy->next!=NULL)
            headcopy = headcopy->next;
		headcopy->next = newNode;
		newNode->next = NULL;
	}
}

void deleteList_Team(Node **head)
{
    Node *headcopy;
    while(*head != NULL)
    {
        headcopy = (*head)->next;
        free(*head);
        *head = headcopy;
    }
    *head = NULL;
}

void deleteList_Top(Node_comp **head)
{
    Node *headcopy;
    while(*head != NULL)
    {
        headcopy = (*head)->next;
        free(*head);
        *head = headcopy;
    }
    *head = NULL;
}
