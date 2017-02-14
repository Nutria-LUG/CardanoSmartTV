/**
 * @file  television_driver.hh
 * @brief This file contains the defintion of the television 
 *        driver class used to perform operation on tv. This is
 *        an abstract class.
 */

#include <memory>
#include "television_status.hh"

#ifndef TELEVISION_DRIVER_INCLUDE_GUARD 
#define TELEVISION_DRIVER_INCLUDE_GUARD 1

/**
 * This class is an abstract class used to represent a generic 
 * video. It is a wrapper for libraries used to handle with 
 * theme.
 */
class TelevisionDriver {

public:
  /** Default constructor. */
  TelevisionDriver();

  /** Virtual Destructor */
  virtual ~TelevisionDriver();

  /**
   * This method gets the current status of the video.
   * @return A struct that describe the status of teh video.
   *
   * == CONTRACT ==
   * @pre  No preconditions.
   * @post Returned pointer is not NULL.
   */
  virtual const TelevisionStatus&
  get_video_status() const = 0;

  /**
   * Power on the television. It must be called if the
   * television is powered off.
   *
   * == CONTRACT ==
   * @pre  Video must be powered off. See get_video_status.
   * @post Video is powered on, its power_status is on.
   */
  virtual void power_on() = 0;

  /**
   * Power off the television. It must be called if the 
   * television is powered on.
   *
   * == CONTRACT ==
   * @pre  Video must be powered on. See get_video_status.
   * @post Video is powered off, its power_status is off.
   */
  virtual void power_off() = 0;
};

#endif
