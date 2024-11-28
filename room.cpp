#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

struct Room{
string name;
bool win;
bool key;
bool arrived;
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
r.key=true;}else{
r.key=false;}
places.push_back(r);
}

return 0;
}
