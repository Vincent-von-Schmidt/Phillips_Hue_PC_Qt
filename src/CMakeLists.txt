include(FetchContent)

cmake_minimum_required(VERSION 3.9.1)
project(phue)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# -- cpr --------------------------------------------------------

set(CPR_ENABLE_SSL ON)

FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 871ed52d350214a034f6ef8a3b8f51c5ce1bd400)
FetchContent_MakeAvailable(cpr)

# target_link_libraries(phue PRIVATE cpr::cpr)

# -- qt ---------------------------------------------------------

set(CMAKE_PREFIX_PATH /home/vincent/Qt/6.5.1/gcc_64/lib/cmake)

find_package(Qt6 REQUIRED COMPONENTS 
    Widgets
)

qt_standard_project_setup()

# target_link_libraries(phue PRIVATE Qt6::Widgets)

# -- json -------------------------------------------------------

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

# ---------------------------------------------------------------

qt_add_executable(phue
    ./main.cpp
    ./window.cpp
    ./side_bar.cpp
    ./page_one.cpp
    ./page_two.cpp
)

target_link_libraries(phue PRIVATE
    cpr::cpr
    Qt6::Widgets
    nlohmann_json::nlohmann_json
)

set_target_properties(phue PROPERTIES
    WIN32_EXECUTABLE ON
)
