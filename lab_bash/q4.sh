echo "Is it mrning? yes or no"
read timeofday
if [ $timeofday = "yes" ]
then
	echo "Good Morning"
elif [ $timeofday = "no" ]
then
	echo "Good Afternoon"
else
	echo "Srroy, do not understand $timeofday"
	exit 1
fi
exit 0
