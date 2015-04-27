#include "AutoTractWindow.h"
#include "AutoTractDerivedWindow.h"
#include "AutoTractCLP.h"
#include <QApplication>


int main( int argc , char** argv )
{
  PARSE_ARGS;
  QApplication app( argc , argv ) ;
  AutoTractDerivedWindow window ;
  window.show() ;
  return app.exec() ;
}
