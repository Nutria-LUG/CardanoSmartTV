#include <memory>
#include "../include/driver_factory.hh"
#include "../include/tv_driver/cec_television_driver.hh"
#include "../include/tv_driver/television_driver_debug.hh"

TelevisionDriver* create_television_driver() {
    #ifdef NDEBUG
    static std::unique_ptr<TelevisionDriver>
	driver(new CecTelevisionDriver());
    #else
    
    std::unique_ptr<TelevisionDriver>
	proxied(new CecTelevisionDriver());

    static std::unique_ptr<TelevisionDriver>
	driver(new TelevisionDriverDebug(std::move(proxied)));
    #endif
    
    return driver.get();
}
