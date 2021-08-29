#include <iostream>
using namespace std;

int cociente(int a, int b)
{

 if(a<b)
    return 0;
 else
    return 1+cociente(a-b,b);
}

int main(void)
{
    cout << "Cociente: " << cociente(9,3) << endl;
}

