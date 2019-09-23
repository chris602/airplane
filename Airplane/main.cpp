#include "Classes.h"


int main(int argc, char** argv) {
    srand(time(NULL));
    //cout << time(NULL) << endl;
    SecurityEmployee s;
    Object &y = s;
    
    clone_encrypt_and_print(y);
    
    return 0;
    Plane x;
    SecurityEmployee se;
    MaintanceEmployee me;
    CleaningEmployee ce;
    
    x.process(&se);
    x.process(&me);
    x.process(&ce);
    
    x.ready_check();
    clone_encrypt_and_print(y);
    return 0;
}

