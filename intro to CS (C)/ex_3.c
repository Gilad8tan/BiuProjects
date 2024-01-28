
#include <stdio.h>
#include <math.h>


/****************************************************************************
*function name: statePrinter
*The Input: int "ans" - 1 or -1 or other=0
*The output: does not output value
*The PrintOut: prints true / false / wrong input
*The Function operation: gets int from readWholeStatement or reafOneStatement
*then check the input and prints out the corrolated statement
****************************************************************************/
void statePrinter(int ans){
    if (ans == 1){
        printf("The statement is true.\n");
    }else {
        if( ans == -1){
            printf("The statement is false.\n");
        }else {
            printf("You have a syntax error in your statement.\n");
        }
    }
}

/****************************************************************************
*function name: readOneStatement
*The Input: NONE
*The output: int valued (-1 , 0 ,1 )
*The PrintOut: NONE
*The Function operation:scans input from user , in case user entered
* "correct" logical statement - returns true or false, case not "correct"
* returs 0 which is my wrong input output
****************************************************************************/
int readOneStatement(){
    char char1;
    int var1 = 0;
    int var2 = 0;
    int ans = 1;
    int not = 1;
    int open = 0;
    int close = 0;
    int validInpt = 1;
    // int var1Counter = 0;
    int operand = 0;
    // int var2Counter = 0;
    //nxt line used with only one statement , print went to readWholeStatement
    //printf("enter your statement: \n");
    //get first char
    scanf("%c",&char1);
    //debug print
    //printf("line 19 \n");
    //printf("char is :%c \n",char1);
    //read open
    if (((int)char1 !=40)&&((int)char1 != 126)){
        validInpt = 0;
        //debug print
        //printf("line 22\n");
        //printf("char is: %c\n",char1);
        //printf("int is: %d\n",char1);
    }
    if (validInpt == 1){
        //in case many not's or longer open
        while (( (int)char1== 40 || (int)char1== 126 )&&validInpt==1){
            //debug print
            //printf("line 26");
            //printf("char is: %c\n",char1);
            //printf("int is: %d\n",char1);
            if ((int)char1 == 40){
                if (open==0){
                open++;
                }else{
                    validInpt =0 ;
                    //debug print
                    // printf("line 79 gets invalid");
                }
            }
            else {
                //we just double not's 2 nots is a yes so -1*-1
                if ((int)char1 == 126){
                    not = not*(-1);
                }
            }
            //debug print
            //printf("line 41 we getchar");
            char1 = getchar();
        }
        //debug print
        //printf("line 42");

        // now we extract the first value
        //while not operand , keep reading
        while (((int)char1 != 60 )&&((int)char1 != 61 )&&((int)char1 != 62 )&&validInpt==1 ){
            //debug print
            //printf("line 93");
            //printf("char is: %c\n",char1);
            //printf("int is: %d\n",char1);
            //printf ("valid is : %d",validInpt);

            //if big letter
            if (64<(int)char1 && (int)char1<91  ){
                var1 = (int)char1+32;
                char1 = getchar();
            }else{
                if (96<(int)char1 && (int)char1<123){
                    var1 = (int)char1;
                    char1 = getchar();
                }else{
                    if (47<(int)char1 && (int)char1<58){
                        var1 =  (var1*10) + ((int)char1-48);
                        //debug print
                        //printf("var1 is : %d\n",var1);
                        //var1Counter++;
                        char1 = getchar();
                    }else {
                        //debug print
                        //printf("line 57 invalid inpt");
                        validInpt = 0;
                        //char1 = getchar();
                    }
                }
            }
        }
        //now we read operand

        //debug print
        //printf("line 71 \n");
        //printf("char is: %c\n",char1);
        //printf("int is: %d\n",char1);


        if ((int)char1 == 60){
            operand = 1;
        }else {
            if ((int)char1 == 61){
                operand = 2;
            }else {
                if ((int)char1 == 62){
                    operand = 3;
                }
                else {
                    validInpt = 0;
                    //debug print
                    //printf("line 85 invalid inpt");
                }
            }
        }
        char1 = getchar();
        //debug print
        //printf("line 88 \n");
        //printf("char is: %c\n",char1);
        //printf("int is: %d\n",char1);

        //now we read 2nd val up untill char = ) closing bracket
        while (((int)char1 != 41) && (validInpt==1) ){
            //debug print
            //printf("line 90 \n");
            //printf("char is: %c\n",char1);
            //printf("int is: %d\n",char1);

            //if big letter
            if (64<(int)char1 &&(int)char1<91  ){
                var2 = (int)char1+32;
                char1 = getchar();
            }else{
                //if small letter
                if (96<(int)char1 && (int)char1<123){
                    var2 = (int)char1;
                    char1 = getchar();
                }else{
                    //if numbers
                    if (47<(int)char1&& (int)char1<58){
                        var2 =  (var2*10) + ((int)char1-48);
                        //debug print
                        // var2Counter++;
                        // printf("var2counteris:%d\n",var2Counter);
                        //printf("var2 is:%d\n",var2);
                        char1 = getchar();
                    }else {
                        validInpt = 0;
                        char1 = getchar();
                    }
                }
            }
        }
        //debug print
        //printf("line 116 \n");
        //printf("char is: %c\n",char1);
        //printf("int is: %d\n",char1);
        if ((int)char1 != 41 ){
            validInpt = 0;
            //debug print
            //printf("line 126 invalidinpt\n");
            //printf("int is: %d\n",char1);
        }else{
            //its a closing bracket
            close++;
        }
        // now for the operation goes in only if valid inpt
        if(validInpt == 1){
            //debug print
            //printf("line 128\n");

            // operand=1  is <
            if (operand ==1){
                if(var2-var1>0){
                    ans = 1;
                }
                else{
                    ans = -1;
                }
            }else{
                // operand=2  is =
                if (operand ==2){
                    if (var1-var2 == 0){
                        ans = 1;
                    }else{
                        ans = -1;
                    }
                }else {
                    // operand=3  is >
                    if (var1-var2 > 0){
                        ans = 1;
                    }else{
                        ans = -1;
                    }
                }
            }
        }
        //debug print
        //printf("line 152 \n");
        //printf("var1 is: %d\n",var1);
        //printf("var2 is: %d\n",var2);
        //printf("op is: %d\n",operand);



    }
    //if valid inpt and all open brackets closed
    if (validInpt ==1 && open-close==0){
        return ans*not;
    }
    else {
        //clear buffer till space or EOL EOF
        while (char1!= '\n' && char1 != EOF && (int)char1!=32 ){
            //printf("char is:%c\n",char1);
            char1 = getchar();
            //printf("char is:%c\n",char1);
            continue;
        }

        return 0;
    }

}

