# Oject Oriented Programming

*Smalltalk is considered as the first truly object-oriented programming language.*

---

Object means a real word entity such as pen, chair, table etc. Object-Oriented Programming is a methodology or paradigm to design a program using classes and objects.

Concept:-
- Object
- Class
- Inheritance
- Polymorphism
- Abstraction
- Encapsulation

## Object

Any entity that has state and behavior is known as an object. For example: chair, pen, table, keyboard, bike etc. It can be physical and logical.

---

## Class

Collection of Object with logical entity

```c++
#include <iostream>  
using namespace std;  
class Student {  
   public:  
      int id;//data member (also instance variable)      
      string name;//data member(also instance variable)      
};  
int main() {  
    Student s1; //creating an object of Student   
    s1.id = 201;    
    s1.name = "Sonoo Jaiswal";   
    cout<<s1.id<<endl;  
    cout<<s1.name<<endl;  
    return 0;  
}   
```

### **C++ Constructor**
Constructor is a special method which is invoked `automatically` at the time of object creation. The constructor in C++ has the same name as class or structure.
There can be two types of constructors in C++.

- Default constructor
```c++
        #include <iostream>  
        using namespace std;  
        class Employee  
        {  
        public:  
                Employee()    
                {    
                    cout<<"Default Constructor Invoked"<<endl;    
                }    
        };  
        int main(void)   
        {  
            Employee e1; //creating an object of Employee   
            Employee e2;   
            return 0;  
        }  
```
- Parameterized constructor
```c++
        #include <iostream>
        using namespace std;
        class Employee {
        public:
            int id;//data member (also instance variable)    
            string name;//data member(also instance variable)
            float salary;
            Employee(int i, string n, float s)  
                {  
                    id = i;  
                    name = n;  
                    salary = s;
                }  
            void display()  
                {  
                    cout<<id<<"  "<<name<<"  "<<salary<<endl;  
                }  
        };
        int main(void) {
            Employee e1 =Employee(101, "Sonoo", 890000); //creating an object of Employee 
            Employee e2=Employee(102, "Nakul", 59000); 
            e1.display();  
            e2.display();  
            return 0;
        }
```

### **C++ Destructor**
A `destructor` works opposite to `constructor`; it destructs the objects of classes. It can be defined only once in a class. Like constructors, it is invoked `automatically`.
A destructor is defined like constructor. It must have same name as class. But it is prefixed with a tilde `sign (~)`.

```c++
        #include <iostream>  
        using namespace std;  
        class Employee  
        {  
        public:  
                Employee()    
                {    
                    cout<<"Constructor Invoked"<<endl;    
                }    
                ~Employee()    
                {    
                    cout<<"Destructor Invoked"<<endl;    
                }  
        };  
        int main(void)   
        {  
            Employee e1; //creating an object of Employee   
            Employee e2; //creating an object of Employee  
            return 0;  
        }  
```
### **C++ `this` Pointer**
`this` is a keyword that refers to the current instance of the class.
Usage:-
- It can be used to pass current object as a parameter to another method.
- It can be used to refer current class instance variable.
- It can be used to declare indexers.
```c++
    class Employee {  
    public:  
        int id; //data member (also instance variable)      
        string name; //data member(also instance variable)  
        float salary;  
        Employee(int id, string name, float salary)    
            {    
                this->id = id;    
                this->name = name;    
                this->salary = salary;   
            }    
        void display()    
            {    
                cout<<id<<"  "<<name<<"  "<<salary<<endl;    
            }    
    };  
```

### **C++ `static`**
`static` is a keyword or modifier that belongs to the type not instance. `static` can be field, method, constructor, class, properties, operator and event. Unlike instance field which gets memory each time, it only create memory feild once. It is used to refer the common property of all objects.

```c++
        #include <iostream>  
        using namespace std;  
        class Account {  
        public:  
            int accno; //data member (also instance variable)      
            string name;   
            static int count;     
            Account(int accno, string name)   
                {    
                    this->accno = accno;    
                    this->name = name;    
                    count++;  
                }    
            void display()    
                {    
                    cout<<accno<<" "<<name<<endl;   
                }    
        };  
        int Account::count=0;  
        int main(void) {  
            Account a1 =Account(201, "Sanjay"); //creating an object of Account  
            Account a2=Account(202, "Nakul");   
            Account a3=Account(203, "Ranjana");  
            a1.display();    
            a2.display();    
            a3.display();    
            cout<<"Total Objects are: "<<Account::count;  
            return 0;  
        }  

```
### **C++ `Structs`**
`Structs` are used for lightweight `objects` such as Rectangle, color, Point, etc and create the instance of a `class`. `structs` in C++ are value type than reference type. It is useful if you have data that is not intended to be modified after creation of struct.

