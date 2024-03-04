#include "kvdb.h"
#include "extensions/databaseext.h"

using namespace kvdb;
using namespace kvdbext;

KVDB::KVDB() {}

const std::unique_ptr<IDatabase> KVDB::create_empty_DB(std::string &db_name) {
    return EmbeddedDatabase::create_empty(db_name);
}

const std::unique_ptr<IDatabase> KVDB::load_db(std::string &db_name) {
    return EmbeddedDatabase::load(db_name);
}
