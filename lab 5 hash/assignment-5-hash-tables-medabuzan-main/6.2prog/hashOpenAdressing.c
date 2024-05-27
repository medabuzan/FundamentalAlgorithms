#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashOpenAdressing.h"

 Node * createNode (char *key)
{

Node * holder = (Node *) malloc (sizeof (Node));


if (holder)
    {


strcpy (holder->key, key);

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



int
rehashingFunction (char *key)
{

int hash = 7;


for (int i = 0; i < strlen (key); i++)
    {

hash = hash * 2 + key[i] % 13;

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

fprintf (stderr, "error not enough memory\n");

exit (3);

}


int hash = hashingFunction (key);


if (hashTable[hash])

hash = rehashingFunction (key);


hashTable[hash] = holder;

}



int
findKey (Table * hashTable[DIM], char *key)
{


int hash = hashingFunction (key);




if (hashTable[hash] && strcmp (key, hashTable[hash]->key) == 0)
    {

return hash;

}

  else
    {


hash = rehashingFunction (key);

if (hashTable[hash] && strcmp (key, hashTable[hash]->key) == 0)

return hash;

}


return -1;

}



void
deleteFromTable (Table * hashTable[DIM], char *key)
{


int hash = hashingFunction (key);


if (strcmp (key, hashTable[hash]->key) == 0)
    {

free (hashTable[hash]);

hashTable[hash] = NULL;

}

  else
    {

hash = rehashingFunction (key);

if (strcmp (key, hashTable[hash]->key) == 0)
	{

free (hashTable[hash]);

hashTable[hash] = NULL;

}

}

}



void
listTable (Table * hashTable[DIM])
{


for (int i = 0; i < DIM; i++)
    {


printf ("Bucket for hash value %d contains student : %s\n", i,
		 hashTable[i]);

}
printf ("\n");

}
