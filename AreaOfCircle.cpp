#include <iostream>

class circle {
  private:
    float PI = 3.14159;
    int radius;

  protected:

  public:
    circle(int radius) {
      this->radius = radius;
    };
    
    ~circle() {
      std::cout << "\nDone";
    }

    float area() {
      return PI * (radius * radius);
    }

    int getRadius() {
      return radius;
    }
    void setRadius(int radius) {
      this->radius = radius;
    }
};


int main() {
  circle myCircle(27);
  std::cout << "Area: " << myCircle.area() << std::endl;
  
  myCircle.setRadius(37);
  std::cout << "Area: " << myCircle.getRadius() << std::endl;
  std::cout << "Area: " << myCircle.area() << std::endl;
  
  return 0;
}