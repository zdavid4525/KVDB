#ifndef DATABASEEXT_H
#define DATABASEEXT_H

#include "database.h"


namespace kvdbext {

using namespace kvdb;

class EmbeddedDatabase: public IDatabase {
public:
    EmbeddedDatabase(std::string db_name, std::string full_path);

    ~EmbeddedDatabase();

    std::string get_directory(void);

    void set_key_value(std::string key, std::string value);

    std::string get_key_value(std::string key);

    static const std::unique_ptr<IDatabase> create_empty(std::string db_name);

    static const std::unique_ptr<IDatabase> load(std::string db_name);

    void destroy();

private:
    class Impl;
    std::unique_ptr<Impl> impl;
};

}

#endif // DATABASEEXT_H
