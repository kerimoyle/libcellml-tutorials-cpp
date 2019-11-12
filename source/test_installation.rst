.. test_installation_ ::

-----------------------------------------------
Tutorial 0: Installing libCellML libraries
-----------------------------------------------


1. Create an empty folder and navigate into it

.. code-block:: console

    mkdir libcellml-tutorials
    cd libcellml-tutorials

2. Clone the branch from the libcellml github repository into the folder.
This will create and populate a folder called :code:`libcellml`.

.. code-block:: console

    git clone -b export_compiler_features_i428 --single-branch https://github.com/hsorby/libcellml.git
    git clone -b develop --single-branch https://github.com/cellml/libcellml.git

Your folder structure is now:

.. code-block:: text

    -- libcellml-tutorials
     +--libcellml
        +-- ... contains the files you cloned


3. Create two more folders inside your :code:`libcellml-tutorials` folder

.. code-block:: console

    mkdir build-library
    mkdir install-library

Your folder structure should now look like this:

.. code-block:: text

    -- libcellml-tutorials
     +--build-library
        +-- ... empty
     +--install-library
        +-- ... empty
     +--libcellml
        +-- ... contains the files you cloned


4. Navigate into the :code:`build-library` directory to make and install the
library:

.. code-block:: console

    cd build-library
    cmake -DINSTALL_PREFIX=../install-library ../libcellml
    make -j
    make install
    cd ..

You should see output similar to this:

.. code-block:: console

    -- The CXX compiler identification is AppleClang 10.0.1.10010046
    -- Check for working CXX compiler: /Library/Developer/CommandLineTools/usr/bin/c++
    -- Check for working CXX compiler: /Library/Developer/CommandLineTools/usr/bin/c++ -- works
    -- Detecting CXX compiler ABI info
    -- Detecting CXX compiler ABI info - done
    -- Detecting CXX compile features
    -- Detecting CXX compile features - done
    -- Found Python: /usr/local/Frameworks/Python.framework/Versions/3.7/bin/python3.7 (found version "3.7.4") found components:  Interpreter Development
    -- Found Doxygen: /usr/local/bin/doxygen (found version "1.8.15") found components:  doxygen dot
    -- Found Sphinx: /usr/local/opt/sphinx-doc/bin/sphinx-build
    -- Found SWIG: /usr/local/bin/swig (found suitable version "4.0.0", minimum required is "3")
    -- Performing Test LLVM_COVERAGE_COMPILER_FLAGS_OK
    -- Performing Test LLVM_COVERAGE_COMPILER_FLAGS_OK - Success
    -- Performing Test GCC_COVERAGE_COMPILER_FLAGS_OK
    -- Performing Test GCC_COVERAGE_COMPILER_FLAGS_OK - Success
    -- Found LibXml2: /usr/lib/libxml2.dylib (found version "2.9.4")
    -- Performing Test COMPILER_HAS_HIDDEN_VISIBILITY
    -- Performing Test COMPILER_HAS_HIDDEN_VISIBILITY - Success
    -- Performing Test COMPILER_HAS_HIDDEN_INLINE_VISIBILITY
    -- Performing Test COMPILER_HAS_HIDDEN_INLINE_VISIBILITY - Success
    -- Performing Test COMPILER_HAS_DEPRECATED_ATTR
    -- Performing Test COMPILER_HAS_DEPRECATED_ATTR - Success
    -- The C compiler identification is AppleClang 10.0.1.10010046
    -- Check for working C compiler: /Library/Developer/CommandLineTools/usr/bin/cc
    -- Check for working C compiler: /Library/Developer/CommandLineTools/usr/bin/cc -- works
    -- Detecting C compiler ABI info
    -- Detecting C compiler ABI info - done
    -- Detecting C compile features
    -- Detecting C compile features - done
    -- Looking for pthread.h
    -- Looking for pthread.h - found
    -- Looking for pthread_create
    -- Looking for pthread_create - found
    -- Found Threads: TRUE
    -- Configuring done
    -- Generating done
    -- Build files have been written to: /Users/YourName/libcellml-tutorials-testing/build-library


5. Change back into the top directory and download the tutorials from ??.

.. code-block:: console

    cd ../


Your folder should now look like this:

.. code-block:: text

    -- libcellml-tutorials
     +--build-library
        +-- ( ... lots of files from your earlier make command )
     +--install-library
        +-- include
        +-- lib
     +--libcellml
     +--test_installation
        +-- test_installation.cpp
        +-- CMakeLists.txt
     +--tutorial1
        +-- ( ... files for the tutorial )
     +--tutorial2
     + ( ... etc ... )

6. Change into the :code:`test_installation` folder and build the test example
to check your installation:

.. code-block:: console

    cd test_installation
    cmake -DCMAKE_PREFIX_PATH=../install-library .
    make -j
    ./test_installation

If your installation is correct you will see the output:

.. code-block:: console

    Hello libCellML!

