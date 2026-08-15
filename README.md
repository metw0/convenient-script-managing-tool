csmt made to improve the experience of scripting your own stuff for Linux, BSD, or macOS;                     
the utility allows you to easily run your scripts in Bash, Python, or binaries by just putting them into one directory;                     
also csmt can run Bash and Python scripts or binaries with just one command *as I wrote about below*                     
## how to download
### with installer
1. download csmt build for your system from [source page](https://github.com/metw0/convenient-script-managing-tool/releases)
2. unzip archive somewhere
3. give installer rights to run: `chmod +x install.sh`
4. run installer: `sudo ./install.sh`
### from source
0. download xmake from their [home page](https://xmake.io/guide/quick-start.html)
1. download source code: `git clone https://github.com/metw0/convenient-script-managing-tool`
2. move to project directory: `cd convenient-script-managing-tool`
3. build it with Xmake: `xmake`
4. find your binary *might be in build/os_name/cpu_arch/release*
5. give csmt rights to run `sudo chmod +x csmt`
6. move it to others binaries `sudo cp csmt /usr/local/bin/` *might be different in mac/bsd, like /opt/homebrew/bin etc.*
## how to use
### commands
**csmt add:**                 
add your script to csmt main folder,                      
use it like `csmt add script_name.sh`                     
**csmt run:**                 
runs your previously added script,                    
use it like `csmt run script_name.sh`                                   
**csmt rm:**                 
remove your script from csmt main folder **!!GONNA DELETE IT!!**,                 
use it like `csmt rm script_name.sh`                 
