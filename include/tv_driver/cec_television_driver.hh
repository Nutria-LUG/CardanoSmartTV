/**
 * @file cec_television_driver.hh
 * @brief This file contains the television driver implemented
 *        through the libcec.
 */

#include <memory>
#include <libcec/cec.h>
#include "television_driver.hh"
#include "television_status.hh"
#include "cec_television_connection.hh"

#ifndef CEC_TELEVISION_DRIVER_INCLUDE_GUARD
#define CEC_TELEVISION_DRIVER_INCLUDE_GUARD 1

/**
 * This is an adapter used to handle a television through HDMI 
 * cable. This use the LibCEC to perform operations.
 */
class CecTelevisionDriver : public TelevisionDriver {

public:  
  /**
   * Default constructor. Initialize each data and television's
   * connection.
   */    
  CecTelevisionDriver();
  /** Default destructor. It release used resources. */
  ~CecTelevisionDriver();

  /** @inheritdoc */
  const TelevisionStatus& get_video_status() const;
    /** @inheritdoc */
  void power_on();
  /** @inheritdoc */
  void power_off();
  
private: 
  /**
   * This method is used to update status of the television. 
   * It use the CEC adapter to check the connection and if 
   * it is on or off; then update the _video_status.
   */
  void update_status();
  
  /** Pointer to the video adapter object of libCEC. */
  CEC::ICECAdapter* _adapter;
  
  /** 
   * Callbacks object usd in the adapter initialization.
   */
  CEC::ICECCallbacks _callbacks;
  
  /** 
   * Configuration object used to initialize the libCEC
   * adapter.
   */
  CEC::libcec_configuration _config;
  
  /**
   * Connection object. It is used to handle the opening and
   * closing of connection as RAII (Resource Aquisition Is
   * Initialization) paradigm. It use an unique_ptr smart 
   * pointer to have the owenrship of the object.<br>
   * IMPORTANT: At now there is not a virtual behavior, but 
   *            it can be an hipotesis. So I instance it as 
   *            pointer to have override.
   */
  std::unique_ptr<CecTelevisionConnection> _connection;

  /** Television status object. */
  TelevisionStatus _video_status;
};
 
#endif
