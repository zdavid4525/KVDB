#include "database.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

Database::Database(std::string db_name, std::string full_path)
    : name(db_name), full_path(full_path)
{
    ;
}

std::string Database::get_directory() {
    return full_path;
}

Database Database::create_empty(std::string db_name) {
    std::string base_dir(".kvdb");
    if (!fs::exists(base_dir)) {
        fs::create_directory(base_dir);
    }

    std::string db_folder(base_dir + "/" + db_name);
    if (!fs::exists(db_folder)) {
        fs::create_directory(db_folder);
    }

    return Database(db_name, db_folder);
}
