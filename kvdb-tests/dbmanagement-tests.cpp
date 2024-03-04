#include "tests.h"

#include <filesystem>
#include <string>

#include "kvdb.h"

namespace fs = std::filesystem;

TEST_CASE("create a empty, new database", "[create_empty_db]") {
    SECTION("Default settings") {
        std::string dbname("emptydb");
        // success when valid DB reference returned (this errors if not)
        std::unique_ptr<kvdb::IDatabase> db(kvdb::KVDB::create_empty_DB(dbname));

        // AND DB has a folder that exists in the file system
        REQUIRE(fs::is_directory(fs::status(db->get_directory())));

        // AND the DB folder is empty, i.e. no database files yet
        const auto &p = fs::directory_iterator(db->get_directory());
        REQUIRE(p == end(p));

        // teardown & check successful teardown
        db->destroy();
        REQUIRE(!fs::is_directory(fs::status(db->get_directory())));
    }
}

TEST_CASE("load an existing database", "[load_db]") {
    SECTION("Default settings") {
        std::string db_name("emptydb");

        //success when a valid db reference is returned (below will err if this fails)
        std::unique_ptr<kvdb::IDatabase> db(kvdb::KVDB::create_empty_DB(db_name));
        std::unique_ptr<kvdb::IDatabase> db2(kvdb::KVDB::load_db(db_name));

        // AND db has a folder that exists in the file system
        REQUIRE(fs::is_directory(fs::status(db2->get_directory())));

        // AND db folder is empty
        const auto &p = fs::directory_iterator(db2->get_directory());
        REQUIRE(p == end(p));

        // teardown & check successful teardown
        db->destroy();
        REQUIRE(!fs::is_directory(fs::status(db2->get_directory())));
    }
}
