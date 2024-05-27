#include <stdio.h>
#include <stdlib.h>
#include "hashTables.h"

#define NAMELENGTH 30

/***
 * Exit codes meaning :
 *      1 : the input / output files are not provided
 *      2 : the program can't open the input / output files
 *      3 : memory allocation issues
 */

void
procedure ()
{


Table * hashTable[DIM];

int hash;


for (int i = 0; i < DIM; i++)
    {

hashTable[i] = NULL;

}

int c;

char *name = (char *) malloc (NAMELENGTH);


if (!name)
    {

fprintf (stderr, "error not enough memory\n");

exit (3);

}


while ((c = getchar ()) != EOF)
    {


int i = 0;

int cc;

while ((cc = getchar ()) != EOF && cc != '\n')

*(name + i++) = cc;

*(name + i) = '\0';


switch (c)
	{

case 'i':

insertNode (hashTable, name);

break;

case 'f':

hash = findKey (hashTable, name);


if (hash == 0)
	    {

printf ("student not in table.\n");

}

	  else
	    {

printf ("student %s is at position %d.\n", name, hash);

}

break;

case 'd':

deleteFromTable (hashTable, name);

break;

case 'l':

listTable (hashTable);

break;

default:

fprintf (stderr, "error unknown command\n");

break;

}

}

}



int
main (int argc, char *argv[])
{

switch (argc)
    {

case 1:

exit (1);

case 3:

if (!freopen (argv[1], "r", stdin))
	{

perror ("Unable to open input file : ");

exit (2);

}

if (!freopen (argv[2], "w", stdout))
	{

perror ("Unable to open output file : ");

exit (2);

}

break;


default:

exit (1);

}


procedure ();

return 0;

}


