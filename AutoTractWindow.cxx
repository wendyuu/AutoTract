#include "AutoTractWindow.h"
#include <iostream>
AutoTractWindow::AutoTractWindow( QWidget * parent , Qt::WFlags f ): QMainWindow( parent , f )
{
    setupUi( this ) ;
}

void AutoTractWindow::SyncUiToModelStructure()
{
    /*1st tab: inputs*/
    para_m.setpara_inputDTIatlas_lineEdit( para_inputDTIatlas_lineEdit->text() ) ;
    para_m.setpara_inputWMmask_lineEdit( para_inputWMmask_lineEdit->text() );
    para_m.setpara_inputCSFmask_lineEdit( para_inputCSFmask_lineEdit->text() );
    para_m.setpara_output_dir_lineEdit( para_output_dir_lineEdit->text() );
    para_m.setpara_refDTIatlas_lineEdit( para_refDTIatlas_lineEdit->text() );

    /*2nd tab: reference tracts*/
    para_m.setpara_tracts_dir_lineEdit( para_tracts_dir_lineEdit->text() );
    std::map<QString,bool> itemList ;
    for( int i = 0 ; i < para_ref_tracts_listWidget->count() ; i++ )
    {
        QListWidgetItem *currentItem = para_ref_tracts_listWidget->item(i) ;
        itemList[ currentItem->text() ] = static_cast<bool>(currentItem->checkState() ) ;
    }
    para_m.setpara_ref_tracts_listWidget(itemList) ;

    /*3rd tab: software*/
    soft_m.setsoft_dtiprocess_lineEdit( soft_dtiprocess_lineEdit->text() );
    soft_m.setsoft_DTIReg_lineEdit( soft_DTIReg_lineEdit->text() );
    soft_m.setsoft_FiberPostProcess_lineEdit( soft_FiberPostProcess_lineEdit->text() );
    soft_m.setsoft_fiberprocess_lineEdit( soft_fiberprocess_lineEdit->text() );
    soft_m.setsoft_ImageMath_lineEdit( soft_ImageMath_lineEdit->text() );
    soft_m.setsoft_ResampleDTIVolume_lineEdit( soft_ResampleDTIVolume_lineEdit->text() );
    soft_m.setsoft_MDT_lineEdit( soft_MDT_lineEdit->text() );
    soft_m.setsoft_polydatatransform_lineEdit( soft_polydatatransform_lineEdit->text() );
    soft_m.setsoft_python_lineEdit( soft_python_lineEdit->text() );
    soft_m.setsoft_TractographyLabelMapSeeding_lineEdit( soft_TractographyLabelMapSeeding_lineEdit->text() );
    soft_m.setsoft_unu_lineEdit( soft_unu_lineEdit->text() );

    /*4th tab: registration*/
    para_m.setpara_registration_type_comboBox( para_registration_type_comboBox->currentText() );
    para_m.setpara_transformation_step_spinBox( para_transformation_step_spinBox->value() );
    para_m.setpara_iterations_spinBox( para_iterations_spinBox->value() );
    para_m.setpara_similarity_metric_comboBox( para_similarity_metric_comboBox->currentText() );
    para_m.setpara_gaussian_sigma_spinBox( para_gaussian_sigma_spinBox->value() );

    /*5th tab*/
    para_m.setpara_dilation_radius_spinBox( para_dilation_radius_spinBox->value() );
    para_m.setpara_seedspacing_spinBox( para_seedspacing_spinBox->value() );
    para_m.setpara_linearmeasure_spinBox( para_linearmeasure_spinBox->value() );
    para_m.setpara_minpathlength_spinBox( para_minpathlength_spinBox->value() );
    para_m.setpara_maxpathlength_spinBox( para_maxpathlength_spinBox->value() );
    para_m.setpara_stoppingvalue_spinBox( para_stoppingvalue_spinBox->value() );
    para_m.setpara_stoppingcurvature_spinBox( para_stoppingcurvature_spinBox->value() );
    para_m.setpara_integrationsteplength_spinBox( para_integrationsteplength_spinBox->value() );



    /*5th tab*/
    para_m.setpara_all_radioButton( para_all_radioButton->isChecked() );
    para_m.setpara_singletract_radioButton( para_singletract_radioButton->isChecked() );

    //m.setdtiprocess_lineEdit();
    //m.setDTIReg_lineEdit();

}

