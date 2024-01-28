

#include <stdio.h>



/****************************************************************************
*function name: chInputCheck
*The Input: none
*The output: returns 1 for Y and -1 for N , 0 if else

*The Function operation: reads char from user and decides what it is y/n
****************************************************************************/
int chInputCheck() {

    #define NO (-1)
    #define YES 0
    #define WRONG 1
    char inputChar;
    int ans= 0;
    scanf(" %c",&inputChar);

    //printf("inchar is: %c",inputChar);

    if (inputChar == 'n' || inputChar == 'N'){
        // so we finish
        ans = NO;
    }
    else{
        if (inputChar != 'Y' && inputChar != 'y') {
            ans = YES;
        }
        else {
        ans = WRONG;
        }
    }
    //we clear spaces and other unnecessary chars
    while( inputChar =getchar() != '\n' && inputChar!=EOF ){
        continue;
        //printf("inptch : %c", inputChar);
    }
    //printf("inptch : %c", inputChar);
    return ans;
}
/****************************************************************************
*function name: buffClean
*The Input: none
*The output: none
*The Function operation: reads stdin buffer until end
****************************************************************************/
void buffClean(){
    char a;
    while ( a=getchar() !='\n' &&  a!=EOF){
        continue;
    }
}
/****************************************************************************
*function name: inRangeCheck
*The Input: int a,b,c standing for board row col
*The output: 1 if input in range , 0 else
*The Function operation: checks if input in range of board
****************************************************************************/
int inRangeCheck( int a,int b ,int c){
    #define FALSE 0
    #define TRUE 1
    #define LOWRANGE 0
    #define HIGHRANGE 3
    if ((LOWRANGE<=a && a<=HIGHRANGE) && (LOWRANGE<=b && b<=HIGHRANGE)
    && (LOWRANGE<=c && c<=HIGHRANGE)){
        return TRUE;
    }else{
        return FALSE;
    }
}
/****************************************************************************
*function name: isfreecheck
*The Input: int a,b,c standing for board row col and arr for board
*The output: 1 if clear 0 if not

*The Function operation: checks if arr[given location] == unassigned to X or O
****************************************************************************/
int isFreeCheck(int arr[] , int a ,int b , int c){
    #define BOARD 16
    #define ROW 4
    #define EMPTY 0
    #define FALSE 0
    #define TRUE 1
    //printf("arr char checked: %d", arr[(a*16)+(b*4)+c]);
    if (arr[(a*BOARD)+(b*ROW)+c] == EMPTY){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
/****************************************************************************
*function name: movecheck
*The Input: int a,b,c standing for board row col and arr for board
*The Function operation: runs inRangecheck and then isFreeCheck
 * if both true - returns 1 else
****************************************************************************/
int moveCheck(int arr[] , int a ,int b , int c){
    #define FALSE 0
    #define TRUE 1
    if (inRangeCheck(a,b,c) == TRUE){
        if (isFreeCheck(arr,a,b,c) == TRUE){
            return TRUE;
        }

    }
    else return FALSE;
}


/****************************************************************************
*function name: rowCheck
*The Input: int a,b,c for board,row,col and arr for board
*The output: 1 if win on row 0 else
*The PrintOut: NONE
*The Function operation: check if whole row is X or O
 * if so return 1 which is win 0 else
****************************************************************************/
int rowCheck(int arr[] , int a , int b, int c){
    #define BOARD 16
    #define ROW 4
    #define EMPTY 0
    #define FALSE 0
    #define TRUE 1
    if (arr[(a * BOARD) + (b * ROW) +0] == arr[(a * BOARD) + (b * ROW) + 1] ==
    arr[(a * BOARD) + (b * ROW) + 2] == arr[( a * BOARD )+( b * ROW) + 3]){
        return TRUE;
    }else
    {
        return FALSE;
    }
}
/****************************************************************************
*function name: colCheck
*The Input: int a,b,c for board,row,col and arr for board
*The output: 1 if win on col 0 else
*The PrintOut: NONE
*The Function operation: check if whole column is X or O
 * if so return 1 which is win 0 else
****************************************************************************/
int colCheck(int arr[] , int a , int b, int c){
    #define BOARD 16
    #define ROW 4
    #define EMPTY 0
    #define FALSE 0
    #define TRUE 1
    if (arr[( a * BOARD ) + ( b * 0) + c] == arr[( a * BOARD ) + (b * 1) + c]
    == arr[( a * BOARD ) + ( b * 2) + c] == arr[( a * BOARD ) + (b * 3) + c]){
        return TRUE;
    }else
    {
        return FALSE;
    }
}
/****************************************************************************
*function name: diagonalCheck
*The Input: int a,b,c for board,row,col and arr for board
*The output: 1 if win on diagonal  0 else
*The PrintOut: NONE
*The Function operation: check corners of board , if they are not 0,
 * we check the rest of cells in diagonal
 * return 1 for true or 0 for false
****************************************************************************/
int diagonalCheck(int arr[] , int a , int b, int c){
    #define BOARD 16
    #define ROW 4
    #define EMPTY 0
    #define FALSE 0
    #define TRUE 1
    #define BOARDRIGHTCORNER arr[ ( a * BOARD ) + 3 ]
    #define BOARDLEFTCORNER arr[a * 16]
#define ROW1 (b*0)
#define ROW2 (b*1)
#define ROW3 (b*2)
#define ROW4 (b*3)
#define COL1 (0)
#define COL2 (1)
#define COL3 (2)
#define COL4 (3)
    //first check if diagonal is possible by new move
    //regular slash / diagonal
    //printf("diag test");
    //printf("arr in corner is :%d",arr[(a*16)+3]);
    if (BOARDRIGHTCORNER != EMPTY){
        //then we check whole diagonal
        if (arr[(a * BOARD )+ ROW2 + COL3] == arr[( a * BOARD ) + ROW3 + COL2 ]
         == arr[( a * BOARD ) + ROW4 + COL1 ]
         == arr[( a * BOARD )+ ROW1 + COL4 ]){
            printf("phph1");
            return TRUE;
        }
    //now check backslash diagonal corner
    }
    else {
        //printf("diag test");
        //printf("arr in corner is :%d",arr[(a*16)]);
        if (BOARDLEFTCORNER != EMPTY) {
            if (arr[(a * BOARD) + ROW2 + COL2] ==
                arr[(a * BOARD) + ROW3 + COL3] ==
                arr[(a * BOARD) + ROW4 + COL4] ==
                arr[(a * BOARD) + ROW1 + COL1]) {
                //printf("phph2");
                return TRUE;
            }else{
                return FALSE;
            }
        }
        else {
            //printf("wentotelse");
            return FALSE;
        }
    }

}
/****************************************************************************
*function name: cubeDiagonalCheck
*The Input: int a,b,c for board,row,col and arr for board
*The output: 1 if win on 3d diagonal 0 else
*The PrintOut: NONE
*The Function operation: if whole 3d diagonal is same (X or O)
 * returns true else 0
****************************************************************************/
int cubeDiagonalCheck(int arr[] , int a , int b, int c){
#define TRUE 1
#define FALSE 0
#define EMPTY 0
#define DIAG1 (arr[3] == arr[22] == arr[41] == arr[60])
#define UPCORNERRIGHT arr[3]
#define DIAG2 (arr[0] == arr[21] == arr[42] == arr[63])
#define UPCORNERLEFT arr[0]
#define DIAG3 (arr[15] == arr[26] == arr[37] == arr[48])
#define UPCORNER2RIGHT arr[15]
#define DIAG4 (arr[12] == arr[25] == arr[38] == arr[51])
#define UPCORNER2LEFT arr[12]

    // firs we check if its even possible (existing corner on a=0 or a=3)
    if (DIAG1 && UPCORNERRIGHT !=EMPTY){
        return TRUE;
    }
    if (DIAG2 && UPCORNERLEFT !=EMPTY){
        return TRUE;
    }
    if (DIAG3 && UPCORNER2RIGHT  !=EMPTY){
        return TRUE;
    }
    if (DIAG4 && UPCORNER2LEFT !=EMPTY){
        return TRUE;
    }
    else{
        return FALSE;
    }


}
/****************************************************************************
*function name: cubeLineCheck
*The Input: int a,b,c for board,row,col and arr for board
*The output: 1 if win on 3d line 0 else
*The PrintOut: NONE
*The Function operation: check if whole column is X or O
 * if so return 1 which is win 0 else
****************************************************************************/
int cubeLineCheck(int arr[] , int a , int b, int c){

#define BOARD1 (0*16)
#define BOARD2 (1*16)
#define BOARD3 (2*16)
#define BOARD4 (3*16)
#define ROW (b*4)
#define ROWBYC (arr[BOARD1 +ROW +c] == arr[BOARD2 + ROW +c] == \
arr[BOARD3 +ROW +c] == arr[BOARD4 + ROW +c])

    if (ROWBYC){
        return TRUE;
    }
    else{
        return FALSE;
    }


}


/****************************************************************************
*function name: checkWin
*The Input: int a,b,c for board,row,col and arr for board and moves int
*The output: 1 if any kind of wincheck is 1 else 0.
*The PrintOut: NONE
*The Function operation: uses all the other checks to check for win
 * if any is 1 == win then it returns the winner sign (+/-)
 * and so we know if its X or O
****************************************************************************/
int checkWin(int arr[] , int a , int b, int c, int moves){
    #define NOWINMOVES (moves<=52)
    #define WON (win>0)
    #define X 1
    #define O (-1)
    //based on last move - check for possible wins
    int win = 0;
    if (NOWINMOVES){
        win += rowCheck(arr,a,b,c);
        printf("win is:%d\n",win);
        win += colCheck(arr,a,b,c);
        printf("win is:%d\n",win);
        win += diagonalCheck(arr,a,b,c);
        printf("win is:%d\n",win);
        win += cubeDiagonalCheck(arr,a,b,c);
        printf("win is:%d\n",win);
        win += cubeLineCheck(arr,a,b,c);
        printf("win is:%d\n",win);

    }
    //if we have any win
    if (WON){
        win = TRUE;
        //its X turn
        if(moves%2==0){
            return X;
        }
        //its O turn
        else{
            return O;
        }
    }else {
        return FALSE;
    }


}
/****************************************************************************
*function name: printBoard
*The Input:  arr as board
*The output: none
*The PrintOut: prints the "board" by given instructions and structure.
*The Function operation: triple loop running on board,col,row respectively
 * last loop works twice , once for k print the triplets (X,Y,Z)
 * and once for t to print the board values
****************************************************************************/
void printBoard(int arr[]) {
#define LOWRANGE 0
#define HIGHRANGE 3
#define CURRENTPLACE arr[(i*16)+(j*4)+t]
#define X 1
#define O (-1)

    for (int i=LOWRANGE; i<=HIGHRANGE; i++){
        for (int j=LOWRANGE; j<=HIGHRANGE ; j++){
            for (int k=LOWRANGE; k<=HIGHRANGE ; k++){
                printf("(%d %d %d) ",i,j,k);
            }
            for (int t=LOWRANGE; t<=HIGHRANGE ; t++){
                if (CURRENTPLACE == X){
                    printf ("X ");
                }
                else {
                    if (CURRENTPLACE == O){
                        printf ("O ");
                    }
                    else {
                        printf ("* ");
                    }
                }
            }
            printf("\n");
        }
        printf("\n");
    }}

/****************************************************************************
*function name: setMove
*The Input: int a,b,c for board,row,col and arr for board and moves int
*The output: returns the value of winCheck
*The PrintOut: NONE
*The Function operation: uses given a b c to change board[place]
 * which is 0 to X or O depending on whose move it is
****************************************************************************/
int setMove(int arr[] , int a ,int b , int c , int moves){
#define XMOVE (moves%2 == 0)
#define CURRENTPLACE arr[(a*16)+(b*4)+c]
#define X 1
#define O (-1)

    //printf("entered set\n");
    //printf("a is:%d b is:%d c is:%d\n",a,b,c);
    if (XMOVE){
        CURRENTPLACE = X;
       // printBoard(arr);
    }
    else{
        CURRENTPLACE = O;
       // printBoard(arr);
    }
    //win check to be returns instantly
    return checkWin(arr,a,b,c,moves);

}


/****************************************************************************
*function name: gameInterface
*The Input: NONE
*The output: returns 0 for another clean board game , 1 to finish
 * else - wrong input and re loopon same board.
*The PrintOut: prints out who wins or tie
*The Function operation:
 * 1.creates the board and fills with zeros ,
 * 2. prints necessary  lines
 * 3. reads moves from players
 * 4. validates cell clear , input in range , then sets the cell to X or O
 * 5. if win is reached - prints out board and asks to reset or finish
 * 6. if moves goes to 0 and no winner - tie .
 *
****************************************************************************/
//game logic , set up clean "board" , ask for input , check , set , return ans
int gameInterface(){

    #define SIZE 64
#define TOTMOVES 64
#define NOWINYET win==0
#define NOTDONE (isDone==0)
#define TRUE 1
#define FALSE 0
#define MOVESLEFT moves !=0
#define NOMOVESLEFT moves==0
#define CONTINUE 1
#define FINISH (-1)
#define ANOTHERGAME 0

    int board[SIZE] ={0};
    //printf("board started again\n");
    int a ,b ,c ;
    char d ;
    int moves = TOTMOVES;
    int ans =0;
    int win = 0;
    int isDone = 0;
    int inptCheck = 0;
    int onePrint = 1 ;
    while (NOTDONE ) {
        if (onePrint == 1) {
            printf("Please enter your game sequence.\n");
            onePrint = 0;
        }
        if (NOWINYET) {
            scanf(" %d %d %d", &a, &b, &c);
        }
        //buffClean();
        //printf("a is:%d b is:%d c is:%d d is:%c\n",a,b,c,d);
        //printBoard(board);
        //if (checkMove(...) == 1
        if (moveCheck(board, a, b, c) == TRUE && NOWINYET) {
            //means we can set the move
            //win will change from 0 and loop finishes if win
            win = setMove(board, a, b, c, moves);
            moves--;


        } else {
            // input  spot taken or out of range
            if (NOWINYET && MOVESLEFT) {
                printf("Input incorrect.\n");
            } else {
                if (win == X) {
                    printf("X is the winner.\n");
                    printBoard(board);
                    //buffClean();
                } else {
                    if (win == O) {
                        printf("O is the winner.\n");
                        printBoard(board);
                        //buffClean();
                    } else {
                        if (NOMOVESLEFT){
                            printf("tie!");
                            //buffClean();
                    }}
                }
            }

            printf("Would you like to continue? (y/n)\n");
            buffClean();

            ans = chInputCheck();
            //printf("ans is:%c",ans);

            if ( ans == FINISH) {
                return  TRUE;
            } else {
                if (ans == CONTINUE && NOWINYET) {
                    //to print enter selection
                    onePrint = 1;
                    continue;
                }
                else {
                    return ANOTHERGAME;
                }
            }
        }

    }

}















int main() {
#define TRUE 1
#define FALSE 0
    int isDone =0;
    int wrongInpt =1;
    int chInput =0;

    printf("Would you like to start? (y/n)\n");
    //we assume wrong inpput , and wait till correct Y/n input
    while (wrongInpt == TRUE){
        chInput = chInputCheck();
        //chInput handler
        if(chInput==FALSE){
            wrongInpt =TRUE;
        }
        else{
            if(chInput == -1){
                isDone = TRUE;
                wrongInpt = FALSE;
            }
            else{
            wrongInpt = FALSE;
            }
        }
        }
    // while user didnt ask to finish we run game
    while (isDone == FALSE){
        isDone = gameInterface();
        if (isDone == TRUE){
            break;
        }



    }
    printf("YEET");



    return 0;
}
