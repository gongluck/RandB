# Configure VS Code for Microsoft C++
* 为Microsoft C ++配置VS代码
* 原文地址 https://code.visualstudio.com/docs/cpp/config-msvc#_set-a-watch

In this tutorial, you configure Visual Studio Code to use the Microsoft Visual C++ compiler and debugger on Windows.

在本教程中，您将Visual Studio Code配置为在Windows上使用Microsoft Visual C ++编译器和调试器。

After configuring VS Code, you will compile and debug a simple Hello World program in VS Code. This tutorial does not teach you details about the Microsoft C++ toolset or the C++ language. For those subjects, there are many good resources available on the Web.

配置VS Code后，您将在VS Code中编译和调试一个简单的Hello World程序。本教程不会教您有关Microsoft C ++工具集或C ++语言的详细信息。对于这些主题，Web上有许多不错的资源。

If you have any problems, feel free to file an issue for this tutorial in the VS Code documentation repository.

如果您有任何问题，请随时在VS Code文档库中提交本教程的问题。

## Prerequisites
* 先决条件

To successfully complete this tutorial, you must do the following:

若要成功完成本教程，您必须执行以下操作：

    Install Visual Studio Code.
    
    安装Visual Studio Code。

    Install the C/C++ extension for VS Code. You can install the C/C++ extension by searching for 'c++' in the Extensions view (Ctrl+Shift+X).
    
    安装VS Code的C/C++扩展。您可以通过在“扩展名”视图（Ctrl + Shift + X）中搜索“c++”来安装C/C++扩展名。

    C/C++ extension
    
    C/C++ 扩展

    Install the Microsoft Visual C++ (MSVC) compiler toolset.
    
    安装Microsoft Visual C++（MSVC）编译器工具集。

    If you have a recent version of Visual Studio, open the Visual Studio Installer from the Windows Start menu and verify that the C++ workload is checked. If it's not installed, then check the box and click the Modify button in the installer.
    
    如果您使用的是Visual Studio的最新版本，请从Windows的“开始”菜单中打开“ Visual Studio安装程序”，并验证是否选中了C++工作负载。如果尚未安装，请选中该框，然后在安装程序中单击“修改”按钮。

    You can also install just the C++ Build Tools, without a full Visual Studio IDE installation. From the Visual Studio Downloads page, scroll down until you see Tools for Visual Studio under the All downloads section and select the download for Build Tools for Visual Studio.
    
    您也可以仅安装C++ Build Tools，而无需完整安装Visual Studio IDE。在“Visual Studio下载”页面上，向下滚动直到在“所有下载”部分下看到“Visual Studio工具”，然后选择“Visual Studio生成工具”的下载。

    Build Tools for Visual Studio download
    
    用于Visual Studio的构建工具下载

    This will launch the Visual Studio Installer, which will bring up a dialog showing the available Visual Studio Build Tools workloads. Check the C++ build tools workload and select Install.
    
    这将启动Visual Studio安装程序，它将弹出一个对话框，显示可用的Visual Studio Build Tools工作量。检查C ++生成工具的工作量，然后选择“安装”。

### Check your Microsoft Visual C++ installation
* 检查您的Microsoft Visual C ++安装

To use MSVC from a command line or VS Code, you must run from a Developer Command Prompt for Visual Studio. An ordinary shell such as PowerShell, Bash, or the Windows command prompt does not have the necessary path environment variables set.

要从命令行或VS Code使用MSVC，必须从Visual Studio的开发人员命令提示符运行。普通的Shell（例如PowerShell，Bash或Windows命令提示符）没有设置必要的路径环境变量。

To open the Developer Command Prompt for VS, start typing 'developer' in the Windows Start menu, and you should see it appear in the list of suggestions. The exact name depends on which version of Visual Studio or the Visual Studio Build Tools you have installed. Click on the item to open the prompt.