void AutoTractWindow::SyncModelStructureToUi()
{
    /*1st tab: inputs*/
    para_inputDTIatlas_lineEdit->setText( para_m.getpara_inputDTIatlas_lineEdit() );
    para_inputWMmask_lineEdit->setText( para_m.getpara_inputWMmask_lineEdit() );
    para_inputCSFmask_lineEdit->setText( para_m.getpara_inputWMmask_lineEdit() );
    para_output_dir_lineEdit->setText( para_m.getpara_output_dir_lineEdit() );
    para_refDTIatlas_lineEdit->setText( para_m.getpara_refDTIatlas_lineEdit() );

    /*2nd tab: reference tracts*/
    para_tracts_dir_lineEdit->setText( para_m.getpara_tracts_dir_lineEdit() );
    std::map<QString,bool> itemList ;
    itemList = para_m.getpara_ref_tracts_listWidget() ;
    para_ref_tracts_listWidget->clear() ;
    for( std::map<QString,bool>::iterator it = itemList.begin() ; it != itemList.end() ; it++ )
    {
        QListWidgetItem *item = new QListWidgetItem( it->first , para_ref_tracts_listWidget ) ;
        item->setCheckState( it->second != 0 ? Qt::Checked : Qt::Unchecked ) ;
    }
    /*3rd tab: software*/
    soft_dtiprocess_lineEdit->setText( soft_m.getsoft_dtiprocess_lineEdit() );
    soft_DTIReg_lineEdit->setText( soft_m.getsoft_DTIReg_lineEdit() );
    soft_FiberPostProcess_lineEdit->setText( soft_m.getsoft_FiberPostProcess_lineEdit() );
    soft_fiberprocess_lineEdit->setText( soft_m.getsoft_fiberprocess_lineEdit() );
    soft_ImageMath_lineEdit->setText( soft_m.getsoft_ImageMath_lineEdit() );
    soft_ResampleDTIVolume_lineEdit->setText( soft_m.getsoft_ResampleDTIVolume_lineEdit() );
    soft_MDT_lineEdit->setText( soft_m.getsoft_MDT_lineEdit() );
    soft_polydatatransform_lineEdit->setText( soft_m.getsoft_polydatatransform_lineEdit() );
    soft_python_lineEdit->setText( soft_m.getsoft_python_lineEdit() );
    soft_TractographyLabelMapSeeding_lineEdit->setText( soft_m.getsoft_TractographyLabelMapSeeding_lineEdit() );
    soft_unu_lineEdit->setText( soft_m.getsoft_unu_lineEdit() );

    /*4th tab: registration*/
    para_registration_type_comboBox->setEditText( para_m.getpara_registration_type_comboBox() );
    para_transformation_step_spinBox->setValue( para_m.getpara_transformation_step_spinBox() );
    para_iterations_spinBox->setValue( para_m.getpara_iterations_spinBox() );
    para_similarity_metric_comboBox->setEditText( para_m.getpara_similarity_metric_comboBox() );
    para_gaussian_sigma_spinBox->setValue( para_m.getpara_gaussian_sigma_spinBox() );

    /*5th tab*/
    para_dilation_radius_spinBox->setValue( para_m.getpara_dilation_radius_spinBox() );
    para_seedspacing_spinBox->setValue( para_m.getpara_seedspacing_spinBox() );
    para_linearmeasure_spinBox->setValue( para_m.getpara_linearmeasure_spinBox() );
    para_minpathlength_spinBox->setValue( para_m.getpara_minpathlength_spinBox() );
    para_maxpathlength_spinBox->setValue( para_m.getpara_maxpathlength_spinBox() );
    para_stoppingvalue_spinBox->setValue( para_m.getpara_stoppingvalue_spinBox() );
    para_stoppingcurvature_spinBox->setValue( para_m.getpara_stoppingcurvature_spinBox() );
    para_integrationsteplength_spinBox->setValue( para_m.getpara_integrationsteplength_spinBox() );



    /*5th tab*/
    para_all_radioButton->setChecked( para_m.getpara_all_radioButton() );
    para_singletract_radioButton->setChecked( para_m.getpara_singletract_radioButton() );

}

void AutoTractWindow::Save_Parameter_Configuration( std::string filename )
{
    SyncUiToModelStructure();
    para_s.save( para_m, filename );
}

void AutoTractWindow::Load_Parameter_Configuration( std::string filename )
{
    para_l.load( para_m, filename );
    SyncModelStructureToUi();
}

void AutoTractWindow::Save_Software_Configuration( std::string filename )
{
    SyncUiToModelStructure();
    soft_s.save( soft_m, filename );
}
void AutoTractWindow::Load_Software_Configuration( std::string filename )
{
    soft_l.load( soft_m, filename );
    SyncModelStructureToUi();
}
