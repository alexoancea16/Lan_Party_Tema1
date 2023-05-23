#include "date.h"

QUEUE *createQueue()
{
    QUEUE *q;
    q = (QUEUE*)malloc(sizeof(QUEUE));
    if(q == NULL)
        return NULL;
    q->fronts = q->rear = NULL;
    return q;
}

int isEmpty(QUEUE *top)
{
    return top == NULL;
}

void enQueue(QUEUE *q, MATCH v)
{
    Node_match *newNode = (Node_match*)malloc(sizeof(Node_match));
    newNode->val.score1 = v.score1;
    newNode->val.score2 = v.score2;
    newNode->val.team1 = (char*)malloc(strlen(v.team1)*sizeof(char));
    strcpy(newNode->val.team1,v.team1);
    newNode->val.team2 = (char*)malloc(strlen(v.team2)*sizeof(char));
    strcpy(newNode->val.team2,v.team2);
    newNode->next = NULL;
    if(q->rear == NULL)
    {
        q->fronts = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

MATCH deQueue(QUEUE *q)
{
    Node_match *aux;
    MATCH d;
    if(q->fronts == NULL)
    {
        printf("Queue is empty!\n");
        exit(1);
    }
    aux = q->fronts;
    d.team1 = (char*)malloc(strlen(aux->val.team1)*sizeof(char));
    strcpy(d.team1,aux->val.team1);
    d.team2 = (char*)malloc(strlen(aux->val.team2)*sizeof(char));
    strcpy(d.team2,aux->val.team2);
    d.score1 = aux->val.score1;
    d.score2 = aux->val.score2;
    q->fronts = aux->next;
    if(q->fronts == NULL)
        q->rear = NULL;
    free(aux);
    return d;
}

void deleteQueue(QUEUE *q)
{
    Node_match *aux;
    while(!isEmpty(q))
    {
        aux = q->fronts;
        q->fronts = q->fronts->next;
        free(aux);
    }
    free(q);
}

void push(Node_comp **top, COMP v)
{
    Node_comp *newNode = (Node_comp*)malloc(sizeof(Node_comp));
    newNode->val.team = (char*)malloc(strlen(v.team)*sizeof(char));
    strcpy(newNode->val.team,v.team);
    newNode->val.score = v.score;
    newNode->next = *top;
    *top = newNode;
}

COMP pop(Node_comp **top)
{
    if(*top == NULL)
    {
        printf("Stack is empty!\n");
        exit(1);
    }
    Node_comp *temp = (*top);
    COMP aux;
    aux.team = (char*)malloc((strlen(temp->val.team))*sizeof(char));
    strcpy(aux.team, temp->val.team);
    aux.score = temp->val.score;
    *top = (*top)->next;
    free(temp);
    return aux;
}

void deleteStack(Node_comp **S)
{
    COMP x;
    while(*S != NULL)
        x = pop(S);
}

