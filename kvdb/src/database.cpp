#include "database.h"
#include "extensions/databaseext.h"

#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

using namespace kvdb;
using namespace kvdbext;

class EmbeddedDatabase::Impl : public IDatabase {
public:
    Impl(std::string db_name, std::string full_path);

    ~Impl();

    std::string get_directory(void);

    void set_key_value(std::string key, std::string value);

    std::string get_key_value(std::string key);

    static const std::unique_ptr<IDatabase> create_empty(std::string db_name);

    static const std::unique_ptr<IDatabase> load(std::string db_name);

    void destroy();

private:
    std::string db_name;
    std::string full_path;
};

EmbeddedDatabase::Impl::Impl(std::string db_name, std::string full_path)
    : db_name(db_name), full_path(full_path)
{
    ;
}

EmbeddedDatabase::Impl::~Impl() {
    ;
}

std::string EmbeddedDatabase::Impl::get_directory() {
    return full_path;
}

void EmbeddedDatabase::Impl::set_key_value(std::string key, std::string value) {
    std::ofstream out_file;

    out_file.open(full_path + "/" + "_string.kv", std::ios::out | std::ios::trunc);
    out_file << value;

    out_file.close();
}

std::string EmbeddedDatabase::Impl::get_key_value(std::string key) {
    std::ifstream in_file(full_path + "/" + "_string.kv");
    std::string value;

    in_file.seekg(0, std::ios::end);
    value.reserve(in_file.tellg());

    in_file.seekg(0, std::ios::beg);
    value.assign((std::istreambuf_iterator<char>(in_file)), std::istreambuf_iterator<char>());

    in_file.close();
    return value;
}

const std::unique_ptr<IDatabase> EmbeddedDatabase::Impl::create_empty(std::string db_name) {
    std::string base_dir(".kvdb");
    if (!fs::exists(base_dir)) {
        fs::create_directory(base_dir);
    }

    std::string db_folder(base_dir + "/" + db_name);
    if (!fs::exists(db_folder)) {
        fs::create_directory(db_folder);
    }

    return std::make_unique<EmbeddedDatabase::Impl>(db_name, db_folder);
}

const std::unique_ptr<IDatabase> EmbeddedDatabase::Impl::load(std::string db_name) {
    std::string base_dir(".kvdb");
    std::string db_folder(base_dir + "/" + db_name);

    return std::make_unique<EmbeddedDatabase::Impl>(db_name, db_folder);
}

void EmbeddedDatabase::Impl::destroy() {
    if (fs::exists(full_path)) {
        fs::remove_all(full_path);
    }
}


EmbeddedDatabase::EmbeddedDatabase(std::string db_name, std::string full_path)
    : impl(std::make_unique<EmbeddedDatabase::Impl>(db_name, full_path))
{
    ;
}

EmbeddedDatabase::~EmbeddedDatabase() {
    ;
}

std::string EmbeddedDatabase::EmbeddedDatabase::get_directory() {
    return impl->get_directory();
}

void EmbeddedDatabase::EmbeddedDatabase::set_key_value(std::string key, std::string value) {
    impl->set_key_value(key, value);
}

std::string EmbeddedDatabase::EmbeddedDatabase::get_key_value(std::string key) {
    return impl->get_key_value(key);
}

const std::unique_ptr<IDatabase> EmbeddedDatabase::EmbeddedDatabase::create_empty(std::string db_name) {
    return EmbeddedDatabase::Impl::create_empty(db_name);
}

const std::unique_ptr<IDatabase> EmbeddedDatabase::EmbeddedDatabase::load(std::string db_name) {
    return EmbeddedDatabase::Impl::load(db_name);
}

void EmbeddedDatabase::EmbeddedDatabase::destroy() {
    impl->destroy();
}
