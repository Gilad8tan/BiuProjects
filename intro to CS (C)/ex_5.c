
///imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///struct def
typedef struct Contact {
    char* firstName;
    char* lastName;
    char* phoneNum;
    struct Contact* next;
} Contact;

///define section
#define LETTERS (26)
#define EXIT (7)


///func decleration
void printContact(struct Contact* contact);
int letterToNum(char* ch);
int nameExistCheck (struct Contact* contact,struct Contact* phonebook[LETTERS]
        , int numOfLetter );
int numExistCheck(struct Contact* contact,struct Contact* phonebook[LETTERS]);
void addToPhonebook(struct Contact* contact,
                    struct Contact* phonebook[LETTERS],int numOfLetter);
struct Contact* addContact(struct Contact* phonebook[LETTERS]);
void cleanMem(Contact* phonebook[LETTERS]);
void menuPrint();
void deleteContact(struct Contact* phonebook[LETTERS]);
struct Contact* findByName(char* fName,char* lName,
        struct Contact* phonebook[LETTERS]);
void printBook(struct Contact* phonebook[LETTERS]);
void addInPlace(struct Contact* contact,
                struct Contact* phonebook[LETTERS]);




///main function
int main() {
    int usrChoice = 0;
    int printMenu = 1;
    char garbage ;

    //phonebook as requested in instructions
    struct Contact *phonebook[26]={NULL};
    while (usrChoice != EXIT){
        if (printMenu == 1){
            menuPrint();
            printMenu = 0 ;
        }
        scanf("%d",&usrChoice);
        printf("userchoice is:%c",usrChoice);
        while ((garbage = getchar()) != '\n');
        switch(usrChoice)
        {
            case 1:
                printf("1\n");
                addContact(phonebook);
                usrChoice =0 ;
                printMenu = 1 ;
                break;
            case 2:
                printf("2\n");
                deleteContact(phonebook);
                usrChoice =0 ;
                printMenu = 1 ;
                break;
            case 3:
                printf("3\n");
                //searchContactNum();
                usrChoice =0 ;
                printMenu = 1 ;
                break;
            case 4:
                printf("4\n");
                //searchContactName();
                usrChoice =0 ;
                printMenu = 1 ;
                break;
            case 5:
                printf("5\n");
                //editContact();
                usrChoice =0 ;
                printMenu = 1 ;
                break;
            case 6:
                printf("6\n");
                printBook(phonebook);
                usrChoice =0 ;
                printMenu = 1 ;
                break;
            case 7:

                break;
            default:
                printf("Wrong option, try again:\n");
                usrChoice =0 ;

                break;

        }
    }
    //cleanup and goodbye
    cleanMem(phonebook);
    printf("Bye!\n");






    return 0;
}



///function definitions

/****************************************************************************
*function name: rowCheck
*The Input: int a,b,c for board,row,col and arr for board
*The output: 1 if win on row 0 else
*The PrintOut: NONE
*The Function operation: check if whole row is X or O                                               ///// notice this is template
 * if so return 1 which is win 0 else
****************************************************************************/
void menuPrint(){
    printf("Welcome to the phone book manager!\n");
    printf("Choose an option:\n");
    printf("1. Add a new contact to the phone book.\n");
    printf("2. Delete a contact from the phone book.\n");
    printf("3. Find a contact in the phone book by phone number.\n");
    printf("4. Find a contact in the phone book by name.\n");
    printf("5. Update phone number for a contact.\n");
    printf("6. Print phone book.\n");
    printf("7. Exit.\n");
}

void printContact(struct Contact* contact){
    printf("%-10s ",contact->firstName);
    printf("%-10s ",contact->lastName);
    printf("%-10s\n",contact->phoneNum);
}

int letterToNum(char* ch){
    int num = (int) *ch;
    printf("num is :%d",num);
    if (num>=97){
        if (num<=122){
            printf("num is :%d",num-97);
            return num-97;
        }

    }
    else{
        if (num<=90){
            if (num>=65){
                printf("num is :%d",num-65);
                return num-65;
            }
        }
        else return -1;
    }
}

