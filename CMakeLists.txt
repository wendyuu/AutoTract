CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )
CMAKE_POLICY(VERSION 2.6)
PROJECT(AutoTract)

find_package(Qt4 REQUIRED )
include(${QT_USE_FILE})

find_package(QtToCppXML REQUIRED)
include(${QtToCppXML_USE_FILE})

set(srcfiles
main.cxx 
AutoTractWindow.cxx
AutoTractDerivedWindow.cxx
)

# Use the include path and library for Qt that is used by VTK.
INCLUDE_DIRECTORIES(
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
  ${QT_INCLUDE_DIR}
  ${AutoTract_BINARY_DIR}
  ${AutoTract_SOURCE_DIR}
)


QT4_WRAP_CPP(QtProject_HEADERS_MOC AutoTractWindow.h AutoTractDerivedWindow.h)
QT4_WRAP_UI(UI_FILES AutoTract.ui)

list( APPEND
srcfiles
${QtProject_HEADERS_MOC}
${UI_FILES}
)
QtToCppXML( SOURCES srcfiles NAME AutoTract UIXML_FILE AutoTract.ui PREFIXES soft_ para_ )

add_executable( AutoTract ${srcfiles})
target_link_libraries(AutoTract ${QT_LIBRARIES})