/****************************************************************************
*function name: readWholeStatement
*The Input: NONE
*The output: int valued (-1 false , 0 wrong inpt ,1 true )
*The PrintOut: NONE
*The Function operation:scans input from user , in case user entered
* one "correct" logical statement - uses readOneStatement
* returns true or false or returns 0 which is  wrong input
* if more then one statement is entered :
* checks each statement using readOneStatement,
* reads the operand between each statement ,
* loops until EOF or EOI symbol , every time saves val1 as last answer
* and check next and current answer based on operand between statements.
****************************************************************************/
int readWholeStatement(){
    char ch;
    int val1,val2;
    int operator = 0;
    printf("\nPlease write your logical statement: ");
    val1 = readOneStatement();
    //if wrong input
    if (val1 == 0){
        return 0;
    }else {
        //right input for 1 statement
        ch = getchar();
        if (ch == '\n' || ch == ' ' || ch == EOF) {
            return val1;
            //if we didnt finish reading
        } else {
            while (ch != '\n' && ch != ' ' && ch != EOF ) {
                //if operator is &
                if ((int) ch == 38) {
                    operator = 1;
                } else {
                    //if operator is |
                    if ((int) ch == 124)
                        operator = 2;
                }
                val2 = readOneStatement();
                // if valid input on 2nd statement
                if (val2 != 0){
                    //now we calculate by operator
                    if(operator == 1){
                        if(val1== 1 && val2 == 1){
                            val1 = 1;
                        }
                        else{
                            val1 = -1;
                        }
                    }else{
                        if(operator ==2){
                            if(val1 ==-1 && val2 ==-1){
                                val1 = -1;
                            }
                            else{
                                val1 = 1;
                            }
                        }
                    }
                }
                ch = getchar();
            }
            return val1;

        }
    }}



