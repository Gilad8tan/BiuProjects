#include <iostream>

using namespace std;
void specialrecur(){







}
void goright(int )
void ex1(){

int numbers=0,count;
int row,column;
cout<<" enter arr size\n";
cin>>column>>row;
numbers=row*column;
count=0;
cout<<"row:"<<row<<"  column:"<<column;  //check
int *arr=new int[row*column];
//was supposed to be deleter - not possible ** to * , instead use no manipulation. leave deleter at end!!!!
cout<<"check - have allocated size of:"<<row*column;//check
while (count<numbers){
        goright();
        godown();
        goleft();
        goup();


}







}

int main()
{
    ex2();
    return 0;
}
