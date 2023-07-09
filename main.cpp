#include <iostream>
#include <fstream>
#include <json/json.h>


using namespace std;

int main()
{
    Json::Value root;
    ifstream ifs;
    ifs.open("profile.json");
    Json::CharReaderBuilder builder;
    builder["collectComments"] = true;
    JSONCPP_STRING errs;
    if (!parseFromStream(builder, ifs, &root, &errs))
    {
        std::cout << errs << std::endl;
        return EXIT_FAILURE;
    }
    Json::Value::iterator itr = root.begin();
    int i = 0;
    string name;
    for (itr = root.begin(); itr != root.end(); itr++)
    {
        name = root.getMemberNames()[i];
        if (root[name].size() > 1) {
            for (auto x:root[name]) {
                    cout << name << ": " << x << endl;
            }
        } else {
            cout << name + " ";
            cout << root[name] << endl;
        }
        i++;
    }