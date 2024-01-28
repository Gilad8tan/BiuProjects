

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinTree.h"

/****************************************************************************
*functions names: generic_function(s)
* void generic_function :
* The Input: BinTree( binary tree struct pointer to head (root) ,
*                   ( pointer to function and args)
* The output: NONE
*
* void generic_function :
* The Input: ( binary tree struct pointer to head (root) ,
*                   ( pointer to function and args)
* The output: int returned from pointed function
* The PrintOut: NONE
* The Functions operation: both functions are for running functions "hidden"
* in the BinTree module.
*
****************************************************************************/


//all function calls from main will pass through these funcs
void generic_function(BinTree* root, void(*task)(void*)) {
    task(root);
}

int generic_int_function(BinTree* root, int(*task)(void*)) {
    return task(root);
}


//addNode = 1.malloc inpt place ,  request and fill input: id ,name ,m/f
//2. create node , fill her with details from 1
//3.release mem of input fields
//4.run insert with pointer and tree

/****************************************************************************
*function name: addNode
* The Input: BinTree**( binary tree struct pointer to pointer to head (root))
* The output: NONE
* The return : NONE
* The Functions operation: passes double pointer from main
* allocates dynamic memory to read user input for BinTree Node
* allocates dynamic memory for the node itself
* free the memory for input
* pass the BinTree node pointer and the root from main
* to insertNode for chaining to the tree.
****************************************************************************/

void addNode(BinTree** root){
    BinTree* tmpPtr=NULL;
    char* name = malloc(sizeof (char[11]));
    int* id = malloc(sizeof (int));
    char* sex = malloc(sizeof (char));
    //check we got mem allocation
    if (!name || !id || !sex){
        //printf("mem alloc failed in addNode");
        free(name);
        free(id);
        free(sex);

        exit(ONE_OR_TRUE);
    }
    else{
        //no problems with malloc so far
        printf("please enter child id:\n");
        scanf("%d",id);
        printf("please insert child name:\n");
        scanf("%s",name);
        printf("please insert child gender:\n");
        scanf(" %c",sex);
        /////////////////////////////////////////////////debug printout
        //printf("addNode after filing input print:\n");
        //printf("id: %d name : %s gen:%c\n",*id,name,*sex);
        ///////////////////////////////////////////////////////////////
        //now we need to create new node and fill fields
        tmpPtr = malloc (sizeof (BinTree));
        if (!tmpPtr){
            //malloc failed
            //printf("malloc failed for BinTree in line 50\n");
            free(name);
            free(id);
            free(sex);
            exit(ONE_OR_TRUE);
        }
        else{
            //malloc succesful so we got pointer to BinTreeNode
            //now to fill fields
            tmpPtr->id = *id;
            tmpPtr->name = name;
            tmpPtr->age = -TWENTY_OR_ITERATION;
            tmpPtr->gender = *sex;

            if(strcmp(tmpPtr->name,"Moshe")==ZERO_OR_FALSE &&
                                        tmpPtr->gender == MALE){
                tmpPtr->task = moshe_task;

            }
            else {
                tmpPtr->task = child_task;
            }
            tmpPtr->action = tmpPtr->name;
            tmpPtr->left = NULL;
            tmpPtr->right = NULL;
            tmpPtr->dad = NULL;
            //fields full (almost) now to clean some mem
            free(id);
            free(sex);
            //name stays with us till deletion.
            //now we have pointer to our new node
            //so we run insert node on it with root
            insertNode(root,tmpPtr);


        }
    }
}


