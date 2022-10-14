myvar="Hi there"
#myx = "error because of spacebar"
echo $myvar
echo 1 "$myvar"
echo 2 '$myvar'
echo 3 'myvar contains ""$myvar""'
echo 4 \$myvar
echo 5 "myvar contains \"$myvar\""
echo Enter some test
read myvar
echo '$myvar' value is $myvar
exit 0
