#define DIM 100

typedef struct node {

    char key[100];
    struct node *next;
} Node;

typedef Node Table;

Node *createNode(char*);
int hashingFunction(char*);
void insertNode(Table**, char*);
int findKey(Table**, char*);
void deleteFromTable(Table **, char*);
void listTable(Table**);

