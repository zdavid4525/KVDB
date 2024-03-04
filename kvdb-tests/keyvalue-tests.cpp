#include <catch.hpp>

#include <filesystem>

#include "kvdb.h"

namespace fs = std::filesystem;

TEST_CASE("store and retrieve a value", "[set_key_value,get_key_value]") {
    SECTION("basic set and get") {
        std::string db_name("emptydb");
        std::unique_ptr<kvdb::IDatabase> db(kvdb::KVDB::create_empty_DB(db_name));

        std::string key("key");
        std::string value("value");

        // success when retrieved value is the same as the stored value
        db->set_key_value(key, value);
        REQUIRE(value == db->get_key_value(key));

        // teardown & check successful teardown
        db->destroy();
        REQUIRE(!fs::is_directory(fs::status(db->get_directory())));
    }
}