```c++
    #include <iostream>    
    using namespace std;    
    struct Rectangle      
    {      
    int width, height;      
        
    };      
    int main(void) {    
        struct Rectangle rec;    
        rec.width=8;    
        rec.height=5;    
    cout<<"Area of Rectangle is: "<<(rec.width * rec.height)<<endl;    
    return 0;    
    }    
```

*Using Constructor and Method*
```c++
    #include <iostream>    
    using namespace std;    
    struct Rectangle    {      
    int width, height;      
    Rectangle(int w, int h)      
        {      
            width = w;      
            height = h;      
        }      
    void areaOfRectangle() {       
        cout<<"Area of Rectangle is: "<<(width*height); }      
    };      
    int main(void) {    
        struct Rectangle rec=Rectangle(4,6);    
        rec.areaOfRectangle();    
    return 0;    
    }
```
### **C++ Enumeration**
Enum in C++ is a data type that contains fixed set of constants.C++ Enums can be thought of as classes that have fixed set of constants.

1. enum improves type safety
1. enum can be easily used in switch
1. enum can be traversed
1. enum can have fields, constructors and methods
1. enum may implement many interfaces but cannot extend any class because it internally extends Enum class

```c++
    #include <iostream>  
    using namespace std;  
    enum week { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };  
    int main()  
    {  
        week day;  
        day = Friday;  
        cout << "Day: " << day+1<<endl;  
        return 0;  
    } 
```
### C++ Friend function
[LINK](https://www.javatpoint.com/cpp-friend-function)

### Math Function
[LINK](https://www.javatpoint.com/cpp-math-functions)

---
##  Access Specifier

In C++, there are three access specifiers:

1. public - members are accessible from outside the class
2. private - members cannot be accessed (or viewed) from outside the class
3. protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes. You will learn more about Inheritance later.

```c++
    class MyClass {
        public:    // Public access specifier
            int x;   // Public attribute
        private:   // Private access specifier
            int y;   // Private attribute
        };

        int main() {
        MyClass myObj;
        myObj.x = 25;  // Allowed (public)
        myObj.y = 50;  // Not allowed (private)
        return 0;
    }
```
> **Note**: By default, all members of a class are `private` if you don't specify an access specifier:

---
## Getter and Setter

```c++
#include <iostream>
#include <sstream>
using namespace std;

class Student{
    private:
        int age, standard;
        string first_name, last_name;
    public:
        void set_age(int age){
            this->age = age;
        }
        void set_first_name(string first_name){
            this->first_name = first_name;
        }
        void set_last_name(string last_name){
            this->last_name = last_name;
        }
        void set_standard(int standard){
            this->standard = standard;
        }
        int get_age(){
            return age;
        }
        string get_first_name(){
            return first_name;
        }
        string get_last_name(){
            return last_name;
        }
        int get_standard(){
            return standard;
        }
        string to_string(){
            ostringstream str1,str2;
            str1<<age;str2<<standard;
            string sage = str1.str();
            string sstandard = str2.str();
            return sage+","+first_name+","+last_name+","+sstandard;
        }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}

```
---
## Inheritance

when one object inheritate the property of parent Object is called Inheritance.

---
## Polymorphism

When one task is performed by different ways i.e. known as polymorphism. For example: to convince the customer differently, to draw something e.g. shape or rectangle etc.
In C++, we use Function overloading and Function overriding to achieve polymorphism.

---
## Abstraction

Hiding internal details and showing functionality is known as abstraction. For example: phone call, we don't know the internal processing.
In C++, we use abstract class and interface to achieve abstraction.

---
## Encapsulation

Binding (or wrapping) code and data together into a single unit is known as encapsulation. For example: capsule, it is wrapped with different medicines.

---
### Advantage of OOPs over Procedure-oriented programming language
>1. OOPs makes development and maintenance easier where as in Procedure-oriented programming language it is not easy to manage if code grows as project size grows.
>1. OOPs provide data hiding whereas in Procedure-oriented programming language a global data can be accessed from anywhere.
>1. OOPs provide ability to simulate real-world event much more effectively. We can provide the solution of real word problem if we are using the Object-Oriented Programming language.
