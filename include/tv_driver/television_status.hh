/**
 * @file  television_status.hh
 * @brief This file contains the struct used to represent the 
 *        status of the telvision.
 */

#ifndef TELEVISION_STATUS_INCLUDE_GUARD
#define TELEVISION_STATUS_INCLUDE_GUARD 1

/**
 * This is an enumeration type used to represent the status of 
 * the video's power: on or off.
 */
enum PowerStatus {
  /** Video is off or in stand by. */
  off = 0,
  /** Video is on or is powering on. */
  on = 1,
};

/**
 * @brief Status of the television.
 * This struct is used to store the informations of the video's
 * status.
 */
struct TelevisionStatus {
  /** Default constructor. */
  TelevisionStatus();
  /** Default destructor. */
  ~TelevisionStatus();

  /**
   * This is the current power status of the video. It is used 
   * to check if it is on or off.
   */
  PowerStatus power_status;
};

#endif