要打开VS的Developer Command Prompt，请在​​Windows“开始”菜单中开始输入“developer”，您应该看到它出现在建议列表中。 确切名称取决于您安装的Visual Studio或Visual Studio Build Tools版本。单击该项目以打开提示。

You can test that you have the C++ compiler, cl.exe, installed correctly by typing 'cl' and you should see a copyright message with the version and basic usage description.

您可以通过键入“cl”来测试是否正确安装了C++编译器cl.exe，并且应该看到版权消息以及其版本和基本用法说明。

If the Developer Command Prompt is using the BuildTools location as the starting directory (you wouldn't want to put projects there), navigate to your user folder (C:\users\{your username}\) before you start creating new projects.

如果开发人员命令提示符使用BuildTools位置作为开始目录（您不想在此处放置项目），请在开始创建新项目之前导航到用户文件夹（C\users\{您的用户名}\）。

## Create Hello World
* 创建Hello World

From the Developer Command Prompt, create an empty folder called "projects" where you can store all your VS Code projects, then create a subfolder called "helloworld", navigate into it, and open VS Code (code) in that folder (.) by entering the following commands:

在“开发人员命令提示符”中，创建一个名为“projects”的空文件夹，您可以在其中存储所有VS Code项目，然后创建一个名为“helloworld”的子文件夹，导航至该文件夹，然后在该文件夹（.）中打开VS Code（code）。 通过输入以下命令：
```
mkdir projects
cd projects
mkdir helloworld
cd helloworld
code .
```           

The "code ." command opens VS Code in the current working folder, which becomes your "workspace". As you go through the tutorial, you will see three files created in a .vscode folder in the workspace:

"code ."命令在当前工作文件夹中打开VS Code，这将成为您的“工作空间”。在学习本教程的过程中，您将看到在工作区的.vscode文件夹中创建的三个文件：
    tasks.json (build instructions)
    launch.json (debugger settings)
    c_cpp_properties.json (compiler path and IntelliSense settings)

### Add a source code file
* 添加源代码文件

In the File Explorer title bar, select the New File button and name the file helloworld.cpp.

在文件资源管理器标题栏中，选择“新建文件”按钮，并将文件命名为helloworld.cpp。

Add hello world source code

添加Hello World源代码

Now paste in this source code:

现在粘贴此源代码：
```
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
```

Now press Ctrl+S to save the file. Notice how the file you just added appears in the File Explorer view (Ctrl+Shift+E) in the side bar of VS Code:

现在按Ctrl + S保存文件。请注意，刚刚添加的文件如何显示在VS Code侧栏中的文件资源管理器视图（Ctrl + Shift + E）中：

You can also enable Auto Save to automatically save your file changes, by checking Auto Save in the main File menu.

您还可以通过选中“文件”主菜单中的“自动保存”，启用“自动保存”以自动保存文件更改。

The Activity Bar on the far left lets you open different views such as Search, Source Control, and Run. You'll look at the Run view later in this tutorial. You can find out more about the other views in the VS Code User Interface documentation.

最左侧的活动栏使您可以打开不同的视图，例如搜索，源代码管理和运行。您将在本教程后面的内容中查看“运行”视图。您可以在VS Code用户界面文档中找到有关其他视图的更多信息。
    
    Note: When you save or open a C++ file, you may see a notification from the C/C++ extension about the availability of an Insiders version, which lets you test new features and fixes. You can ignore this notification by selecting the X (Clear Notification).
   
    注意：保存或打开C++文件时，您可能会看到来自C/C++扩展名的关于Insiders版本可用性的通知，该通知可让您测试新功能和修复。您可以通过选择X（清除通知）来忽略此通知。

## Explore IntelliSense
* 探索智能感知

In your new helloworld.cpp file, hover over vector or string to see type information. After the declaration of the msg variable, start typing msg. as you would when calling a member function. You should immediately see a completion list that shows all the member functions, and a window that shows the type information for the msg object

在新的helloworld.cpp文件中，将鼠标悬停在矢量或字符串上以查看类型信息。在声明msg变量之后，开始键入msg。就像调用成员函数时一样。您应该立即看到一个显示所有成员函数的完成列表，以及一个显示msg对象的类型信息的窗口

You can press the Tab key to insert the selected member; then, when you add the opening parenthesis, you will see information about any arguments that the function requires.

您可以按Tab键插入选定的成员。 然后，当您添加左括号时，您将看到有关该函数所需的任何参数的信息。

## Build helloworld.cpp
* 编译helloworld.cpp

Next, you will create a tasks.json file to tell VS Code how to build (compile) the program. This task will invoke the Microsoft C++ compiler to create an executable file based on the source code.

接下来，您将创建一个task.json文件来告诉VS Code如何构建（编译）程序。 该任务将调用Microsoft C++编译器以基于源代码创建可执行文件。

From the main menu, choose Terminal > Configure Default Build Task. In the dropdown, which will display a tasks dropdown listing various predefined build tasks for C++ compilers. Choose cl.exe build active file, which will build the file that is currently displayed (active) in the editor.

在主菜单中，选择“终端>配置默认生成任务”。 在下拉列表中，将显示任务下拉列表，其中列出了C ++编译器的各种预定义构建任务。 选择cl.exe构建活动文件，它将构建当前在编辑器中显示（活动）的文件。

This will create a tasks.json file in a .vscode folder and open it in the editor.

这将在.vscode文件夹中创建一个task.json文件，并在编辑器中将其打开。

Your new tasks.json file should look similar to the JSON below:

您的新task.json文件应类似于以下JSON：
```
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "shell",
      "label": "cl.exe build active file",
      "command": "cl.exe",
      "args": [
        "/Zi",
        "/EHsc",
        "/Fe:",
        "${fileDirname}\\${fileBasenameNoExtension}.exe",
        "${file}"
      ],
      "problemMatcher": ["$msCompile"],
      "group": {
        "kind": "build",
        "isDefault": true
      }
    }
  ]
}
```

The command setting specifies the program to run; in this case that is "cl.exe". The args array specifies the command-line arguments that will be passed to cl.exe. These arguments must be specified in the order expected by the compiler. This task tells the C++ compiler to take the active file (${file}), compile it, and create an executable file (/Fe: switch) in the current directory (${fileDirname}) with the same name as the active file but with the .exe extension (${fileBasenameNoExtension}.exe), resulting in helloworld.exe for our example.

命令设置指定要运行的程序；在这种情况下，它就是“cl.exe”。 args数组指定将传递给cl.exe的命令行参数。必须按照编译器期望的顺序指定这些参数。该任务告诉C++编译器获取活动文件（${file}），对其进行编译，然后在当前目录（${fileDirname}）中创建一个与活动文件同名的可执行文件（/Fe:switch）。但带有.exe扩展名（${fileBasenameNoExtension}.exe），对于我们的示例将生成helloworld.exe。
    
    Note: You can learn more about task.json variables in the variables reference.
    
    注意：您可以在变量参考中了解有关task.json变量的更多信息。

The label value is what you will see in the tasks list; you can name this whatever you like.

标签值就是您将在任务列表中看到的值；您可以随意命名。

The problemMatcher value selects the output parser to use for finding errors and warnings in the compiler output. For cl.exe, you'll get the best results if you use the $msCompile problem matcher.

problemMatcher值选择输出解析器，以用于在编译器输出中查找错误和警告。对于cl.exe，如果使用$msCompile问题匹配器，将获得最佳结果。

The "isDefault": true value in the group object specifies that this task will be run when you press Ctrl+Shift+B. This property is for convenience only; if you set it to false, you can still run it from the Terminal menu with Tasks: Run Build Task.

组对象中的“isDefault”：true值指定此任务将按下Ctrl + Shift + B组合键即可运行。 此属性仅出于方便起见； 如果将其设置为false，您仍然可以使用“任务：运行构建任务”从“终端”菜单中运行它。

### Running the build
* 运行构建

    Go back to helloworld.cpp. Your task builds the active file and you want to build helloworld.cpp.
    
    返回至helloworld.cpp。 您的任务将构建活动文件，并且您希望构建helloworld.cpp。

    To run the build task defined in tasks.json, press Ctrl+Shift+B or from the Terminal main menu choose Tasks: Run Build Task.
    
    要运行task.json中定义的构建任务，请按Ctrl + Shift + B或从“终端”主菜单中选择“任务：运行构建任务”。

    When the task starts, you should see the Integrated Terminal panel appear below the source code editor. After the task completes, the terminal shows output from the compiler that indicates whether the build succeeded or failed.
    
    任务启动时，您应该看到“集成终端”面板出现在源代码编辑器下方。 任务完成后，终端将显示编译器的输出，指示构建成功还是失败。

    Create a new terminal using the + button and you'll have a new terminal (running PowerShell) with the helloworld folder as the working directory. Run ls and you should now see the executable helloworld.exe along with various intermediate C++ output and debugging files (helloworld.obj, helloworld.pdb).
    
    使用+按钮创建一个新终端，您将拥有一个新终端（运行PowerShell），其中helloworld文件夹作为工作目录。 运行ls，您现在应该看到可执行文件helloworld.exe以及各种中间C++输出和调试文件（helloworld.obj，helloworld.pdb）。

    You can run helloworld in the terminal by typing .\helloworld.exe.
    
    您可以通过在终端中键入.\helloworld.exe来运行helloworld。 

    Note: You might need to press Enter a couple of times initially to see the PowerShell prompt in the terminal. This issue should be fixed in a future release of Windows.
    
    注意：最初可能需要几次按Enter键才能在终端中看到PowerShell提示。 Windows的将来版本中应解决此问题。

### Modifying tasks.json
* 修改task.json

You can modify your tasks.json to build multiple C++ files by using an argument like "${workspaceFolder}\\*.cpp" instead of ${file}. This will build all .cpp files in your current folder. You can also modify the output filename by replacing "${fileDirname}\\${fileBasenameNoExtension}.exe" with a hard-coded filename (for example "${workspaceFolder}\\myProgram.exe").

您可以使用诸如“ ${workspaceFolder}\*.cpp ”之类的参数而不是${file}来修改task.json以构建多个C++文件。 这将在当前文件夹中生成所有.cpp文件。 您也可以通过将“ ${fileDirname}\${fileBasenameNoExtension}.exe ”替换为硬编码的文件名（例如“ ${workspaceFolder}\myProgram.exe ”）来修改输出文件名。

## Debug helloworld.cpp
* 调试helloworld.cpp

Next, you'll create a launch.json file to configure VS Code to launch the Microsoft C++ debugger when you press F5 to debug the program. From the main menu, choose Run > Add Configuration... and then choose C++ (Windows).

接下来，您将创建一个launch.json文件，以配置VS Code以在您按F5调试程序时启动Microsoft C++调试器。 从主菜单中，选择“运行”>“添加配置...”，然后选择“C++（Windows）”。

You'll then see a dropdown for various predefined debugging configurations. Choose cl.exe build and debug active file.

然后，您会看到各种预定义的下拉菜单调试配置。 选择cl.exe构建并调试活动文件。

VS Code creates a launch.json file, opens it in the editor, and builds and runs 'helloworld'.

VS Code创建一个launch.json文件，在编辑器中将其打开，然后生成并运行“helloworld”。
```
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "cl.exe build and debug active file",
      "type": "cppvsdbg",
      "request": "launch",
      "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "preLaunchTask": "cl.exe build active file"
    }
  ]
}
``` 

The program setting specifies the program you want to debug. Here it is set to the active file folder ${fileDirname} and active filename with the .exe extension ${fileBasenameNoExtension}.exe, which if helloworld.cpp is the active file will be helloworld.exe.

程序设置指定要调试的程序。在这里，它被设置为活动文件文件夹${fileDirname}和活动文件名，扩展名为.exe的{fileBasenameNoExtension}.exe，如果helloworld.cpp是活动文件，则文件名为helloworld.exe。

By default, the C++ extension won't add any breakpoints to your source code and the stopAtEntry value is set to false. Change the stopAtEntry value to true to cause the debugger to stop on the main method when you start debugging.

默认情况下，C++扩展不会在源代码中添加任何断点，并且stopAtEntry值设置为false。将stopAtEntry值更改为true以在启动调试时使调试器在main方法上停止。

### Start a debugging session 
* 进行调试会话 
	
	Go back to helloworld.cpp so that it is the active file.
    Press F5 or from the main menu choose Run > Start Debugging. Before you start stepping through the source code, let's take a moment to notice several changes in the user interface:
	
    请返回helloworld.cpp，使其成为活动文件。按F5或从主菜单中选择“运行”>“开始调试”。在开始浏览源代码之前，让我们花一点时间注意用户界面中的几处更改：

    The Integrated Terminal appears at the bottom of the source code editor. In the Debug Output tab, you see output that indicates the debugger is up and running.
	
    Integrated Terminal出现在源代码编辑器的底部。在“调试输出”选项卡中，您将看到指示调试器已启动并正在运行的输出。

    The editor highlights the first statement in the main method. This is a breakpoint that the C++ extension automatically sets for you.
	
    编辑器突出显示main方法中的第一条语句。这是C ++扩展自动为您设置的断点。

    The Run view on the left shows debugging information. You'll see an example later in the tutorial.
	
    初始断点左侧的“运行”视图显示调试信息。您将在本教程的后面看到一个示例。

    At the top of the code editor, a debugging control panel appears. You can move this around the screen by grabbing the dots on the left side.        
	
    在代码编辑器的顶部，将显示一个调试控制面板。您可以通过抓住左侧的点在屏幕上移动它。 

## Step through the code
* 逐步执行代码

Now you're ready to start stepping through the code.

现在，您准备开始逐步执​​行代码。

    Click or press the Step over icon in the debugging control panel until the for (const string& word : msg) statement is highlighted.
	
    单击或按调试控制面板中的“跳过”图标，直到突出显示for（const string＆word：msg）语句。

    The Step Over command skip over all the internal function calls within the vector and string classes that are invoked when the msg variable is created and initialized. Notice the change in the Variables window on the left. In this case, the errors are expected because, although the variable names for the loop are now visible to the debugger, the statement has not executed yet, so there is nothing to read at this point. The contents of msg are visible, however, because that statement has completed.
	
    单步执行命令跳过在创建和初始化msg变量时调用的向量和字符串类中的所有内部函数调用。注意左侧“变量”窗口中的更改。在这种情况下，可能会出现错误，因为尽管调试器现在可以看到循环的变量名，但该语句尚未执行，因此此时无任何内容可读取。但是，由于该语句已完成，因此msg的内容是可见的。

    Press Step over again to advance to the next statement in this program (skipping over all the internal code that is executed to initialize the loop). Now, the Variables window shows information about the loop variables.
	
    再次按Step over前进到该程序中的下一条语句（跳过为初始化循环而执行的所有内部代码）。现在，“变量”窗口显示有关循环变量的信息。

    Press Step over again to execute the cout statement. Note As of the March 2019 version of the extension, no output is displayed until the loop completes.
	
    再次按“跳过”以执行cout语句。注意自扩展程序的2019年3月版起，直到循环完成，才会显示任何输出。

    If you like, you can keep pressing Step over until all the words in the vector have been printed to the console. But if you are curious, try pressing the Step Into button to step through source code in the C++ standard library!
	
    如果愿意，可以继续按Step over，直到将引导程序中的所有单词都打印到控制台为止。 但是，如果您感到好奇，请尝试按Step Into按钮以逐步浏览C++标准库中的源代码！

    To return to your own code, one way is to keep pressing Step over. Another way is to set a breakpoint in your code by switching to the helloworld.cpp tab in the code editor, putting the insertion point somewhere on the cout statement inside the loop, and pressing F9. A red dot appears in the gutter on the left to indicate that a breakpoint has been set on this line.
	
    要返回您自己的代码，一种方法是按住“跳过”。 另一种方法是通过在代码编辑器中切换到helloworld.cpp选项卡，在循环内的cout语句中的某个位置插入插入点，然后按F9来在代码中设置断点。 在左侧的装订线中出现一个红点，指示已在此行上设置断点。

    Then press F5 to start execution from the current line in the standard library header. Execution will break on cout. If you like, you can press F9 again to toggle off the breakpoint.	
	
    然后按F5键从标准库标题中的当前行开始执行。 执行将中断。 如果愿意，可以再次按F9键以关闭断点。
	
## Set a watch
* 设置监视

Sometimes you might want to keep track of the value of a variable as your program executes. You can do this by setting a watch on the variable.

有时，您可能希望在程序执行时跟踪变量的值。您可以通过在变量上设置监视来做到这一点。

    Place the insertion point inside the loop. In the Watch window, click the plus sign and in the text box, type word, which is the name of the loop variable. Now view the Watch window as you step through the loop.
	
    将插入点放在循环内。在“监视”窗口中，单击加号，然后在文本框中键入word，这是循环变量的名称。现在，当您逐步执行循环时，请查看“监视”窗口。


    Add another watch by adding this statement before the loop: int i = 0;. Then, inside the loop, add this statement: ++i;. Now add a watch for i as you did in the previous step.
	
    通过在循环之前添加以下语句来添加另一个监视：int i = 0;。然后，在循环内部添加以下语句：++i;。现在像上一步一样为我添加监视。
	
    To quickly view the value of any variable while execution is paused on a breakpoint, you can hover over it with the mouse pointer.
	
    要在断点处暂停执行时快速查看任何变量的值，可以使用鼠标指针悬停在其上。
	
## C/C++ configurations
* C/C++配置

If you want more control over the C/C++ extension, you can create a c_cpp_properties.json file, which will allow you to change settings such as the path to the compiler, include paths, C++ standard (default is C++17), and more.

如果您想进一步控制C/C ++扩展，则可以创建一个c_cpp_properties.json文件，该文件可让您更改设置，例如编译器的路径，包含路径，C++标准（默认为C++ 17），和更多。

You can view the C/C++ configuration UI by running the command C/C++: Edit Configurations (UI) from the Command Palette (Ctrl+Shift+P).

您可以通过运行命令C/C++：从命令面板（Ctrl + Shift + P）编辑配置（UI）来查看C/C++配置UI。 

This opens the C/C++ Configurations page. When you make changes here, VS Code writes them to a file called c_cpp_properties.json in the .vscode folder.

这将打开“C/C++配置”页面。当您在此处进行更改时，VS Code将它们写入.vscode文件夹中名为c_cpp_properties.json的文件中。

Visual Studio Code places these settings in .vscode\c_cpp_properties.json. If you open that file directly, it should look something like this:

Visual Studio Code将这些设置放在.vscode\c_cpp_properties.json中。如果直接打开该文件，则它应如下所示：
```
{
  "configurations": [
    {
      "name": "Win32",
      "includePath": ["${workspaceFolder}/**"],
      "defines": ["_DEBUG", "UNICODE", "_UNICODE"],
      "windowsSdkVersion": "10.0.18362.0",
      "compilerPath": "C:/Program Files (x86)/Microsoft Visual Studio/2019/BuildTools/VC/Tools/MSVC/14.24.28314/bin/Hostx64/x64/cl.exe",
      "cStandard": "c11",
      "cppStandard": "c++17",
      "intelliSenseMode": "msvc-x64"
    }
  ],
  "version": 4
}
```

You only need to add to the Include path array setting if your program includes header files that are not in your workspace or in the standard library path.

仅当程序包含工作空间或标准库路径中没有的头文件时，才需要添加到“包含路径数组”设置。


### Compiler path
* 编译路径

The compilerPath setting is an important setting in your configuration. The extension uses it to infer the path to the C++ standard library header files. When the extension knows where to find those files, it can provide useful features like smart completions and Go to Definition navigation.

editorPath设置是配置中的重要设置。该扩展使用它来推断C++标准库头文件的路径。当扩展知道在哪里可以找到那些文件时，它可以提供有用的功能，例如智能补全和“转到定义”导航。

The C/C++ extension attempts to populate compilerPath with the default compiler location based on what it finds on your system. The extension looks in several common compiler locations.

C/C++扩展尝试根据在系统上找到的内容，使用默认的编译器位置填充compilePath。该扩展在几个常见的编译器位置中查找。 

The compilerPath search order is:
CompilerPath的搜索顺序为：
    
    First check for the Microsoft Visual C++ compilerOpe
    Then look for g++ on Windows Subsystem for Linux (WSL)
    Then g++ for Mingw-w64.
	
    首先检查Microsoft Visual C++编译器的编译器，然后在Windows Subsystem for Linux（WSL）上寻找g++，然后在Mingw-w64上寻找g++。 

If you have g++ or WSL installed, you might need to change compilerPath to match the preferred compiler for your project. For Microsoft C++, the path should look something like this, depending on which specific version you have installed: "C:/Program Files (x86)/Microsoft Visual Studio/2017/BuildTools/VC/Tools/MSVC/14.16.27023/bin/Hostx64/x64/cl.exe".

如果安装了g++或WSL，则可能需要更改editorPath以匹配项目的首选编译器。对于Microsoft C++，路径应取决于您安装的特定版本：“C:/Program Files (x86)/Microsoft Visual Studio/2017/BuildTools/VC/Tools/MSVC/14.16.27023/bin/Hostx64/x64/cl.exe”。

## Reusing your C++ configuration
* 重用您的C++配置

VS Code is now configured to use the Microsoft C++ compiler. The configuration applies to the current workspace. To reuse the configuration, just copy the JSON files to a .vscode folder in a new project folder (workspace) and change the names of the source file(s) and executable as needed.

VS Code现在已配置为使用Microsoft C++编译器。该配置适用于当前工作空间。要重用配置，只需将JSON文件复制到新项目文件夹（工作区）中的.vscode文件夹，然后根据需要更改源文件和可执行文件的名称。 

## Troubleshooting
* 故障排除

If you see the error "The term 'cl.exe' is not recognized as the name of a cmdlet, function, script file, or operable program.", this usually means you are running VS Code outside of a Developer Command Prompt for Visual Studio and VS Code doesn't know the path to the cl.exe compiler.

如果看到错误“命令'cl.exe'未被识别为cmdlet，函数，脚本文件或可运行程序的名称。”，则这通常意味着您在Visual Studio的开发人员命令提示符之外运行VS Code。 Studio和VS Code不知道cl.exe编译器的路径。

You can always check that you are running VS Code in the context of the Developer Command Prompt by opening a new Terminal (Ctrl+Shift+`) and typing 'cl' to verify cl.exe is available to VS Code.

您始终可以通过打开新的终端（Ctrl + Shift + \`）并键入'cl'来验证cl.exe是否可用于VS Code，从而在开发人员命令提示符的上下文中检查是否正在运行VS Code。

## Next steps
* 后续步骤
   
    Explore the VS Code User Guide.
    Review the Overview of the C++ extension.
    Create a new workspace, copy your .vscode JSON files to it, adjust the necessary settings for the new workspace path, program name, and so on, and start coding!
   
    探索《VS Code用户指南》。查看C++扩展概述。创建一个新的工作区，将您的.vscode JSON文件复制到 调整新工作区路径，程序名称等的必要设置，然后开始编码！