#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Room{
  string name;
  bool win;
  bool key;
  bool arrived; //t=user already got in before
};

int main(){
  string name[]={"canteen","lib","classrm","commonrm"};
  vector <Room> places; 

  srand((unsigned)time(NULL));
  int random=(rand()%4); //random generate one room having key

for (int i=0;i<name.size();i++){ //initialise rooms
  Room r;
  r.name=name[i];
  r.win=false;
  r.arrival=false;
  if (i==random){
    r.key=true;}
  else{
    r.key=false;}
  places.push_back(r);
}

//while true loop here?
cout<<"I wonder where the keys are..."<<endl;
cout<<"Where should I go? ";
int count=0;
for (int i=0;i<places.size();i++){
  if (places[i].arrived==false){
    count+=1;}
}
int counter=0;
//print places that not yet arrived
for (int i=0;i<places.size();i++){
  if (places[i].arrived==false){
    counter+=1;
    if (counter != count){
      cout<<place[i].name<<"/ ";
    }else if (counter == count){
      cout<<place[i].name<<endl;
}

string input;
cin>>input;

    
return 0;
}
