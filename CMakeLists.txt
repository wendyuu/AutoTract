CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )
CMAKE_POLICY(VERSION 2.6)
PROJECT(AutoTract)

find_package(Qt4 REQUIRED )
include(${QT_USE_FILE})

find_package(QtToCppXML REQUIRED)
include(${QtToCppXML_USE_FILE})

# Use the include path and library for Qt that is used by VTK.
INCLUDE_DIRECTORIES(
  ${QT_INCLUDE_DIR}
  ${AutoTract_BINARY_DIR}
  ${AutoTract_SOURCE_DIR}
)

QT4_WRAP_CPP(MOC_FILES AutoTract.h)
QT4_WRAP_UI(UI_FILES AutoTract.ui)

QtToCppXML( srcfiles AutoTract AutoTract.ui)

set(AutoTract_SOURCE main.cxx AutoTract.cxx ${MOC_FILES} ${UI_FILES})
add_executable( AutoTract ${AutoTract_SOURCE} ${srcfiles})
target_link_libraries(AutoTract ${QT_LIBRARIES})
