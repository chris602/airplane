#include "Classes.h"

Object *String::clone() {
    String *b = new String(*this);
    return b;
}

bool String::equal(Object &a) {
    String *b = ((String *)&a);
    
    if (this->length() != b->length())
        return 0;
    
    char *temp1 = get(), *temp2 = b->get();
    int templength = this->length();
    
    for (int i = 0; i < templength; i++)
        if (temp1[i] != temp2[i])
            return 0;
    
    return 1;
}

String::String() {
    cout << "A String has been created" << endl;
    word = NULL;
    letters = 0;
}

String::String(char *original) {
    cout << "A String has been created" << endl;
    letters = 0;
    for (int i = 0; '\0' != original[i]; i++)
        letters++;

    word = new char[letters + 1];
    memcpy(word, original, letters + 1);
}

String::String(String &original) {
    cout << "A String has been created" << endl;
    char *temp = original.get();
    letters = original.length();
    word = new char[letters + 1];
    memcpy(word, temp, letters + 1);
}

String::~String() {
    cout << "A String has been deleted" << endl;
    if (NULL != word) delete word;
}

void String::clear() {
    delete word;
    word = NULL;
    letters = 0;
}

void String::concat(char *extension) {
    char *temp = word;
    int length = 0;
    for (int i = 0; '\0' != extension[i]; i++)
        length++;

    word = new char[letters + length + 1];
    memcpy(word, temp, letters);
    memcpy(word + letters, extension, length + 1);
    delete temp;
    letters += length;
}

void String::concat(String &extension) {
    char *temp = word, *temp2 = extension.get();
    if (NULL == temp2)
        return;
    int length = extension.length();

    word = new char[letters + length + 1];
    memcpy(word, temp, letters);
    memcpy(word + letters, temp2, length + 1);
    delete temp;
    letters += length;
}

void String::print() {
    if (NULL == word) {
        cout << "NULL" << endl;
        return;
    }
    cout << word << endl;
}

void String::print2() {
    if (NULL == word) {
        cout << "NULL";
        return;
    }
    cout << word;
}


char String::at(int position) {
    if (0 > position || letters <= position)
        return '\0';
    return word[position];
}

void String::updateAt(char character, int position) {
    if (0 > position || letters <= position)
        return;
    word[position] = character;
}

String *String::toString() {
    String *result = new String("word: ");
    result->concat(*this);
    result->concat(", letters: ");
    char *temp = tostring(letters);
    result->concat(temp);
    delete temp;
    return result;
}

