///Buzan Meda 30421

// quadratic probing
// we use prime numbersfar small chances of collisions
// the search operation is used on 1501 existing Entries and 1500 non existing Entries
// to be sure that the Entries i will search for are not in the Hash I searched
// for random ids bigger than the number of elements inserted in the hash
// when searching for the 1501 existing Entries i created a variable that ha a random value 
// between 0 and the number of existing elements
/// i used the function rand without keeping track of the Entries that were already searched
/// because for every Entry there should be the same probability of being searched
/// and i considered that to be true for every step
/// 
/// the total efforts are the sum of all efforts to find each Entry : different cases for the existing and non existing Entries
/// the average effort represents the average number of cells that have to be checked before findind an Entry 
/// the average effort = the total efforts / number of Entries  - - - - the number of entries i search fot in my case is 1500 for non existing and 1501 for existing
/// the max effort represents the largest number of cells that have been checked before findind the searched for entry -- different for existing or non ex
///

#include <iostream>
#include <string.h>
#include <string>
#define sizeM 9973
#define C0 3469
#define C1 1669  
#define C2 1697
#define CC 3001

using namespace std;

typedef struct {
    int id;
    char name[30];
} Entry;

Entry TheNull = { -1, "NULL" };

bool EntryEQ(Entry a, Entry b)
{
    if (a.id == b.id && strcmp(a.name, b.name) == 0)
        return 1;
    
    return 0;
}
int hashSimple(int k) {
    return k * C0;
}
int hashFunction(Entry k, int i)
{
    //Quadratic probing
//Quadratic probing uses a hash function of the form
// 
//h(k,i) = (h'(k) + c1*i + c2*i^2) mod m
    return (hashSimple(k.id) + C1 * i + C2 * i * i) % sizeM;

}
int insert(Entry T[], Entry k)
{
    int i = 0;

    do
    {
        int j = hashFunction(k, i);
        if (EntryEQ(T[j] , TheNull))
        {
            T[j] = k;
            return j;
        }
        else
            i++;
    }
    while (i != sizeM);

    return -1;
}
int search(Entry T[], Entry k, int * countOp)
{
    int i = 0;         
    int j;
    (*countOp) = 0;
    do {
         j = hashFunction(k, i);
         (*countOp)++;
         if (EntryEQ(T[j], k))
         {
             return j;
         }
        i++;

    } while (EntryEQ(T[j], TheNull) == 0 && i != sizeM);

    return -1;
}
int search2(Entry T[], Entry k)
{
    int i = 0;
    int j;
   
    do {
        j = hashFunction(k, i);
       
        if (EntryEQ(T[j], k))
        {
            return j;
        }
        i++;

    } while (EntryEQ(T[j], TheNull) == 0 && i != sizeM);

    return -1;
}
void test()
{
    
    Entry T[sizeM];
    for (int i = 0; i < sizeM; i++)
    {
        T[i] = TheNull;
    }
    Entry k = { 1, "anna" };
    Entry k2 = { 2, "are" };
    Entry k3 = { 3, "mere" };
    insert(T, k);
    insert(T, k2);
    ///insert(T, k3);
    int t = search2(T, k);
    if (t != -1)
        cout << T[t].name << ' ';
    else
        cout << "not found ";
    cout << '\n';

    int t2 = search2(T, k2);
    if (t2 != -1)
        cout << T[t2].name << ' ';
    else
        cout << "not found ";
    cout << '\n';

    int t3 = search2(T, k3);
    if (t3 != -1)
        cout << T[t3].name;
    else
        cout << "not found ";
    cout << '\n';

}
void randElem()
{   
    float totalEffEx=0, totalEffNon=0, AvgEx, AvgNon, MaxEx=0, MaxNon=0;
    int countOp;
    float fillingfactor[] = { 0.8, 0.85, 0.9, 0.95, 0.99 };
    Entry T[sizeM];
    cout << '\n';
    cout << "| Filling Factor      | Avg. Effort found     | Max Effort found      | Avg. Effort not found     | Max Effort not found";
    cout << '\n';
    cout << '\n';

    for (int j = 0; j <= 4; j++)
    {
        for (int i = 0; i < sizeM; i++)
        {
            T[i] = TheNull;
        }

        int numberOfElements = fillingfactor[j] * sizeM;
        for (int k = 0; k < numberOfElements; k++)
        {
            Entry rElem = { k, " name "};
            insert(T, rElem);
        }
        

        for (int cont = 0; cont < 1500; cont++) {
            int nonexist = rand() + numberOfElements;
            Entry nonex = { nonexist, " name2 " };

            search(T, nonex, &countOp);

            totalEffNon += countOp;
            if (countOp > MaxNon)
                MaxNon = countOp;
        }

        AvgNon = totalEffNon / 1500;

        for (int cont2 = 0; cont2 <  (CC - 1500); cont2++)
        {
            int exist = rand() % numberOfElements;
            Entry ex = { exist, " name " };

            search(T, ex, &countOp);

            totalEffEx += countOp;
            if (countOp > MaxEx)
                MaxEx = countOp;
        }

        AvgEx = totalEffEx / (CC - 1500);

        ///cout << "| Filling Factor      | Avg. Effort found     | Max Effort found      | Avg. Effort not found     | Max Effort not found";
        cout << "| " << fillingfactor[j] << "                   | " << AvgEx << "                     | " << MaxEx << "                     | " << AvgNon << "                      | " << MaxNon;
        cout << '\n';

    }


}
int main()
{
   /* Entry T[sizeM];
    for (int i = 0; i < sizeM; i++)
    {
        T[i] = TheNull;
    }*/

    ///randElem();

    test();



}
