/**
 * @file  television_driver_debug.hh
 * @brief This file contains the definition of the television
 *        driver used for debug purpose. It implements a proxy
 *        pattern to check assertions of proxied object.
 */

#include <memory>
#include "television_status.hh"
#include "television_driver.hh"

#ifndef TELEVISION_DRIVER_DEBUG_INCLUDE_GUARD
#define TELEVISION_DRIVER_DEBUG_INCLUDE_GUARD 1

/**
 * This television driver is used for debug purpose. It take an
 * other driver, like proxy pattern, to perform the core
 * operations. This is used to make assertion on pre conditions
 * before each operations and post condition after execution of
 * each methods. See TelevisionAdapter documentation to know
 * the Contracts to be checked.<br>
 * NOTE: The proxied object is taken as unique_ptr and the 
 *       ownership is moved to this object through std::move 
 *       function.
 */
class TelevisionDriverDebug : public TelevisionDriver {

public:
  /**
   * Constructor with one parameter. It initialize this adapter
   * using the one passed as parameter to have a proxy pattern
   * behavior.<br>
   * IMPORTANT: It is passed as unique_ptr and ownership is
   *            moved to this object throug std::move function.
   * @param television_driver - Smart pointer to the driver.
   *                            It must be not null.
   */
  explicit TelevisionDriverDebug(
      std::unique_ptr<TelevisionDriver> television_driver);

  /** Default destructor. */
  ~TelevisionDriverDebug();

  /** @inheritdoc */
  const TelevisionStatus&  get_video_status() const;
  /** @inheritdoc */
  void power_on();
  /** @inheritdoc */
  void power_off();

private:
  /** Not implemented. */
  TelevisionDriverDebug();
  /** Not implemented. */
  TelevisionDriverDebug(const TelevisionDriverDebug&);
  /** Not implemented. */
  TelevisionDriverDebug(const TelevisionDriverDebug&&);

  /**
   * Assertion method used to check that driver pointer is not
   * null.
   * @return True if _driver pointer is not null, false
   *         otherwise.
   */
  bool OK() const;
  
  /**
   * This is the inner adapter to debug. This object has its 
   * ownership through the unique_ptr smart pointer.
   */
  std::unique_ptr<TelevisionDriver> _driver;
};

#endif
