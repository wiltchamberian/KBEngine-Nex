# cmake/FindOrBuildOpenSSL.cmake
# 自动查找系统 OpenSSL 或使用自带 OpenSSL，并创建 INTERFACE 库 OpenSSL::SSL

# 判断系统 OpenSSL 是否存在
if(EXISTS "/usr/lib/x86_64-linux-gnu/libssl.a")
    set(USE_SELF_OPENSSL 0)
    set(OPENSSL_DIR "/usr")
    message(STATUS "Using system OpenSSL")
else()
    set(USE_SELF_OPENSSL 1)
    set(OPENSSL_DIR "${KBE_ROOT}/kbe/src/lib/dependencies/openssl")
    message(STATUS "Using self-built OpenSSL")
endif()

# 包含头文件路径
set(OPENSSL_INCLUDE_DIRS ${OPENSSL_DIR}/include CACHE PATH "OpenSSL include dirs")

# 库文件
set(OPENSSL_LIBRARIES ssl crypto dl CACHE STRING "OpenSSL libraries")

# 创建 INTERFACE 库
add_library(OpenSSL::SSL INTERFACE IMPORTED)
set_target_properties(OpenSSL::SSL PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${OPENSSL_INCLUDE_DIRS}"
    INTERFACE_LINK_LIBRARIES "${OPENSSL_LIBRARIES}"
    INTERFACE_COMPILE_DEFINITIONS "USE_OPENSSL"
)