/****************************************************************************
*function name: addNode
* The Input: BinTree**( binary tree struct pointer to pointer to head (root))
*            BinTree* (pointer to node created by addNode with filled fields)
* The output: NONE
* The return : NONE
* The Functions operation: recursively traverses the tree to find place
*                          for node by (id)
****************************************************************************/
void insertNode(BinTree** root, BinTree* node){

    if(!(*root)){
        *root = node;
        return ;
    }
    else {

        if (node->id>=(*root)->id) {
            //case no sons
            if(!(*root)->right){
                //we just chain them
                (*root)->right = node;
                node->dad = (*root);
            }
            else {

                //root has a smaller son so we go in one level
                insertNode(&((*root)->right), node);

            }

        }
        else {
            //we smaller
            if(!(*root)->left){
                //we just chain them
                (*root)->left = node;
                node->dad = (*root);
            }
            else {
                //he has a  son so we go in one level
                insertNode(&((*root)->left),node);
            }
        }
    }
}


/****************************************************************************
*function name: printNode
* The Input: BinTree* (pointer to node with filled fields)
* The output: NONE
* The return : NONE
* The printout : node fields by order : id, name, gender, age
* The Functions operation: prints out one node (a helper func for other prints)
****************************************************************************/

void printNode(BinTree* node){
    if(node){
        printf("id: %d, name: %s, gender: %c, age: %d\n", node->id,
               node->name,node->gender,node->age);
    }
}

/****************************************************************************
*function name: printInorderNodes
* The Input: BinTree* (pointer to subtree(or tree) with filled fields)
* The output: NONE
* The return : NONE
* The printout : node fields by order : id, name, gender, age
* The Functions operation: prints out one node at a time Inorder (LsR)
****************************************************************************/

void printInorderNodes(BinTree* root){
    //recursively traverse the tree inorder and print
    if (!(root)) {
        //means no one to print so we return
        return;
    }
    printInorderNodes(root->left);
    printNode(root);
    printInorderNodes(root->right);
}

/****************************************************************************
*function name: printPreorderNodes
* The Input: BinTree* (pointer to subtree(or tree) with filled fields)
* The output: NONE
* The return : NONE
* The printout : node fields by order : id, name, gender, age
* The Functions operation: prints out one node at a time Preorder (sLR)
****************************************************************************/

void printPreorderNodes(BinTree* root){
    //recursively traverse the tree preorder print
    if (!(root)) {
        //means no one to print so we return
        return;
    }
    printNode(root);
    printPreorderNodes(root->left);
    printPreorderNodes(root->right);
}

/****************************************************************************
*function name: printPostorderNodes
* The Input: BinTree* (pointer to subtree(or tree) with filled fields)
* The output: NONE
* The return : NONE
* The printout : node fields by order : id, name, gender, age
* The Functions operation: prints out one node at a time Postorder (LRs)
****************************************************************************/

void printPostorderNodes(BinTree* root){
    //recursively traverse the tree postorder and print
    if (!(root)) {
        //means no one to print so we return
        return;
    }
    printPostorderNodes(root->left);
    printPostorderNodes(root->right);
    printNode(root);
}

//function to perform aging , death from old age , moshe age =80 check.
//if function returns 0 all ok
//if returns 1 - need to remove head
//if returns -1 we found moshe and he is 80 so free israel

/****************************************************************************
*function name: iterationPass
* The Input: BinTree* (pointer to subtree(or tree) with filled fields)
* The output: NONE
* The return : 1 if need to signal main to set root = NULL
*             -1 if need to finish the program after Moshe (M) is 80 years old
* The printout : newlines for menu in main (by your orders)
* The Functions operation: being called every user menu choice ,
*   calls ageEveryOne func (+20 to age ) , checks for moshe+age 80
*   checks for people age 120 to delete them ,calls deleter and finder funcs
*   and returns to main (The return val)
****************************************************************************/
int iterationPass(BinTree* root){
    if (!root){
        //we must leave cause tree empty
        printf("\n");
        return ZERO_OR_FALSE;
    }
    //we traverse the tree and age everyone +20 years
    ageEveryOne(root);
    if (checkForMosheOld(root) !=ZERO_OR_FALSE ){
        //moshe is 80 so we free israel and thats it

        return -ONE_OR_TRUE;
    }
    else{
        //no moshe+ age 80  so we dead check

        if (checkForDead(root) !=ZERO_OR_FALSE){
            //we need to delete dead nodes
            if (removeNode(returnDeadGuy(root)) == ONE_OR_TRUE){
                //we need to set head as null in main
                printf("\n");
                return ONE_OR_TRUE;
            }
            else {
                //we removed and head is not null
                printf("\n");
                return ZERO_OR_FALSE;
            }
        }
        else {
            printf("\n");
            return ZERO_OR_FALSE;
        }
    }
}

