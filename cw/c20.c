/*struct node *new = NULL;

  while(cur->next){cur = cur->next;}
  new = (struct node*)malloc(sizeof(struct node));
  if(new == NULL){return 1;}
  strcpy(new->str,buf);
  cur->next = new;
  new->prev = cur;
  new->next = NULL;
  return 0;*//*void Print_revers(struct node* cur)
{
  if (cur == NULL)
  {    
      printf("empty\n");
      return;
  }
  while(cur->prev){cur = cur->prev;}
  while(cur->next)
  {
    printf("%s\n",cur->str);
    cur = cur->next;
  }

  printf("%s\n",cur->str);
}*/
/*struct node *new = NULL;

  while(cur->next){cur = cur->next;}
  new = (struct node*)malloc(sizeof(struct node));
  if(new == NULL){return 1;}
  strcpy(new->str,buf);
  cur->next = new;
  new->prev = cur;
  new->next = NULL;
  return 0;*//*void Print_revers(struct node* cur)
{
  if (cur == NULL)
  {    
      printf("empty\n");
      return;
  }
  while(cur->prev){cur = cur->prev;}
  while(cur->next)
  {
    printf("%s\n",cur->str);
    cur = cur->next;
  }

  printf("%s\n",cur->str);
}*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
//链表节点
{  
  struct node * next;
  char str[20];
  struct node * prev;
};

int add_first(struct node* cur,const char* buf)
{
  struct node *new = NULL;

  while(cur->prev){cur = cur->prev;}
  new = (struct node*)malloc(sizeof(struct node));
  if(new == NULL){return 1;}
  strcpy(new->str,buf);
  cur -> prev = new;
  new -> next = cur;
  new -> prev = NULL;
  return 0;
}


void Print_revers(struct node* cur)
{
  if (cur == NULL)
  {    
      printf("empty\n");
      return;
  }
  while(cur->prev){cur = cur->prev;}
  while(cur != NULL)
  {
    printf("%s\n",cur->str);
    cur = cur->next;
  }
}

void Delete_tree(struct node *cur)
{
  while(cur->prev){cur = cur->prev;}
  while(cur->next)
  {
    struct node *tmp = cur->next;
    free(cur);
    cur = tmp;
  }
}

int main(){
  struct node *head = NULL;
  char buf[20];




  while(scanf("%19s",buf)!=EOF)
  {
    if (add_first(head,buf)){
      break;
    }
  }
  Print_revers(head);
  if(head)
  {
    Delete_tree(head);
    free(head);
    head = NULL;
  }
    return 0;
}