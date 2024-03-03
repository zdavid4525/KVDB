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

void Database::set_key_value(std::string key, std::string value) {
    std::ofstream out_file;

    out_file.open(full_path + "/" + "_string.kv", std::ios::out | std::ios::trunc);
    out_file << value;

    out_file.close();
}

std::string Database::get_key_value(std::string key) {
    std::ifstream in_file(full_path + "/" + "_string.kv");
    std::string value;

    in_file.seekg(0, std::ios::end);
    value.reserve(in_file.tellg());

    in_file.seekg(0, std::ios::beg);
    value.assign((std::istreambuf_iterator<char>(in_file)), std::istreambuf_iterator<char>());

    in_file.close();
    return value;
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

Database Database::load(std::string db_name) {
    std::string base_dir(".kvdb");
    std::string db_folder(base_dir + "/" + db_name);

    return Database(db_name, db_folder);
}

void Database::destroy() {
    if (fs::exists(full_path)) {
        fs::remove_all(full_path);
    }
}
