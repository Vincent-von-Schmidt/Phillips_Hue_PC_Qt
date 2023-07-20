#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

#include "PBridge.h"

using json = nlohmann::json;

json PBridge::get_info() {

    cpr::Response response = cpr::Get(
        cpr::Url{"http://{}/api/{}/", *this -> ip, *this -> user}
    );

    std::string* response_text = &response.text;
    json response_json = json::parse( *response_text );

    return response_json;

}
