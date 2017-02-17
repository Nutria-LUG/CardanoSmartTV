#include "../include/driver_factory.hh"
#include <iostream>

int main() {
  TelevisionDriver *driver = create_television_driver();
  if(driver -> get_video_status().power_status == on) {
      std::cout << "Tv ON" << std::endl;
  } else {
      std::cout << "Tv OFF" << std::endl;
  }
  return 0;
}
