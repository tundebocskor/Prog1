#include "std_lib_facilities.h"

class Person{
public:
 Person(){};
 Person(string fn, string ln, int aa);
//Meghívjuk, ami privatba van, csak a Person-on belül lehet elérni 
 string get_fname() const {return firstn;}
 string get_lname() const {return lastn;}
 int get_age() const {return a;}
private:
 string firstn;
 string lastn;
 int a;
};
Person::Person(string fn, string ln, int aa) 
: firstn{fn}, lastn{ln}, a{aa}
{
 if (aa > 150 || aa < 0) error("Invalid age. ");
 for (char c : fn)
 if (!isalpha(c)) error("Invalid firstname. ");

 for (char c : ln) 
 if (!isalpha(c)) error("Invalid lastname. ");

 string nn=fn+ln;
        for(char c:nn){
            if(c==';' || c==':' || c=='"' || c=='[' || c==']' || c=='*' || c=='&' || c=='^' || c=='%' || c=='$' || c=='#' || c=='@' || c=='!'){
                error("Invalid name.");
            }
        }   
}
ostream& operator<<(ostream& os, const Person& p)
{
 os << "First Name: "<< p.get_fname() << "\n Last Name: " << p.get_lname() << "\n Age: " << p.get_age() << endl;
 return os;
}
istream& operator>>(istream& is, Person& p)
{
 string fn;
 string ln;
 int a;

 is >> fn;
 is >> ln;
 is >> a; 

 p = Person(fn, ln, a);
 return is;
}
int main()
{
 Person myperson{"Goofy","P", 63};
 //cout << myperson.name << " " << myperson.age << endl;
 //cout << myperson.get_fname() << " " << myperson.get_age() << endl;
 Person p;
 vector <Person> pv;
 cout << "Enter names and ages: (If you want to quit Press 'x x x') \n";

 for (Person p; cin >> p; )
 {
    

 if (p.get_fname() == "x")
 break;
 cout << "Enter names and ages: (If you want to quit Press 'x x x') \n";
 pv.push_back(p);

 
 }
 for(Person p : pv){

 cout << p << endl;
 }
}
