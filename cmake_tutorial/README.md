# Step 1: A Basic Starting Point
https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html
# Step 2: Adding a Library
https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20a%20Library.html
# Step 3: Adding Usage Requirements for a Library
https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20Usage%20Requirements%20for%20a%20Library.html
# Step 4: Installing and Testing
https://cmake.org/cmake/help/latest/guide/tutorial/Installing%20and%20Testing.html

Run this first:
cmake ../Stepn # From build directory
cmake --build . --config Release
Then this:
cmake --install . --prefix "<INSTALL_DIR>"

# Step 5: Adding System Introspection
Compares to 4 to see the difference.
https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20System%20Introspection.html
# Step 6: Adding a Custom Command and Generated File
https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20a%20Custom%20Command%20and%20Generated%20File.html

# Step 7: Packaging an Installer
https://cmake.org/cmake/help/latest/guide/tutorial/Packaging%20an%20Installer.html

# Step 8: Adding Suport for a Testing Dashboard
https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20Support%20for%20a%20Testing%20Dashboard.html

When using Visual Studio compiler:
ctest [-VV] -C Debug -D Experimental

# Step 9: Selecting Static or Shared Libraries
https://cmake.org/cmake/help/latest/guide/tutorial/Selecting%20Static%20or%20Shared%20Libraries.html

# Step 10: Adding Generator Expression
https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20Generator%20Expressions.html

# Step 11:

# Step 12:
cpack --config MultiCPackConfig.cmake


# User Interaction, consuming rather than producing cmake files as above.
https://cmake.org/cmake/help/latest/guide/user-interaction/index.html