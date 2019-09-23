#include "Classes.h"

/****************************************PLANE COMPONENT*************************************************/
PlaneComponent::PlaneComponent() : desc("Plane Component No") {
    static unsigned int x = 1;
    desc.concat(tostring(x++));
    cout << "A PlaneComponent has been created!" << endl;
    
}
PlaneComponent::PlaneComponent(PlaneComponent& a) : Object(a), desc(*a.getdesc()) {
    cout << "A PlaneComponent has been created!" << endl;
}

PlaneComponent::~PlaneComponent() {
    cout << "A PlaneComponent has been deleted!" << endl;
}


/**************************************PASSENGER COMPARTMENT*********************************************/
PassengerCompartment::PassengerCompartment(int i) : ExtraSpace(NULL) {
    cout << "A PassengerCompartment has been created!" << endl;
    getdesc()->concat(" - Passenger Compartment");
    if (0 != i)
        ExtraSpace = new PassengerCompartment(0);
}

PassengerCompartment::PassengerCompartment() : ExtraSpace(NULL) {
    cout << "A PassengerCompartment has been created!" << endl;
    getdesc()->concat(" - Passenger Compartment");
    if (0 == rand()%2)
        ExtraSpace = new PassengerCompartment(0);
}

PassengerCompartment::PassengerCompartment(PassengerCompartment& a) : PlaneComponent(a) {
    if (NULL == a.getExtraSpace())
        ExtraSpace = NULL;
    else
        ExtraSpace = new PassengerCompartment(*(a.getExtraSpace()));
    cout << "A PassengerCompartment has been created!" << endl;
}

PassengerCompartment::~PassengerCompartment() {
    cout << "A PassengerCompartment has been deleted!" << endl;
}

void PassengerCompartment::ready_check() {
    getdesc()->print2();
    cout << ": Passenger Compartment is ready!" << endl;
    if (NULL != ExtraSpace) {
        cout << "ExtraSpace: ";
        ExtraSpace->ready_check();
    }
}

void PassengerCompartment::process(Employee *e) {
    e->workOn(this);
}

bool PassengerCompartment::equal(Object &a) {
    PassengerCompartment *b = ((PassengerCompartment *) &a);
    
    if (0 == getdesc()->equal(*(b->getdesc())))
        return 0;
    if (NULL == getExtraSpace())
        if (NULL != b->getExtraSpace())
            return 0;
        else
            return 1;
    if (NULL == b->getExtraSpace())
        if (NULL != getExtraSpace())
            return 0;
        else
            return 1;
    Object &c = *(b->getExtraSpace());
    if (0 == getExtraSpace()->equal(c))
        return 0;
    return 1;
}

Object *PassengerCompartment::clone() {
    PassengerCompartment *a = new PassengerCompartment(*this);
    return a;
}

String *PassengerCompartment::toString() {
    String *result = new String("ID: ");
    char *temp = tostring(getid());
    String *temp2;
    result->concat(temp);
    delete temp;
    result->concat(", desc: ");
    temp2 = getdesc()->toString();
    result->concat(*temp2);
    delete temp2;
    result->concat(", ExtraSpace: ");
    if (NULL != ExtraSpace) {
        temp2 = ExtraSpace->toString();
        result->concat(*temp2);
        delete temp2;
    } else {
        result->concat("empty");
    }
    return result;
}

/*PRIVATE COMPARTMENT*/

PrivateCompartment::PrivateCompartment() {
    cout << "A PrivateCompartment has been created!" << endl;
}

PrivateCompartment::PrivateCompartment(PrivateCompartment& a) : PlaneComponent(a) {
    cout << "A PrivateCompartment has been created!" << endl;
}

PrivateCompartment::~PrivateCompartment() {
    cout << "A PrivateCompartment has been deleted!" << endl;
}

Object *PrivateCompartment::clone() {
    
}

/****EQUIPEMENT COMPARTMENT****/

EquipmentCompartment::EquipmentCompartment() {
    cout << "A EquipmentCompartment has been created!" << endl;
    getdesc()->concat(" - Private Compartment - Equipment Compartment");
}

EquipmentCompartment::EquipmentCompartment(EquipmentCompartment& a) : PrivateCompartment(a) {
    cout << "A EquipmentCompartment has been created!" << endl;
}

EquipmentCompartment::~EquipmentCompartment() {
    cout << "A EquipmentCompartment has been deleted!" << endl;
}


bool EquipmentCompartment::equal(Object &a) {
    PassengerCompartment *b = ((PassengerCompartment *) &a);
    return getdesc()->equal(*(b->getdesc()));
}

void EquipmentCompartment::ready_check() {
    getdesc()->print2();
    cout << ": Equipment Compartment is ready!" << endl;
}

void EquipmentCompartment::process(Employee *e) {
    e->workOn(this);
}

Object *EquipmentCompartment::clone() {
    EquipmentCompartment *a = new EquipmentCompartment(*this);
    return a;
}

String *EquipmentCompartment::toString() {
    String *result = new String("ID: ");
    char *temp = tostring(getid());
    String *temp2;
    result->concat(temp);
    delete temp;
    result->concat(", desc: ");
    temp2 = getdesc()->toString();
    result->concat(*temp2);
    delete temp2;
    return result;
}

/*******CARGO BAY******/
CargoBay::CargoBay() {
    cout << "A Cargo Bay has been created!" << endl;
    getdesc()->concat(" - Private Compartment - Cargo Bay");
}

CargoBay::CargoBay(CargoBay& a) : PrivateCompartment(a), ExtraSpace(*(a.getExtraSpace())) {
    cout << "A Cargo Bay has been created!" << endl;
}

CargoBay::~CargoBay() {
    cout << "A Cargo Bay has been deleted!" << endl;
}

bool CargoBay::equal(Object &a) {
    CargoBay *b = ((CargoBay *) &a);
    /*
     if (getid() == b->getid())
        return 1;
     */
    if (0 == getdesc()->equal(*(b->getdesc())))
        return 0;
    if (0 == getExtraSpace()->equal(*(b->getExtraSpace())))
        return 0;
    return 1;
}

void CargoBay::ready_check() {
    getdesc()->print2();
    cout << ": Cargo Bay is ready!" << endl;
    cout << "ExtraSpace: ";
    ExtraSpace.ready_check();
}

void CargoBay::process(Employee *e) {
    e->workOn(this);
}

Object *CargoBay::clone() {
    CargoBay *a = new CargoBay(*this);
    return a;
}

String *CargoBay::toString() {
    String *result = new String("ID: ");
    char *temp = tostring(getid());
    String *temp2;
    result->concat(temp);
    delete temp;
    result->concat(", desc: ");
    temp2 = getdesc()->toString();
    result->concat(*temp2);
    delete temp2;
    result->concat(", ExtraSpace: ");
    temp2 = ExtraSpace.toString();
    result->concat(*temp2);
    delete temp2;
    
    return result;
}

