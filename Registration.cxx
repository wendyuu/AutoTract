#include "Registration.h"

Registration::Registration(QString module) : Script(module)
{
}
void Registration::setRefDTIAtlas(QString refDTIAtlas)
{
    m_refDTIAtlas = refDTIAtlas;
}
void Registration::setInputDTIAtlas(QString inputDTIAtlas)
{
    m_inputDTIAtlas = inputDTIAtlas;
}
void Registration::setRegistrationType(QString registrationType)
{
    m_registrationType = registrationType;
}

void Registration::setSimilarityMetric(QString similarityMetric)
{
    m_similarityMetric = similarityMetric;
}

void Registration::setGaussianSigma(QString gaussianSigma)
{
    m_gaussianSigma = gaussianSigma;
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

    defineExecutable("DTIReg");
    defineParameter("refDTIatlas_dir");
    defineParameter("inputDTIatlas_dir");
    defineParameter("registrationType");
    defineParameter("similarityMetric");
    defineParameter("gaussianSigma");
    m_script += "displacementFieldPath = '" + m_displacementFieldPath + "'\n";

    m_script += "logger = logging.getLogger('AutoTract')\n\n";

    m_script += "runningProcess = None\n\n";
}

void Registration::executeRegistration()
{
    m_log = "Registration";
    m_outputs.insert("displacementField", m_displacementFieldPath);
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

    m_script += "\trefDTIAtlas = '" + m_refDTIAtlas + "'\n";
    m_script += "\tinputDTIAtlas = '" + m_inputDTIAtlas + "'\n";
    m_script += "\tregistrationType = '" + m_registrationType + "'\n";
    m_script += "\tsimilarityMetric = '" + m_similarityMetric + "'\n";
    m_script += "\tgaussianSigma = '" + m_gaussianSigma + "'\n\n";

    m_outputs.insert("displacementField", m_displacementFieldPath);
    checkFinalOutputs();

    m_script += "\tlogger.info('')\n";

    //execute(); seg fault for now (missing args?)
    executeRegistration();
    m_script += "\texecute(args)\n";
    // Cleaning for keven data
    QFileInfo fi(m_refDTIAtlas);
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
