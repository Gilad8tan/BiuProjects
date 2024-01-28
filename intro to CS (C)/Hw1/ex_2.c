/******************************************
* Student name: Gilad Eitan
* Student ID:311810030
* Submit sys ID:eitangi
* Exercise name: Exercise 2
******************************************/
#include <stdio.h>
#include <math.h>


int main() {
    int inptNum1=0;                                  //menu user input
    #define DECDIGIT 10
    #define ZERO 0
    #define ONE 1

    while (inptNum1!=7){                             //case not : BYE!
        printf("Choose an option:\n");        // print out menu
        printf("1. octal to hex\n");
        printf("2. binary addition\n");
        printf("3. print HI\n");
        printf("4. count bits\n");
        printf("5. decimal to binary\n");
        printf("6. Zig-Zag bits\n");
        printf("7. exit\n");
        scanf("%d",&inptNum1);
        //printf("num entered is: %d",inptNum1);    //debug printout

        if (inptNum1<=ZERO || inptNum1>7){             //if menu input is invalid
            inptNum1=ZERO;                             // reset choice
            printf("Invalid option!\n");     //printout invalid..
        }
        else {                                      // input is valid - we use 6 different if's
            /*CHOICE 1: well check user input is valid (digits up to7)
             * we translate every octal num to 3bit binary
             * we add em up , then take out 4 bits for hex representation
             * we translate using if's
             * we print solution
             */
            if (inptNum1==ONE){                       //choice is 1
                inptNum1 = ZERO;                       //reset choice so when finished goes back to loop
                int usrInpt;                        // int for user rntered octal number
                long long int binNum=ZERO;             // saves the binary number
                int digit;                          //last digit proccesed
                short int validInpt=ONE;              //start with valid inpt assumption
                int counter=ZERO;                      //digit counter
                #define MOVE3BITS 1000
                printf("Please enter number in octal base: ");
                scanf("%d",&usrInpt);
                // printf("%d\n", binNum);
                while(usrInpt!=ZERO && validInpt!=ZERO){  //loop to translate oct digit to 3bit binary
                                                    //works untill invalid input or no more input
                    digit = usrInpt%DECDIGIT;
                    if (digit==ZERO){
                        binNum = (binNum*MOVE3BITS)+ZERO;
                    }
                    if (digit==1){
                        binNum = (binNum*MOVE3BITS)+1;
                    }
                    if (digit==2){
                        binNum = (binNum*MOVE3BITS)+10;
                    }
                    if (digit==3){
                        binNum = (binNum*MOVE3BITS)+11;
                    }
                    if (digit==4){
                        binNum = (binNum*MOVE3BITS)+100;
                    }
                    if (digit==5){
                        binNum = (binNum*MOVE3BITS)+101;
                    }
                    if (digit==6){
                        binNum = (binNum*MOVE3BITS)+110;
                    }
                    if (digit==7){
                        binNum = (binNum*MOVE3BITS)+111;
                    }
                    counter++;

                    usrInpt=(int)(usrInpt/DECDIGIT);          //remove last digit from input
                    // printf("%d\n",binNum);           //debug printout
                    if (digit>7){                       //check to see octal number only
                        validInpt = ZERO;
                    }


                }
                if (validInpt==ONE){                      //no non octal digits so now we translate
                    //
                    while(counter!=ZERO && binNum!=ZERO) {      //as long we have digits left
                        counter--;
                        int digits = (pow(10000,counter)); // calculate how many 4 bit digits we have
                        digit = (int)(binNum/digits);            //start with last digit
                        //printf("binnum: %d\n",binNum);         //debug printout
                        // printf("digit: %d\n",digit);
                        //  printf("bunumtodigits: %d\n",(int)(binNum/digits));
                        if (digit==ZERO && (binNum/digits)!=ZERO){ //  && in case binum is empty
                            printf("0");

                        }                                  // whole if part is translation to hex by 4 bits
                        if (digit==1){
                            printf("1");

                        }
                        if (digit==10){
                            printf("2");

                        }
                        if (digit==11){
                            printf("3");

                        }
                        if (digit==100){
                            printf("4");

                        }
                        if (digit==101){
                            printf("5");

                        }
                        if (digit==110){
                            printf("6");

                        }
                        if (digit==111){
                            printf("7");

                        }
                        if (digit==1000){
                            printf("8");

                        }
                        if (digit==1001){
                            printf("9");

                        }
                        if (digit==1010){
                            printf("A");

                        }
                        if (digit==1011){
                            printf("B");

                        }
                        if (digit==1100){
                            printf("C");

                        }
                        if (digit==1101){
                            printf("D");

                        }
                        if (digit==1110){
                            printf("E");

                        }
                        if (digit==1111){
                            printf("F");

                        }
                        binNum = binNum%digits;     // remove the msb letter

                    }
                    printf("\n");               // for output new line
                }
                else{                                   // if was invalid input
                    printf("Invalid input!\n");



                }

            }
            /*CHOICE 2:
             * checks input is binary (only 1's and 0's)
             * recieves 2 binary number, if one is shorter -pads with zeros
             * performs addition by add and carry rules
             * prints input1 + input 2 = calculated expression
             *
             */
            if (inptNum1==2){
                inptNum1 = ZERO;
                unsigned long long num1 = ZERO;
                unsigned long long num2 = ZERO;
                unsigned long long cpyNum =ZERO;
                int digitsNum1 = ZERO;
                int digitsNum2 = ZERO;
                int padding = ZERO;
                short int validInpt = 1;
                int counter = ZERO;
                printf("Please enter two binary numbers: ");
                scanf("%llu",&num1);
                scanf("%llu",&num2);
                //check legal input and count digits
                for (cpyNum=num1;cpyNum!=ZERO;cpyNum=cpyNum/DECDIGIT) {     //counts digits on inpt1 and check validity
                    if (1<cpyNum%DECDIGIT || cpyNum%DECDIGIT<ZERO){
                        validInpt=ZERO;
                    }
                    digitsNum1++;
                }
                for (cpyNum=num2;cpyNum!=ZERO;cpyNum=cpyNum/DECDIGIT) {     //counts digits on inpt2 and check validity
                    if (1<cpyNum%DECDIGIT || cpyNum%DECDIGIT<ZERO){
                        validInpt=ZERO;
                    }
                    digitsNum2++;
                }
                if (digitsNum1>=digitsNum2){  //if num1 bigger - we change places so now num 2 is bigger
                    cpyNum=num2;
                    num2=num1;
                    num1=cpyNum;
                    padding= digitsNum1-digitsNum2;
                }
                else {   // we know num 2 is bigger
                    padding = digitsNum2-digitsNum1;
                }
                if (num1==ZERO){
                    padding--;
                }
                //printf("padding: %d",padding);
                if (validInpt==ONE){

                    for (int i=padding;i!=ZERO;i--){        //padding for smaller num
                        printf("0");
                    }

                    printf("%llu",num1);            //print format asked
                    printf(" ");
                    printf("+");
                    printf(" ");
                    printf("%llu",num2);
                    printf(" ");
                    printf("=");
                    printf(" ");

                    int carry=ZERO;
                    cpyNum=ZERO;
                    while( num2!=ZERO){    // still remaining digits
                        if (num1%DECDIGIT==ZERO && num2%DECDIGIT==ZERO){  // both zero
                            if(carry==ZERO){

                            }else{  // carry is 1
                                cpyNum = (cpyNum+(1*pow(DECDIGIT,counter)));
                                carry = ZERO;
                            }

                        }else{
                            if(num1%DECDIGIT==ZERO && num2%DECDIGIT==ONE){
                                if(carry==ZERO){
                                    cpyNum = cpyNum+(1*pow(DECDIGIT,counter));
                                }else{
                                    //printf("went here");

                                }

                            }else{
                                if(num1%DECDIGIT==ONE && num2%DECDIGIT==ZERO){
                                    if(carry==ZERO){
                                        cpyNum = cpyNum+(1*pow(DECDIGIT,counter));
                                    }else{

                                    }
                                }else{
                                    if(num1%DECDIGIT==ONE && num2%DECDIGIT==ONE){
                                        if(carry==ZERO){

                                            carry = 1;
                                        }else{
                                            cpyNum = cpyNum+(1*pow(DECDIGIT,counter));
                                        }}
                                }
                            }



                        }
                        //printf("cpynum:%llu\n", cpyNum);
                        //printf("carry:%d\n", carry);
                        counter++;
                        num1 = num1/DECDIGIT;
                        num2 = num2/DECDIGIT;
                        //printf("1:%llu\n", num1);
                        //printf("2:%llu\n", num2);

                    }
                    if (carry==ONE){                                        //in case numbers=0 and still 1 in carry
                        cpyNum = cpyNum+(1*(pow(DECDIGIT,counter)));
                    }
                    printf("%llu\n", cpyNum);


                }
                else{
                    printf("Invalid input!\n");
                }






            }
            /* CHOICE 3:
             * prints out HI with internal size of given input
             * i just broke it to 7 segments :
             * 1 and 7 only # and spaces
             * 2 and 6 internal with spaces
             * 3 and 5 outer internal with *
             * 4 only * inside no spaces
             */
            if (inptNum1==3){
                inptNum1 = ZERO;
                unsigned int inpt;
                printf("Please enter size: ");
                scanf("%u",&inpt);
                if(inpt>=ZERO){                              //first segment - no outer loop
                    {for (int i=inpt+2;i!=ZERO;i--){
                            printf("#");
                        }
                        for (int i=inpt+1;i!=ZERO;i--){
                            printf(" ");
                        }
                        for (int i=inpt+2;i!=ZERO;i--){
                            printf("#");
                        }
                        printf(" ");
                        printf(" ");
                        for (int i=inpt+2;i!=ZERO;i--){
                            printf("#");
                        }}
                    printf("\n");
                    {for (int i=inpt;i!=ZERO;i--){             //2nd segment , dual loop
                            printf("#");
                            for(int j =inpt;j!=ZERO;j--){
                                printf("*");
                            }
                            printf("#");
                            for(int j =inpt+1;j!=ZERO;j--){
                                printf(" ");
                            }
                            printf("#");
                            for(int j =inpt;j!=ZERO;j--){
                                printf("*");
                            }
                            printf("#");
                            printf(" ");
                            printf(" ");
                            printf("#");
                            for(int j =inpt;j!=ZERO;j--){
                                printf("*");
                            }
                            printf("#\n");
                        }}
                    printf("#");                  //3rd segment - only line no outer loop
                    for (int i=inpt;i!=ZERO;i--){
                        printf("*");
                    }
                    for (int i=inpt+3;i!=ZERO;i--){
                        printf("#");
                    }
                    for (int i=inpt;i!=ZERO;i--){
                        printf("*");
                    }
                    printf("#");
                    printf(" ");
                    printf(" ");
                    printf("#");
                    for (int i=inpt;i!=ZERO;i--){
                        printf("*");
                    }
                    printf("#\n");
                    for (int i=inpt;i!=ZERO;i--){              //4th segment dual loop
                        printf("#");
                        for(int j =(inpt*3)+3;j!=ZERO;j--){
                            printf("*");
                        }
                        printf("#");

                        printf(" ");
                        printf(" ");
                        printf("#");
                        for(int j =inpt;j!=ZERO;j--){
                            printf("*");
                        }
                        printf("#\n");
                    }
                    printf("#");            // 5th same as 3rd
                    for (int i=inpt;i!=ZERO;i--){
                        printf("*");
                    }
                    for (int i=inpt+3;i!=ZERO;i--){
                        printf("#");
                    }
                    for (int i=inpt;i!=ZERO;i--){
                        printf("*");
                    }
                    printf("#");
                    printf(" ");
                    printf(" ");
                    printf("#");
                    for (int i=inpt;i!=ZERO;i--){
                        printf("*");
                    }
                    printf("#\n");
                    {for (int i=inpt;i!=ZERO;i--){             //6th segment , dual loop same as 2nd
                            printf("#");
                            for(int j =inpt;j!=ZERO;j--){
                                printf("*");
                            }
                            printf("#");
                            for(int j =inpt+1;j!=ZERO;j--){
                                printf(" ");
                            }
                            printf("#");
                            for(int j =inpt;j!=ZERO;j--){
                                printf("*");
                            }
                            printf("#");
                            printf(" ");
                            printf(" ");
                            printf("#");
                            for(int j =inpt;j!=ZERO;j--){
                                printf("*");
                            }
                            printf("#\n");
                        }}
                    for (int i=inpt+2;i!=ZERO;i--){             //7th segment same as 1st
                        printf("#");
                    }
                    for (int i=inpt+1;i!=ZERO;i--){
                        printf(" ");
                    }
                    for (int i=inpt+2;i!=ZERO;i--){
                        printf("#");
                    }
                    printf(" ");
                    printf(" ");
                    for (int i=inpt+1;i!=ZERO;i--){
                        printf("#");
                    }
                    printf("#\n");



                }
                else{
                    printf("Invalid input!\n");
                }


            }

            /*CHOICE 4:
             * checks input chars are only 1,0
             * counts 1 in the number , decreases by char
             * prints total counted number
             */
            if (inptNum1==4){
                inptNum1 = ZERO;
                int digitCount=ZERO;
                unsigned long long inpt=ZERO;
                short int validInpt=ONE;
                printf("Please enter a binary number: ");
                scanf("%llu",&inpt);
                while(inpt!=ZERO){
                    if (inpt%DECDIGIT==ONE){
                        digitCount++;
                    }
                    if (inpt%DECDIGIT!=ZERO && inpt%DECDIGIT!=ONE ){ //valid input check
                        validInpt = ZERO;
                    }
                    inpt = (int)inpt/DECDIGIT;              //remove one char
                }
                if(validInpt==ONE){                       // prints number of 1's
                    printf("%d\n",digitCount);
                }
                else {                                  //propably one char was non 1,0
                    printf("Invalid input!\n");
                }

            }

            /*CHOICE 5:
             * checks input is non negative
             * checks mod 2 on digit , if =1 then next digit in binary is 1
             * uses divide by 2 in a while loop and adds up the digits in reversed order
             * if input correct : prints out inpt => binary
             *
             */
            if (inptNum1==5){
                inptNum1 = ZERO;
                long long int binNum=ZERO;
                int inptCpy;
                short int validInpt = 1;
                int inpt=ZERO;
                int digitCounter = ZERO ;
                printf("Enter a non negative decimal number: ");
                scanf("%d",&inpt);
                if(inpt<ZERO){
                    validInpt =ZERO;
                }
                if (validInpt ==ONE){
                    inptCpy = inpt;             //copy so no ovveride on inpt
                    while(inptCpy!=ZERO){          //still digits remaining or remainder
                        if (inptCpy%2==ONE){          // if 1 then add next msb to the left
                            binNum = binNum+(1*(pow(DECDIGIT,digitCounter)));
                        }
                        inptCpy = (int)inptCpy/2;       //perform division
                        digitCounter++;                 //keeps count of digits to move while mod ==0

                    }
                    printf("%d => %lli\n",inpt,binNum);
                }
                else{
                    printf("Invalid input!\n");
                }
            }

            /*CHOICE 6:
             * checks input is non negative
             * use choice 6 algo to translate decimal to binary
             * then , pass the binary num through zig zag check
             *
             */
            if (inptNum1==6){
                inptNum1 = ZERO;
                long long int binNum=ZERO;
                int inptCpy;
                short int validInpt = 1;
                int inpt=ZERO;
                int digitCounter = ZERO ;
                int last =ZERO;
                short int zigZag=ONE;
                printf("Enter a non negative decimal number: ");
                scanf("%d",&inpt);
                if(inpt<ZERO){
                    validInpt =ZERO;
                }
                if (validInpt ==ONE){
                    inptCpy = inpt;
                    while(inptCpy!=ZERO){
                        if (inptCpy%2==ONE){
                            binNum = binNum+(1*(pow(DECDIGIT,digitCounter)));
                        }
                        inptCpy = (int)inptCpy/2;
                        digitCounter++;

                    }
                }
                while(binNum!=ZERO){               //chars remaining
                    last = binNum%DECDIGIT;
                    if ((binNum/DECDIGIT)%DECDIGIT==last){      //checks last digit and one before
                        zigZag = ZERO;                             //if 2 same digits in a row - not zigzag
                    }
                    binNum = binNum/DECDIGIT;

                }
                if(zigZag==ONE && validInpt==ONE){
                    printf("true\n");
                }
                else if(zigZag==ZERO && validInpt==ONE){
                    printf("false\n");
                }
                else {
                    printf("Invalid input!\n");
                }
            }
        }
    }
    printf("Bye!\n");                          //CHOICE 7: print bye and end program
    return ZERO;

}
