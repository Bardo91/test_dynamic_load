
#include <library.h>
#include <iostream>


class triangle : public ext::Shape{
    void name() override{
        std::cout << "triangle" << std::endl;
    }
};


class square : public ext::Shape{
    void name() override{
        std::cout << "square" << std::endl;
    }
};



class circle : public ext::Shape{
    void name() override{
        std::cout << "circle" << std::endl;
    }
};


extern "C" ext::Shape* factory(std::string _name){
    if(_name == "triangle"){
        return new triangle;
    }else if(_name == "square"){
        return new square;
    }else if(_name == "circle"){
        return new circle;
    }else{
        return nullptr;
    }
}

extern "C" void dummyFun(){
    std::cout <<"I am dummy" << std::endl;
}