//if returns 0 no one is 120 so no need to delete
//if returns -1 moshe is 80
// if returns 1 - we run search old & delete function
/****************************************************************************
*function name: ageEveryOne
* The Input: BinTree* (pointer to subtree(or tree) with filled fields)
* The output: NONE
* The return : NONE
* The printout : NONE
* The Functions operation: recursively (Preorder) traverses tree
*   adds +20 to age .
****************************************************************************/
void ageEveryOne(BinTree* root){
    if (!root){
        //means no one to age our tree empty so return
        return ;
    }
    root->age += TWENTY_OR_ITERATION;
    ageEveryOne(root->left);
    ageEveryOne(root->right);
}

/****************************************************************************
*function name: checkForMosheOld
* The Input: BinTree* (pointer to subtree(or tree) with filled fields)
* The output: NONE
* The return : 1 if found , 0 others.
* The printout : NONE
* The Functions operation: recursively traverses tree searches for
*   name Moshe gender M age 80  for freeIsrael function
****************************************************************************/

int checkForMosheOld(BinTree* root){
    //pass whole tree - return 1 if found moshe and age ==80
    if (!root){
        return ZERO_OR_FALSE;
    }
    else {
        if (strcmp(root->name,"Moshe")==ZERO_OR_FALSE &&
                                  root->gender == MALE &&
                                     root->age == EIGHTY){
            //means we found moshe so we need to free israel so return 1
            printf("%s say: let my people go!", root->name );
            return ONE_OR_TRUE;
        }
        else {
            return checkForMosheOld(root->left) +
                   checkForMosheOld(root->right);
        }
    }
}


/****************************************************************************
*function name: checkForMoshe
* The Input: BinTree* (pointer to subtree(or tree) with filled fields)
* The output: NONE
* The return : 1 if found , 0 others.
* The printout : NONE
* The Functions operation: recursively traverses tree searches for
* name Moshe gender M so we know if hes in the tree (subroutine for drownBoys)
****************************************************************************/
int checkForMoshe(BinTree* root){
    if (root != NULL){
        if (strcmp(root->name,"Moshe")==ZERO_OR_FALSE && root->gender == MALE){
            //means we found the Moshe
            return ONE_OR_TRUE;
        }
        else {
            int tmp =checkForMoshe(root->left);
            if (tmp == ZERO_OR_FALSE){
                tmp = checkForMoshe(root->right);
            }
            return tmp;
        }

    }
    else {
        return ZERO_OR_FALSE;
    }
}



/****************************************************************************
*function name: checkForDead
* The Input: BinTree* (pointer to subtree(or tree) with filled fields)
* The output: NONE
* The return : 1 if found , 0 others.
* The printout : NONE
* The Functions operation: recursively traverses tree searches for
* nodes with age 120 to delete (by your orders)
****************************************************************************/

int checkForDead(BinTree* root){
    //same as moshe check but only for age
    if (root != NULL){
        if (root->age == DEATH_AGE){
            return ONE_OR_TRUE;
        }
        else {
            int tmp = checkForDead(root->left);
            if (tmp == ZERO_OR_FALSE){
                tmp = checkForDead(root->right);
            }
            return tmp;
        }

    }
    else{
        return ZERO_OR_FALSE;
    }

}


