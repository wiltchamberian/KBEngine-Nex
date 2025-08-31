
# 收集源文件
set(SRCS
	machine.cpp
	machine_interface.cpp
	main.cpp
)

# 创建可执行程序
add_executable(machine ${SRCS})


# 链接依赖的库
target_link_libraries(machine
    PRIVATE
        server
        resmgr
        network
        thread
        pyscript
        common
        helper
        math
        g3dlite
        log4cxx

        debug ${KBE_ROOT}/kbe/src/build/vcpkg_installed/x64-linux/debug/lib/libaprutil-1.a
        optimized ${KBE_ROOT}/kbe/src/build/vcpkg_installed/x64-linux/lib/libaprutil-1.a

        debug ${KBE_ROOT}/kbe/src/build/vcpkg_installed/x64-linux/debug/lib/libapr-1.a
        optimized ${KBE_ROOT}/kbe/src/build/vcpkg_installed/x64-linux/lib/libapr-1.a

        debug ${KBE_ROOT}/kbe/src/build/vcpkg_installed/x64-linux/debug/lib/libexpat.a
        optimized ${KBE_ROOT}/kbe/src/build/vcpkg_installed/x64-linux/lib/libexpat.a

)

target_compile_definitions(machine PUBLIC  LOG4CXX_STATIC)


# ---------------- Python ----------------
include(${CMAKE_SOURCE_DIR}/cmakefile/Python.cmake)
target_link_libraries(machine PRIVATE KBE::Python)
target_link_options(machine PRIVATE -Wl,-export-dynamic)

# ---------------- OpenSSL ----------------
include(${CMAKE_SOURCE_DIR}/cmakefile/OpenSSL.cmake)
target_link_libraries(machine PRIVATE OpenSSL::SSL)


# 设置可执行文件输出目录
set_target_properties(machine PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${KBE_ROOT}/kbe/bin/server"
)