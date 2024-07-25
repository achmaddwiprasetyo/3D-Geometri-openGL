# Setting C++ & OpenGL Visual Studio 2022
Thank you for visiting the page for my C++ & OpenGL visual studio project setup. As the title says this is a setup, there is nothing special about this project other than that you can use it to have a base in OpenGL programming.

## Step 1<br/>
Download folder [Library_Glut](https://github.com/achmaddwiprasetyo/3D-Geometri-openGL/tree/main/Library_Glut) and extract file.<br/>
## Step 2<br/>
Create a folder on disk c: with the name openGL, Copy all downloaded library files to the openGL folder.<br/>
## Step 3<br/>
Open your Visual Studio app and create a new project empty project C++, After the project is created, right click on the project name, select > add > new item > select c++ file (name the project).<br/>
## Step 4<br/>
Next, right-click again on the name of the project you created, select Properties.
1. Change Configure to Debug and select Platform Win32
   ![screenshot_35](https://github.com/achmaddwiprasetyo/3D-Geometri-openGL/blob/main/Screenshot%202024-07-26%20003023.png)
2. Select the C/C++ menu > General > Additional Include Directories > Edit > New Line
3. Select a folder from the glut library *C:\openGL\glew-1.11.0\include* and *C:\openGL\freeglut\include*
   ![screenshot_35](https://github.com/achmaddwiprasetyo/3D-Geometri-openGL/blob/main/Screenshot%202024-07-26%20005614.png)
4. Then select the linker menu > General > Additional Include Directories > Edit > New Line
5. Select a folder from the glut library *C:\openGL\glew-1.11.0\lib* and *C:\openGL\freeglut\lib*
   ![screenshot_35](https://github.com/achmaddwiprasetyo/3D-Geometri-openGL/blob/main/Screenshot%202024-07-26%20005630.png)
6. Then select the linker menu > Input > Additional Dependencies > Edit > add text *freeglut.lib;glew32.lib;*
   ![screenshot_35](https://github.com/achmaddwiprasetyo/3D-Geometri-openGL/blob/main/Screenshot%202024-07-26%20005641.png)
7. Copy the source code [3d.cpp](https://github.com/achmaddwiprasetyo/3D-Geometri-openGL/blob/main/UAS_Grafika_Komputer/UAS_Grafika_Komputer/3d.cpp) to the C++ file that was created previously
8. Copy file *freeglut.dll* and *glew32.dll* file into the project folder that has been created.
9. Running program
   ![screenshot_35](https://github.com/achmaddwiprasetyo/3D-Geometri-openGL/blob/main/Screenshot%202024-07-26%20010436.png)

<p align='center'>
   <a href="https://www.linkedin.com/in/achmad-dwi-prasetyo/">
       <img src="https://img.shields.io/badge/linkedin-%230077B5.svg?&style=for-the-badge&logo=linkedin&logoColor=white"/>
   </a>
   <a href="https://t.me/joinchat/">
       <img src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/>
   </a>
<p align='center'>
   📫 How to reach me: <a href='mailto:duikskecebong@gmail.com'>duikskecebong@gmail.com</a>
</p>
