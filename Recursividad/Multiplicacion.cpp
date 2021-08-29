#include <iostream>
using namespace std;

int producto(int a, int b)
{
 if(a==0 || b==0)
   return 0;
  else
   {
    return a+producto(a,b-1);
   }
}

int main(){
 int r;

 r=producto(3,5);
 cout << "El producto es: " << r << endl;
 
	return 0;
}