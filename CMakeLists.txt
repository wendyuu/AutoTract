CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )
CMAKE_POLICY(VERSION 2.6)
PROJECT(AutoTract)

find_package(Qt4 COMPONENTS QtCore QtGui QtXml REQUIRED)
include(${QT_USE_FILE})

find_package(QtToCppXML REQUIRED)
include(${QtToCppXML_USE_FILE})

#Find SlicerExecutionModel
FIND_PACKAGE(SlicerExecutionModel REQUIRED)
INCLUDE(${SlicerExecutionModel_USE_FILE})
#INCLUDE(${GenerateCLP_USE_FILE})

set(srcfiles
AutoTract.cxx 
AutoTractWindow.cxx
AutoTractDerivedWindow.cxx
Pipeline.cxx
MainScriptThread.cxx
)

QT4_ADD_RESOURCES(RESOURCES resources.qrc)
QT4_WRAP_CPP(QtProject_HEADERS_MOC AutoTractWindow.h AutoTractDerivedWindow.h MainScriptThread.h)
QT4_WRAP_UI(UI_FILES AutoTract.ui)

# Use the include path and library for Qt that is used by VTK.
#INCLUDE_DIRECTORIES(
#  ${CMAKE_SOURCE_DIR}
#  ${CMAKE_BINARY_DIR}
#  ${QT_INCLUDE_DIR}
#  ${AutoTract_BINARY_DIR}
#  ${AutoTract_SOURCE_DIR}
#)

list( APPEND
srcfiles
${QtProject_HEADERS_MOC}
${UI_FILES}
)
QtToCppXML( SOURCES srcfiles NAME AutoTract UIXML_FILE AutoTract.ui PREFIXES soft_ para_ )

SEMMacroBuildCLI(
  NAME AutoTract
  EXECUTABLE_ONLY
  ADDITIONAL_SRCS ${srcfiles} ${RESOURCES} 
  TARGET_LIBRARIES ${QT_LIBRARIES} #${VTK_LIBRARIES}
  LINK_DIRECTORIES ${QT_LIBRARY_DIRS} #${VTK_LIBRARY_DIRS}
  INCLUDE_DIRECTORIES ${QT_INCLUDE_DIR} #${VTK_INCLUDE_DIR}
  )
#add_executable( AutoTract ${srcfiles} ${RESOURCES} AutoTract_CLP)
#target_link_libraries(AutoTract ${QT_LIBRARIES})
