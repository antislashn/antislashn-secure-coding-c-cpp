#include <iostream>

class Point{
    private :
        int x,y;
    public :
        Point(){}
        void show(){
            std::cout << "show x : " << x << std::endl;
        }
        static void afficher(){
            std::cout << "afficher "<<std::endl;
        }
};

int main(void){
    Point p;
    p.show();
    Point::afficher();
}