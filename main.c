#include "date.h"

void open_fis(FILE *f)
{
    if(f == NULL)
    {
        printf("Fisierul nu se poate deschide!\n");
        exit(1);
    }
}
void print_team(Node *head, FILE *fos)
{
    while(head != NULL)
    {
        fputs(head->val.team_name,fos);
        fprintf(fos,"\n");
        head=head->next;
    }
}
void print_fight(MATCH x, FILE *fos)
{
    fprintf(fos,"%-33s-",x.team1);
    fprintf(fos,"%33s\n",x.team2);
}
void print_winner(Node_comp *S, FILE *fos)
{
    while(S != NULL)
    {
        fprintf(fos,"%-34s-  ",S->val.team);
        fprintf(fos,"%.2f\n",S->val.score);
        S = S->next;
    }
}
void print_top_team(Node_tree *root, FILE *fos)
{
    if(root)
    {
        print_top_team(root->right,fos);
        fprintf(fos,"%-34s-  ",root->val.team);
        fprintf(fos,"%.2f\n",root->val.score);
        print_top_team(root->left,fos);
    }
}
void print_Level(Node_avl *root, int level, FILE *fos)
{
    if(root == NULL)
        return ;
    if(level == 1)
        fprintf(fos,"%s\n",root->val.team);
    else
        if(level > 1)
        {
            print_Level(root->right,level-1,fos);
            print_Level(root->left,level-1,fos);
        }
}
Node *create_team(FILE *fis, int nr)
{
    char name[40];
    char fst_n[20], snd_n[20];
    char space;
    Node *head=NULL;
    Data team;
    for(int i=0;i<nr;i++)
    {
        fscanf(fis,"%d",&team.number_of_comp);
        fscanf(fis,"%c",&space);
        fgets(name,40,fis);
        int n = strlen(name) - 1;
        if(name[n] == '\n')
            name[n] = '\0';
        team.team_name = (char*)malloc(strlen(name)*sizeof(char));
        strcpy(team.team_name,name);
        team.competitor = (PLAYER*)malloc(team.number_of_comp*sizeof(PLAYER));
        for(int j=0;j<team.number_of_comp;j++)
        {
            fscanf(fis,"%s",&snd_n);
            team.competitor[j].secondName = (char*)malloc(strlen(snd_n)*sizeof(char));
            strcpy(team.competitor[j].secondName,snd_n);
            fscanf(fis,"%s",&fst_n);
            team.competitor[j].firstName = (char*)malloc(strlen(fst_n)*sizeof(char));
            strcpy(team.competitor[j].firstName,fst_n);
            fscanf(fis,"%d",&team.competitor[j].points);
        }
        addAtEnd(&head,team);
    }
	return head;
}
void points(Node **head)
{
    Node *head_copy = *head;
    while(head_copy!= NULL)
    {
        float suma = 0;
        for(int i=0;i<head_copy->val.number_of_comp;i++)
            suma += head_copy->val.competitor[i].points;
        head_copy->val.points_team = (float)suma/head_copy->val.number_of_comp;
        head_copy = head_copy->next;
    }
}
int nr_team_disqualified(int nr_team)
{
    int semn = 1,nr = 1;
    while(semn == 1)
    {
        nr = nr*2;
        if(nr>nr_team)
            semn = 0;
    }
    return nr/2;
}
float min_points(Node *head)
{
    float p_min = head->val.points_team;
    head = head->next;
    while(head != NULL)
    {
        if(p_min>head->val.points_team)
            p_min = head->val.points_team;
        head = head->next;
    }
    return p_min;
}
void disqualified_team(Node **head, int *nr_team)
{
    int nr = nr_team_disqualified(*nr_team);
    Node *prev = NULL;
    points(head);
    while(nr != (*nr_team))
    {
        float p_min = min_points(*head);
        delete_elem(head,p_min);
        *nr_team = *nr_team-1;
    }
}
void create_MQueue(QUEUE *q, Node *head)
{
    MATCH battle;
    while(head != NULL)
    {
        battle.team1 = (char*)malloc(strlen(head->val.team_name)*sizeof(char));
        strcpy(battle.team1,head->val.team_name);
        battle.score1 = head->val.points_team;
        head = head->next;
        battle.team2 = (char*)malloc(strlen(head->val.team_name)*sizeof(char));
        strcpy(battle.team2,head->val.team_name);
        battle.score2 = head->val.points_team;
        head = head->next;
        enQueue(q,battle);
    }
}
void create_Match_new(QUEUE *q, Node_comp **S_winner)
{
    MATCH battle;
    while(*S_winner != NULL)
    {
        COMP x;
        x = pop(S_winner);
        battle.team1 = (char*)malloc(strlen(x.team)*sizeof(char));
        strcpy(battle.team1,x.team);
        battle.score1 = x.score;
        x = pop(S_winner);
        battle.team2 = (char*)malloc(strlen(x.team)*sizeof(char));
        strcpy(battle.team2,x.team);
        battle.score2 = x.score;
        enQueue(q,battle);
    }
    *S_winner = NULL;
}
void resault_match(MATCH x, Node_comp **S1, Node_comp **S2)
{
    COMP c1,c2;
    c1.team = (char*)malloc(strlen(x.team1)*sizeof(char));
    strcpy(c1.team,x.team1);
    c1.score = x.score1;
    push(S1,c1);
    c2.team = (char*)malloc(strlen(x.team2)*sizeof(char));
    strcpy(c2.team,x.team2);
    c2.score = x.score2;
    push(S2,c2);
}
void create_top(Node_comp *S, Node_comp **top_team)
{
    while(S != NULL)
    {
        addAtEnd_top(top_team,S->val);
        S = S->next;
    }
}
COMP fight(QUEUE *q, Node_comp **top_team, int *nr_team,FILE *fos)
{
    Node_comp *S_winner = NULL, *S_loser = NULL;
    COMP winner;
    int nr_round = 0;
    while(*nr_team>1)
    {
        nr_round = nr_round + 1;
        fprintf(fos,"\n--- ROUND NO:%d\n",nr_round);
        while(q->fronts != NULL)
        {
            MATCH x;
            x = deQueue(q);
            print_fight(x,fos);
            if(x.score1>x.score2) {
                x.score1 += 1;
                resault_match(x,&S_winner,&S_loser);
            }
            else {
                x.score2 += 1;
                resault_match(x,&S_loser,&S_winner);
            }
        }
        *nr_team = *nr_team/2;
        Node_comp *copy_stack = S_winner;
        if(*nr_team == 8)
            create_top(copy_stack,top_team);

        deleteStack(&S_loser);
        q=createQueue();
        Node_comp *S = S_winner;
        fprintf(fos,"\nWINNERS OF ROUND NO:%d\n",nr_round);
        print_winner(S,fos);
        if (*nr_team > 1)
            create_Match_new(q,&S_winner);
        else
            winner=pop(&S_winner);
    }
    return winner;
}
void create_top_classament(Node_comp *head, Node_tree **root)
{
    while(head != NULL)
    {
        *root = insert_n(*root,head->val);
        head = head->next;
    }
}
void extract_node(Node_tree *root, Node_avl **node)
{
    if(root)
    {
        extract_node(root->right,node);
        *node = insert_avl(*node,root->val);
        extract_node(root->left,node);
    }
}
int main()
{
    FILE *fis, *fos, *check;
    Node *head = NULL;
    Node_comp *top_team = NULL;
    QUEUE *q;
    COMP winner;
    Node_tree *root = NULL;
    Node_avl *node = NULL;
    int level = 2;
    int nr_team;
    int v[5],cer= 5 ;
    check = fopen("c.in","rt");
    open_fis(check);
    for(int i=0; i<cer; i++)
        fscanf(check,"%d",&v[i]);
    fis = fopen("d.in","rt");
    open_fis(fis);
    fos = fopen("r.out","wt");
    open_fis(fos);
    if(v[0] == 1)
    {
        fscanf(fis,"%d",&nr_team);
        head = create_team(fis,nr_team);
        if (v[1] != 1)
            print_team(head,fos);
    }
    if(v[1] == 1)
    {
        disqualified_team(&head,&nr_team);
        print_team(head,fos);
    }
    if(v[2] == 1)
    {
        q = createQueue();
        create_MQueue(q,head);
        winner = fight(q,&top_team,&nr_team,fos);
    }
    if(v[3] == 1)
    {
        create_top_classament(top_team,&root);
        fprintf(fos,"\nTOP 8 TEAMS:\n");
        print_top_team(root,fos);
    }
    if(v[4] == 1)
    {
        extract_node(root,&node);
        fprintf(fos,"\nTHE LEVEL 2 TEAMS ARE:\n");
        print_Level(node,level + 1,fos);
    }
    fclose(fis);
    fclose(fos);
    fclose(check);
    deleteList_Team(&head);
    deleteList_Top(&top_team);
    return 0;
}
