#include<iostream>
#include<type_traits>

/*
  std::result_of<function(Args..)>::type
  返回函数的返回类型
*/

int fn(int) {return int();}

typedef int(&fnRef)(int);
typedef int(*fnPtr)(int);
struct FnClass {
  int operator()(int i) {
    return i;
  }
};

int main() {
  typedef std::result_of<decltype(fn)&(int)>::type A;
  typedef std::result_of<fnRef(int)>::type B;
  typedef std::result_of<fnPtr(int)>::type C;
  typedef std::result_of<FnClass(int)>::type D;
  

  std::cout << std::boolalpha;
  std::cout << "typedefs of int:" << std::endl;
  
  std::cout << "A: " << std::is_same<int, A>::value << std::endl;
  std::cout << "B: " << std::is_same<int, B>::value << std::endl;
  std::cout << "C: " << std::is_same<int, C>::value << std::endl;
  std::cout << "D: " << std::is_same<int, D>::value << std::endl;

  return 0;
}
