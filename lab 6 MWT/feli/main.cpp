/* 
* 
* 
*/

#include <iostream>
#define maxsize 10000

struct Node1{
    int key;
    int count;
    Node1* children[5];
};
struct Node2 {
    int key;
    Node2* left;
    Node2* right;
};

Node1* createNode1(int i)
{
    Node1* new_node = (Node1*)malloc(sizeof(Node1));
    new_node->key = i;
    new_node->count = 0;
    new_node->children[new_node->count] = NULL;
    return new_node;
}
void addToArray(Node1* curr, Node1* child, int i)
{
    curr->children[curr->count] = child;
    curr->count++;
    curr->children[curr->count] = NULL;
}
void multiway(Node1* curr, int p_arr[], int n, int key)
{
    for (int i = 1; i < n; i++)
    {
        if (p_arr[i] == key) {
            Node1* child = createNode1(i);
            addToArray(curr, child, i);
            multiway(child, p_arr, n, i);
        }
    }
}
Node1* multiwayRoot(int p_arr[], int n)
{
    int i = 1;
    while (p_arr[i] != -1)
    {
        i++;
    }
    Node1* root = createNode1(i);
    return root;
}
Node2* createNode2(int i)
{
    Node2* new_node = (Node2*)malloc(sizeof(Node2));
    new_node->key = i;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void binary(Node1* rootM, Node2* rootB, Node1* parent, int i)
{
    if (rootM->count == 0){
        rootB->left = NULL;
    }else{
        Node2* aux = createNode2(rootM->children[0]->key);
        rootB->left = aux;
        binary(rootM->children[0], rootB->left, rootM, 0);
    }
    if (i == -1){
        rootB->right = NULL;
    }
    else {
        if (parent->count > i+1) {
            Node2 *aux2 = createNode2(parent->children[i + 1]->key);
            rootB->right = aux2;
            binary(parent->children[i + 1], rootB->right, parent, i + 1);
        }else {
            rootB->right = NULL;
        }
    }
}
void printKids(Node1* root, Node1* curr)
{
    std::cout << "Node: " << curr->key << " has as children: ";
    for (int i = 0; i < curr->count; i++)
        std::cout << curr->children[i]->key << " ";
    std::cout << '\n';
}
void printMultiway(Node1* root, Node1* curr)
{
    if (curr->children[0] != NULL) {
        printKids(root, curr);
        for (int i = 0; i < curr->count; i++)
        {
            if (curr->children[i] != NULL)
                printMultiway(root, curr->children[i]);
        }
    }
    else
        std::cout << "Node: " << curr->key << " is leaf." << '\n';
}
void prettyPrint(Node2* curr, int h)
{
    if (curr == NULL) return;
    for (int i = 1; i < 3 * h; i++)
        std::cout << " ";
    std::cout << curr->key << '\n';
    prettyPrint(curr->left, h+1);
    prettyPrint(curr->right, h);
}
void demo()
{
    int n = 10;
    int p_arr[10] = { -253,2,7,5,2,7,7,-1,5,2 };
    std::cout << "R1: ";
    for (int i = 1; i < n; i++)
        std::cout << p_arr[i] << " ";
    std::cout << '\n';

    Node1* root = multiwayRoot(p_arr, n);
    multiway(root, p_arr, n, root->key);
    std::cout << '\n' << "R2: " << '\n';
    std::cout << "Node: " << root->key << " is root." << '\n';
    printMultiway(root,root);

    Node2* rootB = createNode2(root->key);
    binary(root, rootB, root, -1);
    std::cout << '\n' << "R3: " << '\n';
    prettyPrint(rootB, 0);
}
int main()
{
    demo();
}