//just find the dead guy recursively preorder
//return pointer to him
/****************************************************************************
*function name: returnDeadGuy
* The Input: BinTree* (pointer to subtree(or tree) with filled fields)
* The output: NONE
* The return : BinTree* (pointer to node with age 120 )
* The printout : NONE
* The Functions operation: recursively traverses tree searches for
*  node with age 120 to delete (helper for deleteDead)
****************************************************************************/
BinTree* returnDeadGuy(BinTree* root){
    if(root!=NULL){
        if (root->age == DEATH_AGE){
            return root;
        }
        else{
            BinTree* temp =  returnDeadGuy(root->left);
            if (temp == NULL){
                temp = returnDeadGuy(root->right);
            }
            return temp;


        }
    }
    else {
        return NULL;
    }
}


//return 1 if need to null root in main (tree removed)
/****************************************************************************
*function name: removeNode
* The Input: BinTree* (pointer to node with age 120 to remove)
* The output: NONE
* The return : int to main : 1 to set root = NULL , 0 not
* The printout : NONE
* The Functions operation: removes node and keeps all pointers intact
*     around the deleted node.
****************************************************************************/
int removeNode(BinTree* deadGuy){
    BinTree* father = deadGuy->dad;
    BinTree* tmp = NULL;
    int direction = ZERO_OR_FALSE;
    //we have his father
    //not sure need direction any more
    if (father){
        if (father->right){
            if (father->right == deadGuy){
                //deadguy is fathers right son
                direction = ONE_OR_TRUE;
            }
        }
        else {
            //deadguy is his fathers left
            direction = -ONE_OR_TRUE;
        }
    }
    int sons = countSons(deadGuy);
    //we know if deadGuy has sons
    //so we make switch by amount of sons and if in case head
    switch (sons) {
        case ZERO_OR_FALSE:
            if (father == NULL){
                //if father = null means we remove root and no sons
                freeNode(deadGuy);
                return ONE_OR_TRUE;
            }
            else {
                //hes not the root and no sons
                freeNode(deadGuy);
                if(direction > ZERO_OR_FALSE){
                    father->right = NULL;
                }
                else {
                    father->left = NULL;
                }
                return ZERO_OR_FALSE;

            }
            break;

        case ONE_OR_TRUE:
            if (deadGuy->right){
                //his son is right
                tmp = deadGuy->right;
                //copy all fields to dead guy , remove tmp
                swapAndFreeOneSon(deadGuy,tmp);
            }
            else {
                //deadguy has son on left
                tmp = deadGuy->left;
                //copy all fields to dead guy , remove tmp
                swapAndFreeOneSon(deadGuy,tmp);


            }
            return ZERO_OR_FALSE;
            break;

        case TWO:
            //we find smallest larger than us (id)
            tmp = deadGuy->right;
            while (tmp->left){
                tmp = tmp->left;
            }
            // we should have stopped at temp= minimal larger
            if (tmp==deadGuy->right){
                //if we didnt have left to go
                //his son has only 1 son so we just swap up
                deadGuy->right = tmp->right;
                if (tmp->right){
                    tmp->right->dad= deadGuy;
                }


                //manual set pointers
                //so we keep left
                swapAndFreeSons(deadGuy,tmp);
            }
            else {
                //we did go left , just check if he has son to right
                //anyway we set fathers left ptr to tmp right
                tmp->dad->left = tmp->right;
                if (tmp->right){
                    tmp->right->dad = tmp->dad;
                }
                swapAndFreeSons(deadGuy,tmp);
            }
            return ZERO_OR_FALSE;
    }
}


/****************************************************************************
*function name: swapAndFreeOneSon
* The Input: BinTree* X2 (pointer to node to remove, pointer to son to replace)
* The output: NONE
* The return : NONE
* The printout : NONE
* The Functions operation: duplicates fields between 2 nodes by delete algo
* (helper function for removeNode)
****************************************************************************/

