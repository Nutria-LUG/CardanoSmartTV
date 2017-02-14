/**
 * @file  cec_television_connection.hh
 * @brief This file contains the definition of the connection
 *        object used to check status of the cec device and
 *        connect it when it is not connected.
 */
#include <libcec/cec.h>

#ifndef CEC_TELEVISION_CONNECTION_INCLUDE_GUARD
#define CEC_TELEVISION_CONNECTION_INCLUDE_GUARD 1

/**
 * This class represent the connection of the cec device to a 
 * television that support it. This is used to have RAII
 * behavior on connection.
 */
class CecTelevisionConnection {
private:
  /** Typedefinition of the cec adapter. */
  typedef CEC::ICECAdapter adapter;
public:
  /**
   * Constructor with one parameter. This initialize the 
   * connection through the adapeter passed as parameter.
   * <br>
   * Connection is initialize to disconnected state, to perform 
   * the connection use the connect method.
   * @param target_adapter - Pointer to CEC adapter to connect.
   *                         It must be not NULL.
   */
  explicit CecTelevisionConnection(adapter* target_adapter);
  
  /**
   * Destructor. Check if the adapter is connected and release
   * it if needed.
   */
  ~CecTelevisionConnection();

  /**
   * Open a connection to the television through the adapter.
   *
   * === CONTRACT ===
   * @pre  Connection must be closed, is_connected must return
   *       false. 
   * @post No exception thrown.
   */
  void connect();
  
  /**
   * Check if the connection with the television is opened.
   * @return True if the connection is open, false otherwise. 
   *
   * === CONTRACT ===
   * @pre  No preconditions.
   * @post No exception thrown.
   */
  bool is_connected() const;

private:
  /** Not implemented. */
  CecTelevisionConnection();
  /** Not implemented. */
  CecTelevisionConnection(const CecTelevisionConnection&);
  /** Not implemented. */
  CecTelevisionConnection(const CecTelevisionConnection&&);

  /**
   * Assetion method. It is used to check that the adapter is 
   * not null in the assertions for debug purposes.
   * @return True if the adapter is not null, false otherwise.
   */
  bool OK() const;
  /**
   * Pointer to the cec adapter to connect.
   * @private
   */
  adapter* _adapter;
  /**
   * Boolean value used to know if the connection to the
   * adapter is opened.
   * @private
   */
  bool     _is_connected;
  
};

#endif
