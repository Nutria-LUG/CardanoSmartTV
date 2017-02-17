#include "../include/driver_factory.hh"
#include <iostream>

int main() {
  TelevisionDriver *driver = create_television_driver();
  driver -> go_to(1);
  if((driver -> get_video_status()).power_status == on) {
    driver -> power_off();
  } else {
    driver -> power_on();
  }
  return 0;
}