void swapAndFreeOneSon(BinTree* toRemove,BinTree* son ){
    free(toRemove->name);
    toRemove->id = son->id;
    toRemove->name = son->name;
    toRemove->age = son->age;
    toRemove->gender = son->gender;
    toRemove->task = son->task;
    toRemove->left = son->left;
    toRemove->right = son->right;
    int sonsSons = countSons(son);
    switch (sonsSons) {
        case ONE_OR_TRUE:
            if(son->right != NULL){
                son->right->dad=toRemove;
            }
            else{
                son->left->dad=toRemove;
            }
            break;
        case TWO:
            son->right->dad=toRemove;
            son->left->dad=toRemove;
            break;
        default:
            break;
    }
    //dad is same
    free(son);
}

/****************************************************************************
*function name: swapAndFreeSons
* The Input: BinTree* X2 (pointer to node to remove, pointer to son to replace)
* The output: NONE
* The return : NONE
* The printout : NONE
* The Functions operation: duplicates fields between 2 nodes by delete algo
* (helper function for removeNode) for other kind of case
****************************************************************************/
void swapAndFreeSons(BinTree* toRemove,BinTree* son){
    free(toRemove->name);
    toRemove->id = son->id;
    toRemove->name = son->name;
    toRemove->age = son->age;
    toRemove->gender = son->gender;
    toRemove->task = son->task;
   //keep left pointer as we went left
   //keep right pointer cause we do this manuallly in 2nd case(tmp went left)

    free(son);
}

/****************************************************************************
*function name: countSons
* The Input: BinTree* (pointer to node )
* The output: NONE
* The return : INT with number of children nodes for given node.
* The printout : NONE
* The Functions operation: counts sons by check if right/left == null
* (helper function for removeNode) to decide which case we in
****************************************************************************/

int countSons(BinTree* node){
    if(!node){
        return -ONE_OR_TRUE;
    }
    else{
        if (!node->right && !node->left){
            //no sons
            return ZERO_OR_FALSE;
        }
        else {
            if ((node->right && !node->left)||(!node->right && node->left)){
                //one son
                return ONE_OR_TRUE;
            }
            else {
                return TWO;
            }
        }
    }
}
//get a node , free what we allocated

/****************************************************************************
*function name: freeNode
* The Input: BinTree* (pointer to node )
* The output: NONE
* The return : NONE
* The printout : NONE
* The Functions operation: frees fields allocated for node
* (helper function for removeNode)
****************************************************************************/
void freeNode(BinTree* node){
    free(node->name);
    free(node);
}
/****************************************************************************
*function name: freeIsrael
* The Input: BinTree* (pointer to root )
* The output: NONE
* The return : NONE
* The printout : NONE
* The Functions operation:traverse tree and frees all nodes (root last)
****************************************************************************/

void freeIsrael(BinTree* root){
    if (!root){
        return;
    }
    else {
        if (root->right){
            freeIsrael(root->right);
        }
        if (root->left){
            freeIsrael(root->left);
        }
        freeNode(root);
    }

}

/****************************************************************************
*function name: jewCounter
* The Input: BinTree* (pointer to root ) CHAR gender (M/F)
* The output: NONE
* The return : INT with number of nodes for given gender.
* The printout : NONE
* The Functions operation: counts nodes by comparing gender
* (helper function for print num jews(gender))
****************************************************************************/

int jewCounter(BinTree* root , char gender){
    //we just traverse the tree recursively and add up
    if (!root){
        return ZERO_OR_FALSE;
    }
    else {
        if (root->gender == gender){
            return ONE_OR_TRUE + jewCounter(root->left,gender) +
                                jewCounter(root->right,gender) ;
        }
        else {
            return jewCounter(root->left,gender) +
                    jewCounter(root->right,gender);
        }

    }
}

/****************************************************************************
*function name: totCountJew
* The Input: BinTree* (pointer to root )
* The output: NONE
* The return : INT with number of nodes on the tree
* The printout : NONE
* The Functions operation: counts nodes by traversing and adding up
* (helper function for print num jews(gender))
****************************************************************************/

