# new_labcim_labBot

New programming interface software to use with Intellitek robots compatible with ACL language.
It is a frontend to the robot controler via serial comunication and simulation trought the
[ACLC](https://github.com/cimtools/aclc) simulator.

# Install (on ubuntu Linux)

## Building

Clone the git repository.

    git clone git@github.com:cimtools/new_labcim_labBot.git
    
Install the dependencies.

    sudo apt-get install build-essential qtcreator qt5-default libqt5serialport5-dev qtdeclarative5-dev

Build the makefile using qmake

    cd alfa
    qmake alfa.pro
    make

# SEE ALSO

ACL can be found in Google using:

    scorbot define global println delay
