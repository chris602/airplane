//#include "C:\cygwin\lib\gcc\i686-pc-mingw32\3.4.4\c++\cstdlib"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class String;
class Employee;
class Plane;

/*CLASS OBJECT*/

class Object {
public:
    Object();
    virtual ~Object();
    Object(Object&);
    inline int getid() {return id;}
    inline void setid(int NewID) {id = NewID;}
    inline virtual bool identical(Object &a) {return ((this == &a) ? 1 : 0);}
    virtual bool equal(Object &a) = 0;
    virtual Object *clone() = 0;
    virtual String *toString() = 0;
private:
    int id;
};

/*CLASS STRING*/

class String : public Object {
public:
    String();
    String(char *);
    String(String &);
    virtual ~String();
    Object *clone();
    bool equal(Object &);
    String *toString();
    inline int length() {return letters;}
    inline char *get() {return word;}
    void clear();
    void concat(char *);
    void concat(String &);
    void print();
    void print2();
    char at(int);
    void updateAt(char, int);
private:
    char *word;
    int letters;
};

/*CLASS PLANE COMPONENT*/

class PlaneComponent : public Object {
public:
    PlaneComponent();
    PlaneComponent(PlaneComponent&);
    virtual ~PlaneComponent();
    virtual void ready_check() = 0;
    virtual void process(Employee *) = 0;
    inline String *getdesc() {return &desc;}
    inline void setdesc(String &newdesc) {desc.clear(); desc.concat(newdesc);}
private:
    String desc;
};

/*CLASS PASSENGER COMPARTMENT*/

class PassengerCompartment : public PlaneComponent {
public:
    PassengerCompartment(int);
    PassengerCompartment();
    PassengerCompartment(PassengerCompartment&);
    virtual ~PassengerCompartment();
    Object *clone();
    bool equal(Object &);
    String *toString();
    void ready_check();
    void process(Employee *);
    inline PassengerCompartment *getExtraSpace() {return ExtraSpace;}
    inline void setExtraSpace(PassengerCompartment *a) {ExtraSpace = a;}
private:
    PassengerCompartment *ExtraSpace;
};

/*CLASS PRIVATE COMPARTMENT*/

class PrivateCompartment : public PlaneComponent {
public:
    PrivateCompartment();
    PrivateCompartment(PrivateCompartment&);
    virtual ~PrivateCompartment();
    Object *clone();
private:
};

/*CLASS EQUIPMENT COMPARTMENT*/

class EquipmentCompartment : public PrivateCompartment {
public:
    EquipmentCompartment();
    EquipmentCompartment(EquipmentCompartment&);
    virtual ~EquipmentCompartment();
    Object *clone();
    bool equal(Object &);
    String *toString();
    void ready_check();
    void process(Employee *);
private:
};

/*CLASS CARGO BAY*/

class CargoBay : public PrivateCompartment {
public:
    CargoBay();
    CargoBay(CargoBay&);
    virtual ~CargoBay();
    Object *clone();
    bool equal(Object &);
    String *toString();
    void ready_check();
    void process(Employee *);
    inline EquipmentCompartment *getExtraSpace() {return &ExtraSpace;}
private:
    EquipmentCompartment ExtraSpace;
};

/*CLASS EMPLOYEE*/

class Employee : public Object {
public:
    Employee();
    Employee(Employee&);
    ~Employee();
    virtual void workOn(Plane *) = 0;
    virtual void workOn(PassengerCompartment *) = 0;
    virtual void workOn(EquipmentCompartment *) = 0;
    virtual void workOn(CargoBay *) = 0;
    virtual void report() = 0;
    inline String *getname() {return &name;}
    bool equal(Object &);
    String *toString();
private:
    String name;
};

/*SECURITY EMPLOYEE*/

class SecurityEmployee : public Employee {
public:
    SecurityEmployee();
    SecurityEmployee(SecurityEmployee &);
    ~SecurityEmployee();
    Object *clone();
    void workOn(Plane *);
    void workOn(PassengerCompartment *);
    void workOn(EquipmentCompartment *);
    void workOn(CargoBay *);
    void report();
private:
};

/*CLASS MAINTANCE EMPLOYEE*/

class MaintanceEmployee : public Employee {
public:
    MaintanceEmployee();
    MaintanceEmployee(MaintanceEmployee &);
    ~MaintanceEmployee();
    Object *clone();
    void workOn(Plane *);
    void workOn(PassengerCompartment *);
    void workOn(EquipmentCompartment *);
    void workOn(CargoBay *);
    void report();
private:
    
};

/*CLASS CLEANING EMPLOYEE*/

class CleaningEmployee : public Employee {
public:
    CleaningEmployee();
    CleaningEmployee(CleaningEmployee &);
    ~CleaningEmployee();
    Object *clone();
    void workOn(Plane *);
    void workOn(PassengerCompartment *);
    void workOn(EquipmentCompartment *);
    void workOn(CargoBay *);
    void report();
private:
    
};

/*CLASS PLANE*/

class Plane : public Object {
public:
    Plane();
    Plane(Plane &);
    ~Plane();
    bool equal(Object &);
    void ready_check();
    void process(Employee *);
    Object *clone();
    String *toString();
    inline String *getdesc() {return &desc;}
    inline String *gettitle() {return &title;}
    inline unsigned int getcapacity() {return capacity;}
    inline unsigned int getNoofPassengerCompartments() {return NoofPassengerCompartments;}
    inline PassengerCompartment **getPassengerCompartments() {return PassengerCompartments;}
    inline EquipmentCompartment *getEquipmentCompartmentNo1() {return &EquipmentCompartmentNo1;}
    inline EquipmentCompartment *getEquipmentCompartmentNo2() {return &EquipmentCompartmentNo2;}
    inline EquipmentCompartment *getEquipmentCompartmentNo3() {return &EquipmentCompartmentNo3;}
    inline CargoBay *getCargoBayNo1() {return &CargoBayNo1;}
    inline void settitle(String a) {title.clear(); title.concat(a);}
    inline void setdesc(String a) {desc.clear(); desc.concat(a);}
    inline void setPassengerCompartments(PassengerCompartment **a) {PassengerCompartments = a;}
    inline void setcapacity(unsigned int a) { capacity = a;}
    inline void setNoofPassengerCompartments(unsigned int a) {NoofPassengerCompartments = a;}
private:
    PassengerCompartment **PassengerCompartments;
    CargoBay CargoBayNo1;
    EquipmentCompartment EquipmentCompartmentNo1;
    EquipmentCompartment EquipmentCompartmentNo2;
    EquipmentCompartment EquipmentCompartmentNo3;
    String desc;
    String title;
    unsigned int capacity;
    unsigned int NoofPassengerCompartments;
};

char *tostring(unsigned int);
void clone_encrypt_and_print(Object&);

