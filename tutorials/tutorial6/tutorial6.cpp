/**
 *      TUTORIAL 6: CODE GENERATION
 * 
 *  This tutorial explores the ability of libCellML to generate files representing 
 *  the model which can be solved in Python or C.  By the time you have worked 
 *  through Tutorial 6 you will be able to:
 *      - use the Generator functionality to create models in Python or C format
 *      - use the simple solver provided to run the created models.
 * 
 *  Tutorial 6 assumes that you are already comfortable with:
 *      - file manipulation and summarising using the utility functions
 *      
 */

#include <iostream>
#include <libcellml>

#include "../../utilities/tutorial_utilities.h"

int main()
{
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "  STEP 1: Read the potassium channel model" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    //  1.a Read the model created in Tutorial 5.  Note that if you didn't
    //      do that tutorial you can simply copy the CellML file
    //      from resources/tutorial5_PotassiumChannelModel.cellml

    std::string inFileName = "../../resources/tutorial5_PotassiumChannelModel.cellml";
    std::ifstream inFile(inFileName);
    std::stringstream inFileContents;
    inFileContents << inFile.rdbuf();
    std::cout << "Opening the CellML file: '" << inFileName << "'" << std::endl;

    libcellml::Parser parser;
    libcellml::ModelPtr model = parser.parseModel(inFileContents.str());
    model->setName("Tutorial6_PotassiumChannelModel");

    //  1.b Print the parsed model to the terminal and check its contents
    printModelToTerminal(model);

    //  1.c Create a Validator and use it to check that the model is ok so far
    libcellml::Validator validator;
    validator.validateModel(model);
    printErrorsToTerminal(validator);

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "  STEP 2: Construct a Generator instance" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    libcellml::Generator generator;
    generator.processModel(model);
    std::cout << "The generator returned "<<generator.errorCount()<<" errors!"<<std::endl;
    for(size_t e=0; e < generator.errorCount(); ++e){
        std::cout << generator.error(e)->description()<<std::endl;
    }

    // TODO Generator currently segfaults

}
