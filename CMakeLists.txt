cmake_minimum_required(VERSION 3.0.0)

project(obj_viewer)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(extern/glfw)
add_subdirectory(extern/glm)

# hacky solution to get glad workin, as the original library has very interesting cmake solution
set(HEADER_FILES ${PROJECT_SOURCE_DIR}/extern/glad/include/glad/glad.h ${PROJECT_SOURCE_DIR}/extern/glad/include/KHR/khrplatform.h)

add_library(glad
	${PROJECT_SOURCE_DIR}/extern/glad/src/glad.c

	${HEADER_FILES}
)

target_include_directories(glad PRIVATE ${PROJECT_SOURCE_DIR}/extern/glad/include)

#src
add_executable(
    ${PROJECT_NAME}
    main.cpp
    src/App.cpp
    src/Renderer.cpp
    src/InputManager.cpp
    src/FileReader.cpp
    src/FileReader/Converter/Converter.cpp
    src/FileReader/Converter/GlmVec2Converter.cpp
    src/FileReader/Converter/GlmVec3Converter.cpp
    src/FileReader/Converter/StringConverter.cpp
    src/FileReader/Converter/ObjFaceConverter.cpp
    src/FileReader/FileManager/FileManager.cpp
    src/FileReader/FileManager/ObjFileManager.cpp
    src/Renderer/Shader.cpp
    src/Renderer/Object.cpp
    src/Renderer/Mesh.cpp
    src/Renderer/VBO.cpp
    src/Renderer/VAO.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC extern/glfw/include
    PUBLIC extern/glad/include
    PUBLIC include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE extern/glfw/src
    PRIVATE extern/glad/src
    PRIVATE src
)

target_link_libraries(${PROJECT_NAME} glfw glm glad)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/res/ $<TARGET_FILE_DIR:${PROJECT_NAME}>)
