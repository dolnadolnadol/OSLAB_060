for file in $(find . -type f -name "*.c")
do
	#printf "file = %s\n" $file
	name=$(echo $file|cut -d'/' -f2|cut -d'.' -f1)
	#printf "name = %s\n" $name
	#gcc -o $name $file
	$ rm gcc -o $name $file  2> /dev/null
	if [ -f $name ]
	then
		#printf "this is condi %d\n" $(./$name)
		if [ $(./$name) -eq 20 ]
		then
			#printf "this is condi %s" $(./$name)
			printf "%s\t%d\n" $name 10
		elif [ $(./$name) != 20 ]
		then
			printf "%s\t%d\n" $name 7
		fi
	else
		printf "%s\t%s\n" $name 5
	fi
done
