/** 
 * @file  driver_factory.hh
 * @brief This file contains the factory function used to
 *        create the television driver.
 */

#include "./tv_driver/television_driver.hh"

#ifndef DRIVER_FACTORY_INCLUDE_GUARD
#define DRIVER_FACTORY_INCLUDE_GUARD 1

/**
 * Create a an instance of television driver according to the
 * compiler flag: release or debug version according to NDEBUG
 * flag.<br>
 * It implements a singleton pattern, so if it called twice, 
 * both pointers points to the same object.
 * @return A pointer to the television driver. <br>
 *         IMPORTANT: The ownership is satic scope so the
 *                    requestor must not matter of driver
 *                    destruction.
 */
TelevisionDriver* create_television_driver();
#endif
