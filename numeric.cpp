//token categorization
#include<iostream>
#include<string>
using namespace std;

int main()
{
string input="";

int length;

cout<<"enter an input ";

cin>>input;

length=input.length();

for(int i=0;i<length;i++)
    {
        if(!isdigit(input[i]))
        {
            cout<<"given input is  not numeric"<<endl;

            return 1;
        }
    }
    cout<<"given input is a number"<<endl;

       return 0;

}













