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
    if( m_para_m->getpara_computingSystem_comboBox() == "local")
    {
        m_argumentsList << "DTIReg" << "'--movingVolume'" << "refDTIatlas_dir" << "'--fixedVolume'" << "inputDTIatlas_dir" << "'--method useScalar-ANTS'" << "'--ANTSRegistrationType'"<< "registrationType" << "'--ANTSSimilarityMetric'" << "similarityMetric"  << "'--ANTSSimilarityParameter'" << "'4'" << "'--ANTSGaussianSigma'" << "gaussianSigma" << "'--outputDisplacementField'" << "displacementFieldPath";
        execute();
    }
    else
    {
        QString args = "'bsub', '-q', 'day', '-K', '-M', '" + QString::number(8) + "', '-n', '" + QString::number(m_para_m->getpara_nb_threads_spinBox()) + "', '-R', 'span[hosts=1]', ";
        args += "DTIReg, '--movingVolume', refDTIatlas_dir, '--fixedVolume', inputDTIatlas_dir, '--method useScalar-ANTS', '--ANTSRegistrationType', registrationType, '--ANTSSimilarityMetric', similarityMetric, '--ANTSSimilarityParameter', '4', '--ANTSGaussianSigma', gaussianSigma, '--outputDisplacementField', displacementFieldPath";
        m_script += "\targs = [" + args + "]\n";
        m_script += "\tbsub_process = subprocess.Popen(args, stdout=subprocess.PIPE)\n";
        m_script += "\tbsub_output = bsub_process.stdout.read()\n";
        m_script += "\tlogger.info(bsub_output)\n";
        m_script += "\tjobID = re.search('(<{1})([0-9]{1,})(>{1})', bsub_output).group(2)\n";
        m_script += "\tlogger.info(jobID)\n";
    }
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
    m_script += "\tos.environ['ITK_GLOBAL_DEFAULT_NUMBER_OF_THREADS'] = '" + QString::number(m_para_m->getpara_nb_threads_spinBox()) + "' \n";

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
