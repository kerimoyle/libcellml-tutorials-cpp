Generator notes
---------------

Some exciting new functionality of libCellML is its ability to generate a
runable file from a model description.  This means that you don't need to
link your model to a solver of any kind, you can simply generate a script
which contains all the required behind-the-scenes mechanics required to
run your simulation.  Let's give it a go.

The generator is instantiated in the same way as the other items:

.. code-block:: cpp

    // Instantiate the generator and submit the model to it for processing
    libcellml::Generator generator;
    generator.processModel(model);

The Generator functionality allows us to export runable files in
different languages, called *profiles* in libCellML.  The
default setting is for C, but you can change this using the
:code:`setProfile` function if you need to:

.. code-block:: cpp

    libcellml::GeneratorProfilePtr profile = std::make_shared<libcellml::GeneratorProfile>(libcellml::GeneratorProfile::Profile::PYTHON);
    generator.setProfile(profile);

Of course, your choice of generator profile (language) will affect
what you need to export.  If you're using C, then you will need both the
header file as well as the source code.  If you're using Python, you will
only need the source code.

For C:

.. code-block:: cpp

    // Retrieve the interface or header code, and write to a file:
    std::string headerCode = generator.interfaceCode();

    // Retrieve the main source code and write to a file:
    std::string sourceCode = generator.implementationCode();

For Python:

.. code-block:: cpp

    // Retrieve the main script code only:
    std::string sourceCode = generator.implementationCode();

