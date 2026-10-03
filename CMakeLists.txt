cmake_minimum_required(VERSION 4.2.3)

project(Simple-Sprite-Movement---SFML LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add SFML from GitHub
include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.6.2
)
FetchContent_MakeAvailable(SFML)

# Add executable
add_executable(Simple-Sprite-Movement---SFML
	${PROJECT_SOURCE_DIR}/main.cpp
	${PROJECT_SOURCE_DIR}/src/Camera.cpp  
	${PROJECT_SOURCE_DIR}/src/Player.cpp
	${PROJECT_SOURCE_DIR}/src/Wall.cpp  
	${PROJECT_SOURCE_DIR}/include/Camera.h  
	${PROJECT_SOURCE_DIR}/include/Player.h
	${PROJECT_SOURCE_DIR}/include/Wall.h
	${PROJECT_SOURCE_DIR}/include/DEFINITION.h  
)

# Link SFML libraries
target_link_libraries(Simple-Sprite-Movement---SFML
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
	sfml-audio
)
