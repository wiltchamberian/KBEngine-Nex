# cmake_minimum_required(VERSION 3.20)
# project(client_lib)

# ---------------- 源文件 ----------------
set(SRCS
    blowfish.cpp
    common.cpp
    tasks.cpp
    timer.cpp
    timestamp.cpp
    strutil.cpp
	kbeversion.cpp
	kbekey.cpp
	md5.cpp
	sha1.cpp
	ssl.cpp
	base64.cpp
	rsa.cpp
	memorystream.cpp
)
# ---------------- 创建静态库 ----------------
add_library(common STATIC ${SRCS})



target_link_libraries(common PRIVATE fmt::fmt)



# 指定输出路径到 kbe/src/libs
set_target_properties(common PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
    LIBRARY_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
    RUNTIME_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
)
