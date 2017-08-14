cmake_minimum_required(VERSION 2.8.9)
project (ApiExample)

#For the shared library:
set ( PROJECT_LINK_LIBS ${PROJECT_SOURCE_DIR}/../../R2AgentApi/Desktop/libR2AgentApi.so )
link_directories(${PROJECT_SOURCE_DIR}/../../R2AgentApi/Desktop/)

include_directories(${PROJECT_SOURCE_DIR}/../../R2AgentApi/)

add_executable(apiexample ../R2AgentApiExample.c)
target_link_libraries(apiexample ${PROJECT_LINK_LIBS} )

