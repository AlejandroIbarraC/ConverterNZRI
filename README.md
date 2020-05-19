
# HammingNZRI ⚡️

**HammingNZRI** is a simple Qt graphical app for exemplifying common behaviour of some features pertaining logical circuit design concepts. The app has a simple neumorphic look with icons and raised buttons. It runs on the GUI framework Qt 5 for C++. It features two major views that showcase different topics.

### Base Converter/NZRI

Takes an 4 digit number in octal form and shows the equivalent in binary and hexadecimal form. At the top there's a graphical representation of the NZRI square signal, assuming the starting value has a negative amplitude.

### Hamming Code

Takes a 12 digit binary number and draws a matrix following the rules of Hamming code error correction. You can set even or odd parity with a checkbox, and then double click on the bit you want to force an error. The app will generate the corresponding matrix that represents the algorithm's way of finding the error position. For more information about Hamming code analysis refer to external online documentation, this is merely a graphical, automated way to see the process in action.

## Photos 📷

Start                        |Converter/NZRI                      |
:------------------------------:|:------------------------------:
![](readme-images/s1.png)  |  ![](readme-images/s2.png)

Hamming Code                       |Hamming Code with error              |
:-------------------------:|:-------------------------:
![](readme-images/s3.png)  |  ![](readme-images/s4.png)

## Getting Started 🚀

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites 👓

Software you need to install to run this project:

```
Qt 5.14 or higher
CMake 3.15 or higher
```

### Installing 💻

Install Qt using your preferred method. I usually just download the installer found in the official website and select the desktop version along with Qt Creator IDE. You also need to install [CMake](https://cmake.org/download/) if you don't have it already to compile and run C++ programs.

Once that's set up you can run the app using Qt Creator or an IDE of your choice. Keep in mind you may need to replace the editors CMake path with the one bundled with Qt.

An example of this is Jetbrains CLion (a very cool looking C/C++ IDE that I personally really like), to run Qt apps go to

Preferences -> Build, Execution and Deployment -> CMake -> CMake Options entry

Replace content with "-DCMAKE_PREFIX_PATH=(replace with path to CMake folder in Qt installation)"

The app was developed on macOS Catalina running Qt 5.14. As Qt is a cross-platform framework, it should run relatively the same on other platforms, but your mileage may vary.

## Built With 🛠

<table>
  <tr>
    <td>
      <p align=center><img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQPulCp1_2X95McIbF8PzbWQGzI1r9-eYUZZDfIgxpSLpt4zGoP&s" width="100"></p>
    </td>
  </tr>
  
  <tr>
    <td>
      <p align=center><a href="https://www.qt.io/"><b>Qt5</b></a>
      </br>GUI Framework for C++</p>
    </td>
  </tr>
</table>

## Authors 👨🏻‍💻

* **Alejandro Ibarra** - *Developer & Designer* - [AlejandroIbarraC](https://github.com/AlejandroIbarraC)

## License 📄

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments 📎

* Medium article - [Neumorphism the right way — A 2020 Design Trend ](https://medium.com/@artofofiare/neumorphism-the-right-way-a-2020-design-trend-386e6a09040a)
* Costa Rica Institute of Technology
* Juan Carlos Jiménez Robles (a.k.a Bigotes)
* Kevin Cordero - [Skryfall](https://github.com/Skryfall)

<p align="center">
  <img src="https://amin-ahmadi.com/wp-content/uploads/2016/12/Built_with_Qt_RGB_logo_vertical.png" width="40"/>
</p>
<p align="center">This project was made with academical purposes. J.A Ibarra. 2020</p
```

