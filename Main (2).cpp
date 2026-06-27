#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

int refresh = 0;
int returnchoice;
string dotext = "...";
string loadtext = "Loading";
string titletext = "Pet management system v1.0";

void loading()
{for(int j=0;j<loadtext.length();j++)
 {cout << loadtext[j] << flush;
  this_thread::sleep_for(chrono::milliseconds(20));}
 for(int i=0;i<dotext.length();i++)
 {cout << dotext[i] << flush;
  this_thread::sleep_for(chrono::milliseconds(150));}}

void returntomainmenu()
{cout << "Would you like to return to main menu?\n1. Return\n2. Exit\nOption: ";
 cin >> returnchoice;
 if (returnchoice == 1)
 {system("clear"); refresh = 0;}
 else {cout << "\nExiting";
 for (int l=0;l<dotext.length();l++)
 {cout << dotext[l] << flush;
  this_thread::sleep_for(chrono::milliseconds(350));}
  system("clear");}}

void titleline()
{for (int i=0;i<60;i++)
 {cout << "⎯" << flush;
  this_thread::sleep_for(chrono::milliseconds(10));}}

void title()
{for (int j=0;j<titletext.length();j++)
 {cout << titletext[j] << flush;
  this_thread::sleep_for(chrono::milliseconds(25));}}

class Animal
 {public: string name; string species; int agecd=5;
  private: int age = 1; int hunger = 100; int emotion = 100;

  public: void ageenable() {if (agecd == 0) {age++; agecd = 5;}}

  void displaystat() {cout << "Name: " << name << "\nSpecies: " << species
  << "\nAge: " << age << "\nHunger: " << hunger << "/100\n" << "Emotion: "
  << emotion << "/100\n\n";}
  
  void update()
  {agecd--; hunger-=5; emotion-=5;}
  
  void eat()
  {hunger+=20;}
  
  void play()
  {emotion += 10;}};

Animal temp;
vector<Animal> pet;

void updateall()
{for (int j=0;j<pet.size();j++)
 {pet[j].update();}}

int main() {
string options = "1. Create Pet\n2. Feed Pet\n3. Play with pet\n4. View Pets\n5. Exit";
int choice;
string lookingfor;

while (refresh == 0)
{refresh = 1;
titleline(); cout << "\n               ";
title(); cout << "\n";
titleline(); cout << "\n";
for (int p=0;p<options.length();p++)
{cout << options[p] << flush;
 this_thread::sleep_for(chrono::milliseconds(20));}
cout << "\n"; cout << "Option: "; cin >> choice;
titleline(); updateall();

// Create
if (choice == 1)
{updateall();
 cout << "\nPet Name: "; getline(cin >> ws, temp.name);
 cout << "Pet Species: "; getline(cin >> ws, temp.species);
 pet.push_back(temp); cout << "Success!\n"; returntomainmenu();}

// View
else if (choice == 4)
{updateall();cout << "Pet list:\n";
 for (int j=0;j<pet.size();j++)
 {pet[j].displaystat();}
returntomainmenu();}

// Feed
else if (choice == 2)
{updateall(); cout << "Pet Name: "; getline(cin >> ws, lookingfor);
 for(int l=0;l<pet.size();l++)
 {if (lookingfor == pet[l].name)
  {pet[l].eat(); cout << "Success!\n";}
  else {cout << "Error please try again later.\n";}}
returntomainmenu();}

// play
else if (choice == 3)
{updateall(); cout << "Pet name: "; getline(cin >> ws, lookingfor);
 for(int l=0;l<pet.size();l++)
 {if (lookingfor == pet[l].name)
 {pet[l].play(); cout << "Success!\n";}
  else {cout << "Error please try again later.\n";}}
returntomainmenu();}

// exit/invalid
else {cout << "\nExiting "; loading();
system("clear");}
}
}