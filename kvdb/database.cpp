#include "database.h"

Database::Database(std::string db_name, std::string full_path) {

}

std::string Database::get_directory() {
    return "Empty";
}

Database Database::create_empty(std::string db_name) {
    return Database("Empty", "Empty");
}
