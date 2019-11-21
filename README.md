# adventofcode-2018
My solutions for Advent of Code 2018 using C++.  

---
## Prerequisites
* CMake (>= 3.1)
* clang or g++

## About the Project Setup
I wanted to learn more about CMake so I created a new cmake project for each day.  The cmake projects were tested on OS X (using XCode 10.1) and on Slackware 14.2.

### Generating the Day
Each day was generated with a bootstrap CMake project.  GenerateDay.sh contains the order of the commands used.  This was run on my OS X system but could be easily adapted to generate on Linux.  The templates for the CMakeLists.txt and source files are found in the Templates folder.  
### Downloading the Day
The Tools/DownloadDay.py is used to download the days input file and description. In order to use this, a separate file named ```session_key.txt``` is required to be placed in the Tools directory.  This file simply contains the browser session key in order to download your account's input file.  The script assumes you are executing one level up from the Tools folder and requires [beautifulsoup4][1] and [pypandoc][2].  Additional pip modules installed for use with bs4 was requests and html5lib.
> \> python ./Tools/DownloadDay.py \<Day\> \<Year\>

[1]: https://www.crummy.com/software/BeautifulSoup/bs4/doc/#installing-beautiful-soup
[2]: https://pypi.org/project/pypandoc/