/****************************************************************************
*function name: gcd
*The Input: int num1, int num2
*The output: NONE
*The PrintOut: prints every calculation on the euclidian gcd algo
*The Function operation:   *RECURSIVE* checks which num is bigger ,
*then checks how many times the smaller num is in the bigger one , and
*calculates the remainder ,then passes these numbers to another recursive call
*when remainder is 0 - prints GCD
****************************************************************************/
void gcd(int num1, int num2){
    int remainder =0;
    int modul = 0;
    int num11,num22;

    //special cases
    if(num1==0 && num2==0){
        printf("GCD = 0\n");
    }
    else{
        if(num1==0){
            printf("GCD = %d\n",num2);
        }
        else{
            if(num2==0){
                printf("GCD = %d\n",num1);
            }else{
                //ifs - so num 1 is the biggest
                if (num1>=num2) {
                     num11 = num1;
                     num22 = num2;
                }
                else {
                     num11 = num2;
                     num22 = num1;
                }
                //now we know num11 is biggest so we start calculation
                remainder = num11%num22;
                modul = (int)num11/num22;
                printf("%d*%d+%d = %d (num1=%d, num2=%d)\n",num22,modul,remainder,num11,num11,num22);
                gcd(num22 , remainder);

            }
        }
    }


}


/****************************************************************************
*function name: prntMenu
*The Input: NONE
*The output: NONE
*The PrintOut: function to print menu items by the instructions.
*The Function operation:prints line by line the menu
****************************************************************************/
void prntMenu(){
    printf("Choose an option:\n");
    printf("\t1: Logical Statement Calculator\n");
    printf("\t2: Count digit in a number\n");
    printf("\t3: GCD Calculator\n");
    printf("\t4: Exit\n");
}


/****************************************************************************
*function name: digitCheck
*The Input: long num , short int digit
*The output: int - number of occurrences of digit in num
*The PrintOut: NONE
*The Function operation: *RECURSIVE* calculates occurrences of digit in num
*checks if lsd is same as digit if so , passes +1 and removes lsd ->recursion
*if not , checks next lsd untill num is 0
****************************************************************************/
int digitCheck(long long num ,  int digit){

    //this means last digit
    if (num < 10) {
      if(digit == num%10){
          return 1;
        }else{
          return 0;
      }
    }
    //case were not at the last digit we remove lsd and continue
    if (num%10==digit ){
        return 1+ digitCheck((int)num/10,digit);
    }
    else {
        return digitCheck((int)num/10,digit);
    }
}


/****************************************************************************
*function name: userChoice
*The Input: NONE
*The output: int - number of users choice for menu
*The PrintOut: NONE
*The Function operation: reads user input , only 1 char ,
* in case valid option - clears the buffer and returns the choice
* case invalid - clears buffer and returns -1 so we know invalid inpt
****************************************************************************/
int userChoice(){
    int returner;
    char char1 = ' ';
    scanf("%c",&char1);
    //in case we get a char as input - we clear the eof input from buffer

    //debug print
    //printf("char is:%c",char1);

    //user chose 1
    if ((int)char1 == 49){
        returner= 1;
    }else{
        //user chose 2
        if ((int)char1 == 50){
            returner= 2;
        }else{
            //user chose 3
            if ((int)char1 == 51){
                returner= 3;
            }else {
                //user chose 4 - bye
                if ((int)char1 == 52){
                    returner= 4;
                }
                //user entered wrong dogit or char
                else {
                    returner= -1;
                }
            }
        }
    }
    //clear the buffer till next input
    while (char1 != ' ' && char1 != '\n' && char1!=EOF ){
        char1 = getchar();
        //printf("l457 char is:%c",char1);
        continue;
    }
    //char1 = getchar();
    return returner;

}

