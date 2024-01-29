#include <iostream>
#include <random>
#include <cstdlib>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;
struct flower{
double stemLenght;
int petals;
string color;
string name;
bool seasonal;
};
//functions//
void arrangebouqut(flower bouq[],int bouqsize){
int rcount=0,bcount=0,ycount=0;
for (int i=0;i<=bouqsize;i++){
    if (bouq[i].color=="yellow") ycount++;
    if (bouq[i].color=="red") rcount++;
    if (bouq[i].color=="blue") bcount++;
}
int rcountback=rcount,bcountback=bcount,ycountback=ycount;
flower *blues = new flower[bcount];
flower *reds = new flower[rcount];
flower *yellows = new flower[ycount];
for (int i=0;i<=bouqsize;i++){
    if (bouq[i].color=="yellow") {*(yellows+ycount)=bouq[i];ycountback--;}
    if (bouq[i].color=="red") {*(reds+rcount)=bouq[i];rcountback--;}
    if (bouq[i].color=="blue") {*(blues+bcount)=bouq[i];bcountback--;}
    cout<<"check counts go 0"<<ycount<<" "<<bcount<<" "<<rcount<<endl;
    //need to sort by stem size.
    sort(yellows.stemLenght, yellows+ycount);
    sort(blues.stemLenght, blues+bcount);
    sort(reds.stemLenght, reds+rcount);
    //copy back to arr red blue yellow
            for(int j=0;j<rcount;j++){
                bouq[j]=reds[j];
            }

            for(int j=rcount;j<rcount+bcount;j++){
                bouq[j]=blues[j];
            }
            for(int j=rcount+bcount;j<rcount+bcount+ycount;j++){
                bouq[j]=yellows[j];
            }
      //print
      for(int i=0;i<bouqsize;i++){
        cout<<bouq[i].stemLenght<<",";
      }
    }



}
void printFlower(flower curr){
    cout<<"name:"<<curr.name<<endl;
    cout<<"stem lenght:"<<curr.stemLenght<<endl;
    cout<<"petals:"<<curr.petals<<endl;
    cout<<"color:"<<curr.color<<endl;
    if (curr.seasonal) cout<<"seasonal\n";
    else cout<<"not seasonal\n";
        cout<<"--------------\n";


}

flower setMFlower(){
flower curr;
    cout<<"name?\n";
    cin>>curr.name;
    cout<<"stem lenght?\n";
    cin>>curr.stemLenght;
    cout<<"petals?\n";
    cin>>curr.petals;
    cout<<"color?\n";
    cin>>curr.color;
    cout<<"seasonal? enter 1 for yes and 0 for no\n ";
    cin>>curr.seasonal;


return curr;
}

flower setRNDFlower(){
flower curr;
int randNum=0;
double randDoub=0;
randNum=(rand() % 3);
//cout<<"randNUm is:"<<randNum<<endl;
switch(randNum){
case 0:{curr.name="kalanit";break;}
case 1:{curr.name="rakefet";break;}
case 2:{curr.name="shoshana";break;}
}
randNum=(rand() % 3);

switch(randNum){
case 0:{curr.color="yellow";break;}
case 1:{curr.color="red";break;}
case 2:{curr.color="blue";break;}
}
randNum=(rand() % 2);

switch(randNum){
case 0:{curr.seasonal=1;break;}
case 1:{curr.seasonal=0;break;}
}
curr.petals=(rand() % 20)+1;
randDoub=((rand() % 10)+0);
//cout<<"randDoub:"<<randDoub<<endl;
curr.stemLenght=((rand() % 20)+1)+randDoub/10;
// printFlower( curr);

return curr;
}




int main()
{

srand( time(NULL));
int arrSize;
int choice=2;
cout<<"enter bouquet size\n";
cin>>arrSize;
flower* bouquet= new flower[arrSize];   //create array for flowers '  remember to DELETE
cout<<"enter 0 for random bouquet or 1 for manual set bouquet\n";
cin>>choice;
choice=2;   //both options -  delete for real choice

switch (choice){
case 0:{
    for(int i=0;i<arrSize;i++){
            bouquet[i]=setRNDFlower();    }
         for(int i=0;i<arrSize;i++){printFlower(bouquet[i]);}break;}
case 1:{  for(int i=0;i<arrSize;i++){
            bouquet[i]=setMFlower();}
              for(int j=0;j<arrSize;j++){printFlower(bouquet[j]);}break;}
case 2:{
 for(int i=0;i<arrSize;i++){
            bouquet[i]=setMFlower();}
             for(int j=0;j<arrSize;j++){printFlower(bouquet[j]);};
      for(int i=0;i<arrSize;i++){
            bouquet[i]=setRNDFlower();    }
             for(int j=0;j<arrSize;j++){printFlower(bouquet[j]);}break;

            }






    return 0;
    delete [] bouquet;
}}
