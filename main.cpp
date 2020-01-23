#include <library.h>
#include <dlfcn.h>

#include <functional>
#include <iostream>
using namespace std;
#include <string>

int main(){

    void *hndl = dlopen("libext_lib.so", RTLD_NOW);
    if(hndl == nullptr){
        cerr << dlerror() << endl;
        exit(-1);
    }

    dlerror();

    typedef ext::Shape* (*Factory)(std::string);
    void *mkr = dlsym(hndl, "factory");
    Factory factory = (Factory) mkr;

    const char *dlsym_error = dlerror();    
    if (dlsym_error) {
        cerr << "Cannot load symbol 'factory': " << dlsym_error <<            '\n';
    }

    ext::Shape * triangle = factory("triangle");
    ext::Shape * square = factory("square");
    ext::Shape * circle = factory("circle");

    triangle->name();
    square->name();
    circle->name();

}