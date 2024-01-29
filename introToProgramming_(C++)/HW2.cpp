#include <iostream>
#include <string>
using namespace std;


void ex1(){
//user enters numbers untill num is <0 than , program counts from 0 to the num by steps of 1
int num1;
cout<<"enter numbers!\n";
do{
    cin>>num1;}
    while (num1>=0);

for (int i=0;i>=num1;i--){
    if (i==num1)cout<<i;
    else   cout<<i<<",";
}

}

void ex2(){
//user enters number , until -1=> end ,than output avg of nums
int numCount=0;
int sum=0;
int enteredNum;
double avg;
cout<<"enter numbers, finish with -1\n";
while (enteredNum!=-1){
     cin>>enteredNum;
     if (enteredNum!=-1){
    numCount++;
    sum=sum+enteredNum;
   // cout<<"sum:"<<sum<<"entered num:"<<enteredNum<<"numcount:"<<numCount<<endl;  //check for problems
}}
   // cout<<"sum:"<<sum<<"entered num:"<<enteredNum<<"numcount:"<<numCount<<endl;  // check for problems
avg=(double)sum/(double)numCount;
cout<<avg;


}

void ex3(){
//print out all perfect nums up to 1000
//firs we loop on all the nums 1- 1000
for (int num=2;num<=10000;num++){
        int maybeNum=0;

//we use a loop , from the num , run down until modulu==0 , than we subtract from number the whole divider
//continue until all whole dividers were subtracted , then check if what we get is equal to num if so we print out
for (int currNum=num-1;currNum>0;currNum--){
if ((num%currNum)==0){maybeNum=maybeNum+currNum;}
//cout<<"currnum:"<<currNum<<endl;   //checkers
//cout<<"num:"<<num<<endl;           //checkers

}
if (maybeNum==num) { cout<<num<<endl;}



}




}

int main()
{
  // ex1();
 //
  ex2();
  //  ex3();

    return 0;
}
