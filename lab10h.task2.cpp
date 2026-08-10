#include<iostream>
#include<string>
using namespace std;
class Animal 
{
protected:
    string name;
    string species;
public:
    Animal(string n, string s) : name(n), species(s) {}
	void sound()
	{
        cout << "Some generic animal sound" << endl;
    }
	void describe() 
	{
        cout << "Name: " << name << " | Species: " << species << endl;
    }
};
class Cat : public Animal
{
private:
    string breed;
public:
    Cat(string n, string s, string b) : Animal(n, s), breed(b) {}
	void sound()
	{
        cout << "Sound: Meow! Meow!" << endl;
    }
	void describe() 
	{
        Animal::describe();
        cout << "Breed: " << breed << endl;
    }
};
class Dog : public Animal
 {
private:
    string breed;
public:
    Dog(string n, string s, string b) : Animal(n, s), breed(b) {}
	void sound()
	{
        cout << "Sound: Woof! Woof!" << endl;
    }
	void describe()
	{
        Animal::describe();
        cout << "Breed: " << breed << endl;
    }
};
class GuardDog : public Dog 
{
private:
    int trainingLevel;
public:
    GuardDog(string n, string s, string b, int t) : Dog(n, s, b), trainingLevel(t) {}
	void sound() 
	{
        cout << "Sound: WOOF! WOOF! STAY BACK!" << endl;
    }
	void describe() 
	{
        Dog::describe();
        cout << "Training Level: " << trainingLevel << endl;
    }
};
int main()
{
    Cat c("Whiskers", "Feline", "Persian");
    Dog d("Bruno", "Canine", "German Shepherd");
    GuardDog gd("Rex", "Canine", "Rottweiler", 5);
	cout << "=== Cat ===" << endl;
    c.describe();
    c.sound();
    cout << endl;
	cout << "=== Dog ===" << endl;
    d.describe();
    d.sound();
    cout << endl;
	cout << "=== Guard Dog ===" << endl;
    gd.describe();
    gd.sound();
	cout << "Base Dog sound via scope resolution: ";
    gd.Dog::sound();
	return 0;
}
