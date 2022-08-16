#!/bin/sh

# Function to break up each command
newbreak(){
echo "\n----------------------------------------------------------------"
echo "----------------------------------------------------------------\n"
}

newbreak

# Command who - show who is logged on
echo "Who --> Print information about users who are currently logged in. \n"
who
newbreak

# Command whoami - print effective userid
echo "Whoami --> Print  the  user  name  associated  with the current effective user ID. \n"
whoami
newbreak


# Command date - print or set the system date and time
echo "Date --> Display the current time in the given FORMAT, or set the system date. \n"
date
newbreak

# Command hostname - show or set the system's host name
echo "Hostname --> Display the system's DNS name, and  to  display  or set its hostname or NIS domain name. \n"
hostname
newbreak
