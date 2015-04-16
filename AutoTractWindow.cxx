#include "AutoTractWindow.h"
#include <iostream>
AutoTractWindow::AutoTractWindow( QWidget * parent , Qt::WFlags f ): QMainWindow( parent , f )
{
    setupUi( this ) ;
}

void AutoTractWindow::SyncUiToModelStructure()
{
    /*1st tab*/
    para_m.setpara_output_dir_lineEdit( para_output_dir_lineEdit->text() );
    para_m.setpara_ref_atlas_lineEdit( para_ref_atlas_lineEdit->text() );
    para_m.setpara_input_atlas_lineEdit( para_input_atlas_lineEdit->text() );
    para_m.setpara_dilatation_radius_spinBox( para_dilatation_radius_spinBox->value() );
    para_m.setpara_resampling_factor_spinBox( para_resampling_factor_spinBox->value() );
    para_m.setpara_threshold_csf_spinBox( para_threshold_csf_spinBox->value() );
    para_m.setpara_threshold_ref_image_spinBox( para_threshold_ref_image_spinBox->value() );

    /*2nd tab*/
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

    /*3rd tab*/
    para_m.setpara_seedspacing_spinBox( para_seedspacing_spinBox->value() );
    para_m.setpara_linearmeasure_spinBox( para_linearmeasure_spinBox->value() );
    para_m.setpara_minpathlength_spinBox( para_minpathlength_spinBox->value() );
    para_m.setpara_maxpathlength_spinBox( para_maxpathlength_spinBox->value() );
    para_m.setpara_stoppingvalue_spinBox( para_stoppingvalue_spinBox->value() );
    para_m.setpara_stoppingcurvature_spinBox( para_stoppingcurvature_spinBox->value() );
    para_m.setpara_integrationsteplength_spinBox( para_integrationsteplength_spinBox->value() );

    /*4th tab*/
    para_m.setpara_tracts_dir_lineEdit( para_tracts_dir_lineEdit->text() );

    /*5th tab*/
    para_m.setpara_all_radioButton( para_all_radioButton->isChecked() );
    para_m.setpara_singletract_radioButton( para_singletract_radioButton->isChecked() );

    //m.setdtiprocess_lineEdit();
    //m.setDTIReg_lineEdit();

}

void AutoTractWindow::SyncModelStructureToUi()
{
    /*1st tab*/
    para_output_dir_lineEdit->setText( para_m.getpara_output_dir_lineEdit() );
    para_ref_atlas_lineEdit->setText( para_m.getpara_ref_atlas_lineEdit() );
    para_input_atlas_lineEdit->setText( para_m.getpara_input_atlas_lineEdit() );
    para_dilatation_radius_spinBox->setValue( para_m.getpara_dilatation_radius_spinBox() );
    para_resampling_factor_spinBox->setValue( para_m.getpara_resampling_factor_spinBox() );
    para_threshold_csf_spinBox->setValue( para_m.getpara_threshold_csf_spinBox() );
    para_threshold_ref_image_spinBox->setValue( para_m.getpara_threshold_ref_image_spinBox() );

    /*2nd tab*/
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

    /*3rd tab*/
    para_seedspacing_spinBox->setValue( para_m.getpara_seedspacing_spinBox() );
    para_linearmeasure_spinBox->setValue( para_m.getpara_linearmeasure_spinBox() );
    para_minpathlength_spinBox->setValue( para_m.getpara_minpathlength_spinBox() );
    para_maxpathlength_spinBox->setValue( para_m.getpara_maxpathlength_spinBox() );
    para_stoppingvalue_spinBox->setValue( para_m.getpara_stoppingvalue_spinBox() );
    para_stoppingcurvature_spinBox->setValue( para_m.getpara_stoppingcurvature_spinBox() );
    para_integrationsteplength_spinBox->setValue( para_m.getpara_integrationsteplength_spinBox() );

    /*4th tab*/
    para_tracts_dir_lineEdit->setText( para_m.getpara_tracts_dir_lineEdit() );

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
