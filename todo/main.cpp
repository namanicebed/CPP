#include <iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

class todo {
public:
    string name;
    int priority;
    todo()
    {
        char* tempchar=new char[50];
        cout << "name:";
        cin.ignore();
        cin.getline(tempchar, 50);
        name = tempchar;
        cout << "priority:";
        cin >> priority;
    }
};

void display(vector<todo>);
bool vectcomp(todo,todo);
void rempri(vector<todo> &,int );
int main()
{
    vector<todo> todolist;
    int optionvariable;
    while (true)
    {
        cout << "option:";
        cin >> optionvariable;
        if (optionvariable == 1)
        {
            todolist.push_back(todo());
        }
        else if (optionvariable == 2)
        {
            
            int priority;
            cin>>priority;
            rempri(todolist, priority);
        }
        else if (optionvariable == 3)
        {
            sort(todolist.begin(), todolist.end(), vectcomp);
            display(todolist);
        }
        else
            break;
        
    }
    
}

void display(vector<todo> list)
{
    for (vector<todo>::iterator beg = list.begin(); beg < list.end(); beg++)
    {
        cout << beg->name << "\t"<<beg->priority<<"\n";
    }
}

bool vectcomp(todo first,todo second)
{
    return first.priority < second.priority;
}

void rempri(vector<todo> &todoItem,int priority)
{
    
    for (vector<todo>::iterator it=todoItem.begin(); it<todoItem.end(); it++) {
        if(it->priority != priority)
            continue;
        todoItem.erase(it);
    }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
