#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFFFFUL)

typedef struct
{
  char name[MAX_NAME];
  int age;
}person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name)
{
  int length = strnlen(name,MAX_NAME);
  unsigned int hash_value = 0;
  for(int i = 0;i<length;i++)
  {
    hash_value+=name[i];
    hash_value = (hash_value * name[i])% TABLE_SIZE;
  }
  return hash_value;
}
void init_hash_table()
{
  for(int i =0;i<TABLE_SIZE;i++)
  {
    hash_table[i] = NULL;
  }
}
void print_table()
{
  printf("Start\n");
  for(int i = 0;i<TABLE_SIZE;i++)
  {
    if(hash_table[i]==NULL)
    {
      printf("%i--\n",i);
    }
    else if(hash_table[i]==DELETED_NODE)
    {
      printf("%i------deleted\n",i);
    }
    else
    {
      printf("%i--%s\n",i,hash_table[i]->name);
    }
  }
  printf("End\n");
  return;
}

bool hash_table_insert(person *p)
{
  if(p == NULL)
  {
    return false;
  }
  int index = hash(p->name);
  for(int i = 0;i<TABLE_SIZE;i++)
  {
    int try = (i+index)%TABLE_SIZE;
    if(hash_table[try] == NULL || hash_table[try] == DELETED_NODE)
    {
      hash_table[try] = p;
      return true;
    }
  }
  return false;
}

person *hash_table_lookup(char *name)
{
  int index = hash(name);
  for(int i = 0;i<TABLE_SIZE;i++)
  {
    int try = (index+i)%TABLE_SIZE;
    if(hash_table[try] == NULL )
    {
      return NULL;
    }
    if(hash_table[i] == DELETED_NODE)
    {
      continue;
    }
    if(strcmp(hash_table[try]->name,name)==0)
    {
      return hash_table[try];
    }
  }

    return NULL;

}

person *hash_table_delete(char *name)
{
  int index = hash(name);
  for(int i = 0;i<TABLE_SIZE;i++)
  {
    int try = (index+i)%TABLE_SIZE;
    if(hash_table[try] == NULL )
    {
      return NULL;
    }
    if(hash_table[i] == DELETED_NODE)
    {
      continue;
    }
  
    if(strcmp(hash_table[try]->name,name)==0)
    {
      person *tmp = hash_table[try];
      hash_table[try] = DELETED_NODE;
      return tmp;
    }
  }

  return NULL;
  
}
int main()
{
  init_hash_table();

  /*
  printf("Alice => %u\n", hash("Alice"));
  printf("Bob => %u\n", hash("Bob"));
  printf("Charlie => %u\n", hash("Charlie"));
  printf("Diana => %u\n", hash("Diana"));
  printf("Eve => %u\n", hash("Eve"));*/
  person cat      = {.name = "Cat", .age = 3};
  person rabbit   = {.name = "Rabbit", .age = 2};
  person parrot   = {.name = "Parrot", .age = 1};
  person elephant = {.name = "Elephant", .age = 25};
  person tiger    = {.name = "Tiger", .age = 8};
  person fox      = {.name = "Fox", .age = 5};
  person panda    = {.name = "Panda", .age = 6};
  person bear     = {.name = "Bear", .age = 12};
  person lion     = {.name = "Lion", .age = 10};
  person wolf     = {.name = "Wolf", .age = 7};
  hash_table_insert(&cat);
  hash_table_insert(&rabbit);
  hash_table_insert(&parrot);
  hash_table_insert(&elephant);
  hash_table_insert(&tiger);
  hash_table_insert(&fox);
  hash_table_insert(&panda);
  hash_table_insert(&bear);
  hash_table_insert(&lion);
  hash_table_insert(&wolf);
  print_table();
  hash_table_delete("Parrot");
  printf("After deleting:\n\n");
  print_table();

  return 0;
}
