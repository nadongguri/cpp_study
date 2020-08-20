#include <iostream>

// #define ERROR

class DriverProvider {
 public:
  DriverProvider() = default;
  virtual ~DriverProvider() = default;
  #ifdef ERROR
  explicit DriverProvider(const DriverProvider&) { 
  #else
  DriverProvider(const DriverProvider&) { 
  #endif
    std::cout << "DriverProvider(const DriverProvider&)" << std::endl;
  }
  DriverProvider& operator=(const DriverProvider&) {
    std::cout << "DriverProvider& operator=(const DriverProvider&)" << std::endl;
  }
};

class DriverProviderDelete {
 public:
  DriverProviderDelete() = default;
  virtual ~DriverProviderDelete() = default;
  DriverProviderDelete(const DriverProviderDelete&) = delete; 
  DriverProviderDelete& operator=(const DriverProviderDelete&) = delete;
};


int main(void) {

    DriverProvider driverProvider;
    DriverProvider driverProvider2(driverProvider); // DriverProvider(const DriverProvider&)
    DriverProvider driverProvider2_1 = driverProvider2; // explict DriverProvider(const DriverProvide&) will occur error!

    DriverProvider driverProvider3;
    driverProvider3 = driverProvider2; // DriverProvider& operator=(const DriverProvider&)


    DriverProviderDelete dpd;
  #ifdef ERROR
    DriverProviderDelete dpd2(dpd); // error: use of deleted function ‘DriverProviderDelete::DriverProviderDelete(const DriverProviderDelete&'
  #endif
    DriverProviderDelete dpd3;
  #ifdef ERROR
    dpd3 = dpd; // error: use of deleted function ‘DriverProviderDelete& DriverProviderDelete::operator=(const DriverProviderDelete&)’
  #endif
    return 0;
}
