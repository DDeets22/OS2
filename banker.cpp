//OS project 2
//dakota deets
//bankers algorythm

#include <iostream>
#include <fstream>


int work;
int processes[255][2];
int data[255];
std::fstream myFile;
std::string line;


int main(){
//open all the data
myFile.open("processes.txt");
int i = 0;
while(myFile.peek() != std::ifstream::traits_type::eof()){
myFile >> data[i];
i++;
}
i-=1;
int y = 0;
int g = 0;
//parse the data
for(int x = 0; x+y < i; x++){
for(int y = 0; y < 2; y++){
processes[x][y] = data[g];
g++;
}}

work = data[i-1];

//print table
for(int x = 0; x+y < (i/2); x++){

std::cout << "process " << x << ":" << processes[x][0] << " " << processes[x][1] << std::endl;

}
myFile.close();
bool safe = true;
//check to see if in bad state
for(int x = 0; x+y < (i/2); x++){

if(processes[x][2] - processes[x][1] <= work){
safe = false;
std::cout << "the system is not safe";
break;
}
}

if(safe)
{
std::cout << "the system is safe";
}

return 0;
}
