#!/usr/bin/python
# Assignment: Python Shell
# Author: Chris Thomas
# Date: 5/17/2022
# Modifications: N/A

#importing needed libraries 
import subprocess
import os


count = 1                                       #initialize count variable 
excount = 1                                     #initialize excount variable
exe = []                                        #initialize exe list
while 1:
    x = input('cmd> ')                          #give promt and recieve input
    uinput = x.split(' ')                       #split the input by spaces
    if x in ['run']:
        quit("Invalid Run Command")             #if run is entered here quit and send error message
    if x in ['exit']:
        quit("Exiting")                         #if exit was entered quit and send Exiting message
    if x in ['dir']:
        uinput += ['.']                         #if dir was entered add a . to it
    if excount > 1:
        runchoice = int(uinput[1])              #get the run choice from user
        subprocess.run(exe[runchoice - 1])      #run the program that was selected by the user
        exe = []                                #clear the program list
        excount = 1                             #reset the program count
    else:
        result = subprocess.run(['ls', '-l', os.path.expanduser(uinput[1])], stdout=subprocess.PIPE) #call -ls -l on the path inserted by user
        data = bytes.decode(result.stdout)                                                           #decode the result
        lines = data.split('\n')                                                                     #split the info into lines
        excount = 1                                                                                     
        while count < len(lines)-1:                                                                  #go through all the lines
            word = lines[count].split(' ')                                                           #break them lines by spaces
            count += 1                                                                               #increase count by 1
            if (word[0][0] == 'd'):                                                                  #check if it is a directory if it is ignore it
                pass
            elif (word[0][3] == 'x'):                                                                #if its an executable print its name out and increment exxcount
                print(excount, word[-1])
                exe += [os.path.expanduser(uinput[1]) + "/" + word[-1]]                              #add the executable path to the list
                excount += 1                                                                         #increment excount
        #reset all the lists and count
        uinput = []
        result = []
        data = []
        lines = []
        count = 1
