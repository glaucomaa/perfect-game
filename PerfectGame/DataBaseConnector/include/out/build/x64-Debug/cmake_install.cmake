# Install script for directory: C:/Users/MainA/source/repos/perfect-game1/PerfectGame/DataBaseConnector/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/MainA/Source/Repos/perfect-game1/PerfectGame/DataBaseConnector/include/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/json/allocator.h;/json/assertions.h;/json/config.h;/json/forwards.h;/json/json.h;/json/json_features.h;/json/reader.h;/json/value.h;/json/version.h;/json/writer.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/json" TYPE FILE FILES
    "C:/Users/MainA/source/repos/perfect-game1/PerfectGame/DataBaseConnector/include/json/allocator.h"
    "C:/Users/MainA/source/repos/perfect-game1/PerfectGame/DataBaseConnector/include/json/assertions.h"
    "C:/Users/MainA/source/repos/perfect-game1/PerfectGame/DataBaseConnector/include/json/config.h"
    "C:/Users/MainA/source/repos/perfect-game1/PerfectGame/DataBaseConnector/include/json/forwards.h"
    "C:/Users/MainA/source/repos/perfect-game1/PerfectGame/DataBaseConnector/include/json/json.h"
    "C:/Users/MainA/source/repos/perfect-game1/PerfectGame/DataBaseConnector/include/json/json_features.h"
    "C:/Users/MainA/source/repos/perfect-game1/PerfectGame/DataBaseConnector/include/json/reader.h"
    "C:/Users/MainA/source/repos/perfect-game1/PerfectGame/DataBaseConnector/include/json/value.h"
    "C:/Users/MainA/source/repos/perfect-game1/PerfectGame/DataBaseConnector/include/json/version.h"
    "C:/Users/MainA/source/repos/perfect-game1/PerfectGame/DataBaseConnector/include/json/writer.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/MainA/source/repos/perfect-game1/PerfectGame/DataBaseConnector/include/out/build/x64-Debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
