#include<assert.h>
#include "../include/tv_driver/cec_television_connection.hh"

CecTelevisionConnection::
CecTelevisionConnection(adapter* target_adapter)
  : _adapter(target_adapter),
    _is_connected(false) {
  assert(OK());
}

CecTelevisionConnection::~CecTelevisionConnection() {
  assert(OK());
  if(_is_connected) {
    _adapter -> Close();
  }
  assert(OK());
}

void CecTelevisionConnection::connect() {
  CEC::cec_adapter_descriptor descriptor[5];
  assert(OK());
  int number =
    _adapter -> DetectAdapters(descriptor, 10, NULL);
  if(number > 0) {
    _adapter -> InitVideoStandalone();
    _is_connected =
      _adapter -> Open(descriptor[0].strComName);    
  } else {
    _is_connected = false;
  }
  assert(OK());
}

bool CecTelevisionConnection::is_connected() const {
  assert(OK());
  return _is_connected;
}

bool CecTelevisionConnection::OK() const {
  return _adapter != NULL;
}
