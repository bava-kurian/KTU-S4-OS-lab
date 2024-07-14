i=1
echo enter the limit
read n
echo Enter the numbers
while [ $i -le $n ]
do
read num
sum=$(($sum+$num))
i=$(($i+1))
done
average=$(($sum / $n))
echo average=$average