int totCountJew(BinTree* root){
    if (!root){
        return ZERO_OR_FALSE;
    }
    else {
        return ONE_OR_TRUE + totCountJew(root->left) +
                        totCountJew(root->right);
    }
}
/****************************************************************************
*function name: printAllJews
* The Input: BinTree* (pointer to root )
* The output: NONE
* The return : NONE
* The printout : size of all jews (number of nodes)
* The Functions operation: prints return from countJews
****************************************************************************/

void printAllJews(BinTree* root) {
    printf ("size of all jews is: %d\n", totCountJew(root));
}

/****************************************************************************
*function name: printMaleJews
* The Input: BinTree* (pointer to root )
* The output: NONE
* The return : NONE
* The printout : size of all jews (number of nodes)
* The Functions operation: prints return from countJews (MALES)
****************************************************************************/

void printMaleJews(BinTree* root){
    printf ("size of all male jews is: %d\n",
                        jewCounter(root,MALE));
}

/****************************************************************************
*function name: printFemaleJews
* The Input: BinTree* (pointer to root )
* The output: NONE
* The return : NONE
* The printout : size of all jews (number of nodes)
* The Functions operation: prints return from countJews (Female)
****************************************************************************/

void printFemaleJews(BinTree* root){
    printf ("size of all female jews is: %d\n",
                        jewCounter(root,FEMALE));
}

/****************************************************************************
*function name: actionPreorderNodes
* The Input: BinTree* (pointer to root )
* The output: NONE
* The return : NONE
* The printout : NONE
* The Functions operation:calls nodes action in Preorder (sLR) traverse of tree
* (helper function for searchPreorder)
****************************************************************************/
void actionPreorderNodes(BinTree* root){
    //recursively traverse the tree inorder and print
    if (!(root)) {
        //means no one to print so we return
        return;
    }
    root->task(root->action);
    actionPreorderNodes(root->left);
    actionPreorderNodes(root->right);

}

/****************************************************************************
*function name: searchPreorderNodes
* The Input: BinTree* (pointer to root )
* The output: NONE
* The return : NONE
* The printout : tasks of nodes (name - cry waaaa , or moshe quit)
*                  and if moshe found or not
* The Functions operation:calls actionPreorder func
*                     and calls check for moshe func for printout.
****************************************************************************/

void searchPreorderNodes(BinTree* root){
    actionPreorderNodes(root);

    if (checkForMoshe(root) == ONE_OR_TRUE){
        // we dump em to the water
        drownBoys(root);
    }
    else {
        printf("Moshe Not Found!\n");
    }
}

/****************************************************************************
*function name: actionInorderNodes
* The Input: BinTree* (pointer to root )
* The output: NONE
* The return : NONE
* The printout : NONE
* The Functions operation:calls nodes action in Inorder (LsR) traverse of tree
* (helper function for searchInorder)
****************************************************************************/

void actionInorderNodes(BinTree* root){
    //recursively traverse the tree inorder and print
    if (!(root)) {
        //means no one to print so we return
        return;
    }
    actionInorderNodes(root->left);
    root->task(root->action);
    actionInorderNodes(root->right);

}

/****************************************************************************
*function name: searchInorderNodes
* The Input: BinTree* (pointer to root )
* The output: NONE
* The return : NONE
* The printout : tasks of nodes (name - cry waaaa , or moshe quit)
*                  and if moshe found or not
* The Functions operation:calls actionInorder func
*                     and calls check for moshe func for printout.
****************************************************************************/
void searchInorderNodes(BinTree* root){
    actionInorderNodes(root);
    if (checkForMoshe(root) == ONE_OR_TRUE){
        // we dump em to the water
        drownBoys(root);
    }
    else {
        printf("Moshe Not Found!\n");
    }
}

