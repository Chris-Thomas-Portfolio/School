#***************************************************
# Author: Chris Thomas
# Date: 4/9/2022
# Description: Bash script for running foo program.
#****************************************************
#!/usr/bin/bash
#***************************************************
# Purpose: Function to be called to print out the 
#           help message to the screen.
# Pre-condition: N/A
# Post-condition: Display the help message to the screen.
#***************************************************
show_help()
{
    echo "Help Message:"
    echo "Acceptable Parameters:"
    echo "-h display this help message"
    echo "-e sets the ending value"
    echo "-s sets the starting value"
    echo "-v set to verbose mode"
    exit
}
#set default values for the variables
start_v=1
end_v=0
verbose=0
while getopts "he:s:v" option; do #argument handling
    case $option in
        h)
            show_help       #call help function
            ;;
        e)  
            if [ $OPTARG -lt $start_v ]; then #if start_v is greater than
                start_v=$OPTARG             #end_v argumkent set start_v
                end_v=$OPTARG               #and end_v to OPTARG value
            else 
                end_v=$OPTARG               #else set end_v to OPTARG
            fi
            ;;
        s)
            if [ $OPTARG -gt $end_v ]; then #if OPTARG is greater than end_v
                end_v=$OPTARG               #set end_v and start_v to OPTARG
                start_v=$OPTARG
            else
                start_v=$OPTARG             #else set start_v to OPTARG
            fi
            ;;
        v)
            verbose=1                       #set verbose to 1 to trigger
            ;;                              #verbose mode
        *)
            show_help                       #default to show_help
            ;;
    esac
done
if [[ $start_v == 1 && $end_v == 0 ]]; then
    show_help   #if nothing was passed in call show_help function
fi
if [ $verbose == 0 ]; then
    for ii in `seq $start_v $end_v`; do
        ./foo $ii
        if [ $? == 0  ]; then
            echo "$ii was successful"       #only show success if not in verbose
        fi                                  #mode
    done
else
    for ii in `seq $start_v $end_v`; do
        ./foo $ii
        if [ $? == 0  ]; then
            echo "$ii was successful"       #show all in while in verbose mode
        else
            echo "$ii was unsuccessful"
        fi
    done
fi
