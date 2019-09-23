#include "Classes.h"

/*****EMPLOYEE*****/
Employee::Employee() : name("Random Dude No") {
    static int x = 1;
    char *temp = tostring(x++);
    name.concat(temp);
    delete temp;
    cout << "An Employee has been created!" << endl;
}

Employee::Employee(Employee& a) : Object(a), name(*(a.getname())) {
    cout << "An Employee has been created!" << endl;
}

Employee::~Employee() {
    cout << "An Employee has been deleted!" << endl;
}

bool Employee::equal(Object &a) {
    if (this->getid() == a.getid())
        return 1;
    return getname()->equal((String &)a);
}

String *Employee::toString() {
    String *result = new String("ID: ");
    char *temp = tostring(getid());
    String *temp2;
    result->concat(temp);
    delete temp;
    result->concat(", name: ");
    temp2 = name.toString();
    result->concat(*temp2);
    delete temp2;
    return result;
}

/***SECURITY EXPLOYEE***/
SecurityEmployee::SecurityEmployee() {
    cout << "A Security Employee has been created!" << endl;
}

SecurityEmployee::SecurityEmployee(SecurityEmployee& a) : Employee(a) {
    cout << "A Security Employee has been created!" << endl;
}

SecurityEmployee::~SecurityEmployee() {
    cout << "A Security Employee has been deleted!" << endl;
}

Object *SecurityEmployee::clone() {
    SecurityEmployee *a = new SecurityEmployee(*this);
    return a;
}

void SecurityEmployee::workOn(Plane* p) {
    for (int i = 0; i < p->getNoofPassengerCompartments(); i++)
        (p->getPassengerCompartments())[i]->process(this);
    p->getEquipmentCompartmentNo1()->process(this);
    p->getEquipmentCompartmentNo2()->process(this);
    p->getEquipmentCompartmentNo3()->process(this);
    p->getCargoBayNo1()->process(this);
    report();
}

void SecurityEmployee::workOn(PassengerCompartment *p) {
    cout << "Passenger Compartment Processed!" << endl;
    if (NULL != p->getExtraSpace()) {
        cout << "ExtraSpace: ";
        workOn(p->getExtraSpace());
    }
}

void SecurityEmployee::workOn(EquipmentCompartment *p) {
    cout << "Equipment Compartment Processed!" << endl;
}

void SecurityEmployee::workOn(CargoBay *p) {
    cout << "Cargo Bay Processed!" << endl;
}

void SecurityEmployee::report() {
    getname()->print2();
    cout << " reports: Everything OK!" << endl;
}

/***MAINTANCE EMPLOYEE***/
MaintanceEmployee::MaintanceEmployee() {
    cout << "A Maintance Employee has been created!" << endl;
}

MaintanceEmployee::MaintanceEmployee(MaintanceEmployee& a) : Employee(a) {
    cout << "A Maintance Employee has been created!" << endl;
}

MaintanceEmployee::~MaintanceEmployee() {
    cout << "A Maintance Employee has been deleted!" << endl;
}

Object *MaintanceEmployee::clone() {
    MaintanceEmployee *a = new MaintanceEmployee(*this);
    return a;
}

void MaintanceEmployee::workOn(PassengerCompartment *p) {
}

void MaintanceEmployee::workOn(Plane* p) {
    for (int i = 0; i < p->getNoofPassengerCompartments(); i++)
        (p->getPassengerCompartments())[i]->process(this);
    p->getEquipmentCompartmentNo1()->process(this);
    p->getEquipmentCompartmentNo2()->process(this);
    p->getEquipmentCompartmentNo3()->process(this);
    p->getCargoBayNo1()->process(this);
    report();
}

void MaintanceEmployee::workOn(EquipmentCompartment *p) {
    cout << "Equipment Compartment Processed!" << endl;
}

void MaintanceEmployee::workOn(CargoBay *p) {
    cout << "Cargo Bay Processed!" << endl << "ExtraSpace";
    workOn(p->getExtraSpace());
}

void MaintanceEmployee::report() {
    getname()->print2();
    cout << " reports: Everything OK!" << endl;
}

/***CLEANING EMPLOYEE***/
CleaningEmployee::CleaningEmployee() {
    cout << "A Cleaning Employee has been created!" << endl;
}

CleaningEmployee::CleaningEmployee(CleaningEmployee& a) : Employee(a) {
    cout << "A Cleaning Employee has been created!" << endl;
}

CleaningEmployee::~CleaningEmployee() {
    cout << "A Cleaning Employee has been deleted!" << endl;
}

Object *CleaningEmployee::clone() {
    CleaningEmployee *a = new CleaningEmployee(*this);
    return a;
}

void CleaningEmployee::workOn(Plane* p) {
    for (int i = 0; i < p->getNoofPassengerCompartments(); i++)
        (p->getPassengerCompartments())[i]->process(this);
    p->getEquipmentCompartmentNo1()->process(this);
    p->getEquipmentCompartmentNo2()->process(this);
    p->getEquipmentCompartmentNo3()->process(this);
    p->getCargoBayNo1()->process(this);
    report();
}

void CleaningEmployee::workOn(PassengerCompartment *p) {
    cout << "Passenger Compartment Processed!" << endl;
    if (NULL != p->getExtraSpace()) {
        cout << "ExtraSpace: ";
        workOn(p->getExtraSpace());
    }
}

void CleaningEmployee::workOn(EquipmentCompartment *p) {
}

void CleaningEmployee::workOn(CargoBay *p) {
    cout << "Cargo Bay Processed!" << endl;
}

void CleaningEmployee::report() {
    getname()->print2();
    cout << " reports: Everything OK!" << endl;
}

