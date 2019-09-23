#include "Classes.h"

Plane::Plane() {
    cout << "A Plane has been created!" << endl;
    static unsigned int x = 0;
    capacity = (rand()%10 + 1)*100;
    NoofPassengerCompartments = capacity/100;
    PassengerCompartments = new PassengerCompartment*[NoofPassengerCompartments];
    for (int i = 0; i < NoofPassengerCompartments; i++)
        PassengerCompartments[i] = new PassengerCompartment;
    char *temp = tostring(x++);
    desc.concat("New Plane No");
    desc.concat(temp);
    title.concat("Boeing ");
    title.concat(temp);
    delete temp;
}

Plane::Plane(Plane& a) : Object(a), CargoBayNo1(*a.getCargoBayNo1()), 
        EquipmentCompartmentNo1(*a.getEquipmentCompartmentNo1()), 
        EquipmentCompartmentNo2(*a.getEquipmentCompartmentNo2()),
        EquipmentCompartmentNo3(*a.getEquipmentCompartmentNo3()),
        title(*a.gettitle()), desc(*a.getdesc()), capacity(a.getcapacity()),
        NoofPassengerCompartments(a.getNoofPassengerCompartments())
{
    cout << "A Plane has been created!" << endl;
    PassengerCompartments = new PassengerCompartment*[NoofPassengerCompartments];
    for (int i = 0; i < NoofPassengerCompartments; i++)
        PassengerCompartments[i] = new PassengerCompartment(*(a.getPassengerCompartments()[i]));
}

Plane::~Plane() {
    for (int i = 0; i < NoofPassengerCompartments; i++)
        delete PassengerCompartments[i];
    delete [] PassengerCompartments;
    cout << "A Plane has been deleted!" << endl;
}

bool Plane::equal(Object& a) {
    Plane *b = ((Plane*) &a);
    /*
    if (getid() == b->getid())
        return 1;
    */
    if (capacity != b->getcapacity())
        return 0;
    if (NoofPassengerCompartments != b->getNoofPassengerCompartments())
        return 0;
    if (0 == title.equal(*(b->gettitle())))
        return 0;
    if (0 == desc.equal(*(b->getdesc())))
        return 0;
    if (0 == CargoBayNo1.equal(*(b->getCargoBayNo1())))
        return 0;
    if (0 == EquipmentCompartmentNo1.equal(*(b->getEquipmentCompartmentNo1())))
        return 0;
    if (0 == EquipmentCompartmentNo2.equal(*(b->getEquipmentCompartmentNo2())))
        return 0;
    if (0 == EquipmentCompartmentNo3.equal(*(b->getEquipmentCompartmentNo3())))
        return 0;
    
    for (int i = 0; i < NoofPassengerCompartments; i++)
        if (0 == PassengerCompartments[i]->equal(*(b->getPassengerCompartments()[i])))
            return 0;
    
    return 1;
}

Object *Plane::clone() {
    Plane *a = new Plane(*this);
    return a;
}

String *Plane::toString() {
    String *result = new String("ID: ");
    char *temp = tostring(getid());
    result->concat(temp);
    delete temp;
    result->concat(", desc: ");
    result->concat(desc);
    result->concat(", title: ");
    result->concat(title);
    result->concat(", capacity: ");
    temp = tostring(capacity);
    result->concat(temp);
    delete temp;
    result->concat(", NoofPassengerCompartments: ");
    temp = tostring(NoofPassengerCompartments);
    result->concat(temp);
    delete temp;
    
    
    String *temp2;
    for (unsigned int i = 0; i < NoofPassengerCompartments; i++) {
        temp = tostring(i);
        result->concat(", PassengerCompartmentNoo");
        result->concat(temp);
        result->concat(": ");
        delete temp;
        temp2 = PassengerCompartments[i]->toString();
        result->concat(*temp2);
        delete temp2;
    }
    
    result->concat(", EquipmentCompartmentNo1: ");
    temp2 = EquipmentCompartmentNo1.toString();
    result->concat(*temp2);
    delete temp2;
    result->concat(", EquipmentCompartmentNo2: ");
    temp2 = EquipmentCompartmentNo2.toString();
    result->concat(*temp2);
    delete temp2;
    result->concat(", EquipmentCompartmentNo3: ");
    temp2 = EquipmentCompartmentNo3.toString();
    result->concat(*temp2);
    delete temp2;
    result->concat(", CargoBayNo1: ");
    temp2 = CargoBayNo1.toString();
    result->concat(*temp2);
    delete temp2;
    
    return result;
    
}

void Plane::process(Employee* e) {
    e->workOn(this);
}

void Plane::ready_check() {
    
    for (int i = 0; i < NoofPassengerCompartments; i++)
        PassengerCompartments[i]->ready_check();
    EquipmentCompartmentNo1.ready_check();
    EquipmentCompartmentNo2.ready_check();
    EquipmentCompartmentNo3.ready_check();
    CargoBayNo1.ready_check();
    
    cout << "Plane ready to take off!" << endl;
}