/****************************************************************************
*function name: invalidInpt
*The Input: NONE
*The output: NONE
*The PrintOut: 3 sentences given to output in case wrong choice in menu
*The Function operation: prints line by line the given sentences for print
****************************************************************************/
void invalidInpt(){
    printf("Fool of a Took!\n");
    printf("This is a serious journey, not a hobbit walking-party.\n");
    printf("Throw yourself in next time, and then you will be no further nuisance.\n");
}
/****************************************************************************
*function name: choice1
*The Input: NONE
*The output: NONE
*The PrintOut: prints out the answer for entered logical statement
*The Function operation: uses readWholeStatement output int for input to print
****************************************************************************/
void choice1(){
    statePrinter(readWholeStatement());
}

/****************************************************************************
*function name: choice2
*The Input: NONE
*The output: NONE
*The PrintOut: invalid input or number of occurrences of digit in num
*The Function operation:asks for a number ,gets input, checks valid input
*then passes to digitCheck function for calculation
*clears buffer and prints answer .
****************************************************************************/
void choice2(){
    long long int num = 0;
    int digit = 0;
    char char1 =' ';
    printf("\nEnter a number and a digit: ");
    scanf("%lld %d",&num,&digit);
    //buffer clearer till EOF
    while ((char1=getchar()) != '\n' && char1 != EOF && char1!=' '){
        continue;
    }
    //debug print
    //printf("num is: %lli\n",num);
    //printf("dig is: %d\n",digit);

    //if wrong input
    if(num<0 || digit<0 || digit>9){
        printf ("You should stay positive, and so should your input.\n");
    }
    //return calculation
    else {
        printf("The digit %d appears %d times in the number %lld\n",digit,digitCheck(num , digit),num);
    }
}


/****************************************************************************
*function name: choice3
*The Input: NONE
*The output: NONE
*The PrintOut: invalid input or gcd printouts
*The Function operation:asks for 2 numbers ,gets input, checks valid input
*then passes to gcd function for calculation
*clears buffer gets prints from gcd
****************************************************************************/
void choice3(){
    int num1,num2;
    char char1;
    printf("\nEnter two positive numbers: ");
    scanf("%d%d",&num1,&num2);
    //buffer clean
    while ((char1=getchar()) != '\n' && char1 != EOF && char1!=' '){
        continue;
    }
    if (num1<0 || num2<0){
        printf("You should stay positive, and so should your input.\n");
    }
    else {
        gcd(num1,num2);
    }
}




/****************************************************************************
*function name: choiceHandler
*The Input: int menuChoice - from user menu choice
*The output: int - 1 for exit 2 for invalid , else runs function chioce
*The PrintOut: NONE
*The Function operation:gets user input from menuChoice
*if choice is to run a task - runs the task
*else returns special value to kill the main loop
****************************************************************************/
int choiceHandler(int menuChoice){
    if (menuChoice==1){
        choice1();
    }
    else {
        if(menuChoice == 2){
            choice2();
        }
        else{
            if (menuChoice == 3){
                choice3();
            }
            else{
                if(menuChoice == 4){
                    return 1;
                }
                else {
                    invalidInpt();
                    return 2;
                }
            }
        }
    }
}








/****************************************************************************
*function name: main
*The Input: NONE
*The output: 0
*The PrintOut: calls printmenu ,
 * if menu choice 4 - print goodbye statement
* else  passes the choice to handling function
*The Function operation: loops as long not exit(4)
 * prints menu , waits for choice .
****************************************************************************/
int main() {
    int menuChoice = 0;
    int exitChoice = 0;
    int exception = 0;
    //while user didnt choose to exit
    while(exitChoice!=1 && menuChoice!=-1){
        //print menu
        prntMenu();
        menuChoice=userChoice();
        //in case we get 4 or wrong input
        exception=choiceHandler(menuChoice);
        if (exception ==1){
            exitChoice = 1 ;
        }
        else {
            //wrong input , we reset choice and exception and re loop
            if (exception == 2){
                menuChoice =0 ;
                exception = 0;
            }
        }
        }

    printf("So Long, and Thanks for All the Fish!");

    return 0;
}
