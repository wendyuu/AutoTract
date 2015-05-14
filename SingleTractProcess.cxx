
#include "SingleTractProcess.h"

SingleTractProcess::SingleTractProcess(QString module) : Script(module)
{

}

// SET //
void SingleTractProcess::setLog(QString log_path)
{
    m_log_path = log_path;
}

void SingleTractProcess::initializeScript()
{
    definePython();
    importGeneralModules();

    m_script += "import re\n";
    m_script += "import time\n";

    defineExecutable("polydatatransform");

    m_script += "logger = None\n";

    m_script += "runningProcess = None\n";
    m_script += "logFile = None\n\n";
}

void SingleTractProcess::initializeLogging()
{
    m_script += "def initializeLogging(log):\n";

    m_script += "\tglobal logger\n";
    m_script += "\tlogger = logging.getLogger('SingleTractProcess')\n";
    m_script += "\tlogger.setLevel(logging.DEBUG)\n";

    m_script += "\tfileHandler = logging.FileHandler(log)\n";
    m_script += "\tfileHandler.setLevel(logging.DEBUG)\n";
    m_script += "\tfileFormatter = logging.Formatter('%(message)s')\n";
    m_script += "\tfileHandler.setFormatter(fileFormatter)\n";

    m_script += "\tlogger.addHandler(fileHandler)\n\n";
}

void SingleTractProcess::implementSingleTractProcess()
{
    m_script += "def main(name, tract, output, displacementField, log):\n\n";

    m_script += "\tsignal.signal(signal.SIGINT, stop)\n";
    m_script += "\tsignal.signal(signal.SIGTERM, stop)\n\n";

    m_script += "\tlogFile = open(log, \"w\")\n";
    m_script += "\tinitializeLogging(log)\n\n";

    //m_script += "\t\ttime.sleep(0.5)\n";
    /*m_script += "\t\tmainLog = open('" + m_log_path + "','a')\n";
    m_script += "\t\tmainLog.write(name + ' PostProcess -> Skipped\\n')\n";
    m_script += "\t\tmainLog.close()\n";
    m_script += "\t\treturn\n";*/

    m_script += "\tmainLog = open('" + m_log_path + "','a')\n";
    m_script += "\tmainLog.write(name + ' PostProcess...\\n')\n";
    m_script += "\tmainLog.close()\n";

    m_log = "Mapping reference tracts";

    //m_inputs.insert("tract", tract);
    //m_inputs.insert("displacementField", displacementField);

    m_argumentsList << "polydatatransform" << "'--fiber_file'" << "tract" << "'-o'" << "output" << "'-D'" << "displacementField" << "'--inverty'" << "'--invertx'";
    execute();

    m_log = "Dilation and voxelization of the mapped reference tracts";

    /*m_argumentsList <<""

                      subprocess.call([fiberprocess, "--voxelize", outputdir + "dilated_images/" + labelmap,
                                       "--fiber_file", fibersMappedDir + file, "-T", DTIsource])
                      dilatedImage = os.path.splitext(file)[0] + "_dil.nrrd"
                      subprocess.call([ImageMath,  outputdir + "dilated_images/" + labelmap, "-dilate", str(dilationRadius) + ",1", "-outfile",
                                       outputdir + "dilated_images/" + dilatedImage])*/
}

void SingleTractProcess::writeSingleTractProcess()
{
    initializeScript();

    implementStop();
    implementCheckFileExistence();
    initializeLogging();
    implementExecute();
    implementSingleTractProcess();

    m_script += "if __name__ == '__main__':\n";
    m_script += "\tmain(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5])\n";

    QString script_path = m_processing_dir->filePath("SingleTractProcess.py");

    std::ofstream* script_stream = new std::ofstream((script_path.toStdString()).c_str(), std::ios::out | std::ios::trunc);
    *script_stream << m_script.toStdString() << std::endl;
}

void SingleTractProcess::update()
{
    writeSingleTractProcess();
}


