#include <libcec/cec.h>
#include <memory>
#include <iostream>
#include "../include/tv_driver/cec_television_driver.hh"

/*
 * This function is used to check if the video is on. This is 
 * used because condition to check if it is on are complex. 
 * LibCEC has two status to indicate video powering on and 
 * this method compare the parameter passed to them. In this 
 * way let avoid a long row inside the if condition in 
 * update_status method. <br>
  * @param status - Current power status get through the libCEC.
 */
bool is_video_on(const CEC::cec_power_status& status) {
  //I use a break statement '\' because line is too long for
  // 62 character rule.
  return status == CEC::cec_power_status::CEC_POWER_STATUS_ON
      ||  status == CEC::cec_power_status::\
      CEC_POWER_STATUS_IN_TRANSITION_ON_TO_STANDBY;
}

CecTelevisionDriver::CecTelevisionDriver()
  : TelevisionDriver(),
    _adapter(NULL),
    _callbacks(),
    _config(),
    _connection(),
    _video_status() {
  
  _config.Clear();
  _callbacks. Clear();
  _config.clientVersion = CEC::LIBCEC_VERSION_CURRENT;
  _config.bActivateSource = 0;
  _config.callbacks = &_callbacks;
  _config.deviceTypes.Add(
      CEC::CEC_DEVICE_TYPE_PLAYBACK_DEVICE);
  _adapter = (CEC::ICECAdapter*)CECInitialise(&_config);
          
  /* C++11 has not std::make_unique, so I simulate it creating
   * a temp unique_ptr and move it on _connection. 
   */
  std::unique_ptr<CecTelevisionConnection> tmp(
      new CecTelevisionConnection(_adapter));
  _connection = std::move(tmp);
  if(!(_connection -> is_connected())) {
    _connection -> connect();
  }
  update_status();
}

CecTelevisionDriver::~CecTelevisionDriver() {
  /* 
   * The reset is needed to destroy connection before release
   * adapter pointer. 
   */
  _connection.reset();
  CECDestroy(_adapter);
}

const TelevisionStatus&
CecTelevisionDriver::get_video_status() const {
    return _video_status;
}

void CecTelevisionDriver::power_on() {
#ifndef NDEBUG
  std::cout << "Powering on ..." << std::endl;
#endif
    bool is_on = _adapter -> PowerOnDevices();
  if(is_on) {
    _video_status.power_status = on;
#ifndef NDEBUG
  std::cout << "Powered on" << std::endl;
#endif
  } else {
    _video_status.power_status = off;
#ifndef NDEBUG
  std::cerr << "Cannot power on" << std::endl;
#endif
  }  
}

void CecTelevisionDriver::power_off() {
#ifndef NDEBUG
  std::cout << "Powering off ..." << std::endl;
#endif
    bool is_off = _adapter -> StandbyDevices();
    if(is_off) {
	_video_status.power_status = off;
#ifndef NDEBUG
	std::cout << "Powered off" << std::endl;
#endif
    }
#ifndef NDEBUG
    else{
      std::cerr << "Cannot power off" << std::endl;
    }
#endif
}

void CecTelevisionDriver::update_status() {
  CEC::cec_logical_address address =
    CEC::cec_logical_address::CECDEVICE_TV;
  CEC::cec_power_status status =
    _adapter -> GetDevicePowerStatus(address);
  if(is_video_on(status)) {
    _video_status.power_status = on;
  } else {
    _video_status.power_status = off;
  }
}

//TO IMPLEMENT
#include <iostream>
void CecTelevisionDriver::go_to(int channel) {
  std::cout << "Change to channel: " << channel;
}
