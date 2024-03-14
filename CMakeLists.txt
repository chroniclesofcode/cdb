cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)
project(cdb)

add_compile_options(
  -Wall -Werror -Wcast-align -Wcast-qual -Wctor-dtor-privacy
  -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations 
  -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls
  -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default
  -Wundef -Wno-unused
)

find_package( Boost 1.82 COMPONENTS program_options REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

add_subdirectory( include )

set(DB_SOURCE_FILES src/cdb/Database.cpp)
set(SOURCE_FILES src/main.cpp)

add_executable(main ${SOURCE_FILES} ${DB_SOURCE_FILES})
target_link_libraries(main LINK_PUBLIC ${Boost_LIBRARIES})
target_include_directories(main PUBLIC include)