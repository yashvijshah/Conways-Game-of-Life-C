# Conways-Game-of-Life-C
This is the C version of famous Conway's Game of Life.
This project is implemented using SDL library and tested using unity test framework.

Instructions on how to run the program :
   -> Download the files submitted and put it into a folder.
   -> Move the folder to Desktop and rename it to whatever you have named your project in the CMakeLists.txt for the CMakeLists.txt to work.
   -> Open the terminal on Linux and write the following commands:
      -> cd Desktop/foldername
      -> mkdir build
      -> cd build
      -> cmake ../
      -> make
      -> ./gameoflife
      -> ./unit_tests

The size of the world for Conway's game of life is configurable in the initialStateFile.txt. Any changes to the grid can be made there. 
Note that the ROWS and COLS variables are globally defined so if you change the size of the world, the program will run perfectly fine but the finalStateFile will have a 12x12 grid only! 
If you want the finalStateFile to display the size of the world you configured in the initialStateFile, you need to change the 'ROWS' and 'COLS' values in all the header files accordingly.
