# Setting C++ & OpenGL Visual Studio 2022
Thank you for visiting the page for my C++ & OpenGL visual studio project setup. As the title says this is a setup, there is nothing special about this project other than that you can use it to have a base in OpenGL programming.

**Step 1**<br/>
Download folder [Library_Glut](https://github.com/achmaddwiprasetyo/3D-Geometri-openGL/tree/main/Library_Glut) and extract file.
**Step 2**<br/>
Create a folder on disk c: with the name openGL, Copy all downloaded library files to the openGL folder.<br/>
**Step 3**<br/>
Open your Visual Studio app and create a new project empty project C++, After the project is created, right click on the project name, select > add > new item > select c++ file (name the project).<br/>
**Step 4**<br/>
Next, right-click again on the name of the project you created, select Properties.
1. Change Configure to Debug and select Platform Win32
   ![screenshot_35](https://github.com/achmaddwiprasetyo/3D-Geometri-openGL/blob/main/Screenshot%202024-07-26%20003023.png)
3. Select the C/C++ menu > General > Additional Include Directories > Edit > New Line
4. Select a folder from the glut library *C:\openGL\glew-1.11.0\include* and *C:\openGL\freeglut\include*
5. Then select the linker menu > General > Additional Include Directories > Edit > New Line
6. Select a folder from the glut library *C:\openGL\glew-1.11.0\lib* and *C:\openGL\freeglut\lib*
7. Then select the linker menu > Input > Additional Dependencies > Edit > add text *freeglut.lib;glew32.lib;*
8. Copy the source code [3d.cpp](https://github.com/achmaddwiprasetyo/3D-Geometri-openGL/blob/main/UAS_Grafika_Komputer/UAS_Grafika_Komputer/3d.cpp) to the C++ file that was created previously
9. Copy file *freeglut.dll* and *glew32.dll* file into the project folder that has been created.
10. Running program
