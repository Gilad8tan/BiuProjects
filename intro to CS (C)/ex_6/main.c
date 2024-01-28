
#include <stdio.h>
#include "BinTree.h"

//define

#define NEWCHILD (1)
#define DROWNBOYS (2)
#define SEARCHMOSHE (3)
#define PRINTALL (4)
#define SIZEOFJEWS (5)
#define USEREXIT (6)


#define ZERO_OR_FALSE 0

#define ONE_OR_TRUE 1

#define THREE 3

#define TWO 2

//allowed main.c function declarations :
void printMenu();
void printOrderMenu();
void printJewMenu();

/****************************************************************************
*function name: main
*
*
* The Input: int 1-6 and 1-3 for menu selection
* The output: 0 when done
* The PrintOut: prints menus
* The Function operation:
* 1.sets up pointer to hold BinTree node
* 2. prints menus and handles input for them
* 3.null the pointer in case we deleted tree
* 4.calls for memory free at finish
*
****************************************************************************/

int main() {
    //we set up root pointer
    BinTree* root = NULL;
    BinTree** head = &root;
    int nullRoot = ZERO_OR_FALSE;
    //int for user input
    char garbage ;
    int userInputMenu = ZERO_OR_FALSE;
    int userInputOrderMenu = ZERO_OR_FALSE;
    //loop for menu handling
    while (userInputMenu!=USEREXIT){
        //we do +20 for age , dead check , and moshe check
        nullRoot = generic_int_function(root,
                                  (int (*) (void*))  iterationPass);
        if (nullRoot ==ONE_OR_TRUE){
            root = NULL;
        }
        else {
            if (nullRoot == -ONE_OR_TRUE){
                //found moshe , hes 80 so
                generic_function(root,
                               (void (*)(void *)) freeIsrael);
                root = NULL;
                break;
            }
        }
        printMenu();
        //get input with get char to clean buffer
        scanf("%d%c",&userInputMenu,&garbage);
        //input check if we got 1-6 from user
        if (userInputMenu>6 || userInputMenu<ONE_OR_TRUE){
            //means wront input entered
            // we set to no choice = 0
            userInputMenu = ZERO_OR_FALSE;
        }

        //with the input we run the switch
        switch (userInputMenu){
            case NEWCHILD:
                addNode(head);
                userInputMenu = ZERO_OR_FALSE;
                break;

            case DROWNBOYS:
                nullRoot = generic_int_function(root,
                                          (int (*) (void*)) drownBoys);
                if (nullRoot ==ONE_OR_TRUE){
                    root = NULL;
                }
                userInputMenu = ZERO_OR_FALSE;
                break;

            case SEARCHMOSHE:
                printOrderMenu();
                scanf(" %d%c",&userInputOrderMenu,&garbage);
                //input check if we got 1-3 from user
                if (userInputOrderMenu>THREE ||
                                    userInputOrderMenu<ONE_OR_TRUE){
                    //means wront input entered
                    // we set to no choice = 0
                    printf("wrong order!\n");
                    userInputOrderMenu = ZERO_OR_FALSE;
                }
                else {
                    switch (userInputOrderMenu){

                        case ONE_OR_TRUE:
                            //chose preorder
                            generic_function(root,
                                   (void (*)(void *))searchPreorderNodes);
                            break;

                        case TWO:
                            //chose inorder
                            generic_function(root,
                                    (void (*)(void *))searchInorderNodes);
                            break;

                        case THREE:
                            //chose postorder
                            generic_function(root,
                                  (void (*)(void *))searchPostorderNodes);
                            break;

                        default:
                            break;

                    }
                }
                userInputMenu = ZERO_OR_FALSE;
                break;

            case PRINTALL:
                //another "menu" function here for 1-3 choice (order)
                printOrderMenu();
                scanf(" %d%c",&userInputOrderMenu,&garbage);
                //input check if we got 1-3 from user
                if (userInputOrderMenu>THREE ||
                                userInputOrderMenu<ONE_OR_TRUE){
                    //means wrong input entered
                    // we set to no choice = 0
                    printf("wrong order!\n");
                    userInputOrderMenu = ZERO_OR_FALSE;
                }
                else {
                    switch (userInputOrderMenu){

                        case ONE_OR_TRUE:
                            //chose preorder
                            generic_function(root,(void (*)(void *))
                                                     printPreorderNodes);
                            break;

                        case TWO:
                            //chose inorder
                            generic_function(root,(void (*)(void *))
                                                      printInorderNodes);
                            break;

                        case THREE:
                            //chose postorder
                            generic_function(root,(void (*)(void *))
                                                    printPostorderNodes);
                            break;

                        default:
                            break;

                    }
                }
                userInputMenu = ZERO_OR_FALSE;
                break;

            case SIZEOFJEWS:
                printJewMenu();
                scanf(" %d%c",&userInputOrderMenu,&garbage);
                //input check if we got 1-3 from user
                if (userInputOrderMenu>THREE ||
                                userInputOrderMenu<ONE_OR_TRUE){
                    //means wrong input entered
                    // we set to no choice = 0
                    printf("wrong order!\n");
                    userInputOrderMenu = ZERO_OR_FALSE;
                }
                else {
                    switch (userInputOrderMenu){

                        case ONE_OR_TRUE:
                            //chose preorder
                            generic_function(root,
                                       (void (*)(void *))printAllJews);
                            break;

                        case TWO:
                            //chose inorder
                            generic_function(root,
                                       (void (*)(void *))printMaleJews);
                            break;

                        case THREE:
                            //chose postorder
                            generic_function(root,
                                      (void (*)(void *))printFemaleJews);
                            break;

                        default:
                            break;

                    }
                }
                userInputMenu = ZERO_OR_FALSE;
                break;

            case USEREXIT:
                userInputMenu = USEREXIT;
                generic_function(root, (void (*)(void *)) freeIsrael);
                root = NULL;
                break;

            default:
                printf("wrong choose please choose again\n");
                userInputMenu = ZERO_OR_FALSE;
        }
        //mem clean is inside the choice to exit (6)
    }
    return ZERO_OR_FALSE;
}




/****************************************************************************
*function name: printMenu ,printOrderMenu ,printJewMenu
*
*
* The Input: NONE
* The output: NONE
* The PrintOut: prints menus by assignment orders.
*
****************************************************************************/

void printMenu(){
    printf("please choose action:\n");
    printf("(1) A child was born\n");
    printf("(2) Throw into the Nile\n");
    printf("(3) Find Moshe\n");
    printf("(4) Print All\n");
    printf("(5) Size of jews\n");
    printf("(6) Exit\n");

}

void printOrderMenu(){
    printf("please choose order:\n");
    printf("(1) preorder\n");
    printf("(2) inorder\n");
    printf("(3) postorder\n");

}

void printJewMenu(){
    printf("please choose what you want to calculate:\n");
    printf("(1) All jews\n");
    printf("(2) Male\n");
    printf("(3) Female\n");
}
