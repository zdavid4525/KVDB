#include "tests.h"

#include <filesystem>
#include <string>

#include <kvdb.h>

namespace fs = std::filesystem;

TEST_CASE("create a empty, new database", "[createEmptyDB]") {
    SECTION("Default settings") {
        std::string dbname("emptydb");
        // success when valid DB reference returned (this errors if not)
        Database db(KVDB::create_empty_DB(dbname));

        // OR DB has a folder that exists in the file system
        REQUIRE(fs::is_directory(fs::status(db.get_directory())));

        // OR the DB folder is empty, i.e. no database files yet
        const auto &p = fs::directory_iterator(db.get_directory());
        REQUIRE(p == end(p));

        // teardown & check successful teardown
        db.destroy();
        REQUIRE(!fs::is_directory(fs::status(db.get_directory())));
    }
}
