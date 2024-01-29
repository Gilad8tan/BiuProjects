#include <iostream>
#include <string>
using namespace std;


void ex1(){
//user enters acc & time and outputs location at time
double acc,time;  // double because i dont see a point for it to be only in whole units
cout<<"please , enter acceleration (in m /s^2)\n";
cin>>acc;
cout<<"enter time (in sec)\n";
cin>>time;
cout<<endl<<"car is at distance "<<((acc*time*time)/2)<<" meters from 0 point";//calculate by (a*t^2)/2

}

void ex2(){
//user enters weight and height outputs BMI and by BMI conditional "personal" msg
//with respect to boundry cases
float weight,height,bmi;
cout<<"please enter weight (in kg)\n";
cin>>weight;
cout<<endl<<"please enter height (in meters)\n";
cin>>height;
bmi= weight/(height*height);
if (bmi>70 || bmi<7){ cout<<" either data is wrong or you should be dead";}
else{ cout<<"your BMI is :"<<bmi<<endl;
if (bmi>25){
    cout<<"you should eat more salad";}
    else {if (bmi>=18.5){
    cout<<"you are great ! keep it up!!";
    }
    else {cout<<"you should eat more pizza!";}
    }
}}

void ex3(){
//user inputs 3 int output is smallest to largest and then largest to smallest
//in respect to boundry inputs
int num1,num2,num3;
cout<<"please enter 3 numbers, enter after each or space between\n";
cin>>num1>>num2>>num3;
cout<<endl;
if ((num1==num2)&&(num2==num3)){cout<<num1<<endl<<num1;}     //if all same
else if(num1==num2){                                          // if 2 same
        if (num2<num3){cout<<num2<<" "<<num3<<endl<<num3<<" "<<num2;}
        else {cout<<num3<<" "<<num2<<endl<<num2<<" "<<num3; }
     if(num2==num3){
        if (num2>num1){cout<<num1<<" "<<num2<<endl<<num2<<" "<<num1;}
        else {cout<<num2<<" "<<num1<<endl<<num1<<" "<<num2; }
     if(num1==num3){
        if (num2<num3){cout<<num2<<" "<<num3<<endl<<num3<<" "<<num2;}
        else {cout<<num3<<" "<<num2<<endl<<num2<<" "<<num3; }}
     else {                                                    //if none same
    if (num1<num2){                                             //check by size
        if (num2<num3){cout<<num1<<" "<<num2<<" "<<num3<<endl<<num3<<" "<<num2<<" "<<num1;}
        else if (num1<num3){cout<<num1<<" "<<num3<<" "<<num2<<endl<<num2<<" "<<num3<<" "<<num1;}
            else {cout<<num3<<" "<<num1<<" "<<num2<<endl<<num2<<" "<<num1<<" "<<num3;}}
    else{if(num2>num3){cout<<num3<<" "<<num2<<" "<<num1<<endl<<num1<<" "<<num2<<" "<<num3;}
         else if(num1>num3){cout<<num2<<" "<<num3<<" "<<num1<<endl<<num1<<" "<<num3<<" "<<num2;}
             else {cout<<num2<<" "<<num1<<" "<<num3<<endl<<num3<<" "<<num1<<" "<<num2;}
    }
     }
     }
     }else {cout<<num1<<" "<<num2<<" "<<num3<<endl<<num3<<" "<<num2<<" "<<num1;}

}

void ex4(){
//get grade output in words
int score;
const int MAXSCORE=100;
const int MINSCORE=0;
string fail="you FAILED!";
string avgScore="need more PRACTICE!";
string goodScore="Very GOOD!";
cout<<"enter grade:\n";
cin>>score;
if ((score<MINSCORE)||(score>MAXSCORE)) {cout<<"invalid input";}
else if (score<60) {cout<<fail;}
    else if (score<80) {cout<<avgScore;}
        else cout<<goodScore;
}

void ex5(){
//calc with switch for the actions
int num1,num2,choice;
cout<<"enter 2 numbers and 1 for add,2for substract,3 for divide, 4 for multiply\n";
cin>>num1>>num2>>choice;
switch (choice){

case 1: cout<<endl<<num1+num2;break;
case 2: cout<<endl<<num1-num2;break;
case 3: {if (num2==0){ cout<<endl<<"cannot divide by zero";break;}
        else if ((double)num1/(double)num2==num1/num2){ cout<<endl<<num1/num2<<" no remainder";break;}
            else cout<<endl<<num1/num2<<" with remainder";break;}
case 4: cout<<endl<<num1*num2;break;
default: cout<<endl<<"wrong input";

}

}


void ex6(){
//get 2 series of 3 numbers , return if any or both are ordered
bool series1sorted;
bool series2sorted;
int num1,num2,num3;
int num4,num5,num6;
cout<<"enter 2 series of numbers"<<endl;
cin>>num1>>num2>>num3>>num4>>num5>>num6;
if ((num1<=num2)&&(num2<=num3)) series1sorted=1;
else if((num3<=num2)&&(num2<=num1))series1sorted=1;
if ((num4<=num5)&&(num5<=num6)) series2sorted=1;
else if((num6<=num5)&&(num5<=num4))series2sorted=1;

if ((series1sorted)&&(series2sorted)) cout<<endl<<"both are sorted";
else if ((series1sorted)||(series2sorted)) cout<<endl<<"one is sorted";
    else cout<<endl<<"none is sorted";



}

int main()
{
   // ex1();
  //ex2();
   // ex3();
 //  ex4();
 //ex5();
 ex6();
    return 0;
}
