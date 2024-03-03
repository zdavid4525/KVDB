#ifndef KVDB_H
#define KVDB_H

#include <string>
#include "database.h"

class KVDB
{
public:
    KVDB();

    static Database create_empty_DB(std::string &db_name);

    static Database load_db(std::string &db_name);
};

#endif // KVDB_H
