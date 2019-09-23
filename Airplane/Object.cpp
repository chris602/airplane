#include "Classes.h"

Object::Object() {
    static int new_id = 0;
    id = new_id;
    cout << "An Object has been created!" << endl;
    new_id++;
}

Object::Object(Object& a) : id(a.getid()) {
    cout << "An Object has been created!" << endl;
}

Object::~Object() {
    cout << "An Object has been deleted!" << endl;
}

char *tostring(unsigned int number) {
    unsigned int digits = 0, temp = number;
    char *result = NULL;
    if (0 == number) {
        result = new char[2];
        result[0] = '0';
        result[1] = 0;
        return result;
    }

    while (0 != temp) {
        digits++;
        temp /= 10;
    }
    result = new char[digits + 1];
    result[digits--] = 0;
    while (0 != number) {
        result[digits--] = number%10 + '0';
        number /= 10;
    }

    return result;
}OBJECT


void clone_encrypt_and_print(Object &a) {
    Object *b = a.clone();

    if (0 == a.equal(a))
        cout << "Not Equal" << endl;
    else
        cout << "Equal" << endl;

    if (0 == a.identical(*b))
        cout << "Not Identical" << endl;
    else
        cout << "Identical" << endl;

    String *string1 = a.toString(), *string2 = b->toString();

    int length = string1->length();
    int end = rand() % length + 1;
    for (int i = 0; i < end; i++)
        string2->updateAt(rand()% 26 + 'a', rand()%length);
    string1->print();
    string2->print();

    String *string3 = new String(*string1);
    string3->concat(*string2);
    cout << "Length: " << string3->length() << endl;
    cout << "Middle character(s): " << string3->at(string3->length()/2);
    if (0 == string3->length()%2)
        cout << string3->at(string3->length()/2 +1) << endl;
    else
        cout << endl;

    string3->clear();
    cout << "Length: " << string3->length() << endl;
    delete string1;
    delete string2;
    delete string3;
}


