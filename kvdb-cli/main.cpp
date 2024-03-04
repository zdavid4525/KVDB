#include <iostream>
#include <cxxopts.hpp>
#include <kvdb.h>

using namespace std;
using namespace kvdb;

cxxopts::Options options("kvdb-cli", "CLI for KVDB");

void print_usage() {
    cout << "bad config" << endl;
}

int main(int argc, char* argv[])
{
    options.add_options()
        ("c,create", "create a db")
        ("d,destry", "destroy a db")
        ("s,set", "set a key in the db")
        ("g,get", "get a key-value from the db")
        ("n,name", "db name (required)", cxxopts::value<std::string>())
        ("k,key", "key to set/get", cxxopts::value<std::string>())
        ("v,value", "value to set/get", cxxopts::value<std::string>());

    auto result = options.parse(argc, argv);

    if (result.count("c") == 1) {
        if (result.count("n") == 0) {
            cout << "you must specify a db name. usage: ./kvdb-cli -c -n <name>" << endl;
            print_usage();

            return 1;
        }

        std::string db_name(result["n"].as<std::string>());

        std::unique_ptr<kvdb::IDatabase> db(KVDB::create_empty_DB(db_name));
        return 0;
    }

    if (result.count("s") == 1) {
        if (result.count("n") == 0) {
            cout << "you must specify a db name. usage: ./kvdb-cli -s -n <name>" << endl;
            print_usage();

            return 1;
        }

        if (result.count("k") == 0) {
            cout << "you must specify a key to set. usage: ./kvdb-cli -s -k <key>" << endl;
            print_usage();

            return 1;
        }

        if (result.count("v") == 0) {
            cout << "you must specify a value to set. usage: ./kvdb-cli -c -v <value>" << endl;
            print_usage();

            return 1;
        }

        std::string db_name(result["n"].as<std::string>());
        std::string key(result["k"].as<std::string>());
        std::string value(result["v"].as<std::string>());

        std::unique_ptr<kvdb::IDatabase> db(KVDB::load_db(db_name));

        db->set_key_value(key, value);
        return 0;
    }

    if (result.count("g") == 1) {
        if (result.count("n") == 0) {
            cout << "you must specify a db name. usage: ./kvdb-cli -s -n <name>" << endl;
            print_usage();

            return 1;
        }

        if (result.count("k") == 0) {
            cout << "you must specify a key to set. usage: ./kvdb-cli -s -k <key>" << endl;
            print_usage();

            return 1;
        }

        std::string db_name(result["n"].as<std::string>());
        std::string key(result["k"].as<std::string>());
        std::unique_ptr<kvdb::IDatabase> db(KVDB::load_db(db_name));

        cout << db->get_key_value(key) << endl;
        return 0;
    }

    if (result.count("d") == 1) {
        if (result.count("n") == 0) {
            cout << "you must specify a db name. usage: ./kvdb-cli -s -n <name>" << endl;
            print_usage();

            return 1;
        }

        std::string db_name(result["n"].as<std::string>());
        std::unique_ptr<kvdb::IDatabase> db(KVDB::load_db(db_name));

        db->destroy();
        return 0;
    }

    cout << "no command specified" << endl;
    print_usage();
    return 1;
}
