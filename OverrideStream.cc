#include <iostream>

template<typename T>
std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e) {
  return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

enum class new_enum{
  value1,
  value2,
  value3 = 100,
  value4 = 100
};

int main() {
  std::cout << new_enum::value1 << std::endl;
  return 0;
} 
