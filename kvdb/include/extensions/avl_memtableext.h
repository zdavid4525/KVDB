#ifndef AVL_MEMTABLEEXT_H
#define AVL_MEMTABLEEXT_H

#include "memtable.h"


namespace kvdbext {

class AvlMemTable : public IMemTable {
    ~AvlMemTable() {}

    void put(std::string key, std::string value);

    std::string get(std::string key);

private:
    class Impl;
    std::unique_ptr<Impl> impl;
};
}

#endif // AVL_MEMTABLEEXT_H
