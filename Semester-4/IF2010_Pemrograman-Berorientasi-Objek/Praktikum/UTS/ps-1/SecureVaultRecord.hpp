#ifndef SECURE_VAULT_RECORD_HPP
#define SECURE_VAULT_RECORD_HPP

#include "BaseRecord.hpp"
#include <string>

class SecureVaultRecord : private BaseRecord {
  public:
    SecureVaultRecord(std::string author, int key);
};

#endif
