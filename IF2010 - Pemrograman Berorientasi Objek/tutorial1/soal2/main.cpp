# include "A.hpp"

int main(){
    A x('1');
    A y('2');
    A xx = x;
    xx = y;
    xx.show();
}