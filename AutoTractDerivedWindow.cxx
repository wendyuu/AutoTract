#include "AutoTractDerivedWindow.h"
#include <iostream>

AutoTractDerivedWindow::AutoTractDerivedWindow()
{
    connect( this->actionSave_Parameter_Configuration, SIGNAL( triggered() ), SLOT( SaveParaConfigFile() ) );
    connect( this->actionLoad_Parameter_Configuration, SIGNAL( triggered() ), SLOT( LoadParaConfigFile() ) );
    connect( this->actionSave_Software_Configuration, SIGNAL( triggered() ), SLOT( SaveSoftConfigFile() ) );
    connect( this->actionLoad_Software_Configuration, SIGNAL( triggered() ), SLOT( LoadSoftConfigFile() ) );
}

void AutoTractDerivedWindow::SaveParaConfigFile()
{
    QString m_DialogDir;
    QString filename = QFileDialog::getSaveFileName( this , "Save Parameter Configuration File" , m_DialogDir , "XML files (*.xml)" );
    if( filename != "" )
    {
        QFileInfo fi( filename ) ;
        m_DialogDir = fi.dir().absolutePath() ;
    }
    Save_Parameter_Configuration( filename.toStdString() );
}

void AutoTractDerivedWindow::LoadParaConfigFile()
{
    QString m_DialogDir;
    QString filename = QFileDialog::getOpenFileName( this , "Open Parameter Configuration File" , m_DialogDir , "XML files (*.xml)" );
    if( filename != "" )
    {
        QFileInfo fi( filename ) ;
        m_DialogDir = fi.dir().absolutePath() ;
    }
    Load_Parameter_Configuration( filename.toStdString() );
}

void AutoTractDerivedWindow::SaveSoftConfigFile()
{
    QString m_DialogDir;
    QString filename = QFileDialog::getSaveFileName( this , "Save Software Configuration File" , m_DialogDir , "XML files (*.xml)" );
    if( filename != "" )
    {
        QFileInfo fi( filename ) ;
        m_DialogDir = fi.dir().absolutePath() ;
    }
    Save_Software_Configuration( filename.toStdString() );
}

void AutoTractDerivedWindow::LoadSoftConfigFile()
{
    QString m_DialogDir;
    QString filename = QFileDialog::getOpenFileName( this , "Open Software Configuration File" , m_DialogDir , "XML files (*.xml)" );
    if( filename != "" )
    {
        QFileInfo fi( filename ) ;
        m_DialogDir = fi.dir().absolutePath() ;
    }
    Load_Parameter_Configuration( filename.toStdString() );

}

