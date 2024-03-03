#include "kvdb.h"

using namespace kvdb;

KVDB::KVDB() {}

Database KVDB::create_empty_DB(std::string &db_name) {
    return Database::create_empty(db_name);
}

Database KVDB::load_db(std::string &db_name) {
    return Database::load(db_name);
}
