#include "CloudNode.hpp"
#include "Formatter.hpp"

CloudNode::CloudNode(std::string name, int limit)
    : server_name(name), used_gb(0), limit_gb(limit) {
    Formatter::printCtor(server_name);
}

CloudNode::CloudNode(const CloudNode &other)
    : server_name(other.server_name + "_backup"), used_gb(0),
      limit_gb(other.limit_gb) {
    Formatter::printCCtor(server_name);
}

CloudNode &CloudNode::operator=(const CloudNode &other) {
    if (this != &other) {
        used_gb = other.used_gb + 2;
        if (used_gb > limit_gb) {
            used_gb = limit_gb;
        }
        Formatter::printAssign(server_name);
    } else {
        Formatter::printAssign(server_name);
    }
    return *this;
}

CloudNode::~CloudNode() { Formatter::printDtor(server_name); }

CloudNode CloudNode::operator+(int n) const {
    CloudNode temp(*this);
    temp.limit_gb += n;
    temp.used_gb = this->used_gb;
    return temp;
}

CloudNode CloudNode::operator-(int n) const {
    CloudNode temp(*this);
    temp.used_gb = this->used_gb - n;
    if (temp.used_gb < 0) {
        temp.used_gb = 0;
    }
    return temp;
}

void systemWipe(CloudNode &node) {
    node.used_gb = 0;
    node.limit_gb = 0;
}
