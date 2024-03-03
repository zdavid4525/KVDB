#ifndef DATABASE_H
#define DATABASE_H

#include <string>

class Database
{
public:
    Database(std::string db_name, std::string full_path);

    std::string get_directory(void);

    static Database create_empty(std::string db_name);

protected:
    std::string name;
    std::string full_path;
};

#endif // DATABASE_H
