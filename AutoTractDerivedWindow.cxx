#include "AutoTractDerivedWindow.h"
#include <iostream>

AutoTractDerivedWindow::AutoTractDerivedWindow()
{
    connect( this->actionSave_Configuration, SIGNAL( triggered() ), SLOT( SaveConfigFile() ) );
    connect( this->actionLoad_Configuration, SIGNAL( triggered() ), SLOT( LoadConfigFile() ) );
}

void AutoTractDerivedWindow::SaveConfigFile()
{
    Save();
}

void AutoTractDerivedWindow::LoadConfigFile()
{
    /*QString m_DialogDir;
    QString filename = QFileDialog::getOpenFileName( this , "Open Configuration File" , m_DialogDir , "XML files (*.xml)" );
    if( filename != "" )
    {
        QFileInfo fi( filename ) ;
        m_DialogDir = fi.dir().absolutePath() ;
    }*/
    Load();

}
