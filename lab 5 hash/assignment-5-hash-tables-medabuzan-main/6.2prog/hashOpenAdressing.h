#define DIM 100

typedef struct node {

    char key[100];
} Node;

typedef Node Table;

Node *createNode(char*);
int hashingFunction(char*);
int rehasingFunction(char *);
void insertNode(Table**, char*);
int findKey(Table**, char*);
void deleteFromTable(Table **, char*);
void listTable(Table**);
