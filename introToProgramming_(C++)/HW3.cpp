#include <iostream>

using namespace std;


void ex1(){
int arrsize=6;
int firstarr[arrsize];
int scndarr[arrsize];
cout<<"enter first vector"<<endl;
for (int i=0;i<arrsize;i++){
    cin>>firstarr[i];
}
cout<<"enter second vector"<<endl;
for (int i=0;i<arrsize;i++){
    cin>>scndarr[i];
    scndarr[i]=scndarr[i]+firstarr[i];
}
for (int i=0;i<arrsize;i++){
    if (i!=arrsize-1)
    cout<<scndarr[i]<<",";
else cout<<scndarr[i];

}

}

void ex2(){
int arr[5][3]={{5,4,3},{1,2,3},{1,4,3},{1,1,1},{2,2,2}};
for (int i=0;i!=5;i++){
    for (int i2=0;i2!=3;i2++){

        cout<<arr[i][i2];
if (i2==2) cout<<endl;    }

    }
    for (int i3=0;i3!=3;i3++){
    for (int i4=0;i4!=5;i4++){
        cout<<arr[i4][i3];
        if (i4==4) cout<<endl;
}

    }}

void ex3(){
int number=1;
cout<<"enter 9 digit integer\n";
cin>>number;
if (number<100000000 || number>999999999){
    cout << "not 9 digits\n";
}
else {
        number=number-((number/100000000)+((number/100000000)*100000000));

        number=number-(((number/10000000)*10)+((number/10000000)*10000000));

        number=number-((number/1000000)*100+((number/1000000)*1000000));

        number=number-((number/100000)*1000+((number/100000)*100000));

        number=number-((number/10000)*10000);

        if (number==0) cout<<"its a pelindrom!";
else cout<<"not a pelindrom!";
}



}

void ex4(){
    string userinput;
    int counter=0;
    cout<<"enter string!\n";
    getline(cin, userinput);

    for (int i=0;i!=userinput.size();i++)
{
    if ((int)userinput.at(i)==65 || (int)userinput.at(i)==97)counter++;

}
cout<< counter;


}

void ex5(){
int x;
int *p;
p=&x;
x=x-x;
*p= 42;



cout<<x<< endl;
}

void ex6(){
int arr[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
char arrch[20]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t'};
int *parr;
char *pcharr;
parr=arr;
pcharr=arrch;
for (int i=0;i!=15;i++){
    cout<<*parr;
    parr++;

}
cout<<endl;
for (int i=0;i!=20;i++){
    cout<<*pcharr;
    pcharr++;
}

}
int main()
{
    ex6();
}
