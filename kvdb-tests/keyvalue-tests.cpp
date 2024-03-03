#include <catch.hpp>
#include <kvdb.h>

TEST_CASE("store and retrieve a value", "[setKeyValue,getKeyValue]") {
    SECTION("basic set and get") {
        std::string db_name("emptydb");
        Database db(KVDB::create_empty_DB(db_name));

        std::string key("key");
        std::string value("value");

        // success when retrieved value is the same as the stored value
        db.setKeyValue(key, value);
        REQUIRE(value == db.getKeyValue(key));
    }
}
