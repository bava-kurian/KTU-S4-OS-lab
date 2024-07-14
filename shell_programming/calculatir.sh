#simple calculator using functions
echo enter two numbers
read a
read b
echo Your choices are:
echo 1.Addition
echo 2.Subtraction
echo 3.Multiplication
echo 4.Division
echo 5.Modulus
echo -n "Enter your choice: "
read choice
addition()
{
    echo $a + $b = $(($a+$b))
}
subtraction(){
    echo $a - $b = $(($a-$b))
}
multiplication(){
    echo $a * $b = $(($a*$b))
}
division(){
    echo $a / $b = $(($a/$b))
}
modulus(){
    echo $a % $b = $(($a%$b))
}

if [ $choice -eq 1 ]; then
    addition
elif [ $choice -eq 2 ]; then
    subtraction
elif [ $choice -eq 3 ];then
    multiplication
elif [ $choice -eq 4 ];then
    division    
elif [ $choice -eq 5 ];then
    modulus
else
    echo "Wrong choice"
fi 
exit 0;