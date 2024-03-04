#ifndef KVDB_H
#define KVDB_H

#include <string>
#include "database.h"

namespace kvdb {

class KVDB
{
public:
    KVDB();

    static const std::unique_ptr<IDatabase> create_empty_DB(std::string &db_name);

    static const std::unique_ptr<IDatabase> load_db(std::string &db_name);
};

}

#endif // KVDB_H
