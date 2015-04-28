#include "AutoTractWindow.h"
#include "AutoTractDerivedWindow.h"
#include "AutoTractCLP.h"
#include <QApplication>


int main( int argc , char** argv )
{
    PARSE_ARGS;

    if(noGUI == false)
    {
        QApplication app( argc , argv );
        AutoTractDerivedWindow window ;
        if(!executables.empty())
        {
            window.Load_Software_Configuration(executables);
        }
        if(!parameters.empty())
        {
            window.Load_Parameter_Configuration(parameters);
        }
        window.show() ;
        return app.exec() ;
    }
    else
    {
        return 0;
    }

}
