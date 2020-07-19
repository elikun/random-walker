#ifndef COMMON_CONSTANTS_H
#define COMMON_CONSTANTS_H

#include <string>

// TCP port of Environment process used for network socket communication
const uint16_t ENVIRONMENT_PORT = 10001;

// Location of configuration file
const std::string CONFIG_INI_FILE = "/app/exe/conf.ini";

// Localhost IPv4 Address
const std::string LOOPBACK_IPV4_ADDRESS = "127.0.0.1";

// Process names
const std::string COMMANDER_PROCESS = "commander";
const std::string ENVIRONMENT_PROCESS = "environment";

#endif