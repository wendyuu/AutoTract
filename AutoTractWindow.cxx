#include "AutoTractWindow.h"
#include <iostream>
AutoTractWindow::AutoTractWindow( QWidget * parent , Qt::WFlags f ): QMainWindow( parent , f )
{
  setupUi( this ) ;
}

void AutoTractWindow::SyncUiToModelStructure()
{
    /*1st tab*/
    m.setoutput_dir_lineEdit( output_dir_lineEdit->text() ) ;
    m.setref_atlas_lineEdit( ref_atlas_lineEdit->text() ) ;
    m.setinput_atlas_lineEdit( input_atlas_lineEdit->text() ) ;

    m.setall_radioButton( all_radioButton->isChecked() ) ;
    m.setsingletract_radioButton( singletract_radioButton->isChecked() ) ;

    //m.setdtiprocess_lineEdit();
    //m.setDTIReg_lineEdit();

}

void AutoTractWindow::SyncModelStructureToUi()
{
    /*1st tab*/

    output_dir_lineEdit->setText( m.getoutput_dir_lineEdit() );
    ref_atlas_lineEdit->setText( m.getref_atlas_lineEdit() );
    input_atlas_lineEdit->setText( m.getinput_atlas_lineEdit() );

    all_radioButton->setChecked(m.getall_radioButton());
    singletract_radioButton->setChecked(m.getsingletract_radioButton());

}

void AutoTractWindow::Save()
{
    SyncUiToModelStructure();
    s.save(m);
}

void AutoTractWindow::Load()
{
    l.load(m);
    SyncModelStructureToUi();

}