int nameExistCheck (struct Contact* contact,struct Contact* phonebook[LETTERS], int numOfLetter ) {
    Contact* current = NULL;
    // how best ? we have num of letter , so we only need to strcmp
    if (phonebook[numOfLetter] == NULL){
        return  0;
    }
    else{
        // its not null - we need to check for name and lastname strcmp == 0
        current = phonebook[numOfLetter];
        while (current != NULL){
            // while still contact valid
            if ((strcmp(contact->lastName,current->lastName) == 0)&&
                (strcmp(contact->firstName,current->firstName))==0 ){
                return 1;
            }
            current = current->next;
        }
        return 0;
    }

}


//numcheck
int numExistCheck(struct Contact* contact,struct Contact* phonebook[LETTERS]){
    Contact* current = NULL;
    //we loop throught all letter , if not null we enter with pointer
    for (int letter = 0 ; letter<LETTERS ; letter++){
        if (phonebook[letter] !=NULL){
            //we have something pointed to so we loop while
            current = phonebook[letter] ;
            while (current != NULL){
                if (strcmp(current->phoneNum , contact->phoneNum) == 0){
                    return 1;
                }
                else{
                    current = current->next;
                }


            }

        }


    }
    return 0;
}

struct Contact* findPlace(struct Contact* contact,
                          struct Contact* phonebook[LETTERS],int numOfLetter) {
    if (contact == NULL){
        return NULL;
    }
    else{
        //contact is ok , we need to find its place
        if (phonebook[numOfLetter] == NULL){
            //no phonebook record for this letter
            //then we send back
            return phonebook[numOfLetter];
        }
        else {
            //phonebook has contacts under this letter so we search place
            if (strcmp(contact->lastName,phonebook[numOfLetter]->lastName)<0){
                //means contact belongs at head of list
                return phonebook[numOfLetter];
            }
            else {
                Contact* current = phonebook[numOfLetter];
                Contact* oneBeforeCurr = NULL;
                // last name is not smaller then currnt head so we loop
                while (strcmp(contact->lastName,current->lastName)>0){
                    //this loops while our curr name is larger
                    oneBeforeCurr = current;
                    current = current->next;
                    if(current == NULL){
                        //we reached the end so we belong to tail
                        return oneBeforeCurr;
                    }
                }
                if (oneBeforeCurr == NULL){
                    //we didnt loop at all ,
                    oneBeforeCurr = phonebook[numOfLetter];
                }
                //we finished loop so now we in place where lname==lname
                //or passed it
                if (strcmp(contact->lastName,current->lastName)==0){
                    //same last name , we do same check for fname
                    if (strcmp(contact->firstName,current->firstName)<0){
                        //contact belongs before
                        printf("l 264 onebef sent to place is :");
                        printContact(oneBeforeCurr);
                        return oneBeforeCurr;
                    }
                    else{
                        //we need to loop
                        while (strcmp(contact->lastName,current->lastName)==0&&
                             strcmp(contact->firstName,current->firstName)>0){
                            oneBeforeCurr = current;
                            current = current->next;
                            if (current == NULL){
                                //we reached end so return
                                return oneBeforeCurr;
                            }

                        }
                        printf("oone b4 l 280 :");
                        printContact(oneBeforeCurr);
                        return oneBeforeCurr;

                    }
                }
            }
        }
    }

}

void addInPlace(struct Contact* contact,
                struct Contact* phonebook[LETTERS]){


    if (!contact){
        //contact points to null so problem in mem alocation
        //any way we exit with error

    }
    else {

        int numOfLetter = letterToNum(&contact->lastName[0]);
        //contact is ok . now we need to find its place:
        Contact* oneBefore = NULL;
        oneBefore = findPlace(contact , phonebook,numOfLetter);
        if (oneBefore != NULL && oneBefore->next !=NULL){
            printf("295 one b4 is :");
            printContact(oneBefore);
            printf("295 one b4nxt is :");
            printContact(oneBefore->next);
        }

        if (!oneBefore) {
            // if it points to null we need head insertion
            phonebook[numOfLetter] = contact;
        }
        else {
            if (oneBefore == phonebook[numOfLetter]){
                printf("we entered 315\n");
                //under top

                contact->next = phonebook[numOfLetter];
                phonebook[numOfLetter] = contact;


            }
            else{
                //we have pointer to place so we change a pointers around
                if (oneBefore->next == NULL){
                    contact->next = NULL;
                    oneBefore->next =contact;

                    printf("l303 one b4 is:");
                    printContact(oneBefore);
                    printf("which next is : ");
                    printContact(oneBefore->next);

                }
                else{
                    printf("312 which next is : ");
                    printContact(oneBefore->next);
                    contact->next = oneBefore->next;
                    oneBefore->next = contact;
                    printf("l309 one b4 is:");
                    printContact(oneBefore);
                    printf("which next is : ");
                    printContact(oneBefore->next);
                }
            }



        }
    }
    printContact(contact);
    printf("contact added pointing to lname:");
    if(contact->next == NULL){
        printf("NULL");
    }else{
        printContact(contact->next);
    }



}







