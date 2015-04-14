#include "AutoTractWindow.h"
#include "AutoTractDerivedWindow.h"
#include <QApplication>


int main( int argc , char** argv )
{
  QApplication app( argc , argv ) ;
  AutoTractDerivedWindow window ;
  window.show() ;
  return app.exec() ;
}
