#include <iostream>
#include <stdio.h>

// int main()
// {
//     float a = 0.1f + 0.2f;
//     // if (0.1 + 0.2 == 0.3)
//     //     printf("yes\n");
//     // else
//     //     printf("no\n");
//     printf("%.100f\n",a);
//     printf("%.100f\n",0.1+0.2);
// }

//////////////////////////////////////////////////////////////
// #include <iostream>
// using namespace std;

// // Create a demo class
// class A
// {
//   public:
//     int x;
// };

// int main()
// {

//     // Creating an a1 object
//     A a1;
//     a1.x = 10;
//     cout << "a1's x = " << a1.x << endl;

//     // Creating another object using a1
//     A a2(a1);
//     cout << "a2's x = " << a2.x << endl;
//     a2.x = 20;

//     cout << "a1's x = " << a1.x << endl;
//     cout << "a2's x = " << a2.x << endl;
//     a1 = a2;

//     cout << "a1's x = " << a1.x << endl;
//     cout << "a2's x = " << a2.x << endl;

//     return 0;
// }
//////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class A
{
  public:
    int x;
    A(){};

    // Copy Constructor definition
    A(A &obj)
    {
        x = obj.x+1;
        cout << "Copy constructor "
                "called"
             << endl;
    }
};

int main()
{

    // Creating an object of class A
    A obj1;
    obj1.x = 10;
    cout << "obj1's x = " << obj1.x << endl;

    // Creating another object by copying already created object
    A obj2(obj1);
    
    cout << "obj2's x = " << obj2.x << endl;
    return 0;
}