struct Contact* addContact(struct Contact* phonebook[LETTERS]) {
    int contNull = 0;
    int charNum = -1;
    int nameCheck = -1; // -1 is problem
    char *lName = NULL;
    char *fName = NULL;
    char *pNum = NULL;
    //allocate a struct and return pointer to it
    Contact *contact = malloc(sizeof(Contact));
    if (contact == NULL) {
        //allocation failed so we set mistake
        contNull = 1;
    } else {
        //contact created so we malloc free mem for fields
        lName = malloc(sizeof(char[11]));
        fName = malloc(sizeof(char[11]));
        pNum = malloc(sizeof(char[11]));
        // now we check all alocated
        if (!lName || !fName || !pNum) {
            //if one ot them returns null so no mem alloc for it = fail
            //clear whats not null
            free(lName);
            free(fName);
            free(pNum);
            free(contact);
            contNull = 1;
        } else {
            //they all ok
            //we need to set the contact fields to point to fields.
            printf("Enter a contact details (<first name> <last name> <phone number>): \n");
            scanf("%s %s %s", fName, lName, pNum);
            //debug check
            printf("\n %s %s %s", fName, lName, pNum);
            //so fields were changed properly
            //now we set pointers to correct place
            contact->firstName = fName;
            contact->lastName = lName;
            contact->phoneNum = pNum;
            contact->next = NULL;

            printContact(contact);
            //so far so good .
            // now check for name and num existing , so we ask pointer to phonebook for check
            //we add the array in the params
            // now we have access to phone book
            //we should check int of letter
            charNum = letterToNum(contact->lastName);
            if (charNum != -1){
                if( nameExistCheck(contact, phonebook , charNum) == 0){
                    //we passed namechck now check num
                    if(numExistCheck(contact, phonebook) == 0){
                        //no duplicates found so we need to addcontact to book
                        addInPlace(contact,phonebook);
                        return contact;

                    }
                    else{
                        printf("The addition of the contact has failed,"
                               " since the phone number %s already exists!",
                               contact->phoneNum);
                        //now clear all
                        free(lName);
                        free(fName);
                        free(pNum);
                        free(contact);

                    }
                }
                else {

                    printf("The addition of the contact has failed,"
                           " since the contact %s %s already exists!\n",
                           contact->firstName , contact->lastName);
                    free(lName);
                    free(fName);
                    free(pNum);
                    free(contact);

                    //need to cleanup all fields and memory
                }




            }
            else {
                printf("something wrong with letter to num\n");
                free(lName);
                free(fName);
                free(pNum);
                free(contact);
                return NULL;

            }

        }

    }
    if (contNull == 1) {
        printf("The addition of the contact has failed!\n");
        //need to clean all alocated mem - done up when fail check
    }
    return NULL;
}

void cleanMem(struct Contact* phonebook[LETTERS]){
    Contact* ptrToNext = NULL;
    Contact* current = NULL;
    for (int letter = 0 ; letter<LETTERS ; letter++){
        if (phonebook[letter] != NULL){
            //we run with while untill end
            ptrToNext = phonebook[letter];
            while (ptrToNext != NULL){
                current = ptrToNext;
                ptrToNext = current->next;
                //delete fields
                free(current->lastName);
                free(current->firstName);
                free(current->phoneNum);
                free(current->next);
                free(current);

            }
            //set pointers from phone book to NULL
            phonebook[letter] = NULL;
        }

    }
    printf("cleared mem");

    //we run on all phonebook and free internal struct fields
    //then we clear the contact itself , while saving next ptr for acces

}

