#ifndef MEMTABLE_H
#define MEMTABLE_H

#include <string>

class IMemTable {
public:
    virtual ~IMemTable() {}

    virtual void put(std::string key, std::string value) = 0;

    virtual std::string get(std::string key) = 0;
};

#endif // MEMTABLE_H
