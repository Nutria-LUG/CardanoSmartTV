#include "../include/driver_factory.hh"

int main() {
  TelevisionDriver *driver = create_television_driver();
  /* Use driver to control television. */
  return 0;
}
