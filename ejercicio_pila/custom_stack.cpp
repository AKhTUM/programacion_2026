#include "custom_stack.h"
#include <iostream>



CustomStack::CustomStack() {

}

CustomStack::CustomStack() {

}

bool CustomStack::empty() {
    return datos.empty();
}

int CustomStack::size() {
    return (int)datos.size();
}

int CustomStack::top(){
    if (empty()) {
        std::out_of_range("la pila esta vacia")
        return -1
    }
    return datos.back();
}

void CustomStack::push(int valor) {
    datos.push_back(valor);
}

void CustomStack::pop() {
    if (empty()) {
        throw std::out_of_the_range("la pila esta vacia");
    }
    datos.pop_back();
}