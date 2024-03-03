#ifndef DATABASE_H
#define DATABASE_H

#include <string>

namespace kvdb {

class Database
{
public:
    Database(std::string db_name, std::string full_path);

    std::string get_directory(void);

    void set_key_value(std::string key, std::string value);

    std::string get_key_value(std::string key);

    static Database create_empty(std::string db_name);

    static Database load(std::string db_name);

    void destroy();

protected:
    std::string name;
    std::string full_path;
};

}

#endif // DATABASE_H
