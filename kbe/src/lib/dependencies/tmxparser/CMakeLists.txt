# 源文件列表
set(SRCS
	base64.cpp
	TmxEllipse.cpp
	TmxImage.cpp
	TmxImageLayer.cpp
	TmxLayer.cpp
	TmxMap.cpp
	TmxObject.cpp
	TmxObjectGroup.cpp
	TmxPolygon.cpp
	TmxPolyline.cpp
	TmxPropertySet.cpp
	TmxTile.cpp
	TmxTileset.cpp
	TmxUtil.cpp
)

# 生成静态库
add_library(tmxparser STATIC ${SRCS})

# 如果没传入 KBE_ROOT，则默认取上级目录
if(NOT DEFINED KBE_ROOT)
    set(KBE_ROOT ${CMAKE_SOURCE_DIR}/../..) 
endif()


# 指定输出路径到 kbe/src/libs
set_target_properties(tmxparser PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
    LIBRARY_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
    RUNTIME_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
)




# 在这里声明依赖 tinyxml
target_link_libraries(tmxparser PUBLIC tinyxml)

target_link_libraries(tmxparser
    PRIVATE fmt::fmt
)