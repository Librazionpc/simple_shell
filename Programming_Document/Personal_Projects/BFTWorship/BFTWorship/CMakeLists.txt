cmake_minimum_required(VERSION 3.5)

project(BFTWorship VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(BFTWorship
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Resource/Resource.qrc
        Resource/Paste_icon.png Resource/redo_icon.png Resource/Resource.qrc Resource/Resource.qrc.autosave Resource/save_as_icon.png Resource/save_icon.png Resource/undo_icon.png
        Resource/open_icon.png
        Resource/copy_icon.png Resource/new_icon.png
        Resource/new_icon.png
        Resource/copy_icon.png Resource/cut_icon.png Resource/new_icon.png Resource/open_icon.png Resource/Paste_icon.png Resource/redo_icon.png Resource/Resource.qrc Resource/save_as_icon.png Resource/save_icon.png Resource/undo_icon.png
        ../../../../../../media/libzpc/9E8F-71FF/undo_icon.png

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET BFTWorship APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(BFTWorship SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(BFTWorship
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(BFTWorship PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.BFTWorship)
endif()
set_target_properties(BFTWorship PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS BFTWorship
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(BFTWorship)
endif()
