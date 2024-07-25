# Setting C++ & OpenGL Visual Studio 2022
Thank you for visiting the page for my C++ & OpenGL visual studio project setup. As the title says this is a setup, there is nothing special about this project other than that you can use it to have a base in OpenGL programming.

# Step 1
Download folder [Library_Glut] (https://github.com/achmaddwiprasetyo/3D-Geometri-openGL/tree/main/Library_Glut) and extract file.
# Step 2
Create a folder on disk c: with the name openGL, Copy all downloaded library files to the openGL folder.
# Step 3
Open your Visual Studio app and create a new project empty project C++, After the project is created, right click on the project name, select > add > new item > select c++ file (name the project).
# Step 3
Next, right-click again on the name of the project you created, select Properties.
1. Change Configure to Debug and select Platform Win32
2. Select the C/C++ menu > General > Additional Include Directories > Edit > New Line
3. Select a folder from the glut library *C:\openGL\glew-1.11.0\include* and *C:\openGL\freeglut\include*
4. Then select the linker menu > General > Additional Include Directories > Edit > New Line
5. Select a folder from the glut library *C:\openGL\glew-1.11.0\lib* and *C:\openGL\freeglut\lib*
6. Then select the linker menu > Input > Additional Dependencies > Edit > add text *freeglut.lib;glew32.lib;*
