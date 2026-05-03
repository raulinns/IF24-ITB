#ifndef PUBLIC_RECORD_HPP
#define PUBLIC_RECORD_HPP

#include "BaseRecord.hpp"
#include <string>

class PublicRecord : public BaseRecord {
  public:
    PublicRecord(std::string author, int key);
    int calculateClearance() const override;
};

#endif
