#include <memory>
#include <assert.h>
#include "../include/tv_driver/television_status.hh"
#include "../include/tv_driver/television_driver_debug.hh"


TelevisionDriverDebug::TelevisionDriverDebug(
    std::unique_ptr<TelevisionDriver> driver)
    : TelevisionDriver(),
      _driver(std::move(driver)) {
  assert(OK());
}
TelevisionDriverDebug::~TelevisionDriverDebug() { }

const TelevisionStatus&
TelevisionDriverDebug::get_video_status() const  {
  assert(OK());
  const TelevisionStatus& status =
    _driver -> get_video_status();
  assert(OK());
  return status;
}

void TelevisionDriverDebug::power_on() {
  assert(OK() && get_video_status().power_status == off);
  _driver -> power_on();
  assert(OK() && get_video_status().power_status == on);
}

void TelevisionDriverDebug::power_off() {
  assert(OK() && get_video_status().power_status == on);
  _driver -> power_off();
  assert(OK() && get_video_status().power_status == off);
}

bool TelevisionDriverDebug::OK() const {
  return _driver.get() != NULL;
}
