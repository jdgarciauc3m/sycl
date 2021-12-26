#include <iostream>

#include <CL/sycl.hpp>

int main() {
  std::string s = "En un lugar de la mancha de cuyo nombre no quiero "
                  "acordarme";

  sycl::queue q;
  auto r = sycl::malloc_shared<char>(s.size()+1, q);
  std::copy_n(s.begin(), s.size()+1, r);

  q.parallel_for(s.size()+1, [=](auto & i) {
    r[i] +=1;
  }).wait();

  std::cout << "s.size = " << s.size() << "\n";
  std::cout << "[" << s << "]\n";
  std::cout << "[" << r << "]\n";
  return 0;
}
