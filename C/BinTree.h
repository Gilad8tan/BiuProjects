/****************************************************************************
* Student name: Gilad Eitan
* Student ID:311810030
* Submit sys ID:eitangi
* Exercise name: Exercise 6
****************************************************************************/

#ifndef EX_6_BINTREE_H
#define EX_6_BINTREE_H

#define MALE 'M'
#define ONE_OR_TRUE 1
#define ZERO_OR_FALSE 0
#define FEMALE 'F'
#define TWO 2
#define DEATH_AGE 120
#define EIGHTY 80
#define TWENTY_OR_ITERATION 20
//bintree structure definition from the ex file
typedef struct BinTree {
    int id;
    char* name;
    int age;
    char gender;
    void (*task)(void* val);
    void* action;
    struct BinTree* left;
    struct BinTree* right;
    struct BinTree* dad;
} BinTree;

//generic functions by ex file
void generic_function(BinTree* root, void(*task)(void*));
int generic_int_function(BinTree* root, int(*task)(void*));

//my functions
void addNode(BinTree** root);
void child_task(void* val);
void moshe_task(void* val);
void insertNode(BinTree** root, BinTree* node);
void printNode(BinTree* root);
void printInorderNodes(BinTree* root);
void printPreorderNodes(BinTree* root);
void printPostorderNodes(BinTree* root);
int iterationPass(BinTree* root);
void ageEveryOne(BinTree* root);
int checkForDead(BinTree* root);
int checkForMosheOld(BinTree* root);
int checkForMoshe(BinTree* root);
int countSons(BinTree* node);
void freeNode(BinTree* node);
void freeIsrael (BinTree* root);
void printAllJews(BinTree* root);
void printMaleJews(BinTree* root);
void printFemaleJews(BinTree* root);
int jewCounter(BinTree* root , char gender);
int totCountJew(BinTree* root);
void searchPreorderNodes(BinTree* root);
void actionPreorderNodes(BinTree* root);
void searchInorderNodes(BinTree* root);
void actionInorderNodes(BinTree* root);
void searchPostorderNodes(BinTree* root);
void actionPostorderNodes(BinTree* root);
int malesLeftButMoshe(BinTree* root);
BinTree* returnMaleButMoshe(BinTree* root);
int drownBoys(BinTree* root);
BinTree* returnDeadGuy(BinTree* root);
int removeNode(BinTree* root);
void swapAndFreeOneSon(BinTree* toRemove,BinTree* son);
void swapAndFreeSons(BinTree* toRemove,BinTree* son);

#endif //EX_6_BINTREE_H
