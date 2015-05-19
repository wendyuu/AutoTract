#include "Registration.h"

Registration::Registration(QString module) : Script(module)
{
}

void Registration::setDisplacementFieldPath(QString path)
{
    m_displacementFieldPath = path;
}

void Registration::initializeScript()
{
    definePython();
    importGeneralModules();

    m_script += "import re\n";

    m_script += "DTIReg = '" + m_soft_m->getsoft_DTIReg_lineEdit() + "'\n";
    m_script += "refDTIatlas_dir = '" + m_para_m->getpara_refDTIatlas_lineEdit() + "'\n";
    m_script += "inputDTIatlas_dir = '" + m_para_m->getpara_inputDTIatlas_lineEdit() + "'\n";
    m_script += "registrationType = '" + m_para_m->getpara_registration_type_comboBox() + "'\n";
    m_script += "similarityMetric = '" + m_para_m->getpara_similarity_metric_comboBox() + "'\n";
    m_script += "gaussianSigma = '" + QString::number(m_para_m->getpara_gaussian_sigma_spinBox()) + "'\n";
    m_script += "displacementFieldPath = '" + m_displacementFieldPath + "'\n";

    m_script += "logger = logging.getLogger('AutoTract')\n\n";

    m_script += "runningProcess = None\n\n";
}

void Registration::executeRegistration()
{
    m_log = "Registration";
    m_argumentsList << "DTIReg" << "'--movingVolume'" << "refDTIatlas_dir" << "'--fixedVolume'" << "inputDTIatlas_dir" << "'--method useScalar-ANTS'" << "'--ANTSRegistrationType'"<< "registrationType" << "'--ANTSSimilarityMetric'" << "similarityMetric"  << "'--ANTSSimilarityParameter'" << "'4'" << "'--ANTSGaussianSigma'" << "gaussianSigma" << "'--outputDisplacementField'" << "displacementFieldPath";
    execute();
    m_unnecessaryFiles << m_displacementFieldPath;
}

void Registration::implementRun()
{
    m_script += "def run():\n\n";

    m_script += "\tsignal.signal(signal.SIGINT, stop)\n";
    m_script += "\tsignal.signal(signal.SIGTERM, stop)\n\n";

    m_script += "\tlogger.info('=== Registration ===')\n";

    m_outputs.insert("displacementField", m_displacementFieldPath);
    checkFinalOutputs();

    m_script += "\tlogger.info('')\n";

    executeRegistration();
    // Cleaning for keven data
    QFileInfo fi(m_para_m->getpara_refDTIatlas_lineEdit());
    QString base = fi.baseName();
    m_unnecessaryFiles << m_module_dir->filePath(base + "_ANTSAffine.txt");
    m_unnecessaryFiles << m_module_dir->filePath(base + "_InverseWarp.nii.gz");
    m_unnecessaryFiles << m_module_dir->filePath(base + "_Warp.nii.gz");
    m_unnecessaryFiles << m_module_dir->filePath(base + "_DTI-Reg.bms");
    m_unnecessaryFiles << m_module_dir->filePath(base + "_FA.nrrd");
    m_unnecessaryFiles << m_module_dir->filePath(base + "_warp.nrrd");
}

void Registration::update()
{
    initializeScript();
    implementStop();
    implementCheckFileExistence();
    implementExecute();
    implementExecutePipe();
    implementRun();

    writeScript();
}

QString Registration::getDisplacementField()
{
    return m_displacementFieldPath;
}