/****************************************************************************
*function name: actionPostorderNodes
* The Input: BinTree* (pointer to root )
* The output: NONE
* The return : NONE
* The printout : NONE
* The Functions operation:calls nodes action in Postorder (LRs)
 *                                              traverse of tree
* (helper function for searchPostorder)
****************************************************************************/

void actionPostorderNodes(BinTree* root){
    //recursively traverse the tree inorder and print
    if (!(root)) {
        //means no one to print so we return
        return;
    }
    actionPostorderNodes(root->left);
    actionPostorderNodes(root->right);
    root->task(root->action);
}


/****************************************************************************
*function name: searchPostorderNodes
* The Input: BinTree* (pointer to root )
* The output: NONE
* The return : NONE
* The printout : tasks of nodes (name - cry waaaa , or moshe quit)
*                  and if moshe found or not
* The Functions operation:calls actionPostorder func
*                     and calls check for moshe func for printout.
****************************************************************************/


void searchPostorderNodes(BinTree* root){
    actionPostorderNodes(root);
    if (checkForMoshe(root) == ONE_OR_TRUE){
        drownBoys(root);
    }
    else {
        printf("Moshe Not Found!\n");
    }
}

/****************************************************************************
*function name: drownBoys
* The Input: BinTree* (pointer to root )
* The output: NONE
* The return : INT to main , 1 to set root = NULL , 0 else
* The printout : NONE
* The Functions operation:checks for females or moshe ,
*       if only males - removes whole tree, else ,
*       loops and deletes male untill no more males
****************************************************************************/

int drownBoys(BinTree* root) {

    //case no women and no Moshe - we free everyone and return 1 to null root
    if(jewCounter(root,FEMALE)==ZERO_OR_FALSE &&
                                    checkForMoshe(root)==ZERO_OR_FALSE){
        freeIsrael(root);

        return ONE_OR_TRUE;
    }
    else {
        // we  have someone to become root so we delete all male nodes
        /////////////////////////////////////////////////////////////////

        // we should loop here while malesNotMOshe ==1
        while(malesLeftButMoshe(root)==ONE_OR_TRUE){
            removeNode(returnMaleButMoshe(root));
        }
        return ZERO_OR_FALSE;
    }
}

/****************************************************************************
*function name: malesLeftButMoshe
* The Input: BinTree* (pointer to root )
* The output: NONE
* The return : INT - 1 to stay in loop and remove more boys , 0 else
* The printout : NONE
* The Functions operation: compares number of males and moshe untill
*         no males or only moshe
****************************************************************************/

int malesLeftButMoshe(BinTree* root){
    if (jewCounter(root,MALE)> checkForMoshe(root)){
        //we have males left other then moshe
        return ONE_OR_TRUE;
    }
    else {
        return ZERO_OR_FALSE;
    }
}

/****************************************************************************
*function name: returnMaleButMoshe
* The Input: BinTree* (pointer to root )
* The output: NONE
* The return : BinTree* (poiner to node with male (not Moshe))
* The printout : NONE
* The Functions operation: traverses abd returns pointer to male not moshe
*         helper function for drownBoys
****************************************************************************/

BinTree* returnMaleButMoshe(BinTree* root){
    if(root!=NULL){
        if (root->gender == MALE &&
                        strcmp(root->name,"Moshe") != ZERO_OR_FALSE){
            return root;
        }
        else{
            BinTree* tmp = returnMaleButMoshe(root->left);
            if (tmp == NULL){
                tmp = returnMaleButMoshe(root->right);
            }
            return tmp;
        }
    }
    else {
        return NULL;
    }
}


/****************************************************************************
*function name:  child_task / moshe_task
* The Input: BinTree*-> name , set up on creation or duplication of node
* The output: NONE
* The return : NONE
* The printout : everyone - cryy waaaa , moshe - quiet .
* The Functions operation: generic function called from node at search func
****************************************************************************/

void child_task(void* val){
    printf ("%s cry waaaa\n",val);
}
void moshe_task(void* val){
    printf ("%s quiet\n",val);
}