void deleteContact(struct Contact* phonebook[LETTERS]){
    char* fName = NULL;
    char* lName = NULL;
    char garbage;
    char usrYNchar = ' ';
    Contact* toDelete = NULL;
    Contact* oneBefore = NULL;
    Contact* temp = NULL;
    // deletion is by name and need to sure Y/N
    //first we locate me for the fields

    printf("Enter a contact name (<first name> <last name>):");
    fName = malloc(sizeof(char[11]));
    lName = malloc(sizeof(char[11]));
    scanf("%s %s",fName,lName);
    while ((garbage = getchar()) != '\n');
    printf("Are you sure? (y/n)");
    scanf("%c",&usrYNchar);
    //debug print
    printf("%c",usrYNchar);
    if (letterToNum(&usrYNchar) != 24){
        //means user entered not Y/y
        printf("The deletion of the contact has been canceled.");
        free(fName);
        free(lName);

    }
    else{
        //chose Y
        if (fName == NULL || lName == NULL){
            //one or more didnt get memory
            //so we print fail and exit.
            printf("The deletion of the contact has failed!\n");
            free(fName);
            free(lName);

            //need clean mallocs
        }
        else{
            //mem allocation worked now need to find the contact
            oneBefore = findByName(fName,lName,phonebook);
            printf ("onebefore = %p\n",oneBefore);
            //printf ("onebefore fname = %s\n",oneBefore->firstName);
            if (oneBefore == NULL){
                //name doesnt exist
                printf("The deletion of the contact has failed!\n");
                free(fName);
                free(lName);


            }
            else {

                //we got pointer to onbefore so its next is contact to delete
                //we set one b4.next to next of contact
                printf("line 541");
                printf (" this is lname0: %c",&lName[0]);
                if(  phonebook[letterToNum(&lName[0])] == oneBefore ){
                    //its head so we need to set
                    printf("line 544");
                    // we delete the head
                    toDelete = oneBefore;
                    if (phonebook[letterToNum(&lName[0])]->next != NULL) {
                        printf("571");
                        printContact(phonebook[letterToNum(&lName[0])]->next);
                        phonebook[letterToNum(&lName[0])] = toDelete->next;
                        //temp =
                        printContact(phonebook[letterToNum(&lName[0])]);
                    }
                    else {
                        printf("576");
                        phonebook[letterToNum(&lName[0])]= NULL;
                    }

                    free(toDelete->lastName);
                    free(toDelete->firstName);
                    free(toDelete->phoneNum);
                    free(toDelete->next);
                    free(toDelete);
                    free(fName);
                    free(lName);

                }
                else {
                    printf("line 547");
                    toDelete = oneBefore->next;
                    oneBefore->next = toDelete->next;
                    free(toDelete->lastName);
                    free(toDelete->firstName);
                    free(toDelete->phoneNum);
                    free(toDelete->next);
                    free(toDelete);
                    free(fName);
                    free(lName);
                }


                printf("finished free and delete contact");
            }

        }
    }
}

struct Contact* findByName(char* fName,char* lName,
        struct Contact* phonebook[LETTERS]){
    printf("504");
    int letter = letterToNum(&lName[0]);
    //debug print
    printf("lnameval[0]: %d", letter);
    Contact* current = NULL;
    Contact* oneBefore = NULL;

    if (phonebook[letter] == NULL){
        return  NULL;
    }
    else{
        // its not null - we need to check for name and lastname strcmp == 0
        current = phonebook[letter];


        while (current != NULL){
            oneBefore = current;
            // while still contact valid
            if ((strcmp(lName,current->lastName) == 0)&&                                //// bug here ////
                (strcmp(fName,current->firstName))==0 ){

                //we have a match so return one contact b4
                printf("returned from srch:");
                printContact(oneBefore);
                if (oneBefore == current){
                    // means we return phonebookhead
                    return phonebook[letter];
                }else{
                    return oneBefore;
                }
                                                                /// bug still here// problem is i cant clear it.

            }

            current = current->next;
        }
        return NULL;
    }

}

void printBook(struct Contact* phonebook[LETTERS]){
    Contact* current = NULL;
    //we loop throught all letter , if not null we enter with pointer
    for (int letter = 0 ; letter<LETTERS ; letter++){
        if (phonebook[letter] !=NULL){
            //we have something pointed to so we loop while
            current = phonebook[letter] ;
            while (current != NULL){
                printContact(current);
                current = current->next;
                }
            }
        }

}