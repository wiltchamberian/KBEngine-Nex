
# ---------------- 源文件 ----------------
set(SRCS
	debug_helper.cpp
	debug_option.cpp
	eventhistory_stats.cpp
	profile.cpp
	profiler.cpp
	profile_handler.cpp
	script_loglevel.cpp
	sys_info.cpp
	watch_pools.cpp
	watcher.cpp
)
# find_package(expat CONFIG REQUIRED)
# ---------------- 创建静态库 ----------------
add_library(helper STATIC ${SRCS})

# target_compile_definitions(helper PUBLIC ENABLE_WATCHERS=1)

target_include_directories(helper
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}   # helper 自身目录
)


# ---------------- log4cxx ----------------
# 静态库 helper 不直接链接 log4cxx，作为 INTERFACE 传递
# target_link_libraries(helper INTERFACE log4cxx::log4cxx)
# target_compile_definitions(helper INTERFACE LOG4CXX_STATIC)

target_link_libraries(helper PUBLIC  log4cxx)
target_compile_definitions(helper PUBLIC  LOG4CXX_STATIC)

target_link_libraries(helper PUBLIC fmt::fmt)
target_link_libraries(helper PUBLIC sigar)


if(NOT NO_USE_LOG4CXX)
    # 链接库
    target_link_libraries(helper PRIVATE
        expat
        apr-1
        aprutil-1
        log4cxx
    )
else()
    # 添加宏
    target_compile_definitions(helper PRIVATE NO_USE_LOG4CXX)
endif()


# 指定输出路径到 kbe/src/libs
set_target_properties(helper PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
    LIBRARY_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
    RUNTIME_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
)
