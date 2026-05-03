#ifndef INTERNAL_RECORD_HPP
#define INTERNAL_RECORD_HPP

#include "BaseRecord.hpp"
#include <string>

class InternalRecord : protected BaseRecord {
  public:
    InternalRecord(std::string author, int key);
    int peekSecurity() const;
};

#endif
