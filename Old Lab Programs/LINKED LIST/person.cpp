#include<iostream>
#include<stdio.h>
#include<string.h>
#include<conio.h>
using namespace std;

class Person
{
    char *name;
    int age,height;
    float weight;

    public:
    float getBMI();

    friend istream &operator>>(istream &abc, Person &x);
    friend ostream &operator<<(ostream &abc, Person x);

};

float Person::getBMI()
{
    return (weight/(height*height))*10000;
}

istream &operator>>(istream &abc, Person &x)
{
    char nm[50];
    cout<<"\nEnter name: ";
    gets(nm);

    x.name=new char[strlen(nm)+1];
    strcpy(x.name,nm);

    cout<<"\nEnter height in cms: ";
    abc>>x.height;

    cout<<"\nEnter weight in kg: ";
    abc>>x.weight;

    return abc;
}

ostream &operator<<(ostream &abc, Person x)
{
    float bmi=x.getBMI();
    abc<<endl<<"["<<x.name<<" "<<x.weight<<" "<<x.height<<" "<<bmi<<"]"<<endl;
    cout<<endl;

    if(bmi<18.5)
        cout<<"\nOops!!!!You are Underweight";
    else if(bmi>=18.5 && bmi<25.0)
        cout<<"\nHey!!! Your BMI is Normal";
    else if(bmi>=25 && bmi<29)
        cout<<"\nDamn!!! You are Overweigth";
    else
        cout<<"\nsymptoms of obesity.........."<<endl;
    return abc;
}

int main()
{
    Person x;
    cin>>x;
    cout<<x;
    return 0;
}
