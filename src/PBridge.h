#ifndef PBridge_H
#define PBridge_H

#include <nlohmann/json.hpp>
#include "PLight.h"

using json = nlohmann::json;

class PBridge {

    private:

        std::string ip;
        json get_info();

    public:

        PBridge( const std::string &ip );
        std::string create_user();
        std::array<PLight> get_lights();


};

#endif
