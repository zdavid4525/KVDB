#ifndef DATABASE_H
#define DATABASE_H

#include <string>

namespace kvdb {

class IDatabase
{
public:
    IDatabase() = default;

    virtual ~IDatabase() = default;

    virtual std::string get_directory(void) = 0;

    virtual void set_key_value(std::string key, std::string value) = 0;

    virtual std::string get_key_value(std::string key) = 0;

    static const std::unique_ptr<IDatabase> create_empty(std::string db_name);

    static const std::unique_ptr<IDatabase> load(std::string db_name);

    virtual void destroy() = 0;

};
}

#endif // DATABASE_H
