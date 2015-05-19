#include "AutoTractWindow.h"
#include "AutoTractDerivedWindow.h"
#include "AutoTractCLP.h"
#include <QApplication>
#include <QMap>
#include <QString>
#include "para_Save_AutoTract.h"
#include "para_Load_AutoTract.h"
#include "para_Model_AutoTract.h"
#include "soft_Save_AutoTract.h"
#include "soft_Load_AutoTract.h"
#include "soft_Model_AutoTract.h"


int main( int argc , char** argv )
{
    PARSE_ARGS;
    para_Model_AutoTract para_m;
    para_Save_AutoTract para_s;
    para_Load_AutoTract para_l;
    soft_Model_AutoTract soft_m;
    soft_Save_AutoTract soft_s;
    soft_Load_AutoTract soft_l;
    if(!executables.empty())
    {
        soft_l.load( soft_m, executables );
    }
    if(!parameters.empty())
    {
        para_l.load( para_m, parameters );
    }


    /*QMap <QString , QString> lookup_executables_map;
    QMap <QString , QString> lookup_parameters_map;
    lookup_executables_map["DTIReg"] = soft_m.getsoft_DTIReg_lineEdit();
    lookup_executables_map["fiberprocess"] = soft_m.getsoft_fiberprocess_lineEdit();
    lookup_executables_map["ResampleDTIVolume"] = soft_m.getsoft_ResampleDTIVolume_lineEdit();
    lookup_executables_map["ImageMath"] = soft_m.getsoft_ImageMath_lineEdit();
    lookup_executables_map["TractographyLabelMapSeeding"] = soft_m.getsoft_TractographyLabelMapSeeding_lineEdit();
    lookup_executables_map["FiberPostProcess"] = soft_m.getsoft_FiberPostProcess_lineEdit();
    lookup_executables_map["polydatatransform"] = soft_m.getsoft_polydatatransform_lineEdit();
    lookup_executables_map["unu"] = soft_m.getsoft_unu_lineEdit();
    lookup_executables_map["MDT"] = soft_m.getsoft_MDT_lineEdit();
    lookup_executables_map["python"] = soft_m.getsoft_python_lineEdit();
    lookup_executables_map["dtiprocess"] = soft_m.getsoft_dtiprocess_lineEdit();
    lookup_parameters_map["inputDTIatlas_dir"] = para_m.getpara_inputDTIatlas_lineEdit();
    lookup_parameters_map["inputWMmask_dir"] = para_m.getpara_inputWMmask_lineEdit();
    lookup_parameters_map["inputCSFmask_dir"] = para_m.getpara_inputCSFmask_lineEdit();
    lookup_parameters_map["refDTIatlas_dir"] = para_m.getpara_refDTIatlas_lineEdit();
    lookup_parameters_map["tracts_dir"] = para_m.getpara_tracts_dir_lineEdit();
    lookup_parameters_map["registrationType"] = para_m.getpara_registration_type_comboBox();
    lookup_parameters_map["similarityMetric"] = para_m.getpara_similarity_metric_comboBox();
    lookup_parameters_map["gaussianSigma"] = QString::number(para_m.getpara_gaussian_sigma_spinBox());
    lookup_parameters_map["computingSystem"] = para_m.getpara_computingSystem_comboBox();
    lookup_parameters_map["nbCores"] = QString::number(para_m.getpara_nbCores_spinBox());
    lookup_parameters_map["nbTractsProcessed"] = QString::number(para_m.getpara_nbTractsProcessed_spinBox());
    lookup_parameters_map["dilationRadius"] = QString::number(para_m.getpara_dilation_radius_spinBox());*/

    if(noGUI == false)
    {
        QApplication app( argc , argv );
        AutoTractDerivedWindow window ;
        window.SetParaLoad(&para_l);
        window.SetParaSave(&para_s);
        window.SetParaModel(&para_m);
        window.SetSoftLoad(&soft_l);
        window.SetSoftModel(&soft_m);
        window.SetSoftSave(&soft_s);
        /*window.SetLookupExecutableMap(lookup_executables_map);
        window.SetLookupParameterMap(lookup_parameters_map);*/
        //window.SyncModelStructureToUi();
        window.show() ;
        if(parameters.empty() && executables.empty())
        {
            window.initSoftware();
            window.SyncModelStructureToUi("soft");
        }
        if(parameters.empty() && !executables.empty())
        {
            window.SyncModelStructureToUi("soft");

        }
        if(!parameters.empty() && executables.empty())
        {
            window.initSoftware();
            window.SyncModelStructureToUi();
        }
        if(!parameters.empty() && !executables.empty())
        {
            window.SyncModelStructureToUi();
        }
        window.SyncUiToModelStructure();
        return app.exec() ;
    }
    else
    {
        Pipeline* pipeline;
        pipeline = new Pipeline();
        pipeline->setPipelineParameters(&para_m);
        pipeline->setPipelineSoftwares(&soft_m);
        /*pipeline->SetExecutablesMap( lookup_executables_map );
        pipeline->SetParametersMap( lookup_parameters_map );*/
        pipeline->writePipeline();
        pipeline->runPipeline();
        delete( pipeline );
        return 0;
    }
}
