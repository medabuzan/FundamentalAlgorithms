#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashTables.h"


Node * createNode (char *key)
{

Node * holder = (Node *) malloc (sizeof (Node));


if (holder)
    {


strcpy (holder->key, key);

holder->next = NULL;

}


return holder;

}



int
hashingFunction (char *key)
{


int hash = 13;


for (int i = 0; i < strlen (key); i++)
    {

hash = hash + key[i];

}

hash = hash % DIM;


return hash;

}



void
insertNode (Table * hashTable[DIM], char *key)
{


Node * holder = createNode (key);


if (!holder)
    {

    return ;
}

int hash = hashingFunction (key);


holder->next = hashTable[hash];

hashTable[hash] = holder;

}

int

findKey (Table * hashTable[DIM], char *key)
{


int hash = hashingFunction (key);


Node * iterator = hashTable[hash];


while (iterator)
    {


if (strcmp (key, iterator->key) == 0)

return hash;

iterator = iterator->next;

}


return 0;

}



void
deleteFromTable (Table * hashTable[DIM], char *key)
{


int hash = hashingFunction (key);


Node * iterator = hashTable[hash];

Node * prev = NULL;


if (strcmp (iterator->key, key) == 0)
    {

hashTable[hash] = iterator->next;

free (iterator);

}

  else
    {

while (iterator)
	{


if (strcmp (iterator->key, key) == 0)
	    {


prev->next = iterator->next;

free (iterator);

}

prev = iterator;

iterator = iterator->next;

}

}


}



void
listTable (Table * hashTable[DIM])
{

Node * node = NULL;


for (int i = 0; i < DIM; i++)
    {


node = hashTable[i];

printf ("bucket for hash value %d contains students :", i);


while (node)
	{


printf ("%s; ", node->key);

node = node->next;

}

printf ("\n");

}

printf ("\